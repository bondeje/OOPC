UNAME := $(shell uname)
CC = gcc

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

BASE_NAME = rep_nl_tab

CFLAGS = -Wall -pedantic -Wno-missing-braces -Wno-unused-variable -std=c99
IFLAGS = 
LFLAGS = 

EXT = 

ifeq ($(UNAME), Linux)
	# STILL NEED TO MAKE A LINUX SCRIPT
else
	EXT = .exe
endif

all: build

build: rep_nl_tab.c
	$(CC) $(CFLAGS) $(IFLAGS) $(BASE_NAME).c -o ../$(BASE_NAME)$(EXT)

