vpath %.c src
vpath %.c .
vpath %.h include
vpath %.cpp src
vpath %.cpp .

client = client
server = server

clientg = clientdebug
serverg = serverdebug

message = message.hpp
custom = custom.hpp

CC=g++
CPPFLAG=-std=c++11 -lpthread -O2
srcsuffix=cpp

${client} : ${client}.${srcsuffix} ${custom} ${message}
	${CC} ${CPPFLAG} $^ -o $@

${server} : ${server}.${srcsuffix} ${custom} ${message}
	${CC} ${CPPFLAG} $^ -o $@

${clientg} : ${client}.${srcsuffix} ${custom} ${message}
	${CC} -g ${CPPFLAG} $^ -o $@

${serverg} : ${server}.${srcsuffix} ${custom} ${message}
	${CC} -g ${CPPFLAG} $^ -o $@

.PHONY: all clean distclean debug

all: ${server} ${client}

debug: ${serverg} ${clientg}

clean:
	rm ${client} ${server} ${clientg} ${serverg} -rf

distclean: clean
	rm *.o -rf


