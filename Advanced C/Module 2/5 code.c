#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};
struct Node* head = NULL;

void insert(char c) {
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=c;
    temp->next=head;
    head=temp;
}

void display() {
    struct Node* temp;
    temp=head;
	while (temp != NULL) {
        printf("%c", temp->data);
        temp=temp->next;
    }
}

int main(){
	struct Node* head = NULL;
	int i;
	char input[25];
	printf("\nEnter the input to be reversed: ");
	scanf("%s",&input);
	printf("Reversed input: ");
	for(i=0;i<sizeof(input-1);i++){
		insert(input[i]);
	}
	display();
	return 0;
}
