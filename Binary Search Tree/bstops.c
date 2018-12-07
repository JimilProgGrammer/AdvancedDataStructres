#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* tree;

struct Node* insertElement(int data) {
	struct Node *ptr, *parentptr, *nodeptr;
	ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	
	if(tree == NULL) {
		tree = ptr;
		tree->left = NULL;
		tree->right = NULL;
	} else {
		nodeptr = tree;
		parentptr = nodeptr;
		while(nodeptr != NULL) {
			parentptr = nodeptr;
			if(data < nodeptr->data)
				nodeptr = nodeptr->left;
			else if(data > nodeptr->data)
				nodeptr = nodeptr->right;
		}
		if(data < parentptr->data)
			parentptr->left = ptr;
		else
			parentptr->right = ptr;
	}
	return tree;
}

void preOrder(struct Node* root) {
	if(root != NULL) {
		printf("%d\t",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct Node* root) {
	if(root != NULL) {
		inOrder(root->left);
		printf("%d\t",root->data);
		inOrder(root->right);
	}
}

void postOrder(struct Node* root) {
	if(root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d\t",root->data);
	}
}

struct Node* findSmallestElement(struct Node* root) {
	if(root == NULL || root->left == NULL) {
		return root;
	} else {
		return findSmallestElement(root->left);
	}
}

struct Node* findLargestElement(struct Node* root) {
	if(root == NULL || root->right == NULL) {
		return root;
	} else {
		return findLargestElement(root->right);
	}
}

int totalNodes(struct Node* tree) {
	if(tree == NULL) {
		return 0;
	} else {
		return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
	}
}

int totalExternalNodes(struct Node* tree) {
	if(tree == NULL) {
		return 0;
	} else if(tree->left == NULL && tree->right == NULL) {
		return 1;
	} else {
		return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
	}
}

int totalInternalNodes(struct Node* tree) {
	if(tree == NULL || tree->left == NULL && tree->right == NULL) {
		return 0;
	} else {
		return (totalInternalNodes(tree->left)+totalInternalNodes(tree->right)+1);
	}
}

struct Node* deleteElement(int data) {
	struct Node *node, *parent;

	if(tree == NULL) {
		printf("\nTree is empty!");
		return tree;
	}

	node = tree;
	parent = node;
	while(node->data != data) {
		printf("\nUpdating parent from %d",parent->data);		
		parent = node;
		printf(" to %d",parent->data);
		//if(node->data == data)
		//	break;
		if(data < node->data) {
			printf("\nMoving left");		
			node = node->left;
		} else if(data > node->data) {
			printf("\nMoving right");
			node = node->right;
		}
	}

	if(node == NULL) {
		printf("\nSpecified data does not exist in the tree");
		return tree;
	}

	printf("\nData Found, Node: %d",node->data);
	printf("\nParent Node: %d",parent->data);
	
	if(node->left == NULL && node->right == NULL) {
		printf("\nTerminal Node Deletion");		
		if(parent->left == node) {
			printf("\nSet parent's left child to NULL");
			parent->left = NULL;
		} else if(parent->right == node) {
			printf("\nSet parent's right child to NULL");			
			parent->right = NULL;
		}
		node = NULL;
		free(node);
		return tree;
	} else if(node->left != NULL && node->right == NULL) {
		printf("\nCase 2: Node having one child");		
		if(parent->left == node) {		
			printf("\nSetting Left Subtree");	
			parent->left = node->left;
		}
		else if(parent->right == node) {
			printf("\nSetting right subtree");
			parent->right = node->left;	
		}
		node = NULL;
		free(node);
		return tree;
	} else if(node->left == NULL && node->right != NULL) {
		printf("\nCase 2: Node having one child");		
		if(parent->right == node) {			
			printf("\nSetting right subtree");		
			parent->right = node->right;
		}
		else if(parent->left == node) {
			printf("\nSetting left subtree");
			parent->left = node->right;
		}
		node = NULL;
		free(node);
		return tree;
	} else if(node->left != NULL && node->right != NULL) {
		printf("\nCase 3: Node with two children");
		struct Node* insuc = findSmallestElement(node->right);
		printf("\nIn-order successor is %d",insuc->data);
		struct Node *psuc, *temp, *current;
		current = tree;
		while(current != insuc) {
			psuc = current;
			if(insuc->data < current->data) 
				current = current->left;
			else if(insuc->data > current->data)
				current = current->right;
		}
		node->data = insuc->data;
		if(psuc->data != node->data)		
			psuc->left = NULL;
		else if(psuc->data == node->data)
			psuc->right = NULL;
		insuc = NULL;
		free(insuc);
		return tree;
	}
}

struct Node *mirrorImage(struct Node *root)
{
	struct Node *ptr;
	if(root != NULL) {
		mirrorImage(root->left);
		mirrorImage(root->right);
		ptr=root->left;
		root->left = root->right;
		root->right = ptr;
	}
}

void main() {
	int ch, data;
	struct Node *smallest, *largest;
	tree = NULL;
	do {
		printf("\n1.	Insert Element");
		printf("\n2.	Pre-Order Traversal");
		printf("\n3.	In-Order Traversal");
		printf("\n4.	Post-Order Traversal");
		printf("\n5.	Find Smallest Element");
		printf("\n6.	Find Largest Element");
		printf("\n7.	Total Number of Nodes");
		printf("\n8.	Total External/Terminal Nodes");
		printf("\n9.	Total Internal Nodes");
		printf("\n10.	Delete Element");
		printf("\n11.	Mirror Tree");
		printf("\n15.	Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1: printf("\nEnter the data you want to insert: ");
				scanf("%d",&data);
				tree = insertElement(data);
				break;
			case 2: preOrder(tree);
				break;
			case 3: inOrder(tree);
				break;
			case 4: postOrder(tree);
				break;
			case 5: smallest = findSmallestElement(tree);
				if(smallest != NULL) {
					printf("\nSmallest Element is: %d",smallest->data);
				}
				break;
			case 6: largest = findLargestElement(tree);
				if(largest != NULL) {
					printf("\nLargest Element is: %d",largest->data);
				}
				break;
			case 7: printf("\nTotal number of nodes in tree = %d",totalNodes(tree));
				break;
			case 8: printf("\nTotal number of external/leaf nodes = %d",totalExternalNodes(tree));
				break;
			case 9: printf("\nTotal number of internal nodes = %d",totalInternalNodes(tree));
				break;
			case 10: printf("\nEnter data to be deleted: ");
				 scanf("%d",&data);
				 tree = deleteElement(data);
				 break;
			case 11: tree = mirrorImage(tree);
				 break;
		}
	} while(ch != 15);
}
