#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node {
	int data;
	char op;
	struct Node* lc;
	struct Node* rc;
};

struct Node* root;
struct Node* stack[20];
struct Node* newNode;
struct Node* tempNode;

char postfix[20];
int stk[20];
int top=-1;
int top1=-1;
int rightOp = 0;
int leftOp = 0;

//Pushing data onto the int stack --> maintains the operands
void pushInt(int data) {
	printf("\nPushing data %d",data);
	top++;
	stk[top] = data;
}

//Pop operands from the int stack
int popInt() {
	int data;
	printf("\nData to be popped %d",stk[top]);
	data = stk[top];
	top--;
	return data;
}

//Push expression trees onto the Node* stack
void pushNode(struct Node* node) {
	printf("\nPushing operator node %c",node->op);
	top1++;
	printf("\nValue of top = %d",top1);
	stack[top1] = node;
}

//Pop expression trees from the stack
struct Node* popNode() {
	struct Node* anotherTemp = stack[top1];
	printf("\nPopping node with operator %c",anotherTemp->op);
	printf("\nValue of top = %d",top1);
	top1--;
	return anotherTemp;
}

//Recursive util function to traverse tree in in-order fashion
void inorder(struct Node* start) {	
	if(start != NULL) {
		inorder(start->lc);
		if(start->data != 0) {
			printf("%d\t",start->data);
		}
		else {
			printf("%c\t",start->op);
		}
		inorder(start->rc);
	}
}

//Recursive util function to evaluate expression tree
void postordereval(struct Node* start) {
	if(start != NULL) {
		postordereval(start->lc);
		postordereval(start->rc);
		//If data encountered, push it onto int stack
		if(start->data != 0) {
			pushInt(start->data);
		}
		//If operand encountered, pop top two elements from stack, perform operation and push new result onto the int stack
		else {
			rightOp = popInt();
			leftOp = popInt();
			switch(start->op) {
				case '+' : pushInt(leftOp + rightOp);
						   break;
				case '-' : pushInt(leftOp - rightOp);
						   break;
				case '*' : pushInt(leftOp * rightOp);
						   break;
				case '/' : pushInt(leftOp / rightOp);
						   break;
				case '%' : pushInt(leftOp % rightOp);
						   break;
			}
		}
	}
}

void main() {
	int i;
	struct Node* right;
	struct Node* left;
	int r, l;
	int occurence = 0;
	printf("\nEnter the postfix expression");
	scanf("%s",postfix);
	i=0;
	while(postfix[i] != '\0') {
		//Encountered an operand, push onto int stack
		if((int)postfix[i] >= 48 && postfix[i] <= 57) {
			pushInt((int)postfix[i]-(int)48);
		}
		//Encountered an operator, create expression trees
		else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '%') {
			//If first occurence of operator, pop right and left operands from int stack, create an expression tree and push it onto Node stack
			if(occurence == 0) {
				r = popInt();
				l = popInt();
				right = (struct Node*)malloc(sizeof(struct Node*));
				right->data = r;
				right->lc=NULL;
				right->rc=NULL;
				left = (struct Node*)malloc(sizeof(struct Node*));
				left->data = l;
				left->lc=NULL;
				left->rc=NULL;
				newNode	= (struct Node*)malloc(sizeof(struct Node*));
				newNode->op = postfix[i];
				newNode->lc = left;
				newNode->rc = right;
				occurence++;
				pushNode(newNode);					
			} 
			//If next occurence of operator, pop right operator from int stack and left operator as expression tree from Node stack, create new expression tree and push again onto Node stack
			else if(occurence > 0) {
				tempNode = popNode();
				r = popInt();
				right = (struct Node*)malloc(sizeof(struct Node*));
				right->data = r;
				right->lc=NULL;
				right->rc=NULL;
				newNode = (struct Node*)malloc(sizeof(struct Node*));
				newNode->op = postfix[i];
				newNode->lc = tempNode;
				newNode->rc = right;
				occurence++;
				pushNode(newNode);
			}
		}
		i++;
		newNode=NULL;
		tempNode=NULL;
		left=NULL;
		right=NULL;
	}
	root = popNode();
	printf("\n-------------IN-ORDER EXPRESSION-------------\n");
	inorder(root);
	printf("\n");
	top=0;
	for(i = 0; i < 20; i++) {
		stk[i] = 0;
	}
	postordereval(root);
	printf("\nResult of Eval : %d\n",popInt());
}
