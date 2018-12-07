#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int queue[50];
int front, rear, n;

void display() {
	int i;
	for(i = 1; i <= n; i++) {
		printf("%d\t",queue[i]);
	}
}

bool isOverflow() {
	if(front == 1 && rear == n || front == rear+1) 
		return true;
	return false; 
}

bool isUnderflow() {
	if(front == rear)
		return true;
	return false;
}

void enqueue(int data) {
	if(isOverflow()) {
		printf("\nOVERFLOW ENCOUNTERED!");
	} else {
		if(front == 0) {
			front = 1;
			rear = 1;
		} else if(rear == n && front != 1) {
			rear = 1;
		} else {
			rear++;
		}
		queue[rear] = data;
		printf("\nElement enqueued is %d",queue[rear]);
	}
}

int dequeue() {
	int temp;
	if(isUnderflow()) {
		printf("\nUNDERFLOW ENCOUNTERED!");
		return -100;
	} else {
		temp = queue[front];
		queue[front] = -100;
		if(front == rear) {
			front = 0;
			rear = 0;
		} else if(front == n && rear != 1) {
			front = 1;
		} else {
			front++;
		}
		return temp;
	}
}

int atFront() {
	if(!isUnderflow()) {
		return queue[front];
	}
	return -100;
}

int atRear() {
	if(!isUnderflow()) {
		return queue[rear];
	}
	return -100;
}

void main() {
	int ch, data;	
	front = 0;
	rear = 0;
	printf("\nEnter the max-size of the queue: ");
	scanf("%d",&n);
	printf("\n1.	ENQUEUE");
	printf("\n2.	DEQUEUE");
	printf("\n3.	FRONT");
	printf("\n4.	REAR");
	printf("\n5.	DISPLAY");
	printf("\n6.	EXIT");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	do {
		switch(ch) {
			case 1: printf("\nEnter data to be enqueued: ");
				scanf("%d",&data);
				enqueue(data);
				break;
			case 2: data = dequeue();
				if(data != -100) {
					printf("\nElement dequeued is %d",data);
				}
				break;
			case 3: data = atFront();
				if(data!= -100) {
					printf("\nElement at the front of the queue is %d",data);
				}
				break;
			case 4: data = atRear();
				if(data!= -100) {
					printf("\nElement at the rear of the queue is %d",data);
				}
				break;
			case 5: printf("\n");
				display();
				printf("\n");
				break;
		}
		printf("\n1.	ENQUEUE");
		printf("\n2.	DEQUEUE");
		printf("\n3.	FRONT");
		printf("\n4.	REAR");
		printf("\n5.	DISPLAY");
		printf("\n6.	EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
	}while(ch != 6);
}
