/***************************************************************************
                          ezusb.h  -  description
                             -------------------
    begin                : Sat Sep 2 2000
    copyright            : (C) 2000 by William Rachelson
    email                : gurufool@cc.gatech.edu

		ezusb.h is intended for use with SDCC and Anchorchips' EZ-USB.  It is
	based on Anchor's ezusb.h file that was intended for the Keil compiler,
	and also on the standard 8051.h templates for SDCC.

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef EZUSB_H
#define EZUSB_H
#endif

//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------
#define	TRUE 	1
#define FALSE	0

#define bmBIT0	0x01
#define bmBIT1	0x02
#define bmBIT2	0x04
#define bmBIT3	0x08
#define bmBIT4	0x10
#define bmBIT5	0x20
#define bmBIT6	0x40
#define bmBIT7	0x80

#define DEVICE_DSCR		0x01		// Descriptor type: Device
#define CONFIG_DSCR		0x02		// Descriptor type: Configuration
#define STRING_DSCR		0x03		// Descriptor type: String
#define INTRFC_DSCR		0x04		// Descriptor type: Interface
#define ENDPNT_DSCR		0x05		// Descriptor type: End Point

#define	bmBUSPWR	bmBIT7			// Config. attribute: Bus powered
#define bmSELFPWR	bmBIT6			// Config. attribute: Self powered
#define bmRWU		bmBIT5			// Config. attribute: Remote Wakeup

#define bmEPOUT		bmBIT7
#define bmEPIN		0x00

#define EP_CONTROL	0x00			// End Point type: Control
#define EP_ISO		0x01			// End Point type: Isochronous
#define EP_BULK		0x02			// End Point type: Bulk
#define EP_INT		0x03			// End Point type: Interrupt

#define SUD_SIZE				8		// Setup data packet size

#define SC_GET_STATUS			0x00	// Setup command: Get Status
#define SC_CLEAR_FEATURE		0x01	// Setup command: Clear Feature
#define SC_RESERVED				0x02	// Setup command: Reserved
#define SC_SET_FEATURE			0x03	// Setup command: Set Feature
#define SC_SET_ADDRESS			0x05	// Setup command: Set Address
#define SC_GET_DESCRIPTOR		0x06	// Setup command: Get Descriptor
#define SC_SET_DESCRIPTOR		0x07	// Setup command: Set Descriptor
#define SC_GET_CONFIGURATION	0x08	// Setup command: Get Configuration
#define SC_SET_CONFIGURATION	0x09	// Setup command: Set Configuration
#define SC_GET_INTERFACE		0x0a	// Setup command: Get Interface
#define SC_SET_INTERFACE		0x0b	// Setup command: Set Interface
#define SC_SYNC_FRAME			0x0c	// Setup command: Sync Frame
#define SC_ANCHOR_LOAD			0xa0	// Setup command: Anchor load
	
#define GD_DEVICE				0x01	// Get device descriptor: Device
#define GD_CONFIGURATION		0x02	// Get device descriptor: Configuration
#define GD_STRING				0x03	// Get device descriptor: String

#define GS_DEVICE				0x80	// Get Status: Device
#define GS_INTERFACE			0x81	// Get Status: Interface
#define GS_ENDPOINT				0x82	// Get Status: End Point

#define FT_DEVICE				0x00	// Feature: Device
#define FT_ENDPOINT				0x02	// Feature: End Point

#define I2C_IDLE				0		// I2C Status: Idle mode
#define I2C_SENDING				1		// I2C Status: I2C is sending data
#define I2C_RECEIVING			2		// I2C Status: I2C is receiving data
#define I2C_PRIME				3		// I2C Status: I2C is receiving the first byte of a string
#define I2C_STOP				5		// I2C Status: I2C waiting for stop completion
#define I2C_BERROR				6		// I2C Status: I2C error; Bit Error
#define I2C_NACK				7		// I2C Status: I2C error; No Acknowledge
#define I2C_OK					8		// I2C positive return code




/*-----------------------------------------------------------------------------
	Macros
-----------------------------------------------------------------------------*/
#define MSB(word)		(BYTE)(((WORD)word >> 8) & 0xff)
#define LSB(word)		(BYTE)((WORD)word & 0xff)

