OUTFILE = hello
OUTDIR = $(HOME)/cmpt433/public/myApps

CROSS_COMPILE = arm-linux-gnueabihf-
CC_C = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror -Wshadow

all: app

app:
	$(CC_C) $(CFLAGS) hello.c output.c timer.c joystick.c led.c system.c -o $(OUTDIR)/$(OUTFILE)

clean:
	rm $(OUTDIR)/$(OUTFILE)
