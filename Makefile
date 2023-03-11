# This is a comment
# Generate application

main: main.o fifo.o
	gcc -o fifo main.o fifo.o

#generate part1.o
fifo.o: fifo.c fifo.h
	gcc -c fifo.c

#generate main.o
main.o: main.c
	gcc -c main.c

clean:
	rm *.o