#define SWAP_ENDIAN(word)	((BYTE*)&word)[0] ^= ((BYTE*)&word)[1];\
							((BYTE*)&word)[1] ^= ((BYTE*)&word)[0];\
							((BYTE*)&word)[0] ^= ((BYTE*)&word)[1]

#define EZUSB_IRQ_ENABLE()	EUSB = 1
#define EZUSB_IRQ_DISABLE()	EUSB = 0
#ifndef CHIPREV_B
#define EZUSB_IRQ_CLEAR()	EXIF &= ~0x10		// IE2_
#endif

#define EZUSB_STALL_EP0()				EP0CS |= bmEPSTALL
#define EZUSB_STALL_EP(ep_id)  			EPIO[ep_id].cntrl = bmEPSTALL
#define EZUSB_UNSTALL_EP(ep_id)			EPIO[ep_id].cntrl = 0
#define	EZUSB_GET_EP_STATUS(ep_id)		EPIO[ep_id].cntrl
#define EZUSB_SET_EP_BYTES(ep_id,count)	EPIO[ep_id].bytes = count

#define EZUSB_RESET_DATA_TOGGLE(ep)     TOGCTL = (((ep & 0x80) >> 3) + (ep & 0x07));\
                                        TOGCTL |= 0x20


#define EZUSB_ENABLE_RSMIRQ()		(EICON |= 0x20)		// Enable Resume Interrupt (EPFI_)
#define EZUSB_DISABLE_RSMIRQ()		(EICON &= ~0x20)	// Disable Resume Interrupt (EPFI_)
#define EZUSB_CLEAR_RSMIRQ()		(EICON &= ~0x10)	// Clear Resume Interrupt Flag (PFI_)

#define EZUSB_GETI2CSTATUS()		(I2CPckt.status)
#define EZUSB_CLEARI2CSTATUS()		if((I2CPckt.status == I2C_BERROR) || (I2CPckt.status == I2C_NACK))\
										I2CPckt.status = I2C_IDLE;

#define EZUSB_ENABLEBP()			(USBBAV |= bmBPEN)
#define EZUSB_DISABLEBP()			(USBBAV &= ~bmBPEN)
#define EZUSB_CLEARBP()				(USBBAV |= bmBREAK)
#define EZUSB_BP(addr)				BPADDR = (WORD)addr

#define EZUSB_EXTWAKEUP()			(USBCS & bmRWAKEUP)

/* Convert End point ID (d0000eee) to EPIO offset */
#define EPID(id)		(((~id & 0x80) >> 4) + (id & 0x07))



//-----------------------------------------------------------------------------
// Datatypes
//-----------------------------------------------------------------------------
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned long	DWORD;
typedef bit				BOOL;

#define	INT0_VECT	0
#define	TMR0_VECT	1
#define	INT1_VECT	2
#define	TMR1_VECT	3
#define	COM0_VECT	4
#define	TMR2_VECT	5
#define	WKUP_VECT	6
#define	COM1_VECT	7
#define	USB_VECT	8
#define	I2C_VECT	9
#define	INT4_VECT	10
#define	INT5_VECT	11
#define	INT6_VECT	12

#define	SUDAV_USBVECT	(0 << 2)
#define	SOF_USBVECT		(1 << 2)
#define	SUTOK_USBVECT	(2 << 2)
#define	SUSP_USBVECT	(3 << 2)
#define	URES_USBVECT	(4 << 2)
#define	SPARE_USBVECT	(5 << 2)
#define	IN0BUF_USBVECT	(6 << 2)
#define	OUT0BUF_USBVECT	(7 << 2)
#define	IN1BUF_USBVECT	(8 << 2)
#define	OUT1BUF_USBVECT	(9 << 2)
#define	IN2BUF_USBVECT	(10 << 2)
#define	OUT2BUF_USBVECT	(11 << 2)
#define	IN3BUF_USBVECT	(12 << 2)
#define	OUT3BUF_USBVECT	(13 << 2)
#define	IN4BUF_USBVECT	(14 << 2)
#define	OUT4BUF_USBVECT	(15 << 2)
#define	IN5BUF_USBVECT	(16 << 2)
#define	OUT5BUF_USBVECT	(17 << 2)
#define	IN6BUF_USBVECT	(18 << 2)
#define	OUT6BUF_USBVECT	(19 << 2)
#define	IN7BUF_USBVECT	(20 << 2)
#define	OUT7BUF_USBVECT	(21 << 2)

