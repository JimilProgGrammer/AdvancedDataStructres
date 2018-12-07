#include<stdio.h>
#include<stdlib.h>

//Program for creation and insertion of nodes in Binary Search Tree

struct Node {
	int data;
	struct Node* lc;
	struct Node* rc;
};

//Denotes the root node of the tree
struct Node* root;
//For traversal
struct Node* temp;
//Denotes the terminal node to which new node will be attached
struct Node* pos;

//Util function to add a new node
void createNode(int data) {
	int compare = 0;
	
	//Creating Data Node	
	printf("\nCreating data node %d",data);	
	struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
	node->data = data;
	node->lc = NULL;
	node->rc = NULL;	
	
	//If root is empty, set root to newly created node	
	if(root == NULL) {
		printf("\nRoot is empty, setting root to data node %d",node->data);
		root = node;
	}
	//If root is not empty:	
	else if(root != NULL) {
		printf("\nRoot is not null, trying to find terminal node where data node %d will be attached",node->data);		
		pos = NULL;		
		temp = root;	
		
		//Traverse to the end of the tree to find out the terminal node to which new node will be attached	
		while(temp != NULL) {
			compare = temp->data;
			if(data < compare) {
				printf("\nMOVED LEFT");				
				pos = temp;				
				temp = temp->lc;
			} else {
				printf("\nMOVED RIGHT");				
				pos = temp;
				temp=temp->rc;
			}
		}
		printf("\nTerminal Node to which data node %d will be attached is found as %d",node->data,pos->data);
		
		//Determine whether new node will be attached as left child or right child of terminal node		
		if(data < pos->data) {
			printf("\nNew node attached as left child of %d node",pos->data);			
			pos->lc = node;
		} else {
			printf("\nNew node attached as right child of %d node",pos->data);			
			pos->rc = node;
		}
	}
}

//Recursive util function to traverse tree in in-order fashion
void inorder(struct Node* start) {	
	if(start != NULL) {
		inorder(start->lc);
		printf("%d\t",start->data);
		inorder(start->rc);
	}
}

void main() {
	int data,ch;
	printf("\nPress 1 to enter a node and 0 to exit");
	scanf("%d",&ch);	
	if(ch == 1) {
		do {
			printf("\nEnter data for the node");
			scanf("%d",&data);
			createNode(data);
			printf("\nPress 1 to enter a node and 0 to exit");
			scanf("%d",&ch);
		} while(ch != 0);
	}
	printf("\n--------------BINARY SEARCH TREE IN IN-ORDER--------------");
	printf("\n");
	if(root == NULL) {
		printf("\nTREE IS EMPTY");
	} else {
		inorder(root);
		printf("\n");
	}
}
