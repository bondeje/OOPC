UNAME := $(shell uname)
CC = gcc

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

BASE_NAME = collection

PRE_CFLAGS = -E -P
PRE_IFLAGS = -I../../include/ -I. 
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
	CLEAN_SCRIPT += ..\..\scripts\rep_nl_tab.exe
	EXT = .exe
	DEL_FILE = del /f
endif

all: build_test clean

build_classes: build_initializable build_creatable build_sized build_container build_iteration build_collection build_foobar

pp_iteration:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../interfaces/iteration.def.h -o $(current_dir)/iteration.h

build_iteration: pp_iteration
	$(CLEAN_SCRIPT) $(current_dir)/iteration.h

pp_initializable:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../interfaces/initializable.def.h -o $(current_dir)/initializable.h

build_initializable: pp_initializable
	$(CLEAN_SCRIPT) $(current_dir)/initializable.h

pp_creatable:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../interfaces/creatable.def.h -o $(current_dir)/creatable.h

build_creatable: pp_creatable
	$(CLEAN_SCRIPT) $(current_dir)/creatable.h

pp_container:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../interfaces/container.def.h -o $(current_dir)/container.h

build_container: pp_container
	$(CLEAN_SCRIPT) $(current_dir)/container.h

pp_sized:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../interfaces/sized.def.h -o $(current_dir)/sized.h

build_sized: pp_sized
	$(CLEAN_SCRIPT) $(current_dir)/sized.h

pp_collection:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) ../../interfaces/collection.def.h -o $(current_dir)/collection.h

build_collection: pp_collection
	$(CLEAN_SCRIPT) $(current_dir)/collection.h

pp_foobar:
	$(CC) $(PRE_CFLAGS) $(PRE_IFLAGS) $(current_dir)/foobar.def.h -o $(current_dir)/foobar.h

build_foobar: pp_foobar
	$(CLEAN_SCRIPT) $(current_dir)/foobar.h

build_test: build_classes
	$(CC) $(CFLAGS) $(IFLAGS) $(BASE_NAME).c -o $(BASE_NAME)$(EXT)

clean:
	$(DEL_FILE) foobar.h collection.h sized.h container.h creatable.h initializable.h iteration.h