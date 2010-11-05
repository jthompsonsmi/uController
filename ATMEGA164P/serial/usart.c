/*********************************************
* Chip type           : ATmega164p
* Clock frequency     : 8,000,000 MHz

avrdude.conf

programmer
  id    = "ft232r";
  desc  = "FT232R Synchronous BitBang";
  type  = ft245r;
  miso  = 3;  # CTS
  sck   = 5;  # DSR
  mosi  = 6;  # DCD
  reset = 7;  # RI
;

*********************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <stdint.h>

#define F_CPU 8000000UL  // 8 MHz
#include <util/delay.h>

#define xtal 8000000
#define baud 9600

int main(void)
{
        char c;

        DDRA = 0xFF;
        DDRB = 0xFF;
        DDRC = 0xFF;
        DDRD = 0xFF;    
        

        uint32_t temp;
        temp = xtal/16/baud-1;
        UBRR0H = (temp >> 8);
        UBRR0L = (temp & 0xFF);

        UCSR0B = (1 << RXEN0) | (1 << TXEN0);

        UCSR0C = (3 <<UCSZ00);

        while(1)
        {       

                
                
                while((UCSR0A & (1<<RXC0)) == 0);

                c =     UDR0;
                
			         
                while(!(UCSR0A & (1<<UDRE0)));

                UDR0 = c;       
                

        };

        return 0;
}

