#!/bin/bash

vpath *.cpp .
vpath *.hpp .

BoostPath=../../boost_1_64_0

execution=example
CC=g++

${execution} : ${execution}.cpp
	${CC} $< -o $@

.PHONY: all clean distclean

all: ${execution}

clean:
	rm -rf ${execution}

distclean:
	rm -rf ${execution}
	
