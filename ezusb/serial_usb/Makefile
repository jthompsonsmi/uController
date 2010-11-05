VERSION = $(shell date +%Y_%m_%d)
RELEASE_NAME =	ezusbserial-$(VERSION)

CC      =/usr/bin/sdcc
CFLAGS  ="-I."


all: ezusbserial.ihx

ezusbserial.ihx: ezusbserial.c
#	Runs sdcc -I ezusbserial.c
	$(CC) $(CFLAGS) ezusbserial.c

clean:
#	removes all the old compiled stuff
	rm -f [1-9] *.lnk *.asm *.lst *.map *.mem *.rel *.rst *.sym *.ihx *.tar.gz *.tar.bz2 


