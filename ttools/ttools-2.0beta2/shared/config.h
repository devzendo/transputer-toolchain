/* $Id: config.h,v 1.1.1.1 1995/12/22 12:25:10 sizif Exp $ */

/*
 * This file is part of TTOOLS package.
 * Copyright (c) 1995 Yury Shevchuk <sizif@botik.ru>
 */

#ifndef CONFIG_H
#define CONFIG_H

/* The type of expressions.  We use signed long, since transputer
   addresses are signed.  */
typedef long expr_const_t;

#define EXPR_CONST_MIN	LONG_MIN
#define EXPR_CONST_MAX	LONG_MAX
#define EXPR_CONST_FMT	"ld"

#define TARGET_LITTLE_ENDIAN
#undef TARGET_BIG_ENDIAN

/* Identifier of the default segment; this appears as .head,
   head@@start, head@@size */
#define DEFAULT_SEGMENT_IDENT "head"

/* Constant DATA elements smaller than this are converted into BLOCKs */
#define DEFAULT_BLOCK_THRESHOLD 32

#endif /* not CONFIG_H */
