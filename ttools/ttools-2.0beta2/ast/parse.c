
/*  A Bison parser, made from parse.y with Bison version GNU Bison version 1.22
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TOK_NAME	258
#define	TOK_STRING	259
#define	TOK_NUMBER	260
#define	TOK_DIGLAB	261
#define	TOK_DIGREF_B	262
#define	TOK_DIGREF_F	263
#define	TOK_CMD_DIRECT	264
#define	TOK_CMD_DIRECT_PCREL	265
#define	TOK_CMD_INDIR	266
#define	TOK_CMD_FPU	267
#define	TOK_BYTE	268
#define	TOK_HALF	269
#define	TOK_WORD	270
#define	TOK_ALIGN	271
#define	TOK_GLOBL	272
#define	TOK_COMM	273
#define	TOK_NEED	274
#define	TOK_SLOT	275
#define	TOK_DCOLON	276
#define	TOK_SEGMENT	277
#define	TOK_OROR	278
#define	TOK_ANDAND	279
#define	TOK_EQ	280
#define	TOK_NE	281
#define	TOK_LE	282
#define	TOK_GE	283
#define	TOK_LSH	284
#define	TOK_RSH	285
#define	TOP	286

#line 52 "parse.y"

#include "ast.h"
#include "y.tab.h"

/* The segment we are currently emitting to.  */
struct segment *curseg;

/* Nth element holds the expression for the last digital label N seen. */
static expr backlab[10];

/* Every time a forward reference is seen, we create an undefined name
   and put the pointer to that here.  When we encounter a diglab,
   we assign the current point to the corresponding name and zero
   the entry in this array.  */
static name forwlab[10];

/* Used in handling of .byte/.half/.word */
static int data_width;

/* Vector of stored .need directives to be handled at end of parsing */
struct deferred_needs {
    name name;
    name dep;
};
static struct deferred_needs *deferred_needs = NULL;
static int ndeferred_needs = 0;


static void do_pending_alignment (struct segment *seg);
static void drop_pending_alignment (struct segment *seg);
static void *check_defined (name np);
static void yyerror (char *errstr);


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		118
#define	YYFLAG		-32768
#define	YYNTBASE	54

#define YYTRANSLATE(x) ((unsigned)(x) <= 286 ? yytranslate[x] : 69)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    52,     2,     2,     2,    42,    29,     2,    50,
    51,    40,    38,    45,    39,    49,    41,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    24,    44,    32,
    48,    33,    23,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    46,     2,    47,    28,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    27,     2,    53,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    25,    26,    30,
    31,    34,    35,    36,    37,    43
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     4,     5,     8,    10,    12,    14,    16,    18,
    20,    23,    26,    29,    32,    35,    37,    39,    41,    44,
    49,    52,    55,    56,    60,    61,    65,    66,    70,    74,
    75,    78,    80,    84,    86,    88,    93,    98,   100,   104,
   106,   108,   110,   112,   114,   118,   122,   126,   130,   134,
   138,   142,   146,   150,   154,   158,   162,   166,   170,   174,
   178,   182,   186,   190,   193,   196,   199,   202
};

static const short yyrhs[] = {    55,
    56,     0,     0,     0,    56,    57,     0,    58,     0,    59,
     0,    60,     0,    67,     0,    44,     0,     1,     0,     3,
    24,     0,     3,    21,     0,     6,    24,     0,     9,    68,
     0,    10,    68,     0,    11,     0,    12,     0,    22,     0,
    17,     3,     0,    18,     3,    45,    68,     0,    19,     3,
     0,    20,    68,     0,     0,    13,    61,    65,     0,     0,
    14,    62,    65,     0,     0,    15,    63,    65,     0,    16,
    68,    64,     0,     0,    45,    68,     0,    66,     0,    65,
    45,    66,     0,    68,     0,    23,     0,    68,    46,    68,
    47,     0,    23,    46,    68,    47,     0,     4,     0,     3,
    48,    68,     0,     5,     0,     3,     0,    49,     0,     7,
     0,     8,     0,    50,    68,    51,     0,    68,    38,    68,
     0,    68,    39,    68,     0,    68,    29,    68,     0,    68,
    28,    68,     0,    68,    27,    68,     0,    68,    40,    68,
     0,    68,    41,    68,     0,    68,    42,    68,     0,    68,
    32,    68,     0,    68,    33,    68,     0,    68,    34,    68,
     0,    68,    35,    68,     0,    68,    30,    68,     0,    68,
    31,    68,     0,    68,    36,    68,     0,    68,    37,    68,
     0,    68,    25,    68,     0,    68,    26,    68,     0,    38,
    68,     0,    39,    68,     0,    52,    68,     0,    53,    68,
     0,    68,    23,    68,    24,    68,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    89,   124,   152,   153,   165,   166,   167,   168,   173,   174,
   178,   199,   209,   224,   231,   246,   254,   266,   290,   308,
   349,   368,   380,   382,   382,   390,   390,   398,   398,   424,
   429,   435,   436,   439,   448,   458,   466,   475,   488,   502,
   506,   510,   516,   520,   527,   528,   529,   530,   531,   532,
   533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
   543,   544,   545,   546,   547,   548,   549,   550
};

