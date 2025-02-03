#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
} node;

void push(node**stack_ll,int*size, int*top,int data){
    node* newEntry = malloc(sizeof(node));
    newEntry->data = data;
    newEntry->next = (*stack_ll);
    *stack_ll = newEntry;
    *size+=1;
    *top+=1;
}

void pop(node** stack_ll, int*size,int*top){
    if(*size==0 || *top == -1){
        printf("Your stack is empty\n");
        return;
    }
    printf("value %d is popped\n",(*stack_ll)->data);
    *stack_ll =( *stack_ll)->next;
    *top-=1;
    *size-=1;
}
void peek(node* stack_ll, int size,int top){
    if(size==0 || top == -1){
        printf("Your stack is empty\n");
        return;
    }
    printf("Your top element is %d\n",stack_ll->data);
    
}

int main() {
	int size = 0;
	int top = -1;
	node* stack_ll = malloc(sizeof(node));
	stack_ll->next = NULL;


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
			push(&stack_ll, &size, &top,data);
			break;

		case 2:
			pop(&stack_ll,&size,&top);
			break;


		case 3:
			peek(stack_ll,size,top);
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
