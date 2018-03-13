/* $Id: options.h,v 1.2 1996/02/25 15:48:07 sizif Exp $ */

/*
 * This file is part of TTOOLS package.
 * Copyright (c) 1995 Yury Shevchuk <sizif@botik.ru>
 */

/* When option definition lives close to usage instructions, the
   chances for them to be in sync are much better */

#define OPTION_HELP  301
DEFINE_OPTION ("help", no_argument, NULL, OPTION_HELP, "\
--help			show the usage summary\n")

DEFINE_OPTION ("output", required_argument, NULL, 'o', "\
-o F, --output F	output to file F (default a.out)\n")

DEFINE_OPTION ("expr-print-long", no_argument, NULL, 'E', "\
-E, --expr-print-long	longer flavour of expression dumps\n")

DEFINE_OPTION ("maxpasses", required_argument, NULL, 'p', "\
-p N, --maxpasses N	max number of offset optimization passes\n")

DEFINE_OPTION ("trace", required_argument, NULL, 't', "\
-t SPEC, --trace SPEC	enable debugging output\n")

DEFINE_OPTION ("dump", required_argument, NULL, 'd', "\
-d SPEC, --dump SPEC	enable debugging dumps\n")


/* end of common options; lit-specific options follow */

DEFINE_OPTION ("segment-align", required_argument, NULL, 'a', "\
-a N, --segment-align N	assume segments will be loaded at the multiple-of-N
                        boundary; default 4\n")

DEFINE_OPTION ("hook", required_argument, NULL, 'h', "\
-h NAME, --hook NAME	place NAME on the wanted list instead of the\n\
                        default \"@@hook\"; multiple hooks may be given\n")

DEFINE_OPTION ("library", required_argument, NULL, 'l', "\
-lAR, --library AR	add libAR.a to the list of files to link\n")

DEFINE_OPTION ("libdir", required_argument, NULL, 'l', "\
-LDIR, --libdir DIR	add DIR to the library search path\n")

DEFINE_OPTION ("", optional_argument, NULL, 'T', "\
-TSEG ADDR		assign SEG@@start the value ADDR\n")

DEFINE_OPTION ("map", optional_argument, NULL, 'm', "\
-m[FILE], --map[=FILE]	write symbol map to FILE (stdout if FILE omitted)\n")