static const char * const yytname[] = {   "$","error","$illegal.","TOK_NAME",
"TOK_STRING","TOK_NUMBER","TOK_DIGLAB","TOK_DIGREF_B","TOK_DIGREF_F","TOK_CMD_DIRECT",
"TOK_CMD_DIRECT_PCREL","TOK_CMD_INDIR","TOK_CMD_FPU","TOK_BYTE","TOK_HALF","TOK_WORD",
"TOK_ALIGN","TOK_GLOBL","TOK_COMM","TOK_NEED","TOK_SLOT","TOK_DCOLON","TOK_SEGMENT",
"'?'","':'","TOK_OROR","TOK_ANDAND","'|'","'^'","'&'","TOK_EQ","TOK_NE","'<'",
"'>'","TOK_LE","TOK_GE","TOK_LSH","TOK_RSH","'+'","'-'","'*'","'/'","'%'","TOP",
"';'","','","'['","']'","'='","'.'","'('","')'","'!'","'~'","source","initialize",
"statements","statement","label","command","directive","@1","@2","@3","maybe_filler",
"datalist","datum","assignment","expr",""
};
#endif

static const short yyr1[] = {     0,
    54,    55,    56,    56,    57,    57,    57,    57,    57,    57,
    58,    58,    58,    59,    59,    59,    59,    60,    60,    60,
    60,    60,    61,    60,    62,    60,    63,    60,    60,    64,
    64,    65,    65,    66,    66,    66,    66,    66,    67,    68,
    68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
    68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
    68,    68,    68,    68,    68,    68,    68,    68
};

static const short yyr2[] = {     0,
     2,     0,     0,     2,     1,     1,     1,     1,     1,     1,
     2,     2,     2,     2,     2,     1,     1,     1,     2,     4,
     2,     2,     0,     3,     0,     3,     0,     3,     3,     0,
     2,     1,     3,     1,     1,     4,     4,     1,     3,     1,
     1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     2,     2,     2,     2,     5
};

static const short yydefact[] = {     2,
     3,     0,    10,     0,     0,     0,     0,    16,    17,    23,
    25,    27,     0,     0,     0,     0,     0,    18,     9,     4,
     5,     6,     7,     8,    12,    11,     0,    13,    41,    40,
    43,    44,     0,     0,    42,     0,     0,     0,    14,    15,
     0,     0,     0,    30,    19,     0,    21,    22,    39,    64,
    65,     0,    66,    67,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    38,    35,    24,    32,    34,    26,    28,
     0,    29,     0,    45,     0,    62,    63,    50,    49,    48,
    58,    59,    54,    55,    56,    57,    60,    61,    46,    47,
    51,    52,    53,     0,     0,     0,    31,    20,     0,     0,
    33,     0,    68,    37,    36,     0,     0,     0
};

static const short yydefgoto[] = {   116,
     1,     2,    20,    21,    22,    23,    41,    42,    43,    82,
    76,    77,    24,    78
};

