#include <stdio.h>
#include "fifo.h"


int main(void){	
	
	int op, exit = 0;
	int noFifo, new_size, err;
	
	printf("No. of FIFO's to be created (max.5): ");
	scanf("%d",&noFifo);
	
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
		int init_err = MyFIFOInit(&fifo[i], size);
		if (init_err != 0)
		{
			printf("ERROR initializing fifo %d ",init_err);
			if (init_err == ERR_SIZE)
			{
				printf("Size error\n");
			}
			return 0;
		}	
	}
	
	int working_fifo=1;
	int val;
	while(exit!=1){

		printf("\nTempering with FIFO nº%d!",working_fifo);
		printf("\n1-Insert Value\n");
		printf("2-Remove value\n");
		printf("3-Peep oldest value\n");
		printf("4-FIFO occupied space\n");
		printf("5- Change FIFO\n");
		printf("6- Resize FIFO\n");
		printf("7- Exit\n");
		printf("Choice: ");
		
		fscanf(stdin,"%d",&op);
		
		switch(op){
			case 1://insert
				printf("Value to insert: ");
				fscanf(stdin,"%d",&val);
				if(MyFIFOInsert(&fifo[working_fifo-1],val) != 0){
					printf("FIFO is currently full and it is unable to insert a new value.\n");
				}
				else{
				printf("%d was added!\n",val);
				}
				break;

			case 2://remove
				if(MyFIFORemove(&fifo[working_fifo-1]) != 0){
					printf("FIFO is currently empty and it is unable to remove one value.\n");
				}
				else{
				printf("FIFO oldest value has been removed!\n");
				}
				break;

			case 3://peep
				if(MyFIFOPeep(&fifo[working_fifo-1])!=0){
					printf("There hasnt been a value written yet!\n");
				}
				break;

			case 4://size
				printf("FIFO currently occupied space: %d\n",MyFIFOSize(&fifo[working_fifo-1]));
				break;

			case 5://change fifo
				printf("\nDesired FIFO: ");
				fscanf(stdin,"%d",&working_fifo);
				while(working_fifo<1 || working_fifo>noFifo){
					printf("Non existing fifo!\n Desired FIFO: ");
					fscanf(stdin,"%d",&working_fifo);
				};
				break;
				
			case 6://resize
				printf("\nDesired size: ");
				fscanf(stdin,"%d",&new_size);
				MyFIFOResize(&fifo[working_fifo-1],new_size);
				break;

			case 7://leave
				exit = 1;
				for(int i = 0; i < noFifo;i++)
				{
				MyFIFOEnd(&fifo[i]);
				}
				break;
				
			default:
				printf("Invalid Option!");
				break;
		}
	}

	return 0;
}