typedef struct
{
	BYTE	length;
	BYTE	type;
}DSCR;

typedef struct				// Device Descriptor
{
	BYTE	length;			// Descriptor length ( = sizeof(DEVICEDSCR) )
	BYTE	type;			// Decriptor type (Device = 1)
	BYTE	spec_ver_minor;	// Specification Version (BCD) minor
	BYTE	spec_ver_major;	// Specification Version (BCD) major
	BYTE	dev_class;		// Device class
	BYTE	sub_class;		// Device sub-class
	BYTE	protocol;		// Device sub-sub-class
	BYTE	max_packet;		// Maximum packet size
	WORD	vendor_id;		// Vendor ID
	WORD	product_id;		// Product ID
	WORD	version_id;		// Product version ID
	BYTE	mfg_str;		// Manufacturer string index
	BYTE	prod_str;		// Product string index
	BYTE	serialnum_str;	// Serial number string index
	BYTE	configs;		// Numder of configurations
}DEVICEDSCR;

typedef struct
{
	BYTE	length;			// Configuration length ( = sizeof(CONFIGDSCR) )
	BYTE	type;			// Descriptor type (Configuration = 2)
	WORD	config_len;		// Configuration + End Points length
	BYTE	interfaces;		// Number of interfaces
	BYTE	index;			// Configuration number
	BYTE	config_str;		// Configuration string
	BYTE	attrib;			// Attributes (b7 - buspwr, b6 - selfpwr, b5 - rwu
	BYTE	power;			// Power requirement (div 2 ma)
}CONFIGDSCR;

typedef struct
{
	BYTE	length;			// Interface descriptor length ( - sizeof(INTRFCDSCR) )
	BYTE	type;			// Descriptor type (Interface = 4)
	BYTE	index;			// Zero-based index of this interface
	BYTE	alt_setting;	// Alternate setting
	BYTE	ep_cnt;			// Number of end points
	BYTE	class;			// Interface class
	BYTE	sub_class;		// Interface sub class
	BYTE	protocol;		// Interface sub sub class
	BYTE	interface_str;	// Interface descriptor string index
}INTRFCDSCR;

typedef struct
{
	BYTE	length;			// End point descriptor length ( = sizeof(ENDPNTDSCR) )
	BYTE	type;			// Descriptor type (End point = 5)
	BYTE	addr;			// End point address
	BYTE	ep_type;		// End point type
	BYTE	mp_L;			// Maximum packet size
	BYTE	mp_H;
	BYTE	interval;		// Interrupt polling interval
}ENDPNTDSCR;

typedef struct
{
	BYTE	length;			// String descriptor length
	BYTE	type;			// Descriptor type
}STRINGDSCR;

typedef struct
{
	BYTE	cntrl;			// End point control register
	BYTE	bytes;			// End point buffer byte count
}EPIOC;

typedef struct
{
	BYTE	length;
	BYTE	*dat;
	BYTE	count;
	BYTE	status;
}I2CPCKT;



/*-----------------------------------------------------------------------------
	Global Variables
	The Ez-USB registers are defined here.
-----------------------------------------------------------------------------*/

