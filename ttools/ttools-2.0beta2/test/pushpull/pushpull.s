//
// pushpull --
//   Simple sample program for data exchange via the communication board.
//
// The programs comprises two processes, one for input and another for
// output.  Each process is assigned a fixed link to work with.  There
// are two data buffers for input and two for output; this allows PC and
// transputer to act in parallel.  Each buffer has a status word
// associated with it, which provides for synchronization between PC and
// transputer.  Zero status indicates that the buffer is empty.  When one
// fills the buffer with data, it finishes with placing the length of the
// data into the status word.  Status of -1 indicates the end-of-file
// condition.
// 
// 940621, sizif

#include "pushpull.h"

#define LOOPBACK  /* for test: internal loopback via a memory channel */

/* useful macros make life easier */
#define LEND(ctrl,label)        ldlp ctrl; ldc 9f-label; lend; 9: ;
#define LDPI(label)             ldc label-9f; ldpi; 9: ;
#define NEQC(const)             eqc const; eqc 0;
#define LE                      gt; eqc 0;
#define GE                      rev; LE;
#define LT                      rev; gt;
#define BR                      eqc 0; cj   /* traditional "branch if true" */
#define LDUP(local_index)       stl local_index; ldl local_index;
#define LDS(label)              LDPI(label); ldnl 0;         /* load static */
#define STS(label)              LDPI(label); stnl 0;        /* store static */
#define LDSB(label)             LDPI(label); ld;
#define STSB(label)             LDPI(label); sb;

/* which links we should use */
#ifndef LOOPBACK
  #define PUSH_LINK  (0x80000000)  /* Link 0 Output */
  #define PULL_LINK  (0x80000014)  /* Link 1 Input */
  #define LOAD_PUSH_LINK	mint;
  #define LOAD_PULL_LINK	mint; ldnlp +5;
#else /* LOOPBACK */
  #define PUSH_LINK  (0x80000080)
  #define PULL_LINK  PUSH_LINK
  #define LOAD_PUSH_LINK	mint; ldnlp +0x20
  #define LOAD_PULL_LINK	LOAD_PUSH_LINK
#endif /* LOOPBACK */

.globl head@@start;
 head@@start = 0x80008000;

	/*
         * Startup code
         */

.globl @@hook
@@hook:
	/* Initialize status words for all four buffers */
	ldc 0; LDPI (PUSH_STAT1); stnl +0;
	ldc 0; LDPI (PUSH_STAT2); stnl +0;
	ldc 0; LDPI (PULL_STAT1); stnl +0;
	ldc 0; LDPI (PULL_STAT2); stnl +0;

#ifdef LOOPBACK
	/* Initialize the memory link used for loopback */
	mint;
	STS (PUSH_LINK)
#endif /* LOOPBACK */

/* For testing on-board memory with the transputer passive */
#if 0
/* when we do just stopp here, everything goes fine, even with /usr/bin/emacs */
	stopp
#elif 0
/* try to do something irrelevant with memory R/W: may it will interfere?
   nope; everything's fine */
  1:
	ldc 0xaa55aa55;
	ldc 0x80005000;
	stnl +7
	j 1b
#elif 0
/* try to do something like what we do under normal operation: block move */
  1:
//	LDPI (PUSH_BUF1)
//	LDPI (0x80007000)
	LDPI (0x80006000)
	LDPI (0x80006000)
//	ldc PUSHPULL_BUFSIZE
//	ldc 2048+1024 		// No errors
//	ldc 2048+1024+512	// No errors
//	ldc 2048+1024+512+256	// Very rare errors
	ldc 2048+1024+1024	// Errors 50/50
	move
	j 1b
#elif 0
/* see if moving memory block by pieces interfere as well...
   ... it does.  */
  1:
	LDPI (0x80007000)	// from
	stl 0
	LDPI (0x80006000)	// to
	stl 1
	ldc 4096		// count
	stl 2
  2:	
	ldl 0; ldnl 0
	ldl 1; stnl 0
	ldl 0; ldnlp 1; stl 0	
	ldl 1; ldnlp 1; stl 1
	ldl 2; adc -4; stl 2
	ldc 1; ldl 2; gt; cj 2b
	j 1b
