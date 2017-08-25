CC  ?= gcc

BINS = codelib

RM = rm -f

SRC  = $(wildcard src/*.c)
DEPS = $(wildcard deps/*/*.c)
OBJS = $(DEPS:.c=.o)

CFLAGS = -std=c99 -Ideps -Wall

all: $(BINS)

$(BINS): $(SRC) $(OBJS)
	$(CC) $(CFLAGS) -o $@ src/$(@).c $(OBJS) 

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	$(foreach c, $(BINS), $(RM) $(c);)
	$(RM) $(OBJS)

.PHONY: all clean
