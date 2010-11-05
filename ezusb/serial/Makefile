VERSION = $(shell date +%Y_%m_%d)
RELEASE_NAME =	ezusbledtoggle-$(VERSION)

CC      =/usr/bin/sdcc
CFLAGS  ="-I."


all: ezusbledtoggle.ihx

ezusbledtoggle.ihx: ezusbledtoggle.c
#	Runs sdcc -I ezusbledtoggle.c
	$(CC) $(CFLAGS) $^

clean:
#	removes all the old compiled stuff
	rm -f [1-9] *.lnk *.asm *.lst *.map *.mem *.rel *.rst *.sym *.ihx *.tar.gz *.tar.bz2 


