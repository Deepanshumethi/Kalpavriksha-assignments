#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct patients{
    int id;
    char situation[10];
    struct patients*next;
    int index;
}patients;


void addEnd(patients** head, int id_input, char* situation_input,int index){
    patients * newpatient  =malloc(sizeof(patients));
    newpatient->next = NULL;
    newpatient->id = id_input;
    newpatient->index = index;
    // newpatient->situation = situation_input;
    strcpy(newpatient->situation,situation_input);
    if(*head == NULL){
        *head = newpatient;
        return;
    }
    
    patients* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newpatient;
    
    
}

patients* sortThem(patients* head){
    patients* store = head;
    patients* temp = store;
    patients* result = malloc(sizeof(patients));
    result->next = NULL;
    patients* pointer = result;
    while(temp!= NULL){
        if(temp->index == 0){
            printf("Critical\n");
            pointer->next = temp;
            
             pointer = pointer->next;
            
        }
        temp=temp->next;
    }
    temp = store;
    while(temp!= NULL){
        if(temp->index==1){
             printf("Serious\n");
            pointer->next = temp;
             
               pointer = pointer->next;
            
        }
        temp=temp->next;
    }
    
    temp = store;
    while(temp!= NULL){
        if(temp->index==2){
             printf("Stable\n");
            pointer->next = temp;
            
            pointer = pointer->next;
            
        }
        temp=temp->next;
    }
    // printf("id   %s", result->next->situation);
    return result;
    
    
}


int main(){
    
    int number;
    scanf("%d",&number);
      patients* head = NULL;
    
    // patients *list = malloc(number*sizeof(number));
    for(int i=0;i<number;i++){
        int id_input;
        scanf("%d",&id_input);
        // list[i].id = id_input;
        getchar();
        char* situation_input;
        scanf("%s",situation_input);
        // strcpy(list[i].situation,situation_input);
        if(strcmp(situation_input,"Critical")==0){
            // printf("true");
             addEnd(&head,id_input,situation_input,0);
            continue;
        }
        if(strcmp(situation_input,"Serious")==0){
            // printf("true");
             addEnd(&head,id_input,situation_input,1);
            continue;
        }
       if(strcmp(situation_input,"Stable")==0){
            // printf("true");
             addEnd(&head,id_input,situation_input,2);
            continue;
        }
    }
    
  
  
  
//   while(temp != NULL){
//       printf("%d %s\n",temp->id,temp->situation);
//       temp=temp->next;
//   }
  
  
  head = sortThem(head);
//   printf("%s",head->situation);
    patients* temp = head->next;
    //  temp = head;
  int count = 1;
  while(temp != NULL){
      
      printf("%d  %d %s\n",count, temp->id,temp->situation);
      count++;
      temp=temp->next;
  }
    
    

    
    
    
    return 0;
}
