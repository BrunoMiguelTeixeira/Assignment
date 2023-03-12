#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIFO_SIZE 10

int MyFIFOInit(struct FIFO* fifo, int size)
{
	if((size<= 0)||(size>10))
		return -1;
	
	fifo->values =  (int*)malloc(size*sizeof(int));
	if (fifo->values == NULL){
		return -1;	
	}
	
	fifo->size = size;
	fifo->tail = 0;
	fifo->head = 0;
	return 0;
}

int MyFIFOInsert(struct FIFO*fifo, int val);

int MyFIFORemove(struct FIFO* fifo);

int MyFIFOPeep(struct FIFO* fifo)
{	
	if (fifo->tail == fifo->head){
		printf("Fifo is Empty!/n");
	}	
		
	return fifo->values[fifo->head];
}

int MyFIFOSize(struct FIFO* fifo)
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


