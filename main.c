#include <stdio.h>
#include "fifo.h"


int main(void){
	printf("Hello\n");	
	return 0;
	struct FIFO* fifo[2];
	
	for(int i = 0; i < 2; i++)
	{
			MyFIFOInit(fifo[i],2);
	}
	
}


