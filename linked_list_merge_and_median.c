#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
} node;


int getLength(node* head) {
	node* temp = head;
	int count = 0;
	while(temp!= NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

node* findMiddle(node* head) {
	if (head == NULL || head->next == NULL) return head;
	node* slow = head;
	node* fast = head->next;

	while(fast != NULL && fast->next!= NULL) {
		slow= slow->next;
		fast= fast->next->next;
	}
	return slow;
}

node* mergetwoSortedArr(node* first, node * second) {
	node* dummyNode = malloc(sizeof(node));
	dummyNode->next = NULL;
	node* dummyPointer = dummyNode;
	node* left = first;
	node* right = second;

	while(left!= NULL && right != NULL) {
		if(left->data < right->data) {
			dummyPointer->next = left;
			left = left->next;
		}
		else {
			dummyPointer->next = right;
			right = right->next;
		}
		dummyPointer = dummyPointer->next;
	}

	while(left != NULL) {
		dummyPointer->next = left;
		left = left->next;
		dummyPointer = dummyPointer->next;
	}

	while(right != NULL) {
		dummyPointer->next = right;
		right = right->next;
		dummyPointer = dummyPointer->next;
	}

	return dummyNode->next;

}

node* mergeSort(node* head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}

	node* middle = findMiddle(head);
	node * left = head;
	node* right = middle->next;
	middle->next=NULL;
	left = mergeSort(left);
	right = mergeSort(right);

	return mergetwoSortedArr(left,right);
}

void addAtEnd(node* head, int input) {
	node* newNode = malloc(sizeof(node));
	newNode->data = input;
	newNode->next = NULL;
	if(head->next == NULL) {
		head->next = newNode;
		head = head->next;
		return;
	}
	node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next  = newNode;
}

int main() {
	node* head1 = malloc(sizeof(node));
	head1->next = NULL;
	node* head2 = malloc(sizeof(node));
	head2->next = NULL;
	int input;
	printf("Enter Yout first list data seprated by spaces:- ");
	while(scanf("%d",&input) == 1) {
		addAtEnd(head1,input);
		if(getchar() == '\n') {
			break;
		}
	}
	printf("Enter Yout second list data seprated by spaces:- ");
	while(scanf("%d",&input) == 1) {
		addAtEnd(head2,input);
		if(getchar() == '\n') {
			break;
		}
	}
	node* newHead1 = mergeSort(head1->next);
	node * newHead2 = mergeSort(head2->next);
	node* finalList = mergetwoSortedArr(newHead1,newHead2);
	node* temporary = finalList;
	printf("Merged list:- ");
	while(temporary != NULL){
	    printf("%d ", temporary->data);
	    temporary = temporary->next;
	}
	printf("\n");
	int length = getLength(finalList);
    printf("Median:- ");
	if(length%2 != 0) {
		node* middleOfFinal = findMiddle(finalList);
		printf("%d",middleOfFinal->data);
	}
	else {
		node* firstMiddle = findMiddle(finalList);
		float result = (firstMiddle->data + firstMiddle->next->data)/2.0;
		printf("%.2f",result);
	}
	return 0;

}
