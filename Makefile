rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CC = g++
CFLAGS = -O3

AR = ar

SRCDIR := src
OBJDIR := bin/obj

SRC = $(call rwildcard,$(SRCDIR),*.cpp)
DIRS = $(wildcard $(SRCDIR)/*)

OUTFILE = bin/moldengine.a

build:
	$(CC) $(CFLAGS) $(SRC) -c -o engine.o 
	$(AR) -rsv $(OUTFILE) engine.o