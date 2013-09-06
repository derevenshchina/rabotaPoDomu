#DEBUG = -03
DEBUG = 
CC = gcc
INCLUDE  = -I/usr/local/include
CFLAGS = $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS = -L/usr/local/lib
LDLIBS = -lwiringPi -lwiringPiDev -lpthread -lm

SRC	= interruptTest.c \
			interruptTestNoReport.c

OBJ	= $(SRC:.c=.o)

BINS	= $(SRC:.c=.exe)

all: $(BINS)

interruptTest.exe: interruptTest.o
	@echo [link]
	@$(CC) -o $@ interruptTest.o $(LDFLAGS) $(LDLIBS)

interruptTestNoReport.exe: interruptTestNoReport.o
	@echo [link]
	@$(CC) -o $@ interruptTestNoReport.o $(LDFLAGS) $(LDLIBS)

.c.o:
	@echo [CC] $<
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "[Clean]"
	@rm -f $(OBJ) *~ core tags $(BINS)

tags: $(SRC)
	@echo [ctags]
	@ctags $(SRC)
