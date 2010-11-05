// Toggle ezusbledtoggle

#include "ezusb.h"
#include <string.h>

// Prototypes
void delay( const long int DELAY );
void delay_short( const long int DELAY );
void ser_printString(char *String);
void printc(char c);
void TD_Init(void);


void TD_Init(void)
{
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


}


void printc(char c)
{
	delay(10000);
	SBUF0 = c;
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

void delay( const long int DELAY )
{
	int a,b = 0;
	for ( a = 0; a < DELAY; a++ );
	{
		// Doing nothing
		b = a;
	}
}

void delay_short( const long int DELAY )
{
	int a,b = 0;
	for ( a = 0; a < DELAY; a++ );
	{
		// Doing nothing
		b = a;
	}
}

void main()
{

	TD_Init();


	while (1)  // Begin infinite loop
	{
 		const long int DELAY = 10000; 
		OUTA = 0x00;
		//OUTB = 0x00;
		//OUTC = 0x00;
		delay(DELAY);
		OUTA = 0xff; // Set all portA to on
		//OUTB = 0xff;
		//OUTC = 0xff;
		delay(DELAY);
		
		SBUF0 = 'a';
	}// END 
}