static const short yypact[] = {-32768,
-32768,   127,-32768,   -19,   -18,    73,    73,-32768,-32768,-32768,
-32768,-32768,    73,    16,    17,    65,    73,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    73,-32768,-32768,-32768,
-32768,-32768,    73,    73,-32768,    73,    73,    73,   263,   263,
    66,    66,    66,   220,-32768,    27,-32768,   263,   263,-32768,
-32768,   125,-32768,-32768,    73,    73,    73,    73,    73,    73,
    73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
    73,    73,    73,-32768,    33,    37,-32768,   198,    37,    37,
    73,-32768,    73,-32768,   243,   280,     6,   295,   309,   322,
   333,   333,   -24,   -24,   -24,   -24,   -16,   -16,   -32,   -32,
-32768,-32768,-32768,    73,    66,    73,   263,   263,    73,   152,
-32768,   175,   263,-32768,-32768,    83,    84,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   -39,   -20,-32768,    -6
};


#define	YYLAST		375


static const short yytable[] = {    39,
    40,    25,    79,    80,    26,    28,    44,    71,    72,    73,
    48,    67,    68,    69,    70,    71,    72,    73,    45,    46,
    49,    69,    70,    71,    72,    73,    50,    51,    27,    52,
    53,    54,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,    47,    29,    74,
    30,    83,    31,    32,   107,    29,   108,    30,   104,    31,
    32,   105,   117,   118,   111,     0,     0,     0,    75,     0,
     0,     0,     0,     0,     0,     0,     0,   110,     0,   112,
     0,     0,   113,    33,    34,     0,     0,     0,     0,     0,
    33,    34,     0,     0,    35,    36,     0,    37,    38,     0,
     0,    35,    36,     0,    37,    38,    -1,     3,     0,     4,
     0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    55,    18,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,     0,     0,     0,
    19,     0,     0,     0,    55,    84,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,     0,     0,     0,    55,   114,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,     0,     0,     0,
    55,   115,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
     0,     0,    55,   106,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,     0,     0,    81,    55,   109,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    55,     0,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73
};

