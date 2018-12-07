#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct tree {
	char data;
	struct tree *left, *right;
};

struct tree *node, *temp, *ptr;
struct tree* stack[20];
int top = -1;

void push(struct tree* node) {
	stack[++top] = node;
}

struct tree* pop() {
	return stack[top--];
}

int check(char ch) {
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return 1;
	else 
		return 2;
}

void operands(char data) {
	node = (struct tree*)malloc(sizeof(struct tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	push(node);
}

void operators(char data) {
	node = (struct tree*)malloc(sizeof(struct tree));
	node->data = data;
	node->right = pop();
	node->left = pop();
	push(node);
}

void inorder(struct tree* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%c\t",root->data);
		inorder(root->right);
	}
}

int calc(struct tree* root) {
	int ch = check(root->data);
	if(ch == 2)
		return root->data-48;
	else if(ch == 1) {
		if(root->data == '+')
			return calc(root->left) + calc(root->right);
		else if(root->data == '-')
			return calc(root->left) - calc(root->right);
		else if(root->data == '*')
			return calc(root->left) * calc(root->right);
		else if(root->data == '/')
			return calc(root->left) / calc(root->right);
	}
}

void main() {
	int i,p,k,ans;
    	char s[20];
    	printf("Enter the expression in postfix form \n");
    	scanf("%s",s);
    	i=0;
    	for(i=0;s[i]!='\0';i++) {
            p=check(s[i]);
            if(p==1)
            	operators(s[i]);
            else if(p==2)
            	operands(s[i]);
        }
    	ans=calc(stack[top]);
    	printf("\nThe value of the postfix expression you entered is %d\n",ans);
    	printf("\nThe inorder traversal of the tree is \n");
    	inorder(stack[top]);
}
