                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.7.0 #4818 (Oct 18 2007)
                              4 ; This file generated Mon Mar 31 21:31:38 2008
                              5 ;--------------------------------------------------------
                              6 	.module ezusbledtoggle
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _delay_short
                             14 	.globl _delay
                             15 	.globl _TD_Init
                             16 	.globl _EUSB
                             17 	.globl _TF2
                             18 	.globl _TR2
                             19 	.globl _TI_1
                             20 	.globl _RI_1
                             21 	.globl _EA
                             22 	.globl _ES1
                             23 	.globl _ET2
                             24 	.globl _ES0
                             25 	.globl _ET0
                             26 	.globl _IE
                             27 	.globl _TI_0
                             28 	.globl _RI_0
                             29 	.globl _TR1
                             30 	.globl _TR0
                             31 	.globl _EICON
                             32 	.globl _TH2
                             33 	.globl _TL2
                             34 	.globl _RCAP2H
                             35 	.globl _RCAP2L
                             36 	.globl _T2CON
                             37 	.globl _CKCON
                             38 	.globl _SBUF1
                             39 	.globl _SBUF0
                             40 	.globl _SCON1
                             41 	.globl _SCON0
                             42 	.globl _EIE
                             43 	.globl _EXIF
                             44 	.globl _TH1
                             45 	.globl _TH0
                             46 	.globl _TL1
                             47 	.globl _TL0
                             48 	.globl _TMOD
                             49 	.globl _TCON
                             50 	.globl _PCON
                             51 	.globl _SETUPDAT
                             52 	.globl _AUTODATA
                             53 	.globl _AUTOPTRL
                             54 	.globl _AUTOPTRH
                             55 	.globl _OUT07VAL
                             56 	.globl _IN07VAL
                             57 	.globl _USBPAIR
                             58 	.globl _USBFRAMEH
                             59 	.globl _USBFRAMEL
                             60 	.globl _USBCS
                             61 	.globl _SUDPTRL
                             62 	.globl _SUDPTRH
                             63 	.globl _OUT2BC
                             64 	.globl _OUT2CS
                             65 	.globl _OUT1BC
                             66 	.globl _OUT1CS
                             67 	.globl _OUT0BC
                             68 	.globl _IN4BC
                             69 	.globl _IN4CS
                             70 	.globl _IN2BC
                             71 	.globl _IN2CS
                             72 	.globl _IN1BC
                             73 	.globl _IN1CS
                             74 	.globl _IN0BC
                             75 	.globl _EP0CS
                             76 	.globl _USBBAV
                             77 	.globl _USBIEN
                             78 	.globl _OUT07IEN
                             79 	.globl _IN07IEN
                             80 	.globl _USBIRQ
                             81 	.globl _OUT07IRQ
                             82 	.globl _IN07IRQ
                             83 	.globl _I2DAT
                             84 	.globl _I2CS
                             85 	.globl _UART230
                             86 	.globl _OEC
                             87 	.globl _OEB
                             88 	.globl _OEA
                             89 	.globl _PINSC
                             90 	.globl _PINSB
                             91 	.globl _PINSA
                             92 	.globl _OUTC
                             93 	.globl _OUTB
                             94 	.globl _OUTA
                             95 	.globl _PORTCCFG
                             96 	.globl _PORTBCFG
                             97 	.globl _PORTACFG
                             98 	.globl _CPUCS
                             99 	.globl _IN0BUF
                            100 	.globl _OUT0BUF
                            101 	.globl _IN1BUF
                            102 	.globl _OUT1BUF
                            103 	.globl _IN2BUF
                            104 	.globl _OUT2BUF
                            105 	.globl _IN4BUF
                            106 	.globl _EPx
                            107 ;--------------------------------------------------------
                            108 ; special function registers
                            109 ;--------------------------------------------------------
                            110 	.area RSEG    (DATA)
                    0087    111 _PCON	=	0x0087
                    0088    112 _TCON	=	0x0088
                    0089    113 _TMOD	=	0x0089
                    008A    114 _TL0	=	0x008a
                    008B    115 _TL1	=	0x008b
                    008C    116 _TH0	=	0x008c
                    008D    117 _TH1	=	0x008d
                    0091    118 _EXIF	=	0x0091
                    00E8    119 _EIE	=	0x00e8
                    0098    120 _SCON0	=	0x0098
                    00C0    121 _SCON1	=	0x00c0
                    0099    122 _SBUF0	=	0x0099
                    00C1    123 _SBUF1	=	0x00c1
                    008E    124 _CKCON	=	0x008e
                    00C8    125 _T2CON	=	0x00c8
                    00CA    126 _RCAP2L	=	0x00ca
                    00CB    127 _RCAP2H	=	0x00cb
                    00CC    128 _TL2	=	0x00cc
                    00CD    129 _TH2	=	0x00cd
                    00D8    130 _EICON	=	0x00d8
                            131 ;--------------------------------------------------------
                            132 ; special function bits
                            133 ;--------------------------------------------------------
                            134 	.area RSEG    (DATA)
                    008C    135 _TR0	=	0x008c
                    008E    136 _TR1	=	0x008e
                    0098    137 _RI_0	=	0x0098
                    0099    138 _TI_0	=	0x0099
                    00A8    139 _IE	=	0x00a8
                    00A9    140 _ET0	=	0x00a9
                    00AC    141 _ES0	=	0x00ac
                    00AD    142 _ET2	=	0x00ad
                    00AE    143 _ES1	=	0x00ae
                    00AF    144 _EA	=	0x00af
                    00C0    145 _RI_1	=	0x00c0
                    00C1    146 _TI_1	=	0x00c1
                    00CA    147 _TR2	=	0x00ca
                    00CF    148 _TF2	=	0x00cf
                    00E8    149 _EUSB	=	0x00e8
                            150 ;--------------------------------------------------------
                            151 ; overlayable register banks
                            152 ;--------------------------------------------------------
                            153 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     154 	.ds 8
                            155 ;--------------------------------------------------------
                            156 ; internal ram data
                            157 ;--------------------------------------------------------
                            158 	.area DSEG    (DATA)
                            159 ;--------------------------------------------------------
                            160 ; overlayable items in internal ram 
                            161 ;--------------------------------------------------------
                            162 	.area	OSEG    (OVR,DATA)
   0008                     163 _delay_DELAY_1_1::
   0008                     164 	.ds 4
                            165 	.area	OSEG    (OVR,DATA)
   0008                     166 _delay_short_DELAY_1_1::
   0008                     167 	.ds 4
                            168 ;--------------------------------------------------------
                            169 ; Stack segment in internal ram 
                            170 ;--------------------------------------------------------
                            171 	.area	SSEG	(DATA)
   000C                     172 __start__stack:
   000C                     173 	.ds	1
                            174 
                            175 ;--------------------------------------------------------
                            176 ; indirectly addressable internal ram data
                            177 ;--------------------------------------------------------
                            178 	.area ISEG    (DATA)
                            179 ;--------------------------------------------------------
                            180 ; absolute internal ram data
                            181 ;--------------------------------------------------------
                            182 	.area IABS    (ABS,DATA)
                            183 	.area IABS    (ABS,DATA)
                            184 ;--------------------------------------------------------
                            185 ; bit data
                            186 ;--------------------------------------------------------
                            187 	.area BSEG    (BIT)
                            188 ;--------------------------------------------------------
                            189 ; paged external ram data
                            190 ;--------------------------------------------------------
                            191 	.area PSEG    (PAG,XDATA)
                            192 ;--------------------------------------------------------
                            193 ; external ram data
                            194 ;--------------------------------------------------------
                            195 	.area XSEG    (XDATA)
                    7FB4    196 _EPx	=	0x7fb4
                    7D00    197 _IN4BUF	=	0x7d00
                    7DC0    198 _OUT2BUF	=	0x7dc0
                    7E00    199 _IN2BUF	=	0x7e00
                    7E40    200 _OUT1BUF	=	0x7e40
                    7E80    201 _IN1BUF	=	0x7e80
                    7EC0    202 _OUT0BUF	=	0x7ec0
                    7F00    203 _IN0BUF	=	0x7f00
                    7F92    204 _CPUCS	=	0x7f92
                    7F93    205 _PORTACFG	=	0x7f93
                    7F94    206 _PORTBCFG	=	0x7f94
                    7F95    207 _PORTCCFG	=	0x7f95
                    7F96    208 _OUTA	=	0x7f96
                    7F97    209 _OUTB	=	0x7f97
                    7F98    210 _OUTC	=	0x7f98
                    7F99    211 _PINSA	=	0x7f99
                    7F9A    212 _PINSB	=	0x7f9a
                    7F9B    213 _PINSC	=	0x7f9b
                    7F9C    214 _OEA	=	0x7f9c
                    7F9D    215 _OEB	=	0x7f9d
                    7F9E    216 _OEC	=	0x7f9e
                    7F9F    217 _UART230	=	0x7f9f
                    7FA5    218 _I2CS	=	0x7fa5
                    7FA6    219 _I2DAT	=	0x7fa6
                    7FA9    220 _IN07IRQ	=	0x7fa9
                    7FAA    221 _OUT07IRQ	=	0x7faa
                    7FAB    222 _USBIRQ	=	0x7fab
                    7FAC    223 _IN07IEN	=	0x7fac
                    7FAD    224 _OUT07IEN	=	0x7fad
                    7FAE    225 _USBIEN	=	0x7fae
                    7FAF    226 _USBBAV	=	0x7faf
                    7FB4    227 _EP0CS	=	0x7fb4
                    7FB5    228 _IN0BC	=	0x7fb5
                    7FB6    229 _IN1CS	=	0x7fb6
                    7FB7    230 _IN1BC	=	0x7fb7
                    7FB8    231 _IN2CS	=	0x7fb8
                    7FB9    232 _IN2BC	=	0x7fb9
                    7FBC    233 _IN4CS	=	0x7fbc
                    7FBD    234 _IN4BC	=	0x7fbd
                    7FC5    235 _OUT0BC	=	0x7fc5
                    7FC6    236 _OUT1CS	=	0x7fc6
                    7FC7    237 _OUT1BC	=	0x7fc7
                    7FC8    238 _OUT2CS	=	0x7fc8
                    7FC9    239 _OUT2BC	=	0x7fc9
                    7FD4    240 _SUDPTRH	=	0x7fd4
                    7FD5    241 _SUDPTRL	=	0x7fd5
                    7FD6    242 _USBCS	=	0x7fd6
                    7FD8    243 _USBFRAMEL	=	0x7fd8
                    7FD9    244 _USBFRAMEH	=	0x7fd9
                    7FDD    245 _USBPAIR	=	0x7fdd
                    7FDE    246 _IN07VAL	=	0x7fde
                    7FDF    247 _OUT07VAL	=	0x7fdf
                    7FE3    248 _AUTOPTRH	=	0x7fe3
                    7FE4    249 _AUTOPTRL	=	0x7fe4
                    7FE5    250 _AUTODATA	=	0x7fe5
                    7FE8    251 _SETUPDAT	=	0x7fe8
                            252 ;--------------------------------------------------------
                            253 ; absolute external ram data
                            254 ;--------------------------------------------------------
                            255 	.area XABS    (ABS,XDATA)
                            256 ;--------------------------------------------------------
                            257 ; external initialized ram data
                            258 ;--------------------------------------------------------
                            259 	.area XISEG   (XDATA)
                            260 	.area HOME    (CODE)
                            261 	.area GSINIT0 (CODE)
                            262 	.area GSINIT1 (CODE)
                            263 	.area GSINIT2 (CODE)
                            264 	.area GSINIT3 (CODE)
                            265 	.area GSINIT4 (CODE)
                            266 	.area GSINIT5 (CODE)
                            267 	.area GSINIT  (CODE)
                            268 	.area GSFINAL (CODE)
                            269 	.area CSEG    (CODE)
                            270 ;--------------------------------------------------------
                            271 ; interrupt vector 
                            272 ;--------------------------------------------------------
                            273 	.area HOME    (CODE)
   0000                     274 __interrupt_vect:
   0000 02 00 08            275 	ljmp	__sdcc_gsinit_startup
                            276 ;--------------------------------------------------------
                            277 ; global & static initialisations
                            278 ;--------------------------------------------------------
                            279 	.area HOME    (CODE)
                            280 	.area GSINIT  (CODE)
                            281 	.area GSFINAL (CODE)
                            282 	.area GSINIT  (CODE)
                            283 	.globl __sdcc_gsinit_startup
                            284 	.globl __sdcc_program_startup
                            285 	.globl __start__stack
                            286 	.globl __mcs51_genXINIT
                            287 	.globl __mcs51_genXRAMCLEAR
                            288 	.globl __mcs51_genRAMCLEAR
                            289 	.area GSFINAL (CODE)
   0061 02 00 03            290 	ljmp	__sdcc_program_startup
                            291 ;--------------------------------------------------------
                            292 ; Home
                            293 ;--------------------------------------------------------
                            294 	.area HOME    (CODE)
                            295 	.area HOME    (CODE)
   0003                     296 __sdcc_program_startup:
   0003 12 00 F4            297 	lcall	_main
                            298 ;	return from main will lock up
   0006 80 FE               299 	sjmp .
                            300 ;--------------------------------------------------------
                            301 ; code
                            302 ;--------------------------------------------------------
                            303 	.area CSEG    (CODE)
                            304 ;------------------------------------------------------------
                            305 ;Allocation info for local variables in function 'TD_Init'
                            306 ;------------------------------------------------------------
                            307 ;------------------------------------------------------------
                            308 ;	ezusbledtoggle.c:5: void TD_Init(void)
                            309 ;	-----------------------------------------
                            310 ;	 function TD_Init
                            311 ;	-----------------------------------------
   0064                     312 _TD_Init:
                    0002    313 	ar2 = 0x02
                    0003    314 	ar3 = 0x03
                    0004    315 	ar4 = 0x04
                    0005    316 	ar5 = 0x05
                    0006    317 	ar6 = 0x06
                    0007    318 	ar7 = 0x07
                    0000    319 	ar0 = 0x00
                    0001    320 	ar1 = 0x01
                            321 ;	ezusbledtoggle.c:9: PORTACFG = 0x00; // use all port A pins as IO
   0064 90 7F 93            322 	mov	dptr,#_PORTACFG
   0067 E4                  323 	clr	a
   0068 F0                  324 	movx	@dptr,a
                            325 ;	ezusbledtoggle.c:10: OEA = 0xff; // Set all port A pins as output
   0069 90 7F 9C            326 	mov	dptr,#_OEA
   006C 74 FF               327 	mov	a,#0xFF
   006E F0                  328 	movx	@dptr,a
                            329 ;	ezusbledtoggle.c:12: PORTBCFG = 0x00;
   006F 90 7F 94            330 	mov	dptr,#_PORTBCFG
   0072 E4                  331 	clr	a
   0073 F0                  332 	movx	@dptr,a
                            333 ;	ezusbledtoggle.c:13: OEB = 0xff;
   0074 90 7F 9D            334 	mov	dptr,#_OEB
   0077 74 FF               335 	mov	a,#0xFF
   0079 F0                  336 	movx	@dptr,a
                            337 ;	ezusbledtoggle.c:15: PORTCCFG = 0x00;
   007A 90 7F 95            338 	mov	dptr,#_PORTCCFG
   007D E4                  339 	clr	a
   007E F0                  340 	movx	@dptr,a
                            341 ;	ezusbledtoggle.c:16: OEC = 0xff;
   007F 90 7F 9E            342 	mov	dptr,#_OEC
   0082 74 FF               343 	mov	a,#0xFF
   0084 F0                  344 	movx	@dptr,a
   0085 22                  345 	ret
                            346 ;------------------------------------------------------------
                            347 ;Allocation info for local variables in function 'delay'
                            348 ;------------------------------------------------------------
                            349 ;DELAY                     Allocated with name '_delay_DELAY_1_1'
                            350 ;a                         Allocated to registers r6 r7 
                            351 ;b                         Allocated to registers 
                            352 ;------------------------------------------------------------
                            353 ;	ezusbledtoggle.c:20: void delay( const long int DELAY )
                            354 ;	-----------------------------------------
                            355 ;	 function delay
                            356 ;	-----------------------------------------
   0086                     357 _delay:
   0086 85 82 08            358 	mov	_delay_DELAY_1_1,dpl
   0089 85 83 09            359 	mov	(_delay_DELAY_1_1 + 1),dph
   008C 85 F0 0A            360 	mov	(_delay_DELAY_1_1 + 2),b
   008F F5 0B               361 	mov	(_delay_DELAY_1_1 + 3),a
                            362 ;	ezusbledtoggle.c:23: for ( a = 0; a < DELAY; a++ );
   0091 7E 00               363 	mov	r6,#0x00
   0093 7F 00               364 	mov	r7,#0x00
   0095                     365 00101$:
   0095 8E 00               366 	mov	ar0,r6
   0097 EF                  367 	mov	a,r7
   0098 F9                  368 	mov	r1,a
   0099 33                  369 	rlc	a
   009A 95 E0               370 	subb	a,acc
   009C FA                  371 	mov	r2,a
   009D FB                  372 	mov	r3,a
   009E C3                  373 	clr	c
   009F E8                  374 	mov	a,r0
   00A0 95 08               375 	subb	a,_delay_DELAY_1_1
   00A2 E9                  376 	mov	a,r1
   00A3 95 09               377 	subb	a,(_delay_DELAY_1_1 + 1)
   00A5 EA                  378 	mov	a,r2
   00A6 95 0A               379 	subb	a,(_delay_DELAY_1_1 + 2)
   00A8 EB                  380 	mov	a,r3
   00A9 64 80               381 	xrl	a,#0x80
   00AB 85 0B F0            382 	mov	b,(_delay_DELAY_1_1 + 3)
   00AE 63 F0 80            383 	xrl	b,#0x80
   00B1 95 F0               384 	subb	a,b
   00B3 50 07               385 	jnc	00105$
   00B5 0E                  386 	inc	r6
   00B6 BE 00 DC            387 	cjne	r6,#0x00,00101$
   00B9 0F                  388 	inc	r7
                            389 ;	ezusbledtoggle.c:26: b = a;
   00BA 80 D9               390 	sjmp	00101$
   00BC                     391 00105$:
   00BC 22                  392 	ret
                            393 ;------------------------------------------------------------
                            394 ;Allocation info for local variables in function 'delay_short'
                            395 ;------------------------------------------------------------
                            396 ;DELAY                     Allocated with name '_delay_short_DELAY_1_1'
                            397 ;a                         Allocated to registers r6 r7 
                            398 ;b                         Allocated to registers 
                            399 ;------------------------------------------------------------
                            400 ;	ezusbledtoggle.c:30: void delay_short( const long int DELAY )
                            401 ;	-----------------------------------------
                            402 ;	 function delay_short
                            403 ;	-----------------------------------------
   00BD                     404 _delay_short:
   00BD 85 82 08            405 	mov	_delay_short_DELAY_1_1,dpl
   00C0 85 83 09            406 	mov	(_delay_short_DELAY_1_1 + 1),dph
   00C3 85 F0 0A            407 	mov	(_delay_short_DELAY_1_1 + 2),b
   00C6 F5 0B               408 	mov	(_delay_short_DELAY_1_1 + 3),a
                            409 ;	ezusbledtoggle.c:33: for ( a = 0; a < DELAY; a++ );
   00C8 7E 00               410 	mov	r6,#0x00
   00CA 7F 00               411 	mov	r7,#0x00
   00CC                     412 00101$:
   00CC 8E 00               413 	mov	ar0,r6
   00CE EF                  414 	mov	a,r7
   00CF F9                  415 	mov	r1,a
   00D0 33                  416 	rlc	a
   00D1 95 E0               417 	subb	a,acc
   00D3 FA                  418 	mov	r2,a
   00D4 FB                  419 	mov	r3,a
   00D5 C3                  420 	clr	c
   00D6 E8                  421 	mov	a,r0
   00D7 95 08               422 	subb	a,_delay_short_DELAY_1_1
   00D9 E9                  423 	mov	a,r1
   00DA 95 09               424 	subb	a,(_delay_short_DELAY_1_1 + 1)
   00DC EA                  425 	mov	a,r2
   00DD 95 0A               426 	subb	a,(_delay_short_DELAY_1_1 + 2)
   00DF EB                  427 	mov	a,r3
   00E0 64 80               428 	xrl	a,#0x80
   00E2 85 0B F0            429 	mov	b,(_delay_short_DELAY_1_1 + 3)
   00E5 63 F0 80            430 	xrl	b,#0x80
   00E8 95 F0               431 	subb	a,b
   00EA 50 07               432 	jnc	00105$
   00EC 0E                  433 	inc	r6
   00ED BE 00 DC            434 	cjne	r6,#0x00,00101$
   00F0 0F                  435 	inc	r7
                            436 ;	ezusbledtoggle.c:36: b = a;
   00F1 80 D9               437 	sjmp	00101$
   00F3                     438 00105$:
   00F3 22                  439 	ret
                            440 ;------------------------------------------------------------
                            441 ;Allocation info for local variables in function 'main'
                            442 ;------------------------------------------------------------
                            443 ;DELAY                     Allocated to registers 
                            444 ;------------------------------------------------------------
                            445 ;	ezusbledtoggle.c:40: void main()
                            446 ;	-----------------------------------------
                            447 ;	 function main
                            448 ;	-----------------------------------------
   00F4                     449 _main:
                            450 ;	ezusbledtoggle.c:43: TD_Init();
   00F4 12 00 64            451 	lcall	_TD_Init
                            452 ;	ezusbledtoggle.c:45: while (1)
   00F7                     453 00102$:
                            454 ;	ezusbledtoggle.c:50: OUTA = 0x00;
   00F7 90 7F 96            455 	mov	dptr,#_OUTA
   00FA E4                  456 	clr	a
   00FB F0                  457 	movx	@dptr,a
                            458 ;	ezusbledtoggle.c:53: delay(DELAY);
   00FC 90 27 10            459 	mov	dptr,#0x2710
   00FF E4                  460 	clr	a
   0100 F5 F0               461 	mov	b,a
   0102 12 00 86            462 	lcall	_delay
                            463 ;	ezusbledtoggle.c:54: OUTA = 0xff;
   0105 90 7F 96            464 	mov	dptr,#_OUTA
   0108 74 FF               465 	mov	a,#0xFF
   010A F0                  466 	movx	@dptr,a
                            467 ;	ezusbledtoggle.c:57: delay(DELAY);
   010B 90 27 10            468 	mov	dptr,#0x2710
   010E E4                  469 	clr	a
   010F F5 F0               470 	mov	b,a
   0111 12 00 86            471 	lcall	_delay
   0114 80 E1               472 	sjmp	00102$
                            473 	.area CSEG    (CODE)
                            474 	.area CONST   (CODE)
                            475 	.area XINIT   (CODE)
                            476 	.area CABS    (ABS,CODE)