static const short yycheck[] = {     6,
     7,    21,    42,    43,    24,    24,    13,    40,    41,    42,
    17,    36,    37,    38,    39,    40,    41,    42,     3,     3,
    27,    38,    39,    40,    41,    42,    33,    34,    48,    36,
    37,    38,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,     3,     3,     4,
     5,    45,     7,     8,    81,     3,    83,     5,    46,     7,
     8,    45,     0,     0,   105,    -1,    -1,    -1,    23,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,   106,
    -1,    -1,   109,    38,    39,    -1,    -1,    -1,    -1,    -1,
    38,    39,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
    -1,    49,    50,    -1,    52,    53,     0,     1,    -1,     3,
    -1,    -1,     6,    -1,    -1,     9,    10,    11,    12,    13,
    14,    15,    16,    17,    18,    19,    20,    23,    22,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
    44,    -1,    -1,    -1,    23,    51,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    -1,    -1,    -1,    23,    47,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
    23,    47,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    -1,    -1,    23,    46,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    -1,    -1,    45,    23,    24,    25,    26,    27,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    23,    -1,    25,    26,    27,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    29,    30,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/lib/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */


#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#define YYLEX		yylex(&yylval, &yylloc)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 184 "/usr/lib/bison.simple"
int
yyparse()
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 89 "parse.y"
{
	    /*
	     * Tie ends at the end of parsing
	     */
	    int i;

	    /* line number would not be meaningful in the error()s
               below; turn it off */
	    error_report->line_number_ptr = NULL;

	    /* check whether all forward refs to digital labels have
               met their labels */
	    for (i=0; i <= 9; i++) {
		if (forwlab[i] != NULL) {
		    error ("hanging forward reference to digital label %d\n");
		    forwlab[i]->defined = 1;  /* do not catch it again below */
		}
	    }

	    /* complain if there are undefined name references */
	    table_walk (&general_names, check_defined);

	    /* Add deferred needs now that all names are defined */
	    for (i=0; i < ndeferred_needs; i++) {
		expr e = expr_name (deferred_needs[i].dep);

		expr_reduce (e);
		record_needs_name = deferred_needs[i].name;
		record_needs (e);
		EXPR_FREE (e);
	    }
	;
    break;}
case 2:
#line 124 "parse.y"
{
	    /*
	     * Initialization of data used in actions
	     */

	    /* We make default fragments noname, because default
	       fragments in different segments/files should not be
	       unified, and noname symbols provide exactly this
	       semantics. */
	    name deffrag = table_add_noname (&general_names);

	    /* Unlike default fragments, default segment is not
               noname: instances of the default segment in different
               files should be merged into a single segment during
               link phase. */
	    name segname = table_lookup (&segment_names, DEFAULT_SEGMENT_IDENT,
					 sizeof (DEFAULT_SEGMENT_IDENT)-1);

	    globalize_name (deffrag);
	    deffrag->fragment = 1;
	    deffrag->defined = 1;
	    curseg = add_segment (segname, deffrag);

	    memset (forwlab, 0, sizeof (forwlab));
	    memset (backlab, 0, sizeof (backlab));
	;
    break;}
case 4:
#line 153 "parse.y"
{
	    if (traceset & TRACE_POINT) {
		printf ("** POINT ");
		expr_print (stdout, curseg->point);
		printf ("\n");
	    }
	    if (traceset & TRACE_EXPR)
		expr_fsck ();
	;
    break;}
case 11:
#line 178 "parse.y"
{
	    if (yyvsp[-1].u.name->defined)
		error2 (yyvsp[-1].file, yyvsp[-1].line,
			"'%s' already defined\n", yyvsp[-1].u.name->ident);
	    yyvsp[-1].u.name->defined = 1;
	    if (yyvsp[-1].u.name->global) {
		/* public label -- start new fragment */
		yyvsp[-1].u.name->fragment = 1;
		yyvsp[-1].u.name->align = curseg->pending_alignment;
		drop_pending_alignment (curseg);
		add_fragment (curseg, yyvsp[-1].u.name);
	    }
	    else {
		yyvsp[-1].u.name->align = curseg->pending_alignment;
		if (curseg->pending_alignment > 1)
		    do_pending_alignment (curseg);
		/* local label; assign it the current point value */
		name_assign_value (yyvsp[-1].u.name, curseg->point);
	    }
	;
    break;}
case 12:
#line 199 "parse.y"
{
	    if (yyvsp[-1].u.name->defined)
		error2 (yyvsp[-1].file, yyvsp[-1].line,
			"'%s' already defined\n", yyvsp[-1].u.name->ident);
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    yyvsp[-1].u.name->defined = 1;
	    name_assign_value (yyvsp[-1].u.name, curseg->point);
	;
    break;}
case 13:
#line 209 "parse.y"
{	
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    if (backlab[yyvsp[-1].u.num])
		EXPR_FREE (backlab[yyvsp[-1].u.num]);
	    backlab[yyvsp[-1].u.num] = expr_share (curseg->point);
	    if (forwlab[yyvsp[-1].u.num] != NULL) {
		name_assign_value (forwlab[yyvsp[-1].u.num], curseg->point);
		forwlab[yyvsp[-1].u.num]->defined = 1;
		forwlab[yyvsp[-1].u.num] = NULL;
	    }
	;
    break;}
case 14:
#line 224 "parse.y"
{
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    emit_cmd (curseg, yyvsp[-1].u.num, yyvsp[0].u.expr);
	    EXPR_FREE (yyvsp[0].u.expr);
	;
    break;}
case 15:
#line 231 "parse.y"
{
	    name np = table_add_noname (&general_names);
	    expr temp;

	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);

	    temp = expr_binop_owned (EXPR_MINUS, yyvsp[0].u.expr, expr_name (np));
	    emit_cmd (curseg, yyvsp[-1].u.num, temp);
	    EXPR_FREE (temp);

	    name_assign_value (np, curseg->point);
	    np->defined = 1;
	;
    break;}
case 16:
#line 246 "parse.y"
{
	    expr temp;
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    emit_cmd (curseg, OPCODE_OPR, temp = expr_const (yyvsp[0].u.num));
	    EXPR_FREE (temp);
	;
    break;}
case 17:
#line 254 "parse.y"
{
	    expr temp;
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    emit_cmd (curseg, OPCODE_LDC, temp = expr_const (yyvsp[0].u.num));
	    EXPR_FREE (temp);
	    emit_cmd (curseg, OPCODE_OPR, temp = expr_const (OPCODE_FPENTRY));
	    EXPR_FREE (temp);
	;
    break;}
