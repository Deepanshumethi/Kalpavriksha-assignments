#include<stdio.h>
#include<stdlib.h>
void Enqueue(int** stack,int *size, int* top,int data) {
	*size +=1;
	*stack = realloc(*stack,(*size)*sizeof(int));
	*top +=1;
	(*stack)[*top] = data;
}

int Dequeue(int **stack, int* size, int *top) {
	if(*size == 0 || *top == -1) {
		printf("Your queue is empty nothing to dequeue\n");
		return -1;
	}
	if(*top == 0) {
		int popped = (*stack)[*top];
		(*size) -=1;
		*top -=1;
		return popped;
	}
	
	int topElement = (*stack)[*top];
    *top -= 1;
    int dequeuedElement = Dequeue(stack, size, top);
    *top += 1;
    (*stack)[*top] = topElement;

    return dequeuedElement;
	
	
// 	return;
}

void peek(int*stack,int size,int top) {
	if(size == 0 || top == -1) {
		printf("Your queue is empty \n");
		return;
	}

	printf("Your top element is %d\n",stack[0]);
}

int main() {


	int size = 0;
	int top = -1;
	int *stack = malloc(size*sizeof(int));

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
			printf("Enter the value to enqueue:- ");
			scanf("%d",&data);
			Enqueue(&stack, &size, &top,data);
			break;

		case 2:
		int popped =Dequeue(&stack,&size,&top);
		if(popped!=-1){
		    printf("Dequeued element:- %d\n",popped);
		}
			break;


		case 3:
			peek(stack,size,top);
			break;

		case 4:
			if(size == 0 || top ==-1) {
				printf("Your queue is empty \n");
			}
			else {
				printf("Your queue have %d number of elements\n",size);
			}
			break;


		case 5:
			if(size == 0 || top ==-1) {
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
