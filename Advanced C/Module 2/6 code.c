void insert(int x) {
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	
	struct Node* curr;
	curr=head;
	
	if(head==NULL){
		head=temp;
		return;
	}
	
	if(temp->data<head->data){
		temp->next=head;
		head->prev=temp;
		head=temp;
		return;
	}
	
	while (curr->next != NULL && curr->next->data<temp->data) {
        curr=curr->next;
    }
	temp->next = curr->next;
    if (curr->next != NULL)
        curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}
