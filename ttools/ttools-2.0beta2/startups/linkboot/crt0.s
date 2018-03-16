/* $Id: crt0.S,v 1.1.1.1 1995/12/22 12:24:39 sizif Exp $ */

/*
 * This file is part of TTOOLS package.
 * Copyright (c) 1995 Yury Shevchuk <sizif@botik.ru>
 */

/* Universal startup for booting via transputer link.

   * segments are placed back-to-back in the natural order
     (.text,.data,.bss) in link time.  This makes better code than
     loading the separately since the knowledge of relative positions
     of segments allows lit to optimize offsets from text to data/bss
     segments.

   * load address (text@@start) may be unknown till the load stage

   * The segments .head and .head2 are reserved for use by the loader;
     user code must not contibute to these segments.  .head contains a
     small (<=250 bytes) first boot phase as a single BLOCK record.
     As you can notice, the format of (a small) BLOCK record agrees
     with what transputer firmware expects as the boot data, so you
     can get the first phase loaded by transputer firmware if you send
     the LIT format file down a transputer link after resetting the
     transputer.

     The first phase performs some vital initializations, and then
     reads in the second phase from the same link it was booted from.
     The second phase is contained in a (large) BLOCK record.  It
     first probes the available memory [NOT IMPLEMENTED YET] and sets
     stack pointer to the top of it.  Then it loads the rest of the
     file using the C function lit_load_segment, and jumps to the
     beginning of .text, where there is a call to _main.

     Note that both .head and .head2 must consist of a single BLOCK
     record, which requires the code that goes there to be
     position-independent. */


/* Where to load: the address of the .text segment start */
///* load at a fixed absolute address */
//#define LOAD_LOAD_ADDRESS()  mint; adc 0x1000
/* load just past the end of .head2 */
#define LOAD_LOAD_ADDRESS()  LDPI (head2@@start+head2@@size)

/* Address of the top of installed memory.  This hardcoding will go
   away as soon as second phase is taught to do memory probing */
#define MEMORY_TOP (0x80000000 + 256*1024)

/* size of .head2 segment record; use litdump to check it's true */
#define LIT_SEGMENT_HEAD2_RECORD_SZ  9


/* Standard set of handy macros */
#define LDPI(LABEL)	ldc LABEL-9f; ldpi; 9: ;
#define LDS(LABEL)      LDPI(LABEL); ldnl 0;
#define STS(LABEL)      LDPI(LABEL); stnl 0;
#define LDSB(LABEL)     LDPI(LABEL); lb;
#define STSB(LABEL)     LDPI(LABEL); sb;
#define LEND(CTRL,LABEL) ldlp CTRL; ldc 9f-LABEL; lend; 9: ;
#define NEQC(CONST)     eqc CONST; eqc 0;
#define LE              gt; eqc 0;
#define GE              rev; LE;
#define LT              rev; gt;
#define BR              eqc 0; cj   /* traditional "branch if true" */


/* Offsets to boot parameters from Wreg, when it points to `workspace' */
#define L_BOOT_LINK_OUT  ((_boot_link_out-workspace)/4)
#define L_BOOT_MEMORY_START  ((_boot_memory_start-workspace)/4)
#define L_BOOT_OLD_IPTR  ((_boot_old_iptr-workspace)/4)
#define L_BOOT_OLD_WREG  ((_boot_old_wreg-workspace)/4)
#define L_BOOT_LINK_IN  ((_boot_link_in-workspace)/4)

/* Stack frame layouts */
/* phase 1 stack frame */
#define L_LEND_PARAM  (0)
#define L_LEND_PARAM_SZ  (1)
#define L_LEND_COUNT  (L_LEND_PARAM+L_LEND_PARAM_SZ)
#define L_LEND_COUNT_SZ  (1)
#define L_LEND_CONTROL  (L_LEND_PARAM)
#define L_SCRATCH  (L_LEND_COUNT+L_LEND_COUNT_SZ)
#define L_SCRATCH_SZ  (1)
#define PHASE1_WORKSPACE_SZ  (L_SCRATCH+L_SCRATCH_SZ)

