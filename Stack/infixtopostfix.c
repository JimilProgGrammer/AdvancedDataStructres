#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char stk[50];
char infix[50], postfix[50];
int top;

int stk1[50];
int top1;

void push(char data) {
	top++;
	stk[top] = data;
}

void push1(int data) {
	top1++;
	stk1[top1] = data;
}

char pop() {
	char temp;
	temp = stk[top];
	top--;
	return temp;
}

int pop1() {
	int temp;
	temp = stk1[top1];
	top1--;
	return temp;
}

char peek() {
	return stk[top];
}

int getPriority(char op) {
	if(op == '*' || op == '/') 
		return 1;
	else if(op == '+' || op == '-')
		return 0;
}

int postfixeval() {
	int i,j;
	printf("\nEVALUATING...");
	//Step 1: Add ) at the end of postfix expression	
	i = 0;
	while(postfix[i] != '\0') 
		i++;
	postfix[i] = ')';
	i=0;
	//Step 2: Scan postfix from left to right  and repeat for each element
	while(postfix[i] != ')') {
		//Step 2.1: If an operand is encountered, push it onto stack
		if((int)postfix[i] >= 48 && (int)postfix[i] <= 57) {
			printf("\nPushing operand %d onto stack",(int)postfix[i]-48);
			push1((int)postfix[i]-48);
		}
		//Step 2.2: If an operator is encountered, pop top two elements from stack, perform operation and push result onto the stack
		if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			int a, b;
			a = pop1();
			b = pop1();
			switch(postfix[i]) {
				case '+': push1(b + a);
					  break;
				case '-': push1(b - a);
					  break;
				case '*': push1(b * a);
					  break;
				case '/': push1(b/a);
					  break;
			}
		}
		i++;
	}
	int ans;
	ans = pop1();
	return ans;
}

void main() {
	int i, j;
	char op;
	i = 0;
	top = top1 = -1;
	printf("\nEnter the infix expression: ");
	scanf("%s",infix);
	printf("\nInfix expression is: \n");
	puts(infix);
	//Step 1: Push ( onto stack and add ) to the end of infix expression	
	push('(');
	while(infix[i] != '\0')
		i++;
	infix[i] = ')';
	strcpy(postfix,"");
	//Step 2: Scan infix expression from left to right and repeat for each element	
	i = 0;
	j = 0;
	printf("\nInfix and postfix ready");
	while(infix[i] != '\0') {
		//Step 2.1: If an operand is encountered, add it to the postfix expression
		if(infix[i] >= 48 && infix[i] <= 57) {
			printf("\nOpearand encountered...adding to postfix");
			postfix[j] = infix[i];
			j++;
			i++;
		}
		//Step 2.2: If a ( is encountered, push it onto stack
		if(infix[i] == '(') {
			printf("\n( encountered...pushing to stack");
			push(infix[i]);
			i++;
		}
		//Step 2.3: If an operand is encountered, repeatedly pop from stack & add to postfix all operators that have same or higher 			  precendence than this encountered operator, and push this operator onto stack
		if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			while(top != -1 && peek() != '(' && getPriority(peek()) >= getPriority(infix[i])) {
				printf("\nHigher priority operator present on stack...adding to postfix");				
				op = pop();
				postfix[j] = op;
				j++;				
			} 
			printf("\nAll higer priority operators added...pushing this operator onto stack");
			push(infix[i]);
			i++;
		}
		//Step 2.4: If a ) is encountered, repeatedly pop from stack and all operators to postfix, until ( is encountered. Then, 			  remover the (
		if(infix[i] == ')') {
			printf("\n) encountered");			
			op = peek();			
			while(top != -1 && op != '(') {
				printf("\n( is not encountered...popping operator and adding to stack");
				postfix[j] = pop();
				j++;
				op = peek();
			}
			printf("\nRemoving ( from stack");
			op = pop();
			i++;
		}
	}
	postfix[j] = '\0';
	printf("\nThe resulting postfix expression is : \n");
	puts(postfix);
	int ans;
	ans = postfixeval();
	printf("\nResult of above expression is: %d\n",ans);	
}
