#include<stdio.h>
#include<stdlib.h>


void enQueue(int**queue,int*size, int*rear,int data){
    *size+=1;
    *queue = realloc(*queue , (*size)*sizeof(int));
    *rear+=1;
    (*queue)[*rear] = data; 
}

void deQueue(int** queue, int*size, int*rear, int*front){
    if(*size == 0 || *rear == -1){
        printf("Your queue is empty\n");
        return;
    }
    printf("value %d is deQueueped\n",(*queue)[*front]);
    *front+=1;
    *size-=1;
    if(*size == 0){
        *rear = -1;
        *front = 0;
    }
}

void peek(int* queue, int size, int rear, int front){
    if(size == 0 || rear == -1){
        printf("Your queue is empty\n");
        return;
    }
    printf("Your first element is %d\n",(queue)[front]);
   
}


int main() {
	int rear = -1;
	int size = 0;
	int front = 0;

	int *queue = malloc(size*sizeof(int));

	printf("Choose a operation to perform:- \n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Peek\n");
	printf("4. Is Empty\n");
	printf("5. Size\n");
	printf("6. Exit\n");

	int exit_choice = 0;
	while(exit_choice == 0) {
		printf("\nEnter your choice:-");
		int choice;
		scanf("%d",&choice);

		switch (choice) {
		case 1:
			int data;
			printf("Enter the value to enQueue:- ");
			scanf("%d",&data);
			enQueue(&queue, &size, &rear,data);
			break;

		case 2:
			deQueue(&queue,&size,&rear,&front);
			break;


		case 3:
			peek(queue,size,rear,front);
			break;

		case 4:
			if(size == 0 || rear ==-1) {
				printf("Your queue is empty \n");
			}
			else {
				printf("Your queue have %d number of elements\n",size);
			}
			break;


		case 5:
			if(size == 0 || rear ==-1) {
				printf("Your queue is empty \n");
			}
			else {
				printf("Your queue is %d size\n",size);
			}
			break;

		case 6:
			printf("Exiting.... \n");
			exit_choice = 1;
			break;

		default:
			printf("Please enter a valid choice :)\n");
			break;
		}
	}

	return 0;


}
