#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int stk[50];
int top, n;

bool isOverflow() {
	if(top >= (n-1)) 
		return true;
	return false;
}

bool isUnderflow() {
	if(top == -1) 
		return true;
	return false;
}

void push(int data) {
	if(isOverflow()) {
		printf("\nOVERFLOW ENCOUNTERED!");
	} else {
		stk[++top]=data;
		printf("\nElement pushed is : %d",data);
	}
}

int pop() {
	int temp;
	if(isUnderflow()) {
		printf("\nUNDERFLOW ENCOUNTERED!");
		return -100;	
	} else {
		temp = stk[top--];
		return temp;
	}
}

int peek() {
	if(isUnderflow()) {
		printf("\nUNDERFLOW ENCOUNTERED!");
		return -100;
	}	
	return stk[top];
}

void display() {
	int i;
	for(i = top; i >= 0; i--) {
		printf("%d\t",stk[i]);
	}
}

void main() {
	int ch, data;	
	top = -1;
	printf("\nEnter the max-size of the stack: ");
	scanf("%d",&n);
	printf("\n1.	PUSH");
	printf("\n2.	POP");
	printf("\n3.	PEEK");
	printf("\n4.	DISPLAY");
	printf("\n5.	EXIT");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	do {
		switch(ch) {
			case 1: printf("\nEnter data to be pushed onto the stack");
				scanf("%d",&data);
				push(data);
				break;
			case 2: data = pop();
				if(data != -100) {
					printf("\nElement popped is %d",data);
				}
				break;
			case 3: data = peek();
				if(data!= -100) {
					printf("\nElement at the top of the stack is %d",data);
				}
				break;
			case 4: printf("\n");
				display();
				printf("\n");
				break;
		}
		printf("\n1.	PUSH");
		printf("\n2.	POP");
		printf("\n3.	PEEK");
		printf("\n4.	DISPLAY");
		printf("\n5.	EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
	}while(ch != 5);
}
