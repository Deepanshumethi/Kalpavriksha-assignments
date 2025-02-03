#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} node;

void enQueue(node **rear, int data)
{
	node *newEntry = malloc(sizeof(node));
	newEntry->next = NULL;
	newEntry->data = data;
	(*rear)->next = newEntry;
	(*rear) = newEntry;
}

void deQueue(node **queue_ll, node **rear, node **front)
{
	if (*rear == NULL && *rear == *front)
	{
		printf("Your queue is empty\n");
		return;
	}
	printf("value %d is deQueueped\n", (*queue_ll)->data);
	*queue_ll = (*queue_ll)->next;
	*front = *queue_ll;
}

void peek(node *rear, node *front)
{
	if (rear == NULL && rear == front)
	{
		printf("Your queue is empty\n");
		return;
	}

	printf("Yout front element is %d\n", front->data);
	return;
}
int main()
{

	node *queue_ll = malloc(sizeof(node));
	queue_ll->next = NULL;
	node *rear = queue_ll;
	node *front = queue_ll;

	printf("Choose a operation to perform:- \n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Peek\n");
	printf("4. Is Empty\n");
	printf("5. Size\n");
	printf("6. Exit\n");

	int exit_choice = 0;
	while (exit_choice == 0)
	{
		printf("\nEnter your choice:-");
		int choice;
		scanf("%d", &choice);
		int data;
		switch (choice)
		{
		case 1:

			printf("Enter the value to enQueue:- ");
			scanf("%d", &data);
			enQueue(&rear, data);
			break;

		case 2:
			deQueue(&queue_ll->next, &rear->next, &front->next);
			break;

		case 3:
			peek(rear->next, front->next);
			break;

		case 4:
			if (rear->next == NULL && rear->next == front->next)
			{
				printf("Your queue is empty \n");
			}
			else
			{
				int size;
				node *temp = front->next;
				while (temp != NULL)
				{
					size++;
					temp = temp->next;
				}
				printf("Your queue have %d number of elements\n", size);
			}
			break;

		case 5:
			if (rear->next == NULL && rear->next == front->next)
			{
				printf("Your queue is empty \n");
			}
			else
			{
				int size;
				node *temp = front->next;
				while (temp != NULL)
				{
					size++;
					temp = temp->next;
				}
				printf("Your queue have %d number of elements\n", size);
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
