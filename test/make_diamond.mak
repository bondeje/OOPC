UNAME := $(shell uname)
CC = gcc

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

BASE_NAME = diamond
DEFS = defs.h
TARGET_HEADER = $(current_dir)/classes.h

PRE_CFLAGS = -E -CC -P
PRE_IFLAGS = -I../include/

CLEAN_SCRIPT = 

CFLAGS = -Wall -pedantic -Wno-missing-braces
IFLAGS = -I../include/
LFLAGS = 

EXT = 

ifeq ($(UNAME), Linux)
	# STILL NEED TO MAKE A LINUX SCRIPT
else
	CLEAN_SCRIPT += ..\scripts\rep_nl_tab_win.bat
	EXT = .exe
endif

all: build_classes clean_sentinels build

build_classes: 
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) $(DEFS) -o $(TARGET_HEADER)

clean_sentinels:
	$(CLEAN_SCRIPT) $(TARGET_HEADER)

build: build_classes clean_sentinels
	$(CC) $(CFLAGS) $(IFLAGS) $(BASE_NAME).c -o $(BASE_NAME)$(EXT)