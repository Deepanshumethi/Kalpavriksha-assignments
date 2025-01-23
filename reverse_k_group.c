#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next; 
}node;

node*head = NULL;

void addEnd(int value){
    node* newnode  = malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    
    if(head == NULL){
        head = newnode;
        return;
    }
    
    node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    
}

void printLinkedList(node* h){
    node *temp = h;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


node* solve(node** head , int k){
    node* current = *head;
    node* next;
    node* prev = NULL;
    
    int count = 0;
    while(current != NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    if(*head != NULL){
        (*head)->next = current;
    }
    
    count = 0;
    while(current!= NULL && count<k-1){
        current = current->next;
        count++;
    }
    
    if(current != NULL){
        current->next = solve(&current->next,k);
       
    }
     return prev;
}

int main(){
    int ch;
   while(scanf("%d",&ch)==1){
        addEnd(ch);
       if(getchar() == '\n'){
           break;
       }
   }
   
//   printLL(head);
  
   int k;
   printf("enter k:-");
   scanf("%d",&k);
   
    node * result = solve(&head,k);
    
    printLinkedList(result);
    
    
   
    return 0;
}
