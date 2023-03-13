#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIFO_SIZE 10
int err=0;

int MyFIFOInit(struct FIFO* fifo, int size)
{
	if((size<= 0)||(size>10))
		return err=-1;
	
	fifo->values =  (int*)malloc(size*sizeof(int));
	if (fifo->values == NULL){
		return err=-1;	
	}
	
	fifo->size = size;
	fifo->tail = 0;
	fifo->head = 0;
	fifo->count = 0;
	return err=0;
}

void MyFIFOInsert(struct FIFO*fifo, int val)
{
	if(MyFIFOSize(fifo)==fifo->size){
		err=-1;
		return;
	}

	fifo->values[fifo->head]=val;
	fifo->head = (fifo->head +1)% fifo->size;
	fifo->count=fifo->count+1;
	err=0;
}

void MyFIFORemove(struct FIFO* fifo)
{
	if(MyFIFOSize(fifo)==0){
		err=-1;
		return;
	}
	fifo->tail = (fifo->tail+1) % fifo->size;
	fifo->count=fifo->count-1;
	err=0;
}

int MyFIFOPeep(struct FIFO* fifo)
{	
	if (fifo->tail == fifo->head){
		return err=-1;
	}	
	err=0;	
	return fifo->values[fifo->tail];
}

int MyFIFOSize(struct FIFO* fifo)
{	
	return fifo->count;
}