xdata volatile BYTE at	0x7B40	 OUT7BUF[64]  	;
xdata volatile BYTE at	0x7B80	 IN7BUF[64]  	;
xdata volatile BYTE at	0x7BC0	 OUT6BUF[64]  	;
xdata volatile BYTE at	0x7C00	 IN6BUF[64]  	;
xdata volatile BYTE at	0x7C40	 OUT5BUF[64]  	;
xdata volatile BYTE at	0x7C80	 IN5BUF[64]  	;
xdata volatile BYTE at	0x7CC0	 OUT4BUF[64]  	;
xdata volatile BYTE at	0x7D00	 IN4BUF[64]  	;
xdata volatile BYTE at	0x7D40	 OUT3BUF[64]  	;
xdata volatile BYTE at	0x7D80	 IN3BUF[64]  	;
xdata volatile BYTE at	0x7DC0	 OUT2BUF[64]  	;
xdata volatile BYTE at	0x7E00	 IN2BUF[64]  	;
xdata volatile BYTE at	0x7E40	 OUT1BUF[64]  	;
xdata volatile BYTE at	0x7E80	 IN1BUF[64]  	;
xdata volatile BYTE at	0x7EC0	 OUT0BUF[64]  	;
xdata volatile BYTE at	0x7F00	 IN0BUF[64]  	;
xdata volatile BYTE at	0x7F60	 OUT8DATA  	;
xdata volatile BYTE at	0x7F61	 OUT9DATA  	;
xdata volatile BYTE at	0x7F62	 OUT10DATA  	;
xdata volatile BYTE at	0x7F63	 OUT11DATA  	;
xdata volatile BYTE at	0x7F64	 OUT12DATA  	;
xdata volatile BYTE at	0x7F65	 OUT13DATA  	;
xdata volatile BYTE at	0x7F66	 OUT14DATA  	;
xdata volatile BYTE at	0x7F67	 OUT15DATA  	;
xdata volatile BYTE at	0x7F68	 IN8DATA  	;
xdata volatile BYTE at	0x7F69	 IN9DATA  	;
xdata volatile BYTE at	0x7F6A	 IN10DATA  	;
xdata volatile BYTE at	0x7F6B	 IN11DATA  	;
xdata volatile BYTE at	0x7F6C	 IN12DATA  	;
xdata volatile BYTE at	0x7F6D	 IN13DATA  	;
xdata volatile BYTE at	0x7F6E	 IN14DATA  	;
xdata volatile BYTE at	0x7F6F	 IN15DATA  	;
xdata volatile BYTE at	0x7F70	 OUT8BCH  	;
xdata volatile BYTE at	0x7F71	 OUT8BCL  	;
xdata volatile BYTE at	0x7F72	 OUT9BCH  	;
xdata volatile BYTE at	0x7F73	 OUT9BCL  	;
xdata volatile BYTE at	0x7F74	 OUT10BCH  	;
xdata volatile BYTE at	0x7F75	 OUT10BCL  	;
xdata volatile BYTE at	0x7F76	 OUT11BCH  	;
xdata volatile BYTE at	0x7F77	 OUT11BCL  	;
xdata volatile BYTE at	0x7F78	 OUT12BCH  	;
xdata volatile BYTE at	0x7F79	 OUT12BCL  	;
xdata volatile BYTE at	0x7F7A	 OUT13BCH  	;
xdata volatile BYTE at	0x7F7B	 OUT13BCL  	;
xdata volatile BYTE at	0x7F7C	 OUT14BCH  	;
xdata volatile BYTE at	0x7F7D	 OUT14BCL  	;
xdata volatile BYTE at	0x7F7E	 OUT15BCH  	;
xdata volatile BYTE at	0x7F7F	 OUT15BCL  	;
xdata volatile BYTE at	0x7F90	 SPARE1  	;
xdata volatile BYTE at	0x7F91	 SPARE2  	;
xdata volatile BYTE at	0x7F92	 CPUCS  	;
xdata volatile BYTE at	0x7F93	 PORTACFG  	;
xdata volatile BYTE at	0x7F94	 PORTBCFG  	;
xdata volatile BYTE at	0x7F95	 PORTCCFG  	;
xdata volatile BYTE at	0x7F96	 OUTA	;
xdata volatile BYTE at	0x7F97	 OUTB	;
xdata volatile BYTE at	0x7F98	 OUTC	;
xdata volatile BYTE at	0x7F99	 PINSA  	;
xdata volatile BYTE at	0x7F9A	 PINSB  	;
xdata volatile BYTE at	0x7F9B	 PINSC  	;
xdata volatile BYTE at	0x7F9C	 OEA	;
xdata volatile BYTE at	0x7F9D	 OEB	;
xdata volatile BYTE at	0x7F9E	 OEC	;
xdata volatile BYTE at	0x7F9F	 SPARE3  	;
xdata volatile BYTE at	0x7FA0	 ISOERR  	;
xdata volatile BYTE at	0x7FA1	 ISOCTL  	;
xdata volatile BYTE at	0x7FA2	 ZBCOUT  	;
xdata volatile BYTE at	0x7FA3	 ZBCIN  	;
xdata volatile BYTE at	0x7FA4	 SPARE4  	;
xdata volatile BYTE at	0x7FA5	 I2CS	;
xdata volatile BYTE at	0x7FA6	 I2DAT  	;
xdata volatile BYTE at	0x7FA7	 SPARE5  	;
xdata volatile BYTE at	0x7FA8	 IVEC	;
xdata volatile BYTE at	0x7FA9	 IN07IRQ  	;
xdata volatile BYTE at	0x7FAA	 OUT07IRQ  	;
xdata volatile BYTE at	0x7FAB	 USBIRQ  	;
xdata volatile BYTE at	0x7FAC	 IN07IEN  	;
xdata volatile BYTE at	0x7FAD	 OUT07IEN  	;
xdata volatile BYTE at	0x7FAE	 USBIEN  	;
xdata volatile BYTE at	0x7FAF	 USBBAV  	;
xdata volatile WORD at	0x7FB0	 AVADDR  	;
xdata volatile WORD at	0x7FB2	  BPADDR  	;
xdata volatile BYTE at	0x7FB3	 BPADDRL  	;
xdata volatile EPIOC at	0x7FB4	 EPIO[16]  	;
xdata volatile BYTE at	0x7FD4	 SUDPTRH  	;
xdata volatile BYTE at	0x7FD5	 SUDPTRL  	;
xdata volatile BYTE at	0x7FD6	 USBCS  	;
xdata volatile BYTE at	0x7FD7	 TOGCTL  	;
xdata volatile BYTE at	0x7FD8	 USBFRAMEL  	;
xdata volatile BYTE at	0x7FD9	 USBFRAMEH  	;
xdata volatile BYTE at	0x7FDA	 SPARE6  	;
xdata volatile BYTE at	0x7FDB	 FNADDR  	;
xdata volatile BYTE at	0x7FDC	 SPARE7  	;
xdata volatile BYTE at	0x7FDD	 USBPAIR  	;
xdata volatile BYTE at	0x7FDE	 IN07VAL  	;
xdata volatile BYTE at	0x7FDF	 OUT07VAL  	;
xdata volatile BYTE at	0x7FE0	 INISOVAL  	;
xdata volatile BYTE at	0x7FE1	 OUTISOVAL  	;
xdata volatile BYTE at	0x7FE2	 FASTXFR  	;
xdata volatile BYTE at	0x7FE3	 AUTOPTRH  	;
xdata volatile BYTE at	0x7FE4	 AUTOPTRL  	;
xdata volatile BYTE at	0x7FE5	 AUTODATA  	;
xdata volatile BYTE at	0x7FE6	 SPARE8  	;
xdata volatile BYTE at	0x7FE7	 SPARE9  	;
xdata volatile BYTE at	0x7FE8	 SETUPDAT[8]  	;
xdata volatile BYTE at	0x7FF0	 OUT8ADDR  	;
xdata volatile BYTE at	0x7FF1	 OUT9ADDR  	;
xdata volatile BYTE at	0x7FF2	 OUT10ADDR  	;
xdata volatile BYTE at	0x7FF3	 OUT11ADDR  	;
xdata volatile BYTE at	0x7FF4	 OUT12ADDR  	;
xdata volatile BYTE at	0x7FF5	 OUT13ADDR  	;
xdata volatile BYTE at	0x7FF6	 OUT14ADDR  	;
xdata volatile BYTE at	0x7FF7	 OUT15ADDR  	;
xdata volatile BYTE at	0x7FF8	 IN8ADDR  	;
xdata volatile BYTE at	0x7FF9	 IN9ADDR  	;
xdata volatile BYTE at	0x7FFA	 IN10ADDR  	;
xdata volatile BYTE at	0x7FFB	 IN11ADDR  	;
xdata volatile BYTE at	0x7FFC	 IN12ADDR  	;
xdata volatile BYTE at	0x7FFD	 IN13ADDR  	;
xdata volatile BYTE at	0x7FFE	 IN14ADDR  	;
xdata volatile BYTE at	0x7FFF	 IN15ADDR  	;



