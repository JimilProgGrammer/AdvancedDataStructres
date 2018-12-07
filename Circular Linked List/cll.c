#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node* head;

struct Node* insertBeg(int data) {
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = data;
	new->next = head;
	
	head->next = new;
	head = new;
	
	return head;
}

struct Node* insertEnd(int data) {
	struct Node* temp = head;
	while(temp->next != head) {
		temp = temp->next;
	}
	
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = data;
	new->next = head;
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
	new->next = ptr;

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
	new->next = ptr;

	return head;
}

struct Node* createCircularLL() {
	int data;
	printf("\nEnter data or enter -1 to exit: ");
	scanf("%d",&data);	
	while(data != -1) {
		if(head == NULL) {
			head = (struct Node*)malloc(sizeof(struct Node));
			head->data = data;
			head->next = head;
		} else {
			head = insertBeg(data);
		}
		printf("\nEnter data or enter -1 to exit: ");
		scanf("%d",&data);
	}
	return head;
}

void displayCircularLL() {
	if(head == NULL) {
		printf("\nLinked List is empty!");
	} else {
		struct Node* temp = head;
		do {
			printf("%d --> ",temp->data);
			temp = temp->next;
		} while(temp != head);
	}
}

struct Node* deleteBeg() {
	if(head == NULL) {
		printf("\nLinked List Empty!");
		return NULL;
	}	
	struct Node* temp = head;
	while(temp->next != head) 
		temp = temp->next;
	temp->next = head->next;
	head = head->next;
	return head;
}

struct Node* deleteEnd() {
	if(head == NULL) {
		printf("\nLinked List Empty!");
		return NULL;
	}
	struct Node* ptr = head;
	struct Node* pre = ptr;
	while(ptr->next != head) {
		pre = ptr;		
		ptr = ptr->next;
	}
	pre->next = head;
	return head;
}

struct Node* deleteNode(int key) {
	if(head == NULL) {
		printf("\nEmpty List!");
		return NULL;
	}
	struct Node* ptr = head;
	struct Node* pre = ptr;
	while(ptr->data != key) {
		pre = ptr;
		ptr = ptr->next;
	}
	pre->next = ptr->next;
}

struct Node* deleteAfter(int key) {
	struct Node* ptr = head;
	struct Node* pre = ptr;
	do {
		pre = ptr;
		ptr = ptr->next;
	} while(pre->data != key);
	pre->next = ptr->next;	
	return head;
}

struct Node* sortList() {
	if(head == NULL) {
		printf("\nLink List Empty!");
		return NULL;
	}
	struct Node* ptr1 = head;
	struct Node* ptr2 = ptr1;
	while(ptr1->next != head) {
		ptr2 = ptr1;
		while(ptr2->next != head) {
			if(ptr1->data > ptr2->data) {
				int temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
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
		printf("\n9.	DELETE KEY");
		printf("\n10.	DELETE AFTER ELEMENT");
		printf("\n11.	SORT LIST");
		printf("\n12.	EXIT");
		printf("\nEnter an option: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:	head = createCircularLL();
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
				displayCircularLL();
				break;
			case 7: head = deleteBeg();
				break;
			case 8: head = deleteEnd();
				break;
			case 9: printf("\nEnter key of node to be deleted: ");
				scanf("%d",&key);
				head = deleteNode(key);
				break;
			case 10: printf("\nEnter key of node after which new node is to be deleted: ");
				 scanf("%d",&key);
				 head = deleteAfter(key);
				 break;
			case 11: head = sortList();
				 break;
		}
	} while(ch != 12);
}
