#include<stdio.h>
#include<stdlib.h>

void insert();
void display();
void rotate();

struct node* head = NULL;
struct node* tail = NULL;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};


int main(){
	int choice;
	while(1)
	{
	    printf("\n");
	    printf("\n1. Insert");
	    printf("\n2. Display");
	    printf("\n3. Rotate");
	    printf("\n4. Exit");
	    printf("\nEnter the choice: ");
		scanf("%d",&choice);
	    switch(choice)
		{
			case 1: insert();
					break;
			case 2: display();
					break;
			case 3: rotate();
					break;
			case 4: exit(0);
					break;
			default: printf("\nWrong choice entered!");
					 break;
		}
	}
	return 0;
}

void insert(){
	int n;
	printf("\nEnter the value: ");
	scanf("%d",&n);
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL&&tail==NULL){
		head=temp;
		tail=temp;
		temp->prev=temp;
		temp->next=temp;
	}
	else{
		temp->prev=tail;
		tail->next=temp;
		tail=temp;
		tail->next=head;
		head->prev=tail;
	}
}

void display(){
	printf("\nThe linked list: ");
	struct node* temp;
	temp=head;
	do{
		printf("%d-->",temp->data);
		temp=temp->next;
	}while(temp!=head);
}

void rotate(){
	int i,n;
	printf("\nEnter the no of rotations: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		head=head->next;
		tail=tail->next;
	}
}