/*-----------------------------------------------------------------------------
	Special Function Registers (sfr at 0xs)
	The byte registers and bits defined in the following list are based
	on the Synopsis definition of the 8051 Special Function Registers for EZ-USB.
    If you modify the register definitions below, please regenerate the file
    "ezregs.inc" which includes the same basic information for assembly inclusion.
-----------------------------------------------------------------------------*/

sfr at 0x81 SP		;   // Stack Pointer
sfr at 0x82 DPL		;   // Data Pointer Low
sfr at 0x83 DPH		;		// Data Pointer High
sfr at 0x84 DPL1	;
sfr at 0x85 DPH1	;
sfr at 0x86 DPS		;
	/*  DPS  */
sbit at 0x86 SEL	;


/*  PCON  */
sfr at 0x87 PCON;
sbit at 0x87 IDLE;
sbit at 0x88 STOP;
sbit at 0x89 GF0;
sbit at 0x9A GF1;
sbit at 0x9B SMOD0;

/*  TCON  */
sfr at 0x88 TCON	;
sbit at 0x88 IT0;
sbit at 0x89 IE0;
sbit at 0x8A IT1;
sbit at 0x8B IE1;
sbit at 0x8C TR0;
sbit at 0x8D TF0;
sbit at 0x8E TR1;
sbit at 0x8F TF1;

