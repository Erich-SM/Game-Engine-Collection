PROG = rpc
CC = gcc

include common.mk

CXXFLAGS += `sdl2-config --cflags`
CXXFLAGS += -g -lefence -Iinclude

LDFLAGS += `sdl2-config --libs` -lm

# linking the program.
$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
