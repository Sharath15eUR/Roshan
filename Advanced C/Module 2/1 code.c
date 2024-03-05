#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_end();
void removeDuplicates();

struct node* head = NULL;
struct node
{
	int data;
	struct node* next;
};

int main()
{
	int choice;
	while(1)
	{
	    printf("\n\n");
	    printf("0. Create\n");
	    printf("1. display\n");
	    printf("2. Insert Node at end of LinkedList\n");
	    printf("3. Remove Duplicates\n");
		printf("4. To exit\n");
	    
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: create();
					break;
			case 1: display();
					break;
			case 2: insert_end();
					break;
			case 3: removeDuplicates();
					break;
			case 4: exit(0);
			default:printf("\n Wrong Choice");
                    break;
		}
	}
}

void create()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data); 
	temp->next = NULL;
	if(head==NULL)	{
		head = temp;
	}
	else{
		struct node* ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void display()
{
	if(head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
        printf("LinkedList: ");
	struct node* ptr = head;
	while(ptr!=NULL) 
	{
		printf("%d--> ",ptr->data);
		ptr = ptr->next;
	}
    printf("\n");
}

void insert_end()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data); 
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
	        return;
	}
	else{
		struct node* ptr = head;  
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void removeDuplicates() {
    struct node* current = head;
    struct node* next_next;

    if (current == NULL)
        return;

    
    while (current->next != NULL) {
        // Compare current node with the next node
        if (current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}
