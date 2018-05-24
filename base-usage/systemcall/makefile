
vpath .

objs = select.o socket.o 

CFLAGS= -std=c99

select: ${objs}
	gcc $^ -o $@

${objs} : %.o : %.c
	gcc -c ${CFLAGS} $< -o $@

.PHONY: clean

clean:
	rm *.o select
