rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CC = g++
CFLAGS = -O3

AR = ar

SRCDIR := src
OBJDIR := bin/obj

SRC = $(call rwildcard,$(SRCDIR),*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)

OUTFILE = bin/moldengine.a

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

build: $(OBJS)
	$(AR) -rsv $(OUTFILE) $(OBJS)