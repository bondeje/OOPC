UNAME := $(shell uname)
CC = gcc

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

BASE_NAME = diamond
DEFS = defs.h
TARGET_HEADER = classes.h
TARGET_HEADER_FULL = $(current_dir)/$(TARGET_HEADER)

PRE_CFLAGS = -E -P
PRE_IFLAGS = -I../../include/ -I.

CLEAN_SCRIPT = 

CFLAGS = -Wall -pedantic -Wno-missing-braces -Wno-unused-variable -std=c99
IFLAGS = -I../../include/ -I.
LFLAGS = 

EXT = 

DEL_FILE =

ifeq ($(UNAME), Linux)
	# STILL NEED TO MAKE A LINUX SCRIPT
else
	CLEAN_SCRIPT += ..\..\scripts\rep_nl_tab_win.bat
	EXT = .exe
	DEL_FILE = del /f
endif

all: build clean

build_classes: build_i build_defs

pp_i:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) i.def.h -o $(current_dir)/i.h

build_i: pp_i
	$(CLEAN_SCRIPT) $(current_dir)/i.h

pp_classes:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) classes.def.h -o $(current_dir)/classes.h

build_defs: pp_classes
	$(CLEAN_SCRIPT) $(current_dir)/classes.h

build: build_classes
	$(CC) $(CFLAGS) $(IFLAGS) $(BASE_NAME).c -o $(BASE_NAME)$(EXT)

clean:
	$(DEL_FILE) i.h classes.h