case 18:
#line 266 "parse.y"
{
	    if (yyvsp[0].u.name->val)
		curseg = (segment) yyvsp[0].u.name->val;
	    else {
		name deffrag = table_add_noname (&general_names);

		globalize_name (deffrag);
		deffrag->fragment = 1;
		deffrag->defined = 1;

		curseg = add_segment (yyvsp[0].u.name, deffrag);

		/* For .bss, issue the second default fragment.  See
                   the comment on the .comm handling code. */
		if (strcmp (yyvsp[0].u.name->ident, "bss") == 0) {
		    deffrag = table_add_noname (&general_names);
		    globalize_name (deffrag);
		    deffrag->fragment = 1;
		    deffrag->defined = 1;
		    add_fragment (curseg, deffrag);
		}
	    }
	;
    break;}
case 19:
#line 290 "parse.y"
{
	    if (! yyvsp[0].u.name->global && yyvsp[0].u.name->defined)
		error2 (yyvsp[0].file, yyvsp[0].line,
			"'%s' already used as non-global\n", yyvsp[0].u.name->ident);
	    globalize_name (yyvsp[0].u.name);
	;
    break;}
case 20:
#line 308 "parse.y"
{
	    expr temp;
	    segment segbss;
	    name segname = table_lookup (&segment_names, "bss",
					 sizeof ("bss")-1);
	    if (segname->val)
		segbss = (segment) segname->val;
	    else {
		name deffrag = table_add_noname (&general_names);

		globalize_name (deffrag);
		deffrag->fragment = 1;
		deffrag->defined = 1;

		segbss = add_segment (segname, deffrag);

		/* add 2nd default fragment, .bss-specific */
		deffrag = table_add_noname (&general_names);
		globalize_name (deffrag);
		deffrag->fragment = 1;
		deffrag->defined = 1;
		add_fragment (segbss, deffrag);
	    }

	    if (yyvsp[-2].u.name->defined)
		error2 (yyvsp[-2].file, yyvsp[-2].line,
			"'%s' already defined\n", yyvsp[-2].u.name->ident);
	    globalize_name (yyvsp[-2].u.name);
	    yyvsp[-2].u.name->fragment = 1;
	    yyvsp[-2].u.name->defined = 1;
	    yyvsp[-2].u.name->common = 1;
	    yyvsp[-2].u.name->align = curseg->pending_alignment;  /* curseg, not segbss. */
	    drop_pending_alignment (curseg);

	    add_fragment (segbss, yyvsp[-2].u.name);
	    emit_data (segbss, 1, temp = expr_const (0), yyvsp[0].u.expr);
	    EXPR_FREE (temp);
	    swap_last_fragments (segbss);
	    EXPR_FREE (yyvsp[0].u.expr);
	;
    break;}
case 21:
#line 349 "parse.y"
{
	    if (yyvsp[0].u.name->global)
		add_need (curseg->fragments[curseg->nfragments-1].name, yyvsp[0].u.name);
	    else {
		/* For a nonglobal name, we should add needs for all
                   global names this one is defined through.  However,
                   we cannot do this right away, since the name might
                   not be defined yet.  So we defer actual need-adding
                   until the end of parsing */
		if (VECTOR_FULL (64, ndeferred_needs))
		    VECTOR_GROW (64, ndeferred_needs,
				 struct deferred_needs, deferred_needs);
		deferred_needs[ndeferred_needs].name
		    = curseg->fragments[curseg->nfragments-1].name;
		deferred_needs[ndeferred_needs].dep = yyvsp[0].u.name;
		ndeferred_needs++;
	    }
	;
    break;}
case 22:
#line 368 "parse.y"
{
	    if (! EXPR_ISCONST (yyvsp[0].u.expr)) {
		error2 (yyvsp[0].file, yyvsp[0].line,
			"%s should be a constant expression\n",
			"the argument for .slot");
		EXPR_FREE (yyvsp[0].u.expr);
		break;
	    }
	    curseg->slot = yyvsp[0].u.expr->u.constval;
	    EXPR_FREE (yyvsp[0].u.expr);
	;
    break;}
case 23:
#line 380 "parse.y"
{data_width = 1;;
    break;}