/*  TMOD  */
sfr at 0x89 TMOD;
	//sbit at 0x M00    = 0x89+0;
	//sbit at 0x M10    = 0x89+1;
	//sbit at 0x CT0    = 0x89+2;
	//sbit at 0x GATE0  = 0x89+3;
	//sbit at 0x M01    = 0x89+4;
	//sbit at 0x M11    = 0x89+5;
	//sbit at 0x CT1    = 0x89+6;
	//sbit at 0x GATE1  = 0x89+7;
sfr at 0x8A TL0;
sfr at 0x8B TL1;
sfr at 0x8C TH0;
sfr at 0x8D TH1;

/*  CKCON  */
sfr at 0x8E CKCON;
sbit at 0x8E MD0;
sbit at 0x8F MD1;
sbit at 0x90 MD2;
sbit at 0x91 T0M;
sbit at 0x92 T1M;
sbit at 0x93 T2M;

sfr at 0x8F SPC_FNC; // Was WRS in Reg320
	/*  CKCON  */
	//sbit at 0x WRS    = 0x8F+0;
sfr at 0x91 EXIF; // EXIF Bit Values differ from Reg320
	/*  EXIF  */
	//sbit at 0x USBINT = 0x91+4;
	//sbit at 0x I2CINT = 0x91+5;
	//sbit at 0x IE4    = 0x91+6;
	//sbit at 0x IE5    = 0x91+7;
sfr at 0x92 MPAGE;

/*  SCON0  */
sfr at 0x98 SCON0;
sbit at 0x98 RI;
sbit at 0x99 TI;
sbit at 0x9A RB8;
sbit at 0x9B TB8;
sbit at 0x9C REN;
sbit at 0x9D SM2;
sbit at 0x9E SM1;
sbit at 0x9F SM0;

sfr at 0x99 SBUF0;
sfr at 0xA8 IE;
	/*  IE  */
	sbit at 0xA8 EX0;
	sbit at 0xA9 ET0;
	sbit at 0xAA EX1;
	sbit at 0xAB ET1;
	sbit at 0xAC ES0;
	sbit at 0xAD ET2;
	sbit at 0xAE ES1;
	sbit at 0xAF EA;

/*  IP  */
sfr at 0xB8 IP;
sbit at 0xB8 PX0;
sbit at 0xB9 PT0;
sbit at 0xBA PX1;
sbit at 0xBB PT1;
sbit at 0xBC PS0;
sbit at 0xBD PT2;
sbit at 0xBE PS1;


sfr at 0xC0 SCON1;
	/*  SCON1  */
	sbit at 0xC0 RI1;
	sbit at 0xC1 TI1;
	sbit at 0xC2 RB81;
	sbit at 0xC3 TB81;
	sbit at 0xC4 REN1;
	sbit at 0xC5 SM21;
	sbit at 0xC6 SM11;
	sbit at 0xC7 SM01;
