# Generation of executable 

main: main.o fifo.o
	gcc -o fifo main.o fifo.o

#generate fifo.o
fifo.o: fifo.c fifo.h 
	gcc -c fifo.c

#generate main.o
main.o: main.c
	gcc -c main.c

clean:
	rm *.o