case 25:
#line 382 "parse.y"
{
	    data_width = 2;
	    if (curseg->pending_alignment < 2
		&& expr_check_alignment (curseg->point, 2) >= 2)
		warning2 (yyvsp[0].file, yyvsp[0].line,
			"data don't seem to be aligned properly\n");
	  ;
    break;}
case 27:
#line 390 "parse.y"
{
	    data_width = 4;
	    if (curseg->pending_alignment < 4
		&& expr_check_alignment (curseg->point, 4) >= 4)
		warning2 (yyvsp[0].file, yyvsp[0].line,
			"data don't seem to be aligned properly\n");
	  ;
    break;}
case 29:
#line 398 "parse.y"
{
	    if (! EXPR_ISCONST (yyvsp[-1].u.expr)) {
		error2 (yyvsp[-1].file, yyvsp[-1].line,
			"%s should be a constant expression\n",
			"alignment factor");
		EXPR_FREE (yyvsp[-1].u.expr);
		EXPR_FREE (yyvsp[0].u.expr);
		break;
	    }
	    if (yyvsp[-1].u.expr->u.constval < 1) {
		warning2 (yyvsp[-1].file, yyvsp[-1].line,
			  "alignment of %d is meaningless\n", yyvsp[-1].u.expr->u.constval);
		break;
	    }
	    /* Semantics of two succesive .align's is that the first
               one is emitted in the current fragment, and the second
               one becomes the pending alignment. */
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    curseg->pending_alignment = yyvsp[-1].u.expr->u.constval;
	    curseg->pending_alignment_filler = yyvsp[0].u.expr;
	    EXPR_FREE (yyvsp[-1].u.expr);
	;
    break;}
case 30:
#line 424 "parse.y"
{
	    yyval.u.expr = expr_const (strcmp (curseg->name->ident, "text") == 0
			     ? OPCODE_PFIX
			     : 0);
	;
    break;}
case 31:
#line 429 "parse.y"
{
	    yyval.u.expr = yyvsp[0].u.expr;
	;
    break;}
case 34:
#line 439 "parse.y"
{
	    expr temp;
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    emit_data (curseg, data_width, yyvsp[0].u.expr, temp = expr_const (1));
	    EXPR_FREE (temp);
	    EXPR_FREE (yyvsp[0].u.expr);
	;
    break;}
case 35:
#line 448 "parse.y"
{
	    expr count = expr_const (1);
	    expr data = expr_const (0);
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    emit_data (curseg, data_width, data, count);
	    EXPR_FREE (data);
	    EXPR_FREE (count);
	;
    break;}
case 36:
#line 458 "parse.y"
{
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    emit_data (curseg, data_width, yyvsp[-3].u.expr, yyvsp[-1].u.expr);
	    EXPR_FREE (yyvsp[-3].u.expr);
	    EXPR_FREE (yyvsp[-1].u.expr);
	;
    break;}
case 37:
#line 466 "parse.y"
{
	    expr data = expr_const (0);
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    emit_data (curseg, data_width, data, yyvsp[-1].u.expr);
	    EXPR_FREE (data);
	    EXPR_FREE (yyvsp[-1].u.expr);
	;
    break;}
case 38:
#line 475 "parse.y"
{
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    if (data_width != 1) {
		error2 (yyvsp[0].file, yyvsp[0].line,
		  "strings are only allowed with .byte\n");
		break;
	    }
	    emit_block (curseg, yyvsp[0].u.str.ptr, yyvsp[0].u.str.len);
	;
    break;}
case 39:
#line 488 "parse.y"
{
	    if (yyvsp[-2].u.name->defined) {
		error2 (yyvsp[-2].file, yyvsp[-2].line,
			"'%s' already defined\n", yyvsp[-2].u.name->ident);
		EXPR_FREE (yyvsp[0].u.expr);
		break;
	    }
	    yyvsp[-2].u.name->defined = 1;
	    name_assign_value (yyvsp[-2].u.name, yyvsp[0].u.expr);
	    EXPR_FREE (yyvsp[0].u.expr);
	;
    break;}
case 40:
#line 502 "parse.y"
{
	    yyval.u.expr = expr_const (yyvsp[0].u.lnum);
	;
    break;}