sfr at 0xC1 SBUF1;
sfr at 0xC8 T2CON;
	/*  T2CON  */
	sbit at 0xC8 CP_RL2;
	sbit at 0xC9 C_T2;
	sbit at 0xCA TR2;
	sbit at 0xCB EXEN2;
	sbit at 0xCC TCLK;
	sbit at 0xCD RCLK;
	sbit at 0xCE EXF2;
	sbit at 0xCF TF2;
sfr at 0xCA RCAP2L;
sfr at 0xCB RCAP2H;
sfr at 0xCC TL2;
sfr at 0xCD TH2;
sfr at 0xD0 PSW;
	/*  PSW  */
	sbit at 0xD0 P;
	sbit at 0xD1 FL;
	sbit at 0xD2 OV;
	sbit at 0xD3 RS0;
	sbit at 0xD4 RS1;
	sbit at 0xD5 F0;
	sbit at 0xD6 AC;
	sbit at 0xD7 CY;
sfr at 0xD8 EICON; // Was WDCON in DS80C320; Bit Values differ from Reg320
	/*  EICON  */
	sbit at 0xDB INT6;
	sbit at 0xDC RESI;
	sbit at 0xDE ERESI;
	sbit at 0xDF SMOD1;
sfr at 0xE0 ACC;
sfr at 0xE8 EIE; // EIE Bit Values differ from Reg320
  /*  EIE  */
	sbit at 0xE8 EUSB;
	sbit at 0xE9 EI2C;
	sbit at 0xEA EIEX4;
	sbit at 0xEB EIEX5;
	sbit at 0xEC EIEX6;
sfr at 0xF0 B;
sfr at 0xF8 EIP; // EIP Bit Values differ from Reg320
  /*  EIP  */
	sbit at 0xF8 PUSB;
	sbit at 0xF9 PI2C;
	sbit at 0xFA EIPX4;
	sbit at 0xFB EIPX5;
	sbit at 0xFC EIPX6;





/*-----------------------------------------------------------------------------
	Bit Masks
-----------------------------------------------------------------------------*/

/* CPU Control & Status Register */
#define bmCLK24OE		bmBIT1
#define bm8052RES		bmBIT0
/* Port Configuration Registers */
/* Port A */
#define bmRXD1OUT		bmBIT7
#define bmRXD0OUT		bmBIT6
#define bmFRD			bmBIT5
#define bmFWR			bmBIT4
#define bmCS			bmBIT3
#define bmOE			bmBIT2
#define bmT1OUT			bmBIT1
#define bmT0OUT			bmBIT0
/* Port B */
#define bmT2OUT			bmBIT7
#define bmINT6			bmBIT6
#define bmINT5			bmBIT5
#define bmINT4			bmBIT4
#define bmTXD1			bmBIT3
#define bmRXD1			bmBIT2
#define bmT2EX			bmBIT1
#define bmT2			bmBIT0
/* Port C */
#define bmRD			bmBIT7
#define bmWR			bmBIT6
#define bmT1			bmBIT5
#define bmT0			bmBIT4
#define bmINT1			bmBIT3
#define bmINT0			bmBIT2
#define bmTXD0			bmBIT1
#define bmRXD0			bmBIT0
/* Isochronous Status & End Point Valid Registers */
#define bmEP15			bmBIT7
#define bmEP14			bmBIT6
#define bmEP13			bmBIT5
#define bmEP12			bmBIT4
#define bmEP11			bmBIT3
#define bmEP10			bmBIT2
#define bmEP9			bmBIT1
#define bmEP8			bmBIT0
/* I2C Control & Status Register */
#define bmSTART			bmBIT7
#define bmSTOP			bmBIT6
#define bmLASTRD		bmBIT5
#define bmID			(bmBIT4 | bmBIT3)
#define bmBERR			bmBIT2
#define bmACK			bmBIT1
#define bmDONE			bmBIT0
/* Interrupt Vector Register */
#define bmIV4			bmBIT6
#define bmIV3			bmBIT5
#define bmIV2			bmBIT4
#define bmIV1			bmBIT3
#define bmIV0			bmBIT2
/* End point Interrupt Request, End Point Interrupt Enable */
/* And End Point Valid Registers */
#define bmEP7			bmBIT7
#define bmEP6			bmBIT6
#define bmEP5			bmBIT5
#define bmEP4			bmBIT4
#define bmEP3			bmBIT3
#define bmEP2			bmBIT2
#define bmEP1			bmBIT1
#define bmEP0			bmBIT0
/* Global Interrupt Request & Enable Registers */
#define bmURES			bmBIT4
#define bmSUSP			bmBIT3
#define bmSUTOK			bmBIT2
#define bmSOF			bmBIT1
#define bmSUDAV			bmBIT0
/* Global Control */
#define bmBREAK			bmBIT3
#define bmBPPULSE		bmBIT2
#define bmBPEN			bmBIT1
#define bmAVEN			bmBIT0
/* USB Control & Status Register */
#define bmRWAKEUP		bmBIT7
#define bmDISCON		bmBIT3
#define bmDISCOE		bmBIT2
#define bmRENUM			bmBIT1
#define bmSIGRESUME		bmBIT0
/* End Point 0 Control & Status Register */
#define bmOUT			bmBIT3
#define bmIN			bmBIT2
#define bmHS			bmBIT1
#define bmHSSTALL		bmBIT0
/* End Point Control & Status Registers */
#define bmEPSTALL		bmBIT0
#define bmEPBUSY		bmBIT1
/* Fast Transfer Register */
#define bmFISO			bmBIT7
#define bmFBLK			bmBIT6
#define bmRPOL			bmBIT5
#define bmRMOD1			bmBIT4
#define bmRMOD0			bmBIT3
#define bmWPOL			bmBIT2
#define bmWMOD1			bmBIT1
#define bmWMOD0			bmBIT0
/* Endpoint Pairing Register */
#define bmISOSEND0		bmBIT7
#define bmPR6OUT		bmBIT5
#define bmPR4OUT		bmBIT4
#define bmPR2OUT		bmBIT3
#define bmPR6IN			bmBIT2
#define bmPR4IN			bmBIT1
#define bmPR2IN			bmBIT0
/* End point control offsets */

