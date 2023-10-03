UNAME := $(shell uname)
CC = gcc

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

BASE_NAME = test_slice

PRE_CFLAGS = -E -P
PRE_IFLAGS = -I../../include/ -I../../objects/ -I. 
PRE_BASE_DIR = ./

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

all: build_test clean

build_classes: build_iteration build_slice

pp_iteration:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../interfaces/iteration.def.h -o $(current_dir)/iteration.h

build_iteration: pp_iteration
	$(CLEAN_SCRIPT) $(current_dir)/iteration.h

pp_slice:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../objects/slice.def.h -o $(current_dir)/slice.h

build_slice: pp_slice
	$(CLEAN_SCRIPT) $(current_dir)/slice.h

build_test: build_classes
	$(CC) $(CFLAGS) $(IFLAGS) ../../objects/slice.c $(BASE_NAME).c -o $(BASE_NAME)$(EXT)

clean:
	$(DEL_FILE) foobar.h iteration.h slice.h