UNAME := $(shell uname)
CC = gcc

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

BASE_NAME = diamond
DEFS = defs.h
TARGET_HEADER = classes.h
TARGET_HEADER_FULL = $(current_dir)/$(TARGET_HEADER)

PRE_CFLAGS = -E -CC -P -DOOPC
PRE_IFLAGS = -I../../include/

CLEAN_SCRIPT = 

CFLAGS = -Wall -pedantic -Wno-missing-braces
IFLAGS = -I../../include/
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

all: build_classes clean_sentinels build 

#clean

build_classes: 
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) $(DEFS) -o $(TARGET_HEADER_FULL)

clean_sentinels:
	$(CLEAN_SCRIPT) $(TARGET_HEADER_FULL)

build: build_classes clean_sentinels
	$(CC) $(CFLAGS) $(IFLAGS) $(BASE_NAME).c -o $(BASE_NAME)$(EXT)

clean:
	$(DEL_FILE) .\$(TARGET_HEADER)