/* What is this for? */
enum
{
	IN0BUF_ID = 0,
	IN1BUF_ID,
	IN2BUF_ID,
	IN3BUF_ID,
	IN4BUF_ID,
	IN5BUF_ID,
	IN6BUF_ID,
	IN7BUF_ID,
	OUT0BUF_ID,
	OUT1BUF_ID,
	OUT2BUF_ID,
	OUT3BUF_ID,
	OUT4BUF_ID,
	OUT5BUF_ID,
	OUT6BUF_ID,
	OUT7BUF_ID
};


/* What are these for? */
#define EP0CS	EPIO[0].cntrl
#define IN0BC	EPIO[0].bytes
#define IN1CS	EPIO[1].cntrl
#define IN1BC	EPIO[1].bytes
#define IN2CS	EPIO[2].cntrl
#define IN2BC	EPIO[2].bytes
#define IN3CS	EPIO[3].cntrl
#define IN3BC	EPIO[3].bytes
#define IN4CS	EPIO[4].cntrl
#define IN4BC	EPIO[4].bytes
#define IN5CS	EPIO[5].cntrl
#define IN5BC	EPIO[5].bytes
#define IN6CS	EPIO[6].cntrl
#define IN6BC	EPIO[6].bytes
#define IN7CS	EPIO[7].cntrl
#define IN7BC	EPIO[7].bytes
#define OUT0CS	EPIO[8].cntrl
#define OUT0BC	EPIO[8].bytes
#define OUT1CS	EPIO[9].cntrl
#define OUT1BC	EPIO[9].bytes
#define OUT2CS	EPIO[10].cntrl
#define OUT2BC	EPIO[10].bytes
#define OUT3CS	EPIO[11].cntrl
#define OUT3BC	EPIO[11].bytes
#define OUT4CS	EPIO[12].cntrl
#define OUT4BC	EPIO[12].bytes
#define OUT5CS	EPIO[13].cntrl
#define OUT5BC	EPIO[13].bytes
#define OUT6CS	EPIO[14].cntrl
#define OUT6BC	EPIO[14].bytes
#define OUT7CS	EPIO[15].cntrl
#define OUT7BC	EPIO[15].bytes

