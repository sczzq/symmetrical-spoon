vpath %.c src
vpath %.h include

client = client
server = server

CC=gcc

${client} : ${client}.o ${client}.h
	${CC} $< -o $@

${server} : ${server}.o ${server}.h
	${CC} $< -o $@

${client}.o : ${client}.c ${client}.h
	${CC} $< -o $@

${server}.o : ${server}.c ${server}.h
	${CC} $< -o $@

.PHONY: all clean distclean

all: ${server} ${client}

clean:
	rm ${client} ${server} -rf

distclean: clean
	rm *.o -rf


