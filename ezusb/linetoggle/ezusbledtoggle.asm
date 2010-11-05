;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.7.0 #4818 (Oct 18 2007)
; This file generated Mon Mar 31 21:31:38 2008
;--------------------------------------------------------
	.module ezusbledtoggle
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _delay_short
	.globl _delay
	.globl _TD_Init
	.globl _EUSB
	.globl _TF2
	.globl _TR2
	.globl _TI_1
	.globl _RI_1
	.globl _EA
	.globl _ES1
	.globl _ET2
	.globl _ES0
	.globl _ET0
	.globl _IE
	.globl _TI_0
	.globl _RI_0
	.globl _TR1
	.globl _TR0
	.globl _EICON
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _CKCON
	.globl _SBUF1
	.globl _SBUF0
	.globl _SCON1
	.globl _SCON0
	.globl _EIE
	.globl _EXIF
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _SETUPDAT
	.globl _AUTODATA
	.globl _AUTOPTRL
	.globl _AUTOPTRH
	.globl _OUT07VAL
	.globl _IN07VAL
	.globl _USBPAIR
	.globl _USBFRAMEH
	.globl _USBFRAMEL
	.globl _USBCS
	.globl _SUDPTRL
	.globl _SUDPTRH
	.globl _OUT2BC
	.globl _OUT2CS
	.globl _OUT1BC
	.globl _OUT1CS
	.globl _OUT0BC
	.globl _IN4BC
	.globl _IN4CS
	.globl _IN2BC
	.globl _IN2CS
	.globl _IN1BC
	.globl _IN1CS
	.globl _IN0BC
	.globl _EP0CS
	.globl _USBBAV
	.globl _USBIEN
	.globl _OUT07IEN
	.globl _IN07IEN
	.globl _USBIRQ
	.globl _OUT07IRQ
	.globl _IN07IRQ
	.globl _I2DAT
	.globl _I2CS
	.globl _UART230
	.globl _OEC
	.globl _OEB
	.globl _OEA
	.globl _PINSC
	.globl _PINSB
	.globl _PINSA
	.globl _OUTC
	.globl _OUTB
	.globl _OUTA
	.globl _PORTCCFG
	.globl _PORTBCFG
	.globl _PORTACFG
	.globl _CPUCS
	.globl _IN0BUF
	.globl _OUT0BUF
	.globl _IN1BUF
	.globl _OUT1BUF
	.globl _IN2BUF
	.globl _OUT2BUF
	.globl _IN4BUF
	.globl _EPx
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (DATA)
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_EXIF	=	0x0091
_EIE	=	0x00e8
_SCON0	=	0x0098
_SCON1	=	0x00c0
_SBUF0	=	0x0099
_SBUF1	=	0x00c1
_CKCON	=	0x008e
_T2CON	=	0x00c8
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
_EICON	=	0x00d8
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (DATA)
_TR0	=	0x008c
_TR1	=	0x008e
_RI_0	=	0x0098
_TI_0	=	0x0099
_IE	=	0x00a8
_ET0	=	0x00a9
_ES0	=	0x00ac
_ET2	=	0x00ad
_ES1	=	0x00ae
_EA	=	0x00af
_RI_1	=	0x00c0
_TI_1	=	0x00c1
_TR2	=	0x00ca
_TF2	=	0x00cf
_EUSB	=	0x00e8
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
_delay_DELAY_1_1::
	.ds 4
	.area	OSEG    (OVR,DATA)
_delay_short_DELAY_1_1::
	.ds 4
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
_EPx	=	0x7fb4
_IN4BUF	=	0x7d00
_OUT2BUF	=	0x7dc0
_IN2BUF	=	0x7e00
_OUT1BUF	=	0x7e40
_IN1BUF	=	0x7e80
_OUT0BUF	=	0x7ec0
_IN0BUF	=	0x7f00
_CPUCS	=	0x7f92
_PORTACFG	=	0x7f93
_PORTBCFG	=	0x7f94
_PORTCCFG	=	0x7f95
_OUTA	=	0x7f96
_OUTB	=	0x7f97
_OUTC	=	0x7f98
_PINSA	=	0x7f99
_PINSB	=	0x7f9a
_PINSC	=	0x7f9b
_OEA	=	0x7f9c
_OEB	=	0x7f9d
_OEC	=	0x7f9e
_UART230	=	0x7f9f
_I2CS	=	0x7fa5
_I2DAT	=	0x7fa6
_IN07IRQ	=	0x7fa9
_OUT07IRQ	=	0x7faa
_USBIRQ	=	0x7fab
_IN07IEN	=	0x7fac
_OUT07IEN	=	0x7fad
_USBIEN	=	0x7fae
_USBBAV	=	0x7faf
_EP0CS	=	0x7fb4
_IN0BC	=	0x7fb5
_IN1CS	=	0x7fb6
_IN1BC	=	0x7fb7
_IN2CS	=	0x7fb8
_IN2BC	=	0x7fb9
_IN4CS	=	0x7fbc
_IN4BC	=	0x7fbd
_OUT0BC	=	0x7fc5
_OUT1CS	=	0x7fc6
_OUT1BC	=	0x7fc7
_OUT2CS	=	0x7fc8
_OUT2BC	=	0x7fc9
_SUDPTRH	=	0x7fd4
_SUDPTRL	=	0x7fd5
_USBCS	=	0x7fd6
_USBFRAMEL	=	0x7fd8
_USBFRAMEH	=	0x7fd9
_USBPAIR	=	0x7fdd
_IN07VAL	=	0x7fde
_OUT07VAL	=	0x7fdf
_AUTOPTRH	=	0x7fe3
_AUTOPTRL	=	0x7fe4
_AUTODATA	=	0x7fe5
_SETUPDAT	=	0x7fe8
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'TD_Init'
;------------------------------------------------------------
;------------------------------------------------------------
;	ezusbledtoggle.c:5: void TD_Init(void)
;	-----------------------------------------
;	 function TD_Init
;	-----------------------------------------
_TD_Init:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	ezusbledtoggle.c:9: PORTACFG = 0x00; // use all port A pins as IO
	mov	dptr,#_PORTACFG
	clr	a
	movx	@dptr,a
