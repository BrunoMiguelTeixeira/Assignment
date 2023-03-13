#include <stdio.h>
#include "fifo.h"

extern int err;

int main(void){	
	int op, exit = 0;
	int noFifo;
	
	printf("No. of FIFO's to be created (max.5): ");
	fscanf(stdin,"%d",&noFifo);
	
	while((noFifo<1)||(noFifo>5))
	{
		printf("Invalid! No. of FIFO's to be created (max.5): ");
		fscanf(stdin,"%d",&noFifo);
	}
	
	struct FIFO fifo[noFifo];
	
	int size = 0;
	for(int i = 0; i < noFifo;i++)
	{
		printf("Size of fifo %d: ",i);
		fscanf(stdin,"%d",&size);
		MyFIFOInit(&fifo[i], size);
		if (err == -1)
		{
			printf("ERROR initializing fifo");
			return 0;
		}	
	}
	int working_fifo=1;
	int val;
	while(1){

		printf("\nTempering with FIFO nº%d!",working_fifo);
		printf("\n1-Insert Value\n2-Remove value\n3-Peep oldest value\n4-FIFO occupied space\n5- Change FIFO\nChoice: ");
		fscanf(stdin,"%d",&op);
		switch(op){
			case 1://insert
				printf("Value to insert: ");
				fscanf(stdin,"%d",&val);
				MyFIFOInsert(&fifo[working_fifo-1],val);
				if(err!=0){
					printf("FIFO is currently full and it is unable to insert a new value.\n");
					break;
				}
				printf("%d was added!\n",val);
				break;

			case 2://remove
				MyFIFORemove(&fifo[working_fifo-1]);
				if(err!=0){
					printf("FIFO is currently empty and it is unable to remove one value.\n");
					break;
				}
				printf("FIFO oldest value has been removed!\n");
				break;

			case 3://peep
				val=MyFIFOPeep(&fifo[working_fifo-1]);
				if(err!=0){
					printf("There hasnt been a value written yet!\n");
					break;
				}
				printf("Oldest FIFO value: %d\n",val);
				break;

			case 4://size
				printf("FIFO currently occupied space: %d\n",MyFIFOSize(&fifo[working_fifo-1]));
				break;

			case 5://change fifo
				printf("\nDesired FIFO: ");
				do{
					fscanf(stdin,"%d",&working_fifo);
				}while(working_fifo<1 || working_fifo>noFifo);
				break;

			default://leave
				return 0;
		}
	}

	return 0;
}


