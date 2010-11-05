VERSION = $(shell date +%Y_%m_%d)
RELEASE_NAME =	ezusbjtag-$(VERSION)

CC      =/usr/bin/sdcc
CFLAGS  ="-I."


all: ezusbjtag.ihx

ezusbjtag.ihx: ezusbjtag.c
#	Runs sdcc -I ezusbjtag.c
	$(CC) $(CFLAGS) ezusbjtag.c

clean:
#	removes all the old compiled stuff
	rm -f [1-9] *.lnk *.asm *.lst *.map *.mem *.rel *.rst *.sym *.ihx *.tar.gz *.tar.bz2 


