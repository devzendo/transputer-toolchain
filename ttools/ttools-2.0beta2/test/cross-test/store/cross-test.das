0x00000000: $.       24 f2                   mint
0x00000002: $ P      24 20 50                ldnlp 1024 (0x400)
0x00000005: #.       23 fc                   gajw
0x00000007: `.       60 be                   ajw -2
0x00000009: $.       24 f2                   mint
0x0000000b: !.       21 f8                   sthf
0x0000000d: $.       24 f2                   mint
0x0000000f: !.       21 fc                   stlf
0x00000011: K        4b                      ldc 11 (0xb)
0x00000012: .        d1                      stl 1
0x00000013: $.       24 f2                   mint
0x00000015: q        71                      ldl 1
0x00000016: $.       24 f2                   mint
0x00000018: .        fa                      wsub
0x00000019: `.       60 ef                   stnl -1
0x0000001b: .        10                      ldlp 0
0x0000001c: L        4c                      ldc 12 (0xc)
0x0000001d: ".       22 f1                   lend
0x0000001f: ".       22 f9                   testerr
0x00000021: %.       25 f7                   clrhalterr
0x00000023: @        40                      ldc 0
0x00000024: %.       25 f4                   sttimer
0x00000026: .        95                      call 0x0000002c
0x00000027: !.       21 f5                   stopp
0x00000029: .        00                      j 0x0000002a
0x0000002a: .        00                      j 0x0000002b
0x0000002b: .        00                      j 0x0000002c
0x0000002c: a.       61 be                   ajw -18 (0xffffffee)
0x0000002e: "#.      22 23 95                call 0x00000266
0x00000031: !,.      21 2c 99                call 0x000001fd
0x00000034: .        d2                      stl 2
0x00000035: !,.      21 2c 95                call 0x000001fd
0x00000038: .        d3                      stl 3
0x00000039: !,.      21 2c 91                call 0x000001fd
0x0000003c: .        d4                      stl 4
0x0000003d: !+.      21 2b 9d                call 0x000001fd
0x00000040: .        d5                      stl 5
0x00000041: !,.      21 2c 9e                call 0x00000212
0x00000044: H        48                      ldc 8
0x00000045: *.       2a fb                   fpentry
0x00000047: .        16                      ldlp 6
0x00000048: (.       28 f8                   fpstnlsn
0x0000004a: !,.      21 2c 95                call 0x00000212
0x0000004d: H        48                      ldc 8
0x0000004e: *.       2a fb                   fpentry
0x00000050: .        17                      ldlp 7
0x00000051: (.       28 f8                   fpstnlsn
0x00000053: !+.      21 2b 9c                call 0x00000212
0x00000056: .        18                      ldlp 8
0x00000057: (.       28 f4                   fpstnldb
0x00000059: !+.      21 2b 96                call 0x00000212
0x0000005c: .        1a                      ldlp 10
0x0000005d: (.       28 f4                   fpstnldb
0x0000005f: s        73                      ldl 3
0x00000060: r        72                      ldl 2
0x00000061: .        f8                      prod
0x00000062: !).      21 29 94                call 0x000001f9
0x00000065: r        72                      ldl 2
0x00000066: s        73                      ldl 3
0x00000067: ".       22 fc                   div
0x00000069: !(.      21 28 9d                call 0x000001f9
0x0000006c: r        72                      ldl 2
0x0000006d: s        73                      ldl 3
0x0000006e: !.       21 ff                   rem
0x00000070: !(.      21 28 96                call 0x000001f9
0x00000073: @        40                      ldc 0
0x00000074: t        74                      ldl 4
0x00000075: u        75                      ldl 5
0x00000076: !.       21 fa                   ldiv
0x00000078: !'.      21 27 9e                call 0x000001f9
0x0000007b: @        40                      ldc 0
0x0000007c: t        74                      ldl 4
0x0000007d: u        75                      ldl 5
0x0000007e: !.       21 fa                   ldiv
0x00000080: .        f0                      rev
0x00000081: !'.      21 27 95                call 0x000001f9
0x00000084: r        72                      ldl 2
0x00000085: !.       21 fd                   xdble
0x00000087: s        73                      ldl 3
0x00000088: #.       23 f5                   lshr
0x0000008a: !&.      21 26 9c                call 0x000001f9
0x0000008d: r        72                      ldl 2
0x0000008e: s        73                      ldl 3
0x0000008f: $.       24 f1                   shl
0x00000091: !&.      21 26 95                call 0x000001f9
0x00000094: t        74                      ldl 4
0x00000095: u        75                      ldl 5
0x00000096: $.       24 f0                   shr
0x00000098: !%.      21 25 9e                call 0x000001f9
0x0000009b: t        74                      ldl 4
0x0000009c: u        75                      ldl 5
0x0000009d: $.       24 f1                   shl
0x0000009f: !%.      21 25 97                call 0x000001f9
0x000000a2: .        18                      ldlp 8
0x000000a3: (.       28 fa                   fpldnldb
0x000000a5: .        1a                      ldlp 10
0x000000a6: (.       28 fa                   fpldnldb
0x000000a8: (.       28 f7                   fpadd
0x000000aa: .        10                      ldlp 0
0x000000ab: (.       28 f4                   fpstnldb
0x000000ad: q        71                      ldl 1
0x000000ae: p        70                      ldl 0
0x000000af: !$.      21 24 99                call 0x000001fb
0x000000b2: .        18                      ldlp 8
0x000000b3: (.       28 fa                   fpldnldb
0x000000b5: .        1a                      ldlp 10
0x000000b6: (.       28 fa                   fpldnldb
0x000000b8: (.       28 f9                   fpsub
0x000000ba: .        10                      ldlp 0
0x000000bb: (.       28 f4                   fpstnldb
0x000000bd: q        71                      ldl 1
0x000000be: p        70                      ldl 0
0x000000bf: !#.      21 23 99                call 0x000001fb
0x000000c2: .        18                      ldlp 8
0x000000c3: (.       28 fa                   fpldnldb
0x000000c5: .        1a                      ldlp 10
0x000000c6: (.       28 fa                   fpldnldb
0x000000c8: (.       28 fb                   fpmul
0x000000ca: .        10                      ldlp 0
0x000000cb: (.       28 f4                   fpstnldb
0x000000cd: q        71                      ldl 1
0x000000ce: p        70                      ldl 0
0x000000cf: !".      21 22 99                call 0x000001fb
0x000000d2: .        18                      ldlp 8
0x000000d3: (.       28 fa                   fpldnldb
0x000000d5: .        1a                      ldlp 10
0x000000d6: (.       28 fa                   fpldnldb
0x000000d8: (.       28 fc                   fpdiv
0x000000da: .        10                      ldlp 0
0x000000db: (.       28 f4                   fpstnldb
0x000000dd: q        71                      ldl 1
0x000000de: p        70                      ldl 0
0x000000df: !!.      21 21 99                call 0x000001fb
0x000000e2: *.       2a f0                   fpldzerodb
0x000000e4: .        18                      ldlp 8
0x000000e5: (.       28 fa                   fpldnldb
0x000000e7: (.       28 f9                   fpsub
0x000000e9: .        10                      ldlp 0
0x000000ea: (.       28 f4                   fpstnldb
0x000000ec: q        71                      ldl 1
0x000000ed: p        70                      ldl 0
0x000000ee: ! .      21 20 9a                call 0x000001fb
0x000000f1: .        16                      ldlp 6
0x000000f2: (.       28 fe                   fpldnlsn
0x000000f4: .        17                      ldlp 7
0x000000f5: (.       28 fe                   fpldnlsn
0x000000f7: (.       28 f7                   fpadd
0x000000f9: G        47                      ldc 7
0x000000fa: *.       2a fb                   fpentry
0x000000fc: .        10                      ldlp 0
0x000000fd: (.       28 f4                   fpstnldb
0x000000ff: q        71                      ldl 1
0x00000100: p        70                      ldl 0
0x00000101: /.       2f 98                   call 0x000001fb
0x00000103: .        16                      ldlp 6
0x00000104: (.       28 fe                   fpldnlsn
0x00000106: .        17                      ldlp 7
0x00000107: (.       28 fe                   fpldnlsn
0x00000109: (.       28 f9                   fpsub
0x0000010b: G        47                      ldc 7
0x0000010c: *.       2a fb                   fpentry
0x0000010e: .        10                      ldlp 0
0x0000010f: (.       28 f4                   fpstnldb
0x00000111: q        71                      ldl 1
0x00000112: p        70                      ldl 0
0x00000113: ..       2e 96                   call 0x000001fb
0x00000115: .        16                      ldlp 6
0x00000116: (.       28 fe                   fpldnlsn
0x00000118: .        17                      ldlp 7
0x00000119: (.       28 fe                   fpldnlsn
0x0000011b: (.       28 fb                   fpmul
0x0000011d: G        47                      ldc 7
0x0000011e: *.       2a fb                   fpentry
0x00000120: .        10                      ldlp 0
0x00000121: (.       28 f4                   fpstnldb
0x00000123: q        71                      ldl 1
0x00000124: p        70                      ldl 0
0x00000125: -.       2d 94                   call 0x000001fb
0x00000127: .        16                      ldlp 6
0x00000128: (.       28 fe                   fpldnlsn
0x0000012a: .        17                      ldlp 7
0x0000012b: (.       28 fe                   fpldnlsn
0x0000012d: (.       28 fc                   fpdiv
0x0000012f: G        47                      ldc 7
0x00000130: *.       2a fb                   fpentry
0x00000132: .        10                      ldlp 0
0x00000133: (.       28 f4                   fpstnldb
0x00000135: q        71                      ldl 1
0x00000136: p        70                      ldl 0
0x00000137: ,.       2c 92                   call 0x000001fb
0x00000139: ).       29 ff                   fpldzerosn
0x0000013b: .        16                      ldlp 6
0x0000013c: (.       28 fe                   fpldnlsn
0x0000013e: (.       28 f9                   fpsub
0x00000140: G        47                      ldc 7
0x00000141: *.       2a fb                   fpentry
0x00000143: .        10                      ldlp 0
0x00000144: (.       28 f4                   fpstnldb
0x00000146: q        71                      ldl 1
0x00000147: p        70                      ldl 0
0x00000148: +.       2b 91                   call 0x000001fb
0x0000014a: .        18                      ldlp 8
0x0000014b: (.       28 fa                   fpldnldb
0x0000014d: F        46                      ldc 6
0x0000014e: *.       2a fb                   fpentry
0x00000150: *.       2a f1                   fpint
0x00000152: .        10                      ldlp 0
0x00000153: ).       29 fe                   fpstnli32
0x00000155: p        70                      ldl 0
0x00000156: *.       2a 91                   call 0x000001f9
0x00000158: .        16                      ldlp 6
0x00000159: (.       28 fe                   fpldnlsn
0x0000015b: F        46                      ldc 6
0x0000015c: *.       2a fb                   fpentry
0x0000015e: *.       2a f1                   fpint
0x00000160: .        10                      ldlp 0
0x00000161: ).       29 fe                   fpstnli32
0x00000163: p        70                      ldl 0
0x00000164: ).       29 93                   call 0x000001f9
0x00000166: r        72                      ldl 2
0x00000167: .        d0                      stl 0
0x00000168: .        10                      ldlp 0
0x00000169: ).       29 f8                   fpi32tor64
0x0000016b: .        10                      ldlp 0
0x0000016c: (.       28 f4                   fpstnldb
0x0000016e: q        71                      ldl 1
0x0000016f: p        70                      ldl 0
0x00000170: (.       28 99                   call 0x000001fb
0x00000172: r        72                      ldl 2
0x00000173: .        d0                      stl 0
0x00000174: .        10                      ldlp 0
0x00000175: ).       29 f6                   fpi32tor32
0x00000177: G        47                      ldc 7
0x00000178: *.       2a fb                   fpentry
0x0000017a: .        10                      ldlp 0
0x0000017b: (.       28 f4                   fpstnldb
0x0000017d: q        71                      ldl 1
0x0000017e: p        70                      ldl 0
0x0000017f: '.       27 9a                   call 0x000001fb
0x00000181: .        18                      ldlp 8
0x00000182: (.       28 fa                   fpldnldb
0x00000184: H        48                      ldc 8
0x00000185: *.       2a fb                   fpentry
0x00000187: G        47                      ldc 7
0x00000188: *.       2a fb                   fpentry
0x0000018a: .        10                      ldlp 0
0x0000018b: (.       28 f4                   fpstnldb
0x0000018d: q        71                      ldl 1
0x0000018e: p        70                      ldl 0
0x0000018f: &.       26 9a                   call 0x000001fb
0x00000191: .        18                      ldlp 8
0x00000192: (.       28 fa                   fpldnldb
0x00000194: .        1a                      ldlp 10
0x00000195: (.       28 fa                   fpldnldb
0x00000197: ).       29 f5                   fpeq
0x00000199: .        dc                      stl 12 (0xc)
0x0000019a: |        7c                      ldl 12 (0xc)
0x0000019b: %.       25 9c                   call 0x000001f9
0x0000019d: .        1a                      ldlp 10
0x0000019e: (.       28 fa                   fpldnldb
0x000001a0: .        18                      ldlp 8
0x000001a1: (.       28 fa                   fpldnldb
0x000001a3: ).       29 f4                   fpgt
0x000001a5: .        dd                      stl 13 (0xd)
0x000001a6: }        7d                      ldl 13 (0xd)
0x000001a7: %.       25 90                   call 0x000001f9
0x000001a9: .        18                      ldlp 8
0x000001aa: (.       28 fa                   fpldnldb
0x000001ac: .        1a                      ldlp 10
0x000001ad: (.       28 fa                   fpldnldb
0x000001af: ).       29 f4                   fpgt
0x000001b1: .        de                      stl 14 (0xe)
0x000001b2: ~        7e                      ldl 14 (0xe)
0x000001b3: $.       24 94                   call 0x000001f9
0x000001b5: |        7c                      ldl 12 (0xc)
0x000001b6: .        c0                      eqc 0
0x000001b7: $.       24 90                   call 0x000001f9
0x000001b9: ~        7e                      ldl 14 (0xe)
0x000001ba: .        c0                      eqc 0
0x000001bb: #.       23 9c                   call 0x000001f9
0x000001bd: }        7d                      ldl 13 (0xd)
0x000001be: .        c0                      eqc 0
0x000001bf: #.       23 98                   call 0x000001f9
0x000001c1: .        16                      ldlp 6
0x000001c2: (.       28 fe                   fpldnlsn
0x000001c4: .        17                      ldlp 7
0x000001c5: (.       28 fe                   fpldnlsn
0x000001c7: ).       29 f5                   fpeq
0x000001c9: .        df                      stl 15 (0xf)
0x000001ca: .        7f                      ldl 15 (0xf)
0x000001cb: ".       22 9c                   call 0x000001f9
0x000001cd: .        17                      ldlp 7
0x000001ce: (.       28 fe                   fpldnlsn
0x000001d0: .        16                      ldlp 6
0x000001d1: (.       28 fe                   fpldnlsn
0x000001d3: ).       29 f4                   fpgt
0x000001d5: !.       21 d0                   stl 16 (0x10)
0x000001d7: !p       21 70                   ldl 16 (0x10)
0x000001d9: !.       21 9e                   call 0x000001f9
0x000001db: .        16                      ldlp 6
0x000001dc: (.       28 fe                   fpldnlsn
0x000001de: .        17                      ldlp 7
0x000001df: (.       28 fe                   fpldnlsn
0x000001e1: ).       29 f4                   fpgt
0x000001e3: !.       21 d1                   stl 17 (0x11)
0x000001e5: !q       21 71                   ldl 17 (0x11)
0x000001e7: !.       21 90                   call 0x000001f9
0x000001e9: .        7f                      ldl 15 (0xf)
0x000001ea: .        c0                      eqc 0
0x000001eb: .        9d                      call 0x000001f9
0x000001ec: !q       21 71                   ldl 17 (0x11)
0x000001ee: .        c0                      eqc 0
0x000001ef: .        99                      call 0x000001f9
0x000001f0: !p       21 70                   ldl 16 (0x10)
0x000001f2: .        c0                      eqc 0
0x000001f3: .        95                      call 0x000001f9
0x000001f4: @        40                      ldc 0
0x000001f5: !.       21 b2                   ajw 18 (0x12)
0x000001f7: ".       22 f0                   ret
0x000001f9: ".       22 f0                   ret
0x000001fb: ".       22 f0                   ret
0x000001fd: *K       2a 4b                   ldc 171 (0xab)
0x000001ff: !.       21 fb                   ldpi
0x00000201: 0        30                      ldnl 0
0x00000202: %.       25 fa                   dup
0x00000204: .        81                      adc 1
0x00000205: *C       2a 43                   ldc 163 (0xa3)
0x00000207: !.       21 fb                   ldpi
0x00000209: .        e0                      stnl 0
0x0000020a: &J       26 4a                   ldc 106 (0x6a)
0x0000020c: !.       21 fb                   ldpi
0x0000020e: .        fa                      wsub
0x0000020f: 0        30                      ldnl 0
0x00000210: ".       22 f0                   ret
0x00000212: )J       29 4a                   ldc 154 (0x9a)
0x00000214: !.       21 fb                   ldpi
0x00000216: 0        30                      ldnl 0
0x00000217: %.       25 fa                   dup
0x00000219: .        81                      adc 1
0x0000021a: )B       29 42                   ldc 146 (0x92)
0x0000021c: !.       21 fb                   ldpi
0x0000021e: .        e0                      stnl 0
0x0000021f: &E       26 45                   ldc 101 (0x65)
0x00000221: !.       21 fb                   ldpi
0x00000223: (.       28 f2                   fpldnldbi
0x00000225: ".       22 f0                   ret
0x00000227: `.       60 bd                   ajw -3 (0xfffffffd)
0x00000229: (G       28 47                   ldc 135 (0x87)
0x0000022b: !.       21 fb                   ldpi
0x0000022d: 0        30                      ldnl 0
0x0000022e: .        d0                      stl 0
0x0000022f: p        70                      ldl 0
0x00000230: `.       60 cf                   eqc -1
0x00000232: !.       21 a4                   cj 0x00000248
0x00000234: @        40                      ldc 0
0x00000235: .        d0                      stl 0
0x00000236: 'N       27 4e                   ldc 126 (0x7e)
0x00000238: !.       21 fb                   ldpi
0x0000023a: .        d2                      stl 2
0x0000023b: r        72                      ldl 2
0x0000023c: 0        30                      ldnl 0
0x0000023d: .        c0                      eqc 0
0x0000023e: .        a1                      cj 0x00000240
0x0000023f: .        08                      j 0x00000248
0x00000240: r        72                      ldl 2
0x00000241: Q        51                      ldnlp 1
0x00000242: .        d2                      stl 2
0x00000243: p        70                      ldl 0
0x00000244: .        81                      adc 1
0x00000245: .        d0                      stl 0
0x00000246: `.       60 03                   j 0x0000023b
0x00000248: p        70                      ldl 0
0x00000249: .        d1                      stl 1
0x0000024a: q        71                      ldl 1
0x0000024b: .        c0                      eqc 0
0x0000024c: .        a3                      cj 0x00000250
0x0000024d: .        b3                      ajw 3
0x0000024e: ".       22 f0                   ret
0x00000250: q        71                      ldl 1
0x00000251: %O       25 4f                   ldc 95 (0x5f)
0x00000253: !.       21 fb                   ldpi
0x00000255: .        fa                      wsub
0x00000256: 0        30                      ldnl 0
0x00000257: `.       60 bf                   ajw -1
0x00000259: B        42                      ldc 2
0x0000025a: !.       21 fb                   ldpi
0x0000025c: .        d0                      stl 0
0x0000025d: .        f6                      gcall
0x0000025e: `.       60 bd                   ajw -3 (0xfffffffd)
0x00000260: q        71                      ldl 1
0x00000261: `.       60 8f                   adc -1
0x00000263: .        d1                      stl 1
0x00000264: a.       61 04                   j 0x0000024a
0x00000266: #N       23 4e                   ldc 62 (0x3e)
0x00000268: !.       21 fb                   ldpi
0x0000026a: 0        30                      ldnl 0
0x0000026b: .        c0                      eqc 0
0x0000026c: .        a8                      cj 0x00000275
0x0000026d: A        41                      ldc 1
0x0000026e: #F       23 46                   ldc 54 (0x36)
0x00000270: !.       21 fb                   ldpi
0x00000272: .        e0                      stnl 0
0x00000273: d.       64 92                   call 0x00000227
0x00000275: ".       22 f0                   ret
0x00000277: .        00                      j 0x00000278
0x00000278: .        14                      ldlp 4
0x00000279: .        00                      j 0x0000027a
0x0000027a: .        00                      j 0x0000027b
0x0000027b: .        00                      j 0x0000027c
0x0000027c: E        45                      ldc 5
0x0000027d: .        00                      j 0x0000027e
0x0000027e: .        00                      j 0x0000027f
0x0000027f: .        00                      j 0x00000280
0x00000280: .        04                      j 0x00000285
0x00000281: .        00                      j 0x00000282
0x00000282: .        00                      j 0x00000283
0x00000283: .        00                      j 0x00000284
0x00000284: .        0c                      j 0x00000291
0x00000285: .        00                      j 0x00000286
0x00000286: .        00                      j 0x00000287
0x00000287: .        00                      j 0x00000288
0x00000288: ffffff4  66 66 66 66 66 66 34    ldnl 110532244 (0x6969694)
0x0000028f: @        40                      ldc 0
0x00000290: =        3d                      ldnl 13 (0xd)
0x00000291: .        0a                      j 0x0000029c
0x00000292: .        d7                      stl 7
0x00000293: .        a3                      cj 0x00000297
0x00000294: p        70                      ldl 0
0x00000295: }        7d                      ldl 13 (0xd)
0x00000296: Q        51                      ldnlp 1
0x00000297: @        40                      ldc 0
0x00000298: .        9a                      call 0x000002a3
0x00000299: .        99                      call 0x000002a3
0x0000029a: .        99                      call 0x000002a4
0x0000029b: .        99                      call 0x000002a5
0x0000029c: .        99                      call 0x000002a6
0x0000029d: .        99                      call 0x000002a7
0x0000029e: .        11                      ldlp 1
0x0000029f: @        40                      ldc 0
0x000002a0: X        58                      ldnlp 8
0x000002a1: 9        39                      ldnl 9
0x000002a2: .        b4                      ajw 4
0x000002a3: .        c8                      eqc 8
0x000002a4: v        76                      ldl 6
0x000002a5: F        46                      ldc 6
0x000002a6: i@       69 40                   ldc -160 (0xffffff60)
0x000002a8: .        00                      j 0x000002a9
0x000002a9: .        00                      j 0x000002aa
0x000002aa: .        00                      j 0x000002ab
0x000002ab: .        00                      j 0x000002ac
0x000002ac: .        00                      j 0x000002ad
0x000002ad: .        00                      j 0x000002ae
0x000002ae: .        00                      j 0x000002af
0x000002af: .        00                      j 0x000002b0
0x000002b0: .        00                      j 0x000002b1
0x000002b1: .        00                      j 0x000002b2
0x000002b2: .        00                      j 0x000002b3
0x000002b3: .        00                      j 0x000002b4
0x000002b4: .        00                      j 0x000002b5
0x000002b5: .        00                      j 0x000002b6
0x000002b6: .        00                      j 0x000002b7
0x000002b7: .        00                      j 0x000002b8
0x000002b8: .        00                      j 0x000002b9
0x000002b9: .        00                      j 0x000002ba
0x000002ba: .        00                      j 0x000002bb
0x000002bb: .        00                      j 0x000002bc
