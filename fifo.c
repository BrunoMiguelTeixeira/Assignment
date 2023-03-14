#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIFO_SIZE 10


int MyFIFOInit(struct FIFO* fifo, int size)
{
	if((size<= 0)||(size>MAX_FIFO_SIZE))
		return MAX_FIFO_SIZE + 1;
	
	fifo->values =  (int*)malloc(size*sizeof(int));
	if (fifo == NULL){
		return -1;	
	}
	
	fifo->size = size;
	fifo->tail = 0;
	fifo->head = 0;
	fifo->count = 0;
	return 0;
}

int MyFIFOInsert(struct FIFO*fifo, int val)
{
	
	if(fifo->head == fifo->tail && fifo->count==fifo->size){
		return -1;
	}
	fifo->values[fifo->tail] = val;
	fifo->tail = (fifo->tail + 1) % fifo->size;
	fifo->count = fifo->count + 1;
	return 0;
}

int MyFIFORemove(struct FIFO* fifo)
{
	if(fifo->head == fifo->tail && fifo->count== 0){
		return -1;
	}
	printf("\nValue removed: %d\n",fifo->values[fifo->head]);
	fifo->head = (fifo->head + 1) % fifo->size;
	fifo->count = fifo->count - 1;
	return 0;
}

int MyFIFOPeep(struct FIFO* fifo)
{	
	if (fifo->tail == fifo->head && fifo->count== 0){
		return -1;
	}
	printf("\nOldest element: %d\n", fifo->values[fifo->head]);
		
	return 0;
}

int MyFIFOSize(struct FIFO* fifo)
{	
	return fifo->count;
}

int MyFIFOResize(struct FIFO* fifo, int newsize)
{
	if((newsize<= 0)||(newsize>MAX_FIFO_SIZE)||newsize ==fifo->size)
		return MAX_FIFO_SIZE + 1;
	
	int* new_values;
	new_values =  (int*)realloc(fifo->values,newsize*sizeof(int));
	if (new_values == NULL){
		return -1;	
	}
	
	if(newsize <= fifo->size)
	{
	/*	printf("\nNEW SIZE SMALLER THAN CURRENT SIZR DATA MAY BE LOST\n");
		
		if(fifo->head>=newsize)
				fifo->head = 0;
		if(fifo->head>=newsize)
				fifo->head = newsize - 1;
		if(fifo->count>=newsize)
				fifo->count = newsize;
		fifo->size = newsize;
		fifo->values = new_values;*/
		
	}
	else{
	fifo->size = newsize;
	fifo->values = new_values;
	}
	return 0;
	
}

