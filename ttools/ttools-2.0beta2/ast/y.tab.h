/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_NAME = 258,
    TOK_STRING = 259,
    TOK_NUMBER = 260,
    TOK_DIGLAB = 261,
    TOK_DIGREF_B = 262,
    TOK_DIGREF_F = 263,
    TOK_CMD_DIRECT = 264,
    TOK_CMD_DIRECT_PCREL = 265,
    TOK_CMD_INDIR = 266,
    TOK_CMD_FPU = 267,
    TOK_BYTE = 268,
    TOK_HALF = 269,
    TOK_WORD = 270,
    TOK_ALIGN = 271,
    TOK_GLOBL = 272,
    TOK_COMM = 273,
    TOK_NEED = 274,
    TOK_SLOT = 275,
    TOK_DCOLON = 276,
    TOK_SEGMENT = 277,
    TOK_OROR = 278,
    TOK_ANDAND = 279,
    TOK_EQ = 280,
    TOK_NE = 281,
    TOK_LE = 282,
    TOK_GE = 283,
    TOK_LSH = 284,
    TOK_RSH = 285,
    TOP = 286
  };
#endif
/* Tokens.  */
#define TOK_NAME 258
#define TOK_STRING 259
#define TOK_NUMBER 260
#define TOK_DIGLAB 261
#define TOK_DIGREF_B 262
#define TOK_DIGREF_F 263
#define TOK_CMD_DIRECT 264
#define TOK_CMD_DIRECT_PCREL 265
#define TOK_CMD_INDIR 266
#define TOK_CMD_FPU 267
#define TOK_BYTE 268
#define TOK_HALF 269
#define TOK_WORD 270
#define TOK_ALIGN 271
#define TOK_GLOBL 272
#define TOK_COMM 273
#define TOK_NEED 274
#define TOK_SLOT 275
#define TOK_DCOLON 276
#define TOK_SEGMENT 277
#define TOK_OROR 278
#define TOK_ANDAND 279
#define TOK_EQ 280
#define TOK_NE 281
#define TOK_LE 282
#define TOK_GE 283
#define TOK_LSH 284
#define TOK_RSH 285
#define TOP 286

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
