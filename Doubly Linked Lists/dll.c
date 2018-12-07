#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node {
	int data;
	struct Node *next, *prev;
};

struct Node* head;

struct Node* insertBeg(int data) {
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = data;
	new->next = head;
	new->prev = NULL;
	
	head->prev = new;
	head = new;
	
	return head;
}

struct Node* insertEnd(int data) {
	struct Node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = data;
	new->next = NULL;
	new->prev = temp;
	temp->next = new;

	return head;
}

struct Node* insertBefore(int data, int key) {
	struct Node* ptr = head;
	struct Node* pre = ptr;
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = data;

	while(ptr->data != key) {
		pre = ptr;
		ptr = ptr->next;
	}

	pre->next = new;
	new->prev = pre;
	new->next = ptr;
	ptr->prev = new;

	return head;
}

struct Node* insertAfter(int data, int key) {
	struct Node* ptr = head;
	struct Node* pre = ptr;
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = data;

	while(pre->data != key) {
		pre = ptr;
		ptr = ptr->next;
	}

	pre->next = new;
	new->prev = pre;
	new->next = ptr;
	if(ptr != NULL)	
		ptr->prev = new;

	return head;
}

struct Node* createDoublyLL() {
	int data;
	printf("\nEnter data or enter -1 to exit: ");
	scanf("%d",&data);	
	while(data != -1) {
		if(head == NULL) {
			head = (struct Node*)malloc(sizeof(struct Node));
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
		} else {
			head = insertBeg(data);
		}
		printf("\nEnter data or enter -1 to exit: ");
		scanf("%d",&data);
	}
	return head;
}

void displayDoublyLL() {
	if(head == NULL) {
		printf("\nLinked List is empty!");
	} else {
		struct Node* temp = head;
		while(temp != NULL) {
			printf("%d --> ",temp->data);
			temp = temp->next;
		}
	}
}

struct Node* deleteBeg() {
	if(head == NULL) {
		printf("\nLinked List Empty!");
		return NULL;
	}
	head = head->next;
	head->prev = NULL;
	return head;
}

struct Node* deleteEnd() {
	if(head == NULL) {
		printf("\nLinked List Empty!");
		return NULL;
	}
	struct Node* ptr = head;
	struct Node* pre = ptr;
	while(ptr->next != NULL) {
		pre = ptr;		
		ptr = ptr->next;
	}
	pre->next = NULL;
	return head;
}

struct Node* deleteBefore(int key) {
	struct Node* ptr = head;
	struct Node* pre = ptr;
	while(ptr->data != key) {
		pre = ptr;
		ptr = ptr->next;
	}
	ptr->prev = pre->prev;
	if(pre->prev != NULL)	
		pre->prev->next = ptr;
	else 
		head = ptr;
	return head;
}

struct Node* deleteAfter(int key) {
	struct Node* ptr = head;
	struct Node* pre = ptr;
	while(pre->data != key) {
		pre = ptr;
		ptr = ptr->next;
	}
	pre->next = ptr->next;
	if(ptr->next != NULL)	
		ptr->next->prev = pre;	
	return head;
}

void main() {
	int ch, data, key;	
	do {
		printf("\n1.	CREATE LINK LIST");
		printf("\n2.	INSERT AT THE BEGGINING");
		printf("\n3.	INSERT AT THE END");
		printf("\n4.	INSERT BEFORE ELEMENT");
		printf("\n5.	INSERT AFTER ELEMENT");
		printf("\n6.	DISPLAY");
		printf("\n7.	DELETE FROM BEGINNING");
		printf("\n8.	DELETE FROM END");
		printf("\n9.	DELETE BEFORE ELEMENT");
		printf("\n10.	DELETE AFTER ELEMENT");
		printf("\n11.	EXIT");
		printf("\nEnter an option: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:	head = createDoublyLL();
				break;
			case 2: printf("\nEnter data to be inserted: ");
				scanf("%d",&data);
				head = insertBeg(data);
				break;
			case 3: printf("\nEnter data to be inserted: ");
				scanf("%d",&data);
				head = insertEnd(data);
				break;
			case 4: printf("\nEnter data to be inserted: ");
				scanf("%d",&data);
				printf("\nEnter data of the node before which new node is to be inserted: ");
				scanf("%d",&key);
				head = insertBefore(data,key);
				break;
			case 5: printf("\nEnter data to be inserted: ");
				scanf("%d",&data);
				printf("\nEnter data of the node after which new node is to be inserted: ");
				scanf("%d",&key);
				head = insertAfter(data,key);
				break;
			case 6: printf("\n");
				displayDoublyLL();
				break;
			case 7: head = deleteBeg();
				break;
			case 8: head = deleteEnd();
				break;
			case 9: printf("\nEnter key of node before which new node is to be deleted: ");
				scanf("%d",&key);
				head = deleteBefore(key);
				break;
			case 10: printf("\nEnter key of node after which new node is to be deleted: ");
				 scanf("%d",&key);
				 head = deleteAfter(key);
				 break;
		}
	} while(ch != 11);
}
