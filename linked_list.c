#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node* link;
	int key;
}node;


void insert(node** head , int k){
	if(*head == NULL){
//				printf("gg\n");

		node* temp = malloc(sizeof(node));;
		temp->link = NULL;
		temp->key = k;
		*head = temp;

		return;
	}
	node *prev,*cur;
	node* new_node = (node*)malloc(sizeof(node));
	new_node->link = NULL;
	new_node->key = k;
	prev = cur = *head;

	while(cur && cur->key < k){
		prev = cur;
		cur = cur->link;
	}
	if(prev == cur){
		//insert in the beginning
		*head = new_node;

	}
	else{
	prev->link = new_node;
	}

		new_node->link = cur;

	return;
}

void print(node* head){
	node* p = head;
	while(p){
		printf("%d ", p->key);
		p = p->link;
	}
	printf("\n");
}

int main(){
	node* head = NULL;
	insert(&head , 10);
	insert(&head , 20);
	insert(&head , 40);
	insert(&head , 1);
	
	
//	printf("%d",(head)->key);
	print(head);
	return 0;
}