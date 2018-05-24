LDFLAGS=
CFLAGS=

OBJS=number.o driver.o

TARGET=test

CC:=gcc

${TARGET}: ${OBJS}
	${CC} $^ -o ${TARGET}

.PHONE: ${TARGET}

clean:
	rm number.o driver.o test