case 41:
#line 506 "parse.y"
{
	    yyval.u.expr = expr_name (yyvsp[0].u.name);
	;
    break;}
case 42:
#line 510 "parse.y"
{
	    if (curseg->pending_alignment > 1)
		do_pending_alignment (curseg);
	    yyval.u.expr = expr_share (curseg->point);
	;
    break;}
case 43:
#line 516 "parse.y"
{
	    yyval.u.expr = expr_share (backlab[yyvsp[0].u.num]);
	;
    break;}
case 44:
#line 520 "parse.y"
{
	    if (forwlab[yyvsp[0].u.num] == NULL) {
		forwlab[yyvsp[0].u.num] = table_add_noname (&general_names);
	    }
	    yyval.u.expr = expr_name (forwlab[yyvsp[0].u.num]);
	;
    break;}
case 45:
#line 527 "parse.y"
{ yyval.u.expr = yyvsp[-1].u.expr; ;
    break;}
case 46:
#line 528 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_PLUS, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 47:
#line 529 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_MINUS, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 48:
#line 530 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_AND, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 49:
#line 531 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_XOR, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 50:
#line 532 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_OR, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 51:
#line 533 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_MUL, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 52:
#line 534 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_DIV, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 53:
#line 535 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_REM, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 54:
#line 536 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_LT, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 55:
#line 537 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_GT, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 56:
#line 538 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_LE, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 57:
#line 539 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_GE, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 58:
#line 540 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_EQ, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 59:
#line 541 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_NE, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 60:
#line 542 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_LSH, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 61:
#line 543 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_RSH, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 62:
#line 544 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_OROR, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 63:
#line 545 "parse.y"
{ yyval.u.expr = expr_binop_owned (EXPR_ANDAND, yyvsp[-2].u.expr, yyvsp[0].u.expr); ;
    break;}
case 64:
#line 546 "parse.y"
{ yyval.u.expr = yyvsp[0].u.expr; ;
    break;}
case 65:
#line 547 "parse.y"
{ yyval.u.expr = expr_unop_owned (EXPR_NEG, yyvsp[0].u.expr); ;
    break;}
case 66:
#line 548 "parse.y"
{ yyval.u.expr = expr_unop_owned (EXPR_NOT, yyvsp[0].u.expr); ;
    break;}
case 67:
#line 549 "parse.y"
{ yyval.u.expr = expr_unop_owned (EXPR_COMPL, yyvsp[0].u.expr); ;
    break;}
