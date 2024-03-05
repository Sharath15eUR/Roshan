#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head=NULL;

void enqueue(){
	int x;
	printf("\nEnter the value: ");
	scanf("%d",&x);
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		struct Node* curr;
		curr=head;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=temp;
	}
}

void dequeue(){
	struct Node* curr;
	curr=head;
	head=head->next;
	free(curr);
}

void isempty(){
	if(head==NULL){
		printf("\nYes, the queue is empty!");
	}
	else
		printf("\nNo, the queue is not empty!");
}

void nofelements(){
	int n;
	if(head==NULL){
		n=0;
	}
	else{
		struct Node* curr;
		curr=head;
		n=1;
		while(curr->next!=NULL){
			curr=curr->next;
			n++;
		}
	}
	printf("\nThe no. of elements in the queue are: %d",n);
}

void print(){
	struct Node* curr=head;
	if(curr==NULL){
		printf("\nEmpty Queue!");
	}
	else{
		while(curr!=NULL){
			printf("%d-->",curr->data);
			curr=curr->next;
		}
	}
}

int main(){
	int choice;
	while(1)
	{
	    printf("\n");
	    printf("\n1. Enqueue");
	    printf("\n2. Dequeue");
	    printf("\n3. Isempty?");
	    printf("\n4. No. of Elements");
	    printf("\n5. Print");
	    printf("\n6. Exit");
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
	    switch(choice)
		{
			case 1: enqueue();
					break;
			case 2: dequeue();
					break;
			case 3: isempty();
					break;
			case 4: nofelements();
					break;
			case 5: print();
					break;
			case 6: exit(0);
					break;
			default: printf("\nWrong choice entered!");
					 break;
		}
	}
	return 0;
}