#elif 0
/* so it seems that any write operation from transputer is dangerous.
   Try to simplify the test case */
	// Move the program to the internal memory (which is safe from the corruption)
	LDPI (1f)
	mint; adc 0xf0	// plcace the program at 0x800000f0
	ldc 2f-1f
	move
	// Put destination address to the workspace
	LDPI (0x80006000 + 4095)
	stl 1
//	mint; adc 0xf0; gcall
  1:
	ldl 1; stnl 0	// write a random garbage to the address specified
	ldl 1; stnl 0	// write a random garbage to the address specified
	ldl 1; stnl 0	// write a random garbage to the address specified
	ldl 1; stnl 0	// write a random garbage to the address specified
	ldl 1; stnl 0	// write a random garbage to the address specified
	j 1b
  2:
#elif 0
  1:
	LDPI (0x80007000+2048+1024+512)
	LDPI (0x80006000+2048+1024+512)
	ldc 512
	move
	j 1b
#endif


	/* start transmitter process */
	ldc push - 9f
	ldlp +0x50
	startp;
  9:
	/* start receiver process */
	ldc pull - 9f
	ldlp +0xa0
	startp;
  9:
	/* ... and die. */
	stopp


	/*
         * Transmitter process code
         */
push:
  1:
	LDPI (PUSH_STAT1)
	LDPI (PUSH_BUF1)
	call push1
	LDPI (PUSH_STAT2)
	LDPI (PUSH_BUF2)
	call push1
	j 1b

#define PUSH_STAT_ADDR  (NAUTO+1+1)
#define PUSH_BUF  (NAUTO+1+0)
#define NAUTO 2
#define STATUS 1
#define UNUSED 0
push1:
	ajw -NAUTO

	/* Wait until the buffer becomes filled with data */
  1:
	ldtimer; tin;	// deschedule
	ldl PUSH_STAT_ADDR
	ldnl 0
	LDUP (STATUS)
	cj 1b

	/* Make sure the status word is stable (paranoia) */
  1:
        ldtimer; adc 1; tin;
	ldl STATUS
	ldl PUSH_STAT_ADDR
	ldnl 0
	LDUP (STATUS)
	diff
	BR 1b

	/* Send the status down the output link */
	ldlp STATUS	// buffer
	LOAD_PUSH_LINK	// channel
	ldc 4		// count
	out

	/* If the status is really the end-of-file indicator,
           there's no need to transmit any data */
	ldl STATUS;
        eqc -1;
	BR 1f

	  /* Send the message proper */
	  ldl PUSH_BUF		// buffer
	  LOAD_PUSH_LINK	// channel
	  ldl STATUS		// count
	  out
  1:	
        /* Indicate that the buffer is now empty */
	ldc 0
	ldl PUSH_STAT_ADDR
	stnl 0

	ajw +NAUTO
	ret
#undef PUSH_STAT_ADDR
#undef PUSH_BUF
#undef NAUTO


	/*
         * Receiver process code
         */
pull:
  1:
	LDPI (PULL_STAT1)
	LDPI (PULL_BUF1)
	call pull1
	LDPI (PULL_STAT2)
	LDPI (PULL_BUF2)
	call pull1
	j 1b

#define PULL_STAT_ADDR  (NAUTO+1+1)
#define PULL_BUF  (NAUTO+1+0)
#define NAUTO  2
#define LENGTH  1
#define UNUSED  0
pull1:
	ajw -NAUTO

	/* Wait until the buffer becomes free */
  1:
	ldl PULL_STAT_ADDR
	ldnl 0
	cj 1f
	ldtimer; tin;	// deschedule
	j 1b

  1:
	/* Get message length from the input link */
	ldlp LENGTH	// buffer
	LOAD_PULL_LINK	// channel
	ldc 4		// count
	in

	/* If the message length was really the end-of-file indicator,
           there's no need to receive any data */
	ldl LENGTH;
        eqc -1;
	BR 1f

	  /* Receive the message */
	  ldl PULL_BUF		// buffer
	  LOAD_PULL_LINK	// channel
	  ldl LENGTH		// count
	  in
  1:
	/* Indicate that the buffer is full of data */
	ldl LENGTH
	ldl PULL_STAT_ADDR
	stnl 0
	
	ajw +NAUTO
	ret
#undef PULL_STAT_ADDR
#undef PULL_BUF
#undef NAUTO
	
	
	
	


