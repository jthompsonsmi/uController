// Toggle ezusbledtoggle

#include "ezusb.h"
// #include "usb.h"
#include <string.h>

// Globals  // This may crash device
//unsigned char xdata ser_txBuffer[0x100];
//unsigned char xdata ser_rxBuffer[0x100];

//static bit ser_txBusy;
 unsigned char pin_status[3];

// Prototypes
void delay( const long int DELAY );
void delay_short( const long int DELAY );
void ser_printString(char *String);
void printc(char c);
void TD_Init(void);
void toggle_ep1buf(void);
static void ReEnum(void);
void sendserial( char *msg);

void TD_Init(void)
{
	
	/* disable USB interrupts */
	EUSB = 0;
	
	// configure ports
	
	PORTACFG = 0x00; // use all port A pins as IO
	PORTACFG = ( 6 << 1);
	OEA = 0xff; // Set all port A pins as output
	
	PORTBCFG = 0x00;
	OEB = 0xff;
	
	//Start Serial Configuration

        //Disable Serial Ints
        //ES0 = FALSE;

	//PORTCCFG = 0x00;
	PORTCCFG |= 3;
        SM0 = 0; SM1 = 1;    // Mode 1
        SM2 = 1;              // RI on valid STOP only
        REN = 1;              // Receive Enabled


        // Timer 2 setup
        TCLK = 1;               // Use the Timer 2 for the Tx clk
        RCLK = 1;               // Use the Timer 2 for the Rx clk
        C_T2 = 0;               // Use it as a timer, not counter
        TH2 = 0xFF;             // Set the counter to reload soon
        TL2 = 0xFF;
        //RCAP2H = 0xFF;                // 19.2kHz
        //RCAP2L = 0xD9;
        RCAP2H = 0xFF; RCAP2L = 0xB2;           // 9.6kHz
        TR2 = 1;                // Start the Timer 2 running
        TI = 0;         // Clear the transmit flag

	
	// Timer setup 
	// TMOD = 10 00 10 00
	TMOD = 0x20;
	//Setup serial
	// scon 0101 just the first four config bits
	// the last four bits are operational
	SCON0 = 0x50; // mode 1
	
	//PCON = ( 1 << 7 );  // serial port rate double
	//T1M = 1;	//clk source
	
	// TH0 = 256 - ((Crystal / 384) / Baud)
	// TH0 = 256 - ((24000000 / 384) / 115200)
	//TH0 = 255; // set timer BAUD rate 115200
	TH0 = 0xd9; // set timer BAUD rate to 9600
	TH1 = 0xff;

        //ES0 = TRUE;             // Enable serial interrupt.
        //Enable Interrupts
        //EA = 1;

	EUSB = 1;

}

void toggle_ep1buf(void)
{
    char i, j;                  // Variables for saving EP1OUTBC and counting
    i = 0;                      // Initializing i
//    j = EP1OUTBC;               // Saving EP1OUTBC to j
    j = OUT1BC;
    while (i < j)               // While still being beneath the actual data in
    {
        // EP1INBUF[i] = EP1OUTBUF[(j - 1) - i];
        // EP1OUTBUF, we move the data from i to maximum-i
	IN1BUF[i] = IN1BUF[(j-1)-1];
        i++;   // so anything gets turned upside down. Data is
    }          // take from EP1OUTBUF and written to EP1INBUF
    // EP1INCS = EP1INCS & (0xff - bmEPSTALL);
    IN1CS = IN1CS & (0xff - bmEPSTALL );
    // Reset STALL bits, just to be sure...
    //EP1OUTCS = EP1OUTCS & (0xff - bmEPSTALL);
    OUT1CS = OUT1CS & (0xff - bmEPSTALL);
    //EP1INBC = j;                // Arm endpoint 1 for in and out transfers
    IN1BC = j;
    //EP1OUTBC = 0x40;
    OUT1BC = 0x40;
}

void toggle_ep0buf(void)
{
    char i, j;                  // Variables for saving EP1OUTBC and counting
    i = 0;                      // Initializing i
//    j = EP1OUTBC;               // Saving EP1OUTBC to j
    j = OUT0BC;
    while (i < j)               // While still being beneath the actual data in
    {
        // EP1INBUF[i] = EP1OUTBUF[(j - 1) - i];
        // EP1OUTBUF, we move the data from i to maximum-i
	IN0BUF[i] = 'l';
        i++;   // so anything gets turned upside down. Data is
    }          // take from EP1OUTBUF and written to EP1INBUF
    // EP1INCS = EP1INCS & (0xff - bmEPSTALL);
    // IN0CS = IN0CS & (0xff - bmEPSTALL );
    // Reset STALL bits, just to be sure...
    //EP1OUTCS = EP1OUTCS & (0xff - bmEPSTALL);
    // OUT0CS = OUT0CS & (0xff - bmEPSTALL);
    //EP1INBC = j;                // Arm endpoint 1 for in and out transfers
    // IN0BC = j;
    //EP1OUTBC = 0x40;
    // OUT0BC = 0x40;
}

void printc(char c)
{
	if ( TI )
	{
		SBUF0 = c;
		TI = 0;
	}
}


