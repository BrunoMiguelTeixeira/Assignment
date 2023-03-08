#ifndef FIFO_H
#define FIFO_H

/**
 * Fifo structure instantiation
 */
struct FIFO{
	int Size;
	int* values;
	int tail;
	int head;
	};

/**
 * Fifo Initialization
 */
int MyFIFOInit(void* fifo, int size);

int MyFIFOInsert(void* fifo, int val);

int MyFIFORemove(void* fifo);

int MyFIFOPeep(void* fifo);

int MyFIFOSize(void* fifo);


#endif
