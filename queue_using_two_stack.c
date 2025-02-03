#include <stdio.h>
#include <stdlib.h>

void Enqueue(int** stack1, int* size1, int* top1, int data) {
    *size1 += 1;
    *stack1 = realloc(*stack1, (*size1) * sizeof(int));
    *top1 += 1;
    (*stack1)[*top1] = data;
}

int Dequeue(int** stack1, int* size1, int* top1, int** stack2, int* size2, int* top2) {
    if (*size2 == 0) {
        if (*size1 == 0) {
            printf("Your queue is empty, nothing to dequeue\n");
            return -1;
        }
        while (*top1 != -1) {
            *size2 += 1;
            *stack2 = realloc(*stack2, (*size2) * sizeof(int));
            (*stack2)[*top2 + 1] = (*stack1)[*top1];
            *top2 += 1;
            *top1 -= 1;
            *size1 -= 1;
        }
    }
    int dequeuedElement = (*stack2)[*top2];
    *top2 -= 1;
    *size2 -= 1;
    return dequeuedElement;
}

void peek(int* stack1, int size1, int top1, int* stack2, int size2, int top2) {
    if (size2 == 0) {
        if (size1 == 0) {
            printf("Your queue is empty\n");
            return;
        }
        printf("Your front element is %d\n", stack1[0]);
    } else {
        printf("Your front element is %d\n", stack2[top2]);
    }
}

int main() {
    int size1 = 0, size2 = 0;
    int top1 = -1, top2 = -1;
    int* stack1 = malloc(size1 * sizeof(int));
    int* stack2 = malloc(size2 * sizeof(int));

    printf("Choose an operation to perform:- \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Is Empty\n");
    printf("5. Size\n");
    printf("6. Exit\n");

    int exit_choice = 0;
    while (exit_choice == 0) {
        printf("\nEnter your choice:- ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data;
                printf("Enter the value to enqueue:- ");
                scanf("%d", &data);
                Enqueue(&stack1, &size1, &top1, data);
                break;
            }
            case 2: {
                int dequeued = Dequeue(&stack1, &size1, &top1, &stack2, &size2, &top2);
                if (dequeued != -1) {
                    printf("Dequeued element:- %d\n", dequeued);
                }
                break;
            }
            case 3:
                peek(stack1, size1, top1, stack2, size2, top2);
                break;
            case 4:
                if (size1 == 0 && size2 == 0) {
                    printf("Your queue is empty\n");
                } else {
                    printf("Your queue has %d number of elements\n", size1 + size2);
                }
                break;
            case 5:
                if (size1 == 0 && size2 == 0) {
                    printf("Your queue is empty\n");
                } else {
                    printf("Your queue size is %d\n", size1 + size2);
                }
                break;
            case 6:
                printf("Exiting....\n");
                exit_choice = 1;
                break;
            default:
                printf("Please enter a valid choice :)\n");
                break;
        }
    }

    return 0;
}