void ser_printString(char *String)
{
	int index = 0;

  while (*String)
        {
                //ser_putc(*String++);
		printc(*String + index);
		index = index + 1;
        }
}

/****************************************************
* setup_usb_int( * Setup the USB inetrrupts
****************************************************/
static void setup_usb_int(void){

EA          = 0;    /* disable global interrupts */
USBBAV      = 0x00;    /* clear autovectoring and break reporting*/
USBIRQ      = 0xFF; /* enable SUDAV interrupt and all other interrupts */
USBIEN      = 0x11; /* enable SUDAV interrupt and RESET interrupt */
IN07IRQ     = 0xFF; /* clear all interrupts */
IN07IEN     = 0x15; /* enable IN0 IN2 IN4 interrupt */

OUT07IRQ    = 0xFF; /* clear all interrupts */
OUT07IEN    = 0x03; /* enable OUT0 OUT1 interrupt */

OUT1CS      = 0x00; /* unstall endpoint OUT 1 */
IN2CS       = 0x00; /* unstall endpoint IN  2 */
IN4CS       = 0x00; /* unstall endpoint IN  4 */

IN07VAL     = 0x15; /* endpoint IN 0 IN2 IN4 */
OUT07VAL    = 0x03; /* endpoint OUT 0 OUT 1 */

EUSB        = 1;    /* enable USB interrupt */
EA          = 1;    /* enable global interrupts */

}

static void SpinDelay(unsigned int count)
{
	while(count > 0) count -=1;
}

// pulls in chars to make command string
static void checkcommand( char inchar )
{
	const int MAXSIZE = 8;
	int charindex = 0;
	char *command[8];
	// FIXME char *command[MAXSIZE]; //error 2: Initializer element is not constant

	while ( charindex < (MAXSIZE - 1) )
	{
		if ( RI ){
			if ( '\r' != inchar )
			{
				*command[charindex] = inchar;
				charindex = charindex + 1;
				//sendserial(&"nocharreturn");
			}
			else
			{
				sendserial(&"found command: ");
				sendserial(*command);
				sendserial(&"\n\r\n\r");
				charindex = MAXSIZE + 1;
			}
		}// END if RI
		SBUF0 = inchar; // echo char
		RI = 0;
	}
	charindex = 0;
	
}

static void ReEnum(void)
{
	USBCS &= ~0x04;
	USBCS |= 0x08;
	USBCS |= 0x02;
	SpinDelay(10000);
	USBCS &= ~0x08;
	USBCS |= 0x04;
}

void readports()
{
	pin_status[0] = PINSA;
	pin_status[1] = PINSB;
	pin_status[2] = PINSC;
}

void sendserial( char *msg)
{
	int count = 7, i = 0;
	for ( i ; i < count; i++) 
	{
		SpinDelay(1000);
		SBUF0 = msg[i];
	}
}

void main()
{

	TD_Init();
	setup_usb_int();
	// ReEnum();
	//sendserial(&"Serial Port is loaded\n");

	while (1)  // Begin infinite loop
	{

	char inchar;
	int charindex = 0;
	char *command[8];

	//readports();
	//SBUF0 = pin_status[0];


		OUTA = 0x00;
		//OUTA = (1 << 5);
		//OUTB = 0x00;
		//OUTC = 0x00;
		SpinDelay(1000);
		OUTA = 0xff; // Set all portA to on
		//OUTB = 0xff;
		//OUTC = 0xff;
		//delay(DELAY);

		// toggle_ep0buf();

	if ( RI ) //Check recieve char
	{

		OUTA = (1 << 5);
		inchar = SBUF0;
		RI = 0;
		if ( '\r' != inchar )
		{
			SBUF0 = inchar;
			*command[charindex] = inchar;
			charindex = charindex + 1;
		} 
		else
		{
			// *command[charindex]
			charindex = 0;
			sendserial(&"\ncommand: OK\n"); // This comes out only partly
			sendserial(command); // This comes out as garbage
			sendserial(&"\n");
		}
		//SBUF0 = inchar;
		//checkcommand(inchar);

	}

        if (!(OUT1CS & bmEPBUSY))     // Wait for EP1OUTBUF having data and
        {
		SBUF0 = ';';
		if (!(IN1CS & bmEPBUSY))
                toggle_ep1buf();
            // EP1INBUF to be read for there is nothing overwritten
        }   // If both Buffers are ready, call toggle_ep1buf
		//ser_printString("Hello Rosely");
// 		if ( RI )
// 		{
// 			inchar = SBUF0;
// 		//	SBUF0 = inchar;
// 			printc = inchar;
// 			RI = 0;
// 		}
		//SBUF0 = 'a';
/*		if ( in2buf ) // if data found at End Point 0
		{
			SBUF0 = 'c';
		}// END if in2buf
		else if ( in4buf )
		{
			SBUF0 = 'b';
		}*/
// 		else if ( RBUF0 )
// 		{
// 			SBUF0 = RBUF0;
// 		}
		//SCON = ( 0 << 1 ); // clear the serial transmit buffer
		//SBUF0 = 'z'; // send z to serial port
// 		while ((( SCON0 & ( 1 << 1) >> 1 )) == 1) //Check pin 1 equals 1
// 		{
// 			//waiting for serial output buffer to clear
// 			
// 		}
	}// END 
}
