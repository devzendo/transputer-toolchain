README.txt
----------

This is the source code distribution of various build tools for the Parachute parallel programming environment.
These tools were not originally developed by me; this is just a collection
found on the Internet, with a failed attempt to modify them to build on current
development systems by me.

Status: abandoned. Details of where I stopped/why are given below....

Copyrights of the individual tools are given in the various subdirectories, alongside the tool distribution archives.
My patches, build scripts and later modifications however are...

(C) 2005-2018 Matt J. Gumbley
matt.gumbley@gmail.com
@mattgumbley @devzendo
http://devzendo.github.io/dev/parachute

LICENSING
---------
This software is distributed under a variety of licenses - see subdirectories.

All software here obtained from http://wotug.org/parallel/transputer/software/compilers/gcc/pereslavl/
University of Pereslavl, Russia.

Many thanks to the authors listed below for their work in adding Transputer support to the GCC toolchain.

DIRECTORY STRUCTURE
-------------------
The source is split into the following directories:

gcc-t800: the GCC-T800 GCC 2.7.2 compiler.
  Supported: code generation for most (all?) 32-bit transputers (t800, t805, t425, t9000, t450); asm_operands;
  floating point instructions (no opt). Unsupported: debugging.
  Author: Yury Shevchuk (sizif@botik.ru)

  I (Matt) have ungzipped the original gcc-2.7.2-t800.12.dif.gz into ...diff
  The gcc-2.7.2-t800.parachute.patch adds support for i686 Linux.

  The gcc-2.7.2 directory in here is the unzipped original GCC 2.7.2 source release, with the t800 patch subsequently
  applied, then the parachute patch applied. Commits were made at each of these stages so I can work with Mercurial for
  understanding differences, rather than diffs. Subsequent commits in this directory are to enable the toolchain to
  build on more recent OSs.

ttools: TTOOLS 2.0beta2: Transputer tools - assembler, linker, loader and auxiliary programs.
  A free package comprising assembler, linker, loader(s), and auxiliary programs intended for software development for
  transputers. It is designed to work with gcc-t800, a port of GNU C/C++ Compiler to transputers.
  Author: Yury Shevchuk (sizif@botik.ru)

libxputer:  A simple attempt to wrap all transputer architecture features into C functions.
  Author: Roman Pozlevich (roma@botik.ru)

dasm: a Transputer disassembler.


BUILDING AND INSTALLING
-----------------------
The distribution currently builds under the following systems:
* Ubuntu Linux 5.04 i386 
* It may also build under other 32-bit distros of that vintage.

It does NOT build correctly on 64-bit systems:
* Mac OSX 'El Capitan' 10.11
* Ubuntu Linux 16.04.4 LTS Intel x86-64
* CentOS Linux 7.4 Intel x86-64
* Windows 10

Prerequisites:
- Ubuntu Linux: flex, build-essential
- A very old version of bison 1.25 is required: the input to bison was
  originally written with bison 1.22 which I could no longer find on the
  Internet. 1.25 is the oldest available.

The install location is /opt/parachute. Changing this would entail changes to
Makefiles in the above hierarchy, and changes to *.parachute.patch in
subdirectories.

To build, cd to the top level directory (where this README.txt is) and do:
make

During the build, you will be prompted for a password. This is since the files
are installed as root, and the build requires a sudo password.


BUILDING ON 64-BIT
------------------
The ttools assembler has a bug in creating SIZE range structures. On 32-bit
it'll typically create them as [1..8], whereas on 64-bit it'll generate
[1..16]. This is found when running test/pushpull (make test). The
pushpull.o.dump will show the difference. Fault is somewhere in shared/cmd.c
cmd_size, or shared/expr.c expr_estimate or shared/ments.c emit_cmd/EXPR_CONST
processing.

I timeboxed fixing this, but had to stop.
Running the test/pushpull with ASTFLAGS = --dump +all --trace +all illustrates
the problem. The assembly of the ldc 0; LDPI (PUSH_STAT1); stnl +0; is where
the diff of 'the authors snapshots of output products' vs 'this current build
output products' shows a difference... see below.

On Ubuntu 5.04/64, some differences in ttools’ test binaries:
The .o files are the same length, but some bytes are different. Consistently
different: current build has 0x10, stored file has 0x08 in each of the
differences. First difference at offset 0x45 (69) - which is inside the block
that has a different size area, in the dump (described below):

000051: element #1 CMD 0x40
	arg (-2147446819 - (@@hook + [1]))
	size [1..16]
So where does the assembler create CMD blocks? 
Disassembled, this block is:
000051: element #1 CMD 0x40
        (@@hook + 1):
                         ldc (-2147446819 - (@@hook + [1]))
                         
The .o.dump files have differences in CMD blocks (and only CMD blocks, but not
all of them): the current .o.dump file as built on 64-bit has ‘size [1..16]’,
whereas the stored file has ‘size [1..8]’ (in some, but not all CMD blocks).

Is this a fault in the dump utility?
There is also a difference in the disassembler das’ output: in the current
build, ldc of negative constants is different:

new build:
0x0000001e: g %L     67 20 25 4c             ldc -32676 (0xffffffffffff805c)
stored file:
0x0000001e: g %L     67 20 25 4c             ldc -32676 (0xffff805c)

The bytes in the file (67 20 25 4c) are the same; this is likely to be a printf
bug, assuming an incorrect word length for 32-bit quantities?

The preprocessed file in the ttools test/pushpull is identical, when the tests
are run on Ubuntu 5.04 64-bit - so it’s not the preprocessor that’s causing the
difference in the assembled .o file - it must be the assembler itself that’s
assembling the following line incorrectly on 64 vs 32 bit:

        ldc 0; ldc  (0x80009000-0x20+0x00)  -9f; ldpi; 9: ; ; stnl +0;


Otherwise, getting gcc compiled was also proving very hard.



MAILING LIST
------------
Groups.io

... to be continued ...




