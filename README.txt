README.txt
----------

This is the source code distribution of various build tools for the Parachute
parallel programming environment. These tools were not developed by me; this is
just a collection found on the Internet, and modified to build on current
development systems by me.

Copyrights of the individual tools are given in the various subdirectories,
alongside the tool distribution archives. My patches and build scripts however
are...

(C) 2005-2018 Matt J. Gumbley
matt.gumbley@gmail.com
@mattgumbley @devzendo
http://devzendo.github.io/dev/parachute

LICENSING
---------
This software is distributed under a variety of licenses - see subdirectories.
All software here obtained from http://wotug.org/parallel/transputer/software/compilers/gcc/pereslavl/
University of Pereslavl, Russia.

DIRECTORY STRUCTURE
-------------------
The source is split into the following directories:

gcc-t800: the GCC-T800 GCC 2.7.2 compiler.
  Supported: code generation for most (all?) 32-bit transputers (t800, t805, t425, t9000, t450); asm_operands;
  floating point instructions (no opt). Unsupported: debugging.
  Author: Yury Shevchuk (sizif@botik.ru)

  I (Matt) have ungzipped the original gcc-2.7.2-t800.12.dif.gz into ...diff
  The gcc-2.7.2-t800.parachute.patch adds support for i686 Linux, and OSX.

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
* Mac OSX 'El Capitan' 10.11
* Ubuntu Linux 16.04.4 LTS Intel x86-64
* CentOS Linux 7.4 Intel x86-64
* Windows 10

Prerequisites:
- Ubuntu Linux: flex, build-essential

The install location is /opt/parachute. Changing this would entail changes to
Makefiles in the above hierarchy, and changes to *.parachute.patch in
subdirectories.

To build, cd to the top level directory (where this README.txt is) and do:
make

During the build, you will be prompted for a password. This is since the files
are installed as root, and the build requires a sudo password.


MAILING LIST
------------
Groups.io

... to be continued ...