case 68:
#line 550 "parse.y"
{
	    yyval.u.expr = expr_questop (yyvsp[-4].u.expr, yyvsp[-2].u.expr, yyvsp[0].u.expr);
	    EXPR_FREE (yyvsp[-4].u.expr);
	    EXPR_FREE (yyvsp[-2].u.expr);
	    EXPR_FREE (yyvsp[0].u.expr);
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 465 "/usr/lib/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 557 "parse.y"


static void
yyerror (char *errstr)
{
       error ("%s\n", errstr);
}

static void
do_pending_alignment (struct segment *seg)
{

    if (emit_align (seg, seg->pending_alignment, seg->pending_alignment_filler)) {
	/* emit_align has actually emitted something; let's make the
           point look aligned for expr_check_alignment to be able to
           do its job  */
	name np = table_add_noname (&general_names);

	name_assign_value (np, seg->point);
	np->align = seg->pending_alignment;
	np->defined = 1;
	EXPR_FREE (seg->point);
	seg->point = expr_name (np);
    }

    drop_pending_alignment (seg);
}

static void
drop_pending_alignment (struct segment *seg)
{
    seg->pending_alignment = 1;
    if (seg->pending_alignment_filler) {
	EXPR_FREE (seg->pending_alignment_filler);
	seg->pending_alignment_filler = NULL;
    }
}

/* Issue an error message if name is not defined.  Used over the whole
   namespace once the source parsing is complete. */

static void *
check_defined (name np)
{
    if (!np->defined && !np->global)
	error ("`%s' undefined\n", np->ident);
    return NULL;
}

/* Print a token in readable form for debugging purposes */

void
print_token (FILE *stream, int token, YYSTYPE *tp)
{
    fprintf (stream, "** LEX %s:%d ", tp->file, tp->line);
    switch (token) {
    case TOK_NAME:
	fprintf (stream, "NAME %s\n", tp->u.name->ident);
	return;
    case TOK_STRING:
	{
	    int i;
	    fprintf (stream, "STRING \"");
	    for (i=0; i < tp->u.str.len; i++)
		fprintf (stream, isprint (tp->u.str.ptr[i])? "%c": "\\%03o",
			 tp->u.str.ptr[i]);
	    fprintf (stream, "\"\n");
	    return;
	}
    case TOK_NUMBER:
	fprintf (stream, "NUMBER %ld (0x%lx)\n", tp->u.lnum, tp->u.lnum);
	return;
    case TOK_DIGLAB:
	fprintf (stream, "DIGLAB %d\n", tp->u.num);
	return;
    case TOK_DIGREF_B:
	fprintf (stream, "DIGREF_B %d\n", tp->u.num);
	return;
    case TOK_DIGREF_F:
	fprintf (stream, "DIGREF_F %d\n", tp->u.num);
	return;
    case TOK_CMD_DIRECT:
	fprintf (stream, "CMD_DIRECT 0x%x\n", tp->u.num);
	return;
    case TOK_CMD_DIRECT_PCREL:
	fprintf (stream, "CMD_DIRECT_PCREL 0x%x\n", tp->u.num);
	return;
    case TOK_CMD_INDIR:
	fprintf (stream, "CMD_INDIR 0x%x\n", tp->u.num);
	return;
    case TOK_CMD_FPU:
	fprintf (stream, "CMD_FPU 0x%x\n", tp->u.num);
	return;
    case TOK_BYTE:
	fprintf (stream, "BYTE\n");
	return;
    case TOK_HALF:
	fprintf (stream, "HALF\n");
	return;
    case TOK_WORD:
	fprintf (stream, "WORD\n");
	return;
    case TOK_ALIGN:
	fprintf (stream, "ALIGN\n");
	return;
    case TOK_GLOBL:
	fprintf (stream, "GLOBL\n");
	return;
    case TOK_NEED:
	fprintf (stream, "NEED\n");
	return;
    case TOK_SLOT:
	fprintf (stream, "SLOT\n");
	return;
    case TOK_DCOLON:
	fprintf (stream, "DCOLON\n");
	return;
    case TOK_SEGMENT:
	fprintf (stream, "SEGMENT %s\n", tp->u.name->ident);
	return;
    case TOK_OROR:
	fprintf (stream, "OROR\n");
	return;
    case TOK_ANDAND:
	fprintf (stream, "ANDAND\n");
	return;
    case TOK_EQ:
	fprintf (stream, "EQ\n");
	return;
    case TOK_NE:
	fprintf (stream, "NE\n");
	return;
    case TOK_LE:
	fprintf (stream, "LE\n");
	return;
    case TOK_GE:
	fprintf (stream, "GE\n");
	return;
    case TOK_LSH:
	fprintf (stream, "LSH\n");
	return;
    case TOK_RSH:
	fprintf (stream, "RSH\n");
	return;
    default:
	if (token >= ' ' && token < 0x7f)
	    fprintf (stream, "'%c'\n", token);
	else
	    abort ();
	return;
    }
}

void
expr_fsck ()
{
#ifdef EXPR_DEBUG
    expr e;
    int i;

    for (e = expr_list->forw; e != expr_list; e = e->forw)
	e->refcount = 0;

    pass_count_refs ();
    table_walk (&general_names, name_count_refs);
    for (i=0; i < nsegments; i++) {
	if (segments[i]->point)
	    expr_count_refs (segments[i]->point);
	if (segments[i]->pending_alignment_filler)
	    expr_count_refs (segments[i]->pending_alignment_filler);
    }
    for (i=0; i <= 9; i++) {
	if (backlab[i])
	    expr_count_refs (backlab[i]);
    }

    for (e = expr_list->forw; e != expr_list; e = e->forw) {
	if (e->refcount != e->nrefs) {
	    printf ("** EXPR %p nrefs %u -- counted %u\n",
		    e, e->nrefs, e->refcount);
	}
	else if (e->refcount == 0) {
	    printf ("** EXPR %p unreferenced\n", e);
	}
    }
#endif
}