/* phase 2 stack frame */
#define L_OUTARGS  (0)
#define L_OUTARGS_SZ  (4)
#define L_AREA  (L_OUTARGS+L_OUTARGS_SZ)
#define L_AREA_SZ  (1)
#define L_NTAB  (L_AREA+L_AREA_SZ)
#define L_NTAB_SZ  (3)
#define PHASE2_WORKSPACE_SZ  (L_NTAB+L_NTAB_SZ)

.globl head@@start
.globl head2@@start
.globl text@@start
.globl data@@start
.globl bss@@start

.globl head@@size
.globl head2@@size
.globl text@@size
.globl data@@size
.globl bss@@size

.globl head@@blocksize
.globl head2@@blocksize

/* imported symbols */
.globl _lit_load_segment
.globl _lit_load_segsize
.globl _main

/* exported symbols */
.globl @@hook
.globl _boot_link_out
.globl _boot_memory_start
.globl _boot_old_iptr
.globl _boot_old_wreg
.globl _boot_link_in

/* Define segment order and nomenclature; in partcular, this makes lit
   define bss@@size even if user code puts nothing in .bss */
.head .head2 .text .data .bss

/*
 * Relative placement of some segments is known prior to loading;
 * let linker know about it
 */

/* head@@start is not known till load time, but it is not used anyway
   as the code in .head and .head2 is position-independent. */
/* text@@start is not known till load time */
head2@@start = head@@start + head@@size
data@@start = text@@start + text@@size
bss@@start  = data@@start + data@@size

/* Tell lit to make .head and .head2 segments a single BLOCK records */
head@@blocksize = 10*1024
head2@@blocksize = 10*1024


/*
 * First phase of the loader.
 */

 /* Firmware bootstrap procedure loads the contents of .head as the
    first BLOCK from the executable file and jumps to the start of it.
    The size of the first block should be below 250, or else the
    format of the BLOCK record will be different from what the
    firmware expects. */

.head
@@hook:
	.need second_phase

        /*
	 * Save load parms:
	 *   Creg = load channel
	 *   Breg = old Wreg
	 *   Areg = old Iptr
	 *   Iptr = memstart
	 */

        call 1f
1:
	/* Point Wreg to the beginning of the area reserved for
	   workspace, where all L_ offsets to static vars are
	   counted from. */
	LDPI (workspace)
	gajw

	/* saved memstart value needs correction for the size of the
	   call above */
        ldl L_BOOT_MEMORY_START
        adc -(1b-@@hook)
        ldl L_BOOT_MEMORY_START

        /* Compute output channel address */
        ldl L_BOOT_LINK_IN
        ldnlp -4
        stl L_BOOT_LINK_OUT

	/*
	 * vital initializations
	 */

        /* Initialize heads of process' queues */
        mint; sthf
        mint; stlf

        /* Initialize channels, external event and timers */
        ldc 4+4+1+2;
        stl L_LEND_COUNT
1:      mint
        ldl L_LEND_COUNT
        mint
        wsub
        stnl -1;
        LEND (L_LEND_CONTROL, 1b)

        /* Clear error flag & halt-on-error flag */
        testerr;
        clrhalterr;

        /* Start timer (ret won't work unless this is done!) */
        ldc 0
        sttimer


	/*
	 * Initialization comlete -- read on.
	 */

	/* Eat segment switch record.  We don't bother checking if it
	   is really what we expect. */
	LDPI (first_phase_top)
	ldl L_BOOT_LINK_IN
        ldc LIT_SEGMENT_HEAD2_RECORD_SZ
        in

	/* Get the BLOCK length; first, the number type */
	ldc 0
	stl L_SCRATCH
	ldlp L_SCRATCH
	ldl L_BOOT_LINK_IN
        ldc 1
        in

	/* we expect the length to be a two-byte integer, code 252.
           Panic if not */
	ldl L_SCRATCH
	ldc 252	/* 2-byte integer number type */
	diff
	cj 1f
	stopp