;	ezusbledtoggle.c:10: OEA = 0xff; // Set all port A pins as output
	mov	dptr,#_OEA
	mov	a,#0xFF
	movx	@dptr,a
;	ezusbledtoggle.c:12: PORTBCFG = 0x00;
	mov	dptr,#_PORTBCFG
	clr	a
	movx	@dptr,a
;	ezusbledtoggle.c:13: OEB = 0xff;
	mov	dptr,#_OEB
	mov	a,#0xFF
	movx	@dptr,a
;	ezusbledtoggle.c:15: PORTCCFG = 0x00;
	mov	dptr,#_PORTCCFG
	clr	a
	movx	@dptr,a
;	ezusbledtoggle.c:16: OEC = 0xff;
	mov	dptr,#_OEC
	mov	a,#0xFF
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay'
;------------------------------------------------------------
;DELAY                     Allocated with name '_delay_DELAY_1_1'
;a                         Allocated to registers r6 r7 
;b                         Allocated to registers 
;------------------------------------------------------------
;	ezusbledtoggle.c:20: void delay( const long int DELAY )
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
	mov	_delay_DELAY_1_1,dpl
	mov	(_delay_DELAY_1_1 + 1),dph
	mov	(_delay_DELAY_1_1 + 2),b
	mov	(_delay_DELAY_1_1 + 3),a
;	ezusbledtoggle.c:23: for ( a = 0; a < DELAY; a++ );
	mov	r6,#0x00
	mov	r7,#0x00
00101$:
	mov	ar0,r6
	mov	a,r7
	mov	r1,a
	rlc	a
	subb	a,acc
	mov	r2,a
	mov	r3,a
	clr	c
	mov	a,r0
	subb	a,_delay_DELAY_1_1
	mov	a,r1
	subb	a,(_delay_DELAY_1_1 + 1)
	mov	a,r2
	subb	a,(_delay_DELAY_1_1 + 2)
	mov	a,r3
	xrl	a,#0x80
	mov	b,(_delay_DELAY_1_1 + 3)
	xrl	b,#0x80
	subb	a,b
	jnc	00105$
	inc	r6
	cjne	r6,#0x00,00101$
	inc	r7
;	ezusbledtoggle.c:26: b = a;
	sjmp	00101$
00105$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_short'
;------------------------------------------------------------
;DELAY                     Allocated with name '_delay_short_DELAY_1_1'
;a                         Allocated to registers r6 r7 
;b                         Allocated to registers 
;------------------------------------------------------------
;	ezusbledtoggle.c:30: void delay_short( const long int DELAY )
;	-----------------------------------------
;	 function delay_short
;	-----------------------------------------
_delay_short:
	mov	_delay_short_DELAY_1_1,dpl
	mov	(_delay_short_DELAY_1_1 + 1),dph
	mov	(_delay_short_DELAY_1_1 + 2),b
	mov	(_delay_short_DELAY_1_1 + 3),a
;	ezusbledtoggle.c:33: for ( a = 0; a < DELAY; a++ );
	mov	r6,#0x00
	mov	r7,#0x00
00101$:
	mov	ar0,r6
	mov	a,r7
	mov	r1,a
	rlc	a
	subb	a,acc
	mov	r2,a
	mov	r3,a
	clr	c
	mov	a,r0
	subb	a,_delay_short_DELAY_1_1
	mov	a,r1
	subb	a,(_delay_short_DELAY_1_1 + 1)
	mov	a,r2
	subb	a,(_delay_short_DELAY_1_1 + 2)
	mov	a,r3
	xrl	a,#0x80
	mov	b,(_delay_short_DELAY_1_1 + 3)
	xrl	b,#0x80
	subb	a,b
	jnc	00105$
	inc	r6
	cjne	r6,#0x00,00101$
	inc	r7
;	ezusbledtoggle.c:36: b = a;
	sjmp	00101$
00105$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;DELAY                     Allocated to registers 
;------------------------------------------------------------
;	ezusbledtoggle.c:40: void main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	ezusbledtoggle.c:43: TD_Init();
	lcall	_TD_Init
;	ezusbledtoggle.c:45: while (1)
00102$:
;	ezusbledtoggle.c:50: OUTA = 0x00;
	mov	dptr,#_OUTA
	clr	a
	movx	@dptr,a
;	ezusbledtoggle.c:53: delay(DELAY);
	mov	dptr,#0x2710
	clr	a
	mov	b,a
	lcall	_delay
;	ezusbledtoggle.c:54: OUTA = 0xff;
	mov	dptr,#_OUTA
	mov	a,#0xFF
	movx	@dptr,a
;	ezusbledtoggle.c:57: delay(DELAY);
	mov	dptr,#0x2710
	clr	a
	mov	b,a
	lcall	_delay
	sjmp	00102$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
