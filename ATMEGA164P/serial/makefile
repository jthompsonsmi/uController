MCU=atmega164p
CC=avr-gcc
OBJCOPY=avr-objcopy
# optimize for size:
CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -mcall-prologues
#-------------------
all: usart.hex
#-------------------
usart.hex : usart.out 
	$(OBJCOPY) -R .eeprom -O ihex usart.out usart.hex 
usart.out : usart.o 
	$(CC) $(CFLAGS) -o usart.out -Wl,-Map,usart.map usart.o 
usart.o : usart.c 
	$(CC) $(CFLAGS) -Os -c usart.c
# you need to erase first before loading the program.
# load (program) the software into the eeprom:
load_compat: usart.hex
	avrdude -C /etc/avrdude.conf -c ft232r -p atmega164p -B 1 -P ft0 -U flash:w:usart.hex
load: usart.hex
	avrdude -C /etc/avrdude.conf -c ft232r -p atmega164p -P ft0 -U flash:w:usart.hex
rfuse: usart.hex
	avrdude -C /etc/avrdude.conf -c ft232r -p atmega164p -B 1 -P ft0 -U hfuse:r:fuses_high.txt:r -U lfuse:r:fuses_low.txt:r
whfuse: usart.hex
	avrdude -C /etc/avrdude.conf -c ft232r -p atmega164p -B 1 -P ft0 -U hfuse:w:0x99:m
#-------------------
clean:
	rm -f *.o *.map *.out
#-------------------

