#include<stdio.h>
#include<stdlib.h>
void push(int** stack,int *size, int* top,int data) {
	*size +=1;
	*stack = realloc(*stack,(*size)*sizeof(int));
	*top +=1;
	(*stack)[*top] = data;
}

void pop(int **stack, int* size, int *top) {
	if(*size == 0 || *top == -1) {
		printf("Your stack is empty nothing to pop\n");
		return;
	}

	printf("value %d is popped\n",(*stack)[*top]);
	*size -=1;
	*top -=1;
	return;
}

void peek(int*stack,int size,int top) {
	if(size == 0 || top == -1) {
		printf("Your stack is empty \n");
		return;
	}

	printf("Your top element is %d\n",stack[top]);
}

int main() {


	int size = 0;
	int top = -1;
	int *stack = malloc(size*sizeof(int));

printf("-: Stack implementation uing array :- \n");
	printf("Choose a operation to perform:- \n");
	printf("1. Push\n");
	printf("2. Pop\n");
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
			push(&stack, &size, &top,data);
			break;

		case 2:
			pop(&stack,&size,&top);
			break;


		case 3:
			peek(stack,size,top);
			break;

		case 4:
			if(size == 0 || top ==-1) {
				printf("Your stack is empty \n");
			}
			else {
				printf("Your stack have %d number of elements\n",size);
			}
			break;


		case 5:
			if(size == 0 || top ==-1) {
				printf("Your stack is empty \n");
			}
			else {
				printf("Your stack is %d size\n",size);
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
