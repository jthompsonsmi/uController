// Toggle ezusbledtoggle

#include "ezusb_reg.h"

void TD_Init(void)
{
// configure ports

PORTACFG = 0x00; // use all port A pins as IO
OEA = 0xff; // Set all port A pins as output

PORTBCFG = 0x00;
OEB = 0xff;

PORTCCFG = 0x00;
OEC = 0xff;

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

	while (1)
	{


 		const long int DELAY = 10000; 
		OUTA = 0x00;
		//OUTB = 0x00;
		//OUTC = 0x00;
		delay(DELAY);
		OUTA = 0xff;
		//OUTB = 0xff;
		//OUTC = 0xff;
		delay(DELAY);

	}
}
