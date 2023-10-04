UNAME := $(shell uname)
CC = gcc

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

BASE_NAME = callable

PRE_CFLAGS = -E -P
PRE_IFLAGS = -I../../include/ -I../../templates/ -I../../interfaces/ -I. 
PRE_BASE_DIR = ./

CLEAN_SCRIPT = 

CFLAGS = -Wall -pedantic -Wno-missing-braces -Wno-unused-variable -std=c99
IFLAGS = -I../../include/ -I../../templates/ -I. 
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

build_classes: build_callable build_foobar

pp_callable:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../interfaces/callable.def.h -o $(current_dir)/callable.h

build_callable: pp_callable
	$(CLEAN_SCRIPT) $(current_dir)/callable.h

pp_foobar:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) $(current_dir)/foobar.def.h -o $(current_dir)/foobar.h

build_foobar: pp_foobar
	$(CLEAN_SCRIPT) $(current_dir)/foobar.h

build_test: build_classes
	$(CC) $(CFLAGS) $(IFLAGS) foobar.c $(BASE_NAME).c -o $(BASE_NAME)$(EXT)

clean:
	$(DEL_FILE) foobar.h callable.h