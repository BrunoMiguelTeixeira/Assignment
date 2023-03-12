#include <stdio.h>
#include "fifo.h"


int main(void){	
	int op, exit = 0;
	int noFifo;
	
	printf("No. of FIFO's to be created (max.5): ");
	scanf("%d",&noFifo);
	
	while((noFifo<1)||(noFifo>5))
	{
		printf("Invalid! No. of FIFO's to be created (max.5): ");
		scanf("%d",&noFifo);
	}
	
	struct FIFO fifo[noFifo];
	
	int size = 0;
	for(int i = 0; i < noFifo;i++)
	{
		printf("Size of fifo %d: ",i);
		scanf("%d",&size);
		int err = MyFIFOInit(&fifo[i], size);
		if (err == -1)
		{
			printf("ERROR initializing fifo");
			return 0;
		}	
	}
	
	
	
	return 0;
}


