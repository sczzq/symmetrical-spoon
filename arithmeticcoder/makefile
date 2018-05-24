CFLAGS=-std=c++11 -mrtd=cdecl

APP=arthcod

CC=g++

all: ArithmeticCoderC.o ModelI.o ModelOrder0C.o $(APP)

$(APP): ArithmeticCoderC.o ModelI.o ModelOrder0C.o main.cpp
	$(CC) $(LNFLAGS) $^ -o $@$(EXT)

ArithmeticCoderC.o: ArithmeticCoderC.cpp *.h 
	$(CC) $(CFLAGS) -c ArithmeticCoderC.cpp -o ArithmeticCoderC.o

ModelI.o: ModelI.cpp *.h
	$(CC) $(CFLAGS) -c ModelI.cpp -o ModelI.o

ModelOrder0C.o: ModelOrder0C.cpp *.h
	$(CC) $(CFLAGS) -c ModelOrder0C.cpp -o ModelOrder0C.o

