#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum {
	GENERAL = 0,
	SENIOR_CITIZEN=1,
	VIP=2
} passenger_type;

typedef struct node {
	passenger_type type;
	int id;
	char name[50];
} node;


void enqueue(node** queue,int *size, int*rear,int*front,int id,char type[15], char name[50]) {

	if (strcmp(type, "GENERAL") == 0) {
	    (*rear)++;
		(*queue)[*rear].type = GENERAL;
	} else if (strcmp(type, "SENIOR_CITIZEN") == 0) {
	    (*rear)++;
		(*queue)[*rear].type = SENIOR_CITIZEN;
	} else if (strcmp(type, "VIP") == 0) {
	    (*rear)++;
		(*queue)[*rear].type = VIP;
	} else {
		printf("Invalid passenger type.\n");
		return;
	}

	(*size)++;
	(*queue)[(*rear)].id = id;
	strcpy((*queue)[(*rear)].name, name);
//bubble sort
	for(int i=*front; i<(*rear); i++) {
		for(int j=i+1; j<=(*rear); j++) {
			if((*queue)[i].type<(*queue)[j].type) {
				node temp = (*queue)[j];
				(*queue)[j] = (*queue)[i];
				(*queue)[i] = temp;
			}
		}
	}
}

void dequeue(node**queue,int*size,int*front,char priority[][15]){
    if((*size)==0){
        printf("Queue is empty\n");
        return;
    }
    printf("Serving Passenger:ID:%d , Name:%s, Type:%s \n",(*queue)[*front].id,(*queue)[*front].name,priority[(*queue)[*front].type]);
    *front = *front+1;
    *size = *size-1;
}

void printQueue(node* queue, int size, int front,char priority[][15], int rear) {
	if(size == 0) {
		printf("Queue is empty\n");
		return;
	}
printf("Waiting Passangers:\n");
	for (int i = front; i <= rear; i++) {
        printf("ID: %d, Name: %s, Type: %s\n", queue[i].id, priority[queue[i].type], queue[i].name);
    }
}

int main() {
	int query_count;
	printf("Enter the number of operations: ");
	scanf("%d",&query_count);
	char priority[3][15] = {"GENERAL","SENIOR_CITIZEN","VIP"};
	node*queue = malloc(query_count*sizeof(node));
	int rear = -1;
	int size = 0;
	int front = 0;	
	int iterator = 0;
	while(iterator<query_count) {
		int choice;
		scanf("%d",&choice);
		switch (choice) {
		case 1: {
			int id;
			char type[15];
			char name[50];
			scanf(",%d,%[^,],\"%[^\"]\";", &id, type, name);
			enqueue(&queue,&size,&rear,&front,id,type,name);
			break;
		}
		case 2:
			dequeue(&queue,&size,&front,priority);
			break;
		case 3:
			printQueue(queue,size,front,priority,rear);
			break;
		default:
			printf("Please enter a valid choice :)\n");
			break;
		}
		iterator++;
	}
	return 0;
}
