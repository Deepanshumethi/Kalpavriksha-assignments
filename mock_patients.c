#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patients {
	int id;
	char situation[10];
	struct patients *next;
	int index;
} patients;

typedef struct map {
	int id;
} map;

int checkid(map mapper[],int id,int count) {
	for(int i=0; i<count; i++) {
		if(mapper[i].id == id) {
			return 1;
		}
	}
	return 0;
}

void addEnd(patients **head, int id_input, char *situation_input, int index) {
	patients *newpatient = malloc(sizeof(patients));
	newpatient->next = NULL;
	newpatient->id = id_input;
	newpatient->index = index;
	strcpy(newpatient->situation, situation_input);
	if (*head == NULL) {
		*head = newpatient;
		return;
	}
	patients *temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newpatient;
}
int takeValid(char* str){
    if(strcmp(str,"critical") ==0 || strcmp(str,"stable")==0 || strcmp(str,"serious") == 0){
        return 1;
    }
    return 0;
}

int main() {
	int number;
	printf("Enter number of entries:- ");
	scanf("%d", &number);
	map mapper[number];
	int map_count = 0;
	patients *critical = NULL;
	patients *serious = NULL;
	patients *stable = NULL;

	while (number>0) {
		int id_input;
		scanf("%d", &id_input);
		getchar();
		char situation_input[10];
		scanf("%s", situation_input);
		while(takeValid(situation_input) == 0){
		    printf("Enter the valid situation name(serious , critical , stable):- ");
		    scanf("%s",situation_input);
		}
		if(checkid(mapper,id_input,map_count) == 0) {
			mapper[map_count++].id = id_input;
			number--;
			if (strcmp(situation_input, "critical") == 0) {
				addEnd(&critical, id_input, situation_input, 0);
			} else if (strcmp(situation_input, "serious") == 0) {
				addEnd(&serious, id_input, situation_input, 1);
			} else if (strcmp(situation_input, "stable") == 0) {
				addEnd(&stable, id_input, situation_input, 2);
			}
		} else {
			printf("Enter a unique id:-");
		}
	}
	patients *temp = critical;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = serious;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next=stable;
	printf("\n\n");
	while(critical!= NULL) {
		printf(" %d %s\n", critical->id, critical->situation);
		critical=critical->next;
	}
	return 0;
}
