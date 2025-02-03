#include<stdio.h>
#include<stdlib.h>


void enQueue(int**queue,int*size, int*rear,int data){
    *size = *size+1;
    // *queue = realloc(*queue , (*size)*sizeof(int));
    *rear+=1;
    (*queue)[*rear] = data; 
}

int deQueue(int** queue, int*size, int*rear, int*front){
    if(*size == 0 || *rear == -1){
        return -1;
    }
    int popped=(*queue)[*front];
    *front+=1;
    *size-=1;
    if(*size == 0){
        *rear = -1;
        *front = 0;
    }
    return popped;
}

void push(int**queue,int*size, int*rear,int*front,int data,int**tempQue,int*temp_size, int*temp_rear,int*temp_front){
     enQueue(queue, size, rear,data);
     
    for(int i=(*temp_front);i<=(*temp_rear);i++){
        int popped = deQueue(tempQue,temp_size,temp_rear,temp_front);
        if(popped == -1){
            break;
        }
        else{
            enQueue(queue, size, rear,popped);
        }
    }
    
    for(int i=(*front);i<=(*rear);i++){
        int popped = deQueue(queue,size,rear,front);
        if(popped == -1){
            break;
        }
        else{
            enQueue(tempQue, temp_size, temp_rear,popped);
        }
    }
   
    
    
    
   
}

int pop(int** queue, int*size, int*rear, int*front){
    int popped=deQueue( queue, size,rear,front);
    return popped;
}

void peek(int* queue, int size, int rear, int front){
    if(size == 0 || rear == -1){
        printf("Your stack is empty\n");
        return;
    }
    printf("Your first element is %d\n",(queue)[front]);
   
}


int main() {
	int rear = -1;
	int size = 0;
	int front = 0;

	int *queue = malloc(100*sizeof(int));
	
	
	int *tempQue = malloc(100*sizeof(int));
    int temp_front = 0;
    int temp_rear = -1;
    int temp_size = 0;
    
   

	printf("Choose a operation to perform:- \n");
	printf("1. push\n");
	printf("2. pop\n");
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
			printf("Enter the value to push:- ");
			scanf("%d",&data);
			push(&queue, &size, &rear,&front,data,&tempQue,&temp_size,&temp_rear,&temp_front);
			break;

		case 2:
			int popped=pop(&tempQue,&temp_size,&temp_rear,&temp_front);
			if(popped==-1){
			    printf("Your stack is empty\n");
			}
			else{
			    printf("Popped the value %d on top of the stack\n",popped);
			}
			break;


		case 3:
			peek(tempQue,temp_size,temp_rear,temp_front);
			break;

		case 4:
			if(temp_size == 0 || temp_rear ==-1) {
				printf("Your stack is empty \n");
			}
			else {
				printf("Your stack have %d number of elements\n",temp_size);
			}
			break;


		case 5:
			if(temp_size == 0 || temp_rear ==-1) {
				printf("Your stack is empty \n");
			}
			else {
				printf("Your stack is %d size\n",temp_size);
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
