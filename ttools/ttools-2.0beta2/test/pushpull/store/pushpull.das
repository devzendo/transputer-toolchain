0x00000000: @        40                      ldc 0
0x00000001: /-J      2f 2d 4a                ldc 4058 (0xfda)
0x00000004: !.       21 fb                   ldpi
0x00000006: .        e0                      stnl 0
0x00000007: @        40                      ldc 0
0x00000008: /-G      2f 2d 47                ldc 4055 (0xfd7)
0x0000000b: !.       21 fb                   ldpi
0x0000000d: .        e0                      stnl 0
0x0000000e: @        40                      ldc 0
0x0000000f: /-D      2f 2d 44                ldc 4052 (0xfd4)
0x00000012: !.       21 fb                   ldpi
0x00000014: .        e0                      stnl 0
0x00000015: @        40                      ldc 0
0x00000016: /-A      2f 2d 41                ldc 4049 (0xfd1)
0x00000019: !.       21 fb                   ldpi
0x0000001b: .        e0                      stnl 0
0x0000001c: $.       24 f2                   mint
0x0000001e: g %L     67 20 25 4c             ldc -32676 (0xffff805c)
0x00000022: !.       21 fb                   ldpi
0x00000024: .        e0                      stnl 0
0x00000025: G        47                      ldc 7
0x00000026: %.       25 10                   ldlp 80 (0x50)
0x00000028: .        fd                      startp
0x00000029: $O       24 4f                   ldc 79 (0x4f)
0x0000002b: *.       2a 10                   ldlp 160 (0xa0)
0x0000002d: .        fd                      startp
0x0000002e: !.       21 f5                   stopp
0x00000030: /*K      2f 2a 4b                ldc 4011 (0xfab)
0x00000033: !.       21 fb                   ldpi
0x00000035: g/,E     67 2f 2c 45             ldc -28731 (0xffff8fc5)
0x00000039: !.       21 fb                   ldpi
0x0000003b: .        9e                      call 0x0000004a
0x0000003c: /*C      2f 2a 43                ldc 4003 (0xfa3)
0x0000003f: !.       21 fb                   ldpi
0x00000041: f/+I     66 2f 2b 49             ldc -24647 (0xffff9fb9)
0x00000045: !.       21 fb                   ldpi
0x00000047: .        92                      call 0x0000004a
0x00000048: a.       61 06                   j 0x00000030
0x0000004a: `.       60 be                   ajw -2
0x0000004c: ".       22 f2                   ldtimer
0x0000004e: ".       22 fb                   tin
0x00000050: t        74                      ldl 4
0x00000051: 0        30                      ldnl 0
0x00000052: .        d1                      stl 1
0x00000053: q        71                      ldl 1
0x00000054: `.       60 a6                   cj 0x0000004c
0x00000056: ".       22 f2                   ldtimer
0x00000058: .        81                      adc 1
0x00000059: ".       22 fb                   tin
0x0000005b: q        71                      ldl 1
0x0000005c: t        74                      ldl 4
0x0000005d: 0        30                      ldnl 0
0x0000005e: .        d1                      stl 1
0x0000005f: q        71                      ldl 1
0x00000060: .        f4                      diff
0x00000061: .        c0                      eqc 0
0x00000062: `.       60 a2                   cj 0x00000056
0x00000064: .        11                      ldlp 1
0x00000065: $.       24 f2                   mint
0x00000067: "P       22 50                   ldnlp 32 (0x20)
0x00000069: D        44                      ldc 4
0x0000006a: .        fb                      out
0x0000006b: q        71                      ldl 1
0x0000006c: `.       60 cf                   eqc -1
0x0000006e: .        c0                      eqc 0
0x0000006f: .        a7                      cj 0x00000077
0x00000070: s        73                      ldl 3
0x00000071: $.       24 f2                   mint
0x00000073: "P       22 50                   ldnlp 32 (0x20)
0x00000075: q        71                      ldl 1
0x00000076: .        fb                      out
0x00000077: @        40                      ldc 0
0x00000078: t        74                      ldl 4
0x00000079: .        e0                      stnl 0
0x0000007a: .        b2                      ajw 2
0x0000007b: ".       22 f0                   ret
0x0000007d: /&F      2f 26 46                ldc 3942 (0xf66)
0x00000080: !.       21 fb                   ldpi
0x00000082: e/'H     65 2f 27 48             ldc -20616 (0xffffaf78)
0x00000086: !.       21 fb                   ldpi
0x00000088: .        9e                      call 0x00000097
0x00000089: /%N      2f 25 4e                ldc 3934 (0xf5e)
0x0000008c: !.       21 fb                   ldpi
0x0000008e: d/&L     64 2f 26 4c             ldc -16532 (0xffffbf6c)
0x00000092: !.       21 fb                   ldpi
0x00000094: .        92                      call 0x00000097
0x00000095: a.       61 06                   j 0x0000007d
0x00000097: `.       60 be                   ajw -2
0x00000099: t        74                      ldl 4
0x0000009a: 0        30                      ldnl 0
0x0000009b: .        a6                      cj 0x000000a2
0x0000009c: ".       22 f2                   ldtimer
0x0000009e: ".       22 fb                   tin
0x000000a0: `.       60 07                   j 0x00000099
0x000000a2: .        11                      ldlp 1
0x000000a3: $.       24 f2                   mint
0x000000a5: "P       22 50                   ldnlp 32 (0x20)
0x000000a7: D        44                      ldc 4
0x000000a8: .        f7                      in
0x000000a9: q        71                      ldl 1
0x000000aa: `.       60 cf                   eqc -1
0x000000ac: .        c0                      eqc 0
0x000000ad: .        a7                      cj 0x000000b5
0x000000ae: s        73                      ldl 3
0x000000af: $.       24 f2                   mint
0x000000b1: "P       22 50                   ldnlp 32 (0x20)
0x000000b3: q        71                      ldl 1
0x000000b4: .        f7                      in
0x000000b5: q        71                      ldl 1
0x000000b6: t        74                      ldl 4
0x000000b7: .        e0                      stnl 0
0x000000b8: .        b2                      ajw 2
0x000000b9: ".       22 f0                   ret
0x000000bb: .        00                      j 0x000000bc
