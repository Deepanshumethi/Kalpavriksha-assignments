#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
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

void reverse(node **head){
    node* prev = NULL;
    node*curr = *head;
    node * forw = NULL;
    while(curr != NULL){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    
    *head = prev;
}
void printLL(){
    node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int sumLastK(int k){
   
    reverse(&head);
   
    node *temp = head;
    int i=0;
    int sum = 0;
    while(i<k && temp != NULL){
        sum += temp->data;
        temp = temp->next;
        i++;
    }
    reverse(&head);
   
    return sum;
  
    
    
    
}



int main(){
    int n ;
    int k;
    scanf("%d", &n);
    scanf("%d", &k);
    int count = 0;
    int *arr = malloc(count*sizeof(int)); 
    int p;
    int j=0;
    getchar();
   
    for(int i=0;i<n;i++){
        char inp;
        scanf("%c",&inp);
        getchar();
        int ant;
        if(inp == 'A'){
            scanf("%d",&ant);
            getchar();
            addEnd(ant);
        }
        else if(inp == 'S'){
           
            count++;
            arr = (int*)realloc(arr,count*sizeof(int));
           p = sumLastK(k);
           arr[j++] = p;
       
        }
        else{
            printf("You entered wrong\n");
        }
       
    }
  
    
    for(int i=0;i<j;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
