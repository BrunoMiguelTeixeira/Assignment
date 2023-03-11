
#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

int MyFIFOInit(void* fifo, int size)
{
	fifo->values = (void*)malloc(size*sizeof(int));
	if (fifo->values == NULL){
		return -1;	
	}
	
	fifo->size = size;
	fifo->tail = 0;
	fifo->head = 0;
	return 0;
}

int MyFIFOInsert(void*fifo, int val);

int MyFIFORemove(void* fifo);

int MyFIFOPeep(void* fifo)
{	
	if (fifo->tail == fifo->head){
		printf("Fifo is Empty!/n");
		return -99;
	}	
		
	return fifo->Values[head];
}

int MyFIFOSize(void* fifo)
{	
	int fifoSize = 0;
	if (fifo->head < fifo->tail){
			fifoSize = fifo->tail - fifo->head;
	}
	else{
		fifoSize = -(fifo->tail - fifo->head);
		}
		
	return fifoSize;
}


