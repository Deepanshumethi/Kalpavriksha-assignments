#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node * next;
} node;

node *head = NULL;

void insertAtBeginning(int value) {
	node *newnode = NULL;
	newnode = malloc(sizeof(node));
	newnode->data = value;
	newnode->next = head;
	head = newnode;
}

void insertAtEnd(int value) {
	if(head == NULL) {
		insertAtBeginning(value);
		return;
	}
	node *newnode = NULL;
	newnode = malloc(sizeof(node));
	newnode->data = value;
	node *temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next= newnode;
	newnode->next = NULL;

// 	free(temp);
}


void insertAtPosition(int position, int value) {
    if(position<=0){
        printf("Enter a valid value for the position\n");
        return;
    }
	if(head == NULL) {
		printf("Your list is empty");
		return;
	}
	int pos = position;
	if(pos ==1) {
		insertAtBeginning(value);
		return;
	}
	node * newnode = NULL;
	newnode = malloc(sizeof(node));
	newnode->data = value;
	node *temp = head;

	for(int i=2; i<pos&&temp!=NULL; i++) {
		temp = temp->next;
	}
	if(temp == NULL) {
		printf("Enter a valid position to put value\n");
		// free(temp);
		return;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}


void updateAtPosition(int position, int value) {
    if(position<=0){
        printf("Enter a valid value for the position\n");
        return;
    }
	if(head == NULL) {
		printf("Your list is empty\n");
		return;
	}
	node *temp = head;
	for(int i=1; i<position&&temp!=NULL; i++) {
		temp = temp->next;
	}
	if(temp == NULL) {
		printf("Enter a valid position\n");
		return;
	}
	temp->data = value;

}

void deleteFromBeginning() {
	if(head == NULL) {
		printf("Nothing to delete from the list\n");
		return;
	}
	head = head->next;
}

void deleteAtEnd() {
	if(head == NULL) {
		printf("Nothing to delete from the list\n");
		return;
	}
	node *temp = head;

	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	temp->next = NULL;
}

void deleteAtPosition(int position) {
    if(position<=0){
        printf("Enter a valid value for the position\n");
        return;
    }
	if(head == NULL) {
		printf("Your list is already empty\n");
		return;
	}
	if(position == 1) {
		deleteFromBeginning();
		return;
	}
	node *temp = head;
	for(int i=2; i<position&&temp->next!=NULL; i++) {
		temp=temp->next;
	}
	if(temp != NULL || temp -> next != NULL || temp->next->next != NULL) {
		temp->next = temp->next->next;
		return;
	}
	else {
		printf("Enter a valid position\n");
	}

}


void display(node * head) {

	if(head == NULL) {
		printf("List is empty Nothing to print\n");
		return;
	}
	node * temp = head;



	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
// 	free(temp);
}

int main() {
	int no_of_statements;
	scanf("%d",&no_of_statements);
	if(no_of_statements<=0 || no_of_statements >100) {
		printf("Enter a valid count of Number of operations(1-100)");
		return 0;
	}
	// printf("%d",no_of_statements);

	for(int i=0; i<no_of_statements; i++) {
		int first_checker ;
		scanf("%d",&first_checker);

		switch(first_checker) {

		case 1:
			int valAddToEnd;
			scanf("%d",&valAddToEnd);
			insertAtEnd(valAddToEnd);
			break;
		case 2:
			int valAddToStart;
			scanf("%d",&valAddToStart);
			insertAtBeginning(valAddToStart);
			break;
		case 3:
			int position;
			int valueToAdd;
			scanf("%d", &position);
			scanf("%d", &valueToAdd);
			insertAtPosition(position,valueToAdd);
			break;

		case 4:
			display(head);
			break;

		case 5:
			int posi;
			int valueToUpdate;
			scanf("%d",&posi);
			scanf("%d",&valueToUpdate);
			updateAtPosition(posi,valueToUpdate);
			break;

		case 6:
			deleteFromBeginning();
			break;

		case 7:
			deleteAtEnd();
			break;

		case 8:
			int pos;
			scanf("%d",&pos);
			deleteAtPosition(pos);
			break;

		default:
			printf("Enter a valid number for the operation(1-8)");
			break;
		}
	}
	return 0;
}