1:
	/* read the two bytes of the length proper */
	ldc 0
	stl L_SCRATCH
	ldlp L_SCRATCH
	ldl L_BOOT_LINK_IN
        ldc 2
        in

	/* and in the end, read the second phase BLOCK */
	LDPI (first_phase_top)
	ldl L_BOOT_LINK_IN
	ldl L_SCRATCH	/* block length */
        in

#ifdef DEBUG_PHASE1
	ldc 0x80000070; mint; ldc 256; out;  // dump our memory
	stopp
#endif

	/* OK, now we should have valid code at ``first_phase_top'',
	   go there */
	j first_phase_top


	/* Reserve a bit of space below Wreg, so as not to have code
           clobbered in case firmware decides to write something to
           Wreg[-1], etc */
	.align 4
safetyspace:
	.word ?[5]

	/* Wreg is set up to point here during phase 1; just above
           Wred is PHASE1_WORKSPACE_SZ words for use as local
           variables */
workspace:
	.word ?[PHASE1_WORKSPACE_SZ]

	/* Saved boot parameters visible to C code.  As these are at
           known offsets from Wreg, first phase code can access them
           as local vars using defined L_* offsets */
_boot_link_out::
	.word ?
_boot_memory_start::
	.word ?
_boot_old_iptr::
	.word ?
_boot_old_wreg::
	.word ?
_boot_link_in::
	.word ?

	/* Wreg is set here by bootstrap firmware. */
	.align 4
first_phase_top:


/*
 * Second phase of the loader
 */

.head2
second_phase:
	.need main_trampoline

#ifdef DEBUG_PHASE2
	mint; ldc __LINE__|0x22220000; outword;
#endif

#ifdef notyet
	/*
         * Find out how much memory is here.
	 */
#endif

	/* Set up stack.  This must be done at this point since
           lit_load_segment needs about 100 words of stack space. */
	ldc MEMORY_TOP - PHASE2_WORKSPACE_SZ*4;
	gajw

	/* Set up segment address table (ntab) which is necessary for
	   lit_load_segment.  It will have entries for .head, .head2,
	   and .text; all others should have been eliminated in link
	   lime.  Actually, refs to head2@@start should have been
	   eliminated as well, we put head2 into the table just so. */
	LDPI (head@@start)	
	stl L_NTAB
	LDPI (head2@@start)
	stl L_NTAB+1
	LOAD_LOAD_ADDRESS()
	stl L_NTAB+2

	/* call lit_load_segment repeatedly for every segment found in
	   the file.  The prototype is:
         lit_load_segment (char *area, int areasz, long *ntab, int ntabsz) */

	/* setup running area pointer */
	ldl L_NTAB+2
	stl L_AREA
1:

#ifdef DEBUG_PHASE2
	mint; ldc __LINE__|0x22220000; outword;
#endif

	/* ntabsz */
	ldc 3; stl 0

	/* ntab */
	ldlp L_NTAB

	/* areasz */
	ldc MEMORY_TOP-(200*4)	/* -our stack sz, avoid overwriting */
	ldl L_AREA
	diff

	/* area */
	ldl L_AREA

	call _lit_load_segment		/* args complete, do the call */
	cj 1f				/* jump out if no more segments */

	/* move load point to the end of the segment just loaded */
	LDS(_lit_load_segsize)
	ldl L_AREA
	add
	stl L_AREA

	/* go load next segment */
	j 1b

1:
	/* Done loading; jump to the loaded code -- this is
	   essentially a jump to `main_trampoline' below. */

#ifdef DEBUG_PHASE2
	mint; ldc __LINE__|0x22220000; outword;
	ldl L_NTAB+2; mint; ldc text@@size + data@@size + bss@@size; out;
	stopp
#endif

	ldl L_NTAB+2
	gcall

	/*NOTREACHED*/
	.align 4
second_phase_top:


/*
 * _main trampoline.  This is not a part of .head2, as the relative
 * placement of .head2 and .text is not (generally speaking) known at
 * link time, hence that call would translate into a CMD record,
 * whereas .head2 is required to be a single BLOCK.
 */

.text
main_trampoline:
	call _main
	stopp


/* end of crt0.S */
