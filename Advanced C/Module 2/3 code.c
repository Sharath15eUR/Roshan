#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref) {
	int new_data;
	printf("Enter the value: ");
	scanf("%d",&new_data);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
	int choice;
	while(1)
	{
	    printf("\n");
	    printf("\n1. Insert");
	    printf("\n2. Display");
	    printf("\n3. Bubblesort");
	    printf("\n4. Exit");
	    printf("\nEnter the choice: ");
		scanf("%d",&choice);
	    switch(choice)
		{
			case 1: insert(&head);
					break;
			case 2: display(head);
					break;
			case 3: bubbleSort(head);
					break;
			case 4: exit(0);
					break;
			default: printf("\nWrong choice entered!");
					 break;
		}
	}
	return 0;
}
