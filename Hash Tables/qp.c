#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int value[50], status[50], count, m, size;
bool flag;

void insert(int key, int pos, int initpos) {
	int initpos1 = initpos;
	flag = false;
	if(status[pos] == 0) {
		value[pos] = key;
		status[pos] = 1;
		flag = true;
		count++;
		printf("\n%d was inserted into slot %d",key,pos);
		printf("\n%d elements currently present in the hash table",count);
	} else {
		while(flag != true) {
			if(flag == true) 
				break;
			m++;
			printf("\nCollision: Probing Next Slot");
			insert(key, (initpos1+(m*m))%size, initpos1);
		}
	}
}

void find(int key, int pos, int initpos) {
	int initpos1 = initpos;	
	flag = false;
	if(status[pos] == 0) {
		printf("\nSEARCH UNSUCCESSFUL!");
		flag = true;
		return;
	} else {
		if(value[pos] == key) {
			printf("\n%d was found in slot %d in the hash table",key,pos);
			flag = true;
			return;
		} else {
			while(flag != true) {
				if(flag == true) 
					break;
				m++;
				printf("\nCollision: Probing Next Sequence");
				find(key, initpos1+(m*m)%size, initpos1);
			}
		}
	}
}

void main() {
	int ch, key;
	ch = key = m = 0;
	flag = false;
	count = 0;
	printf("\nEnter the size of the hash table: ");
	scanf("%d",&size);
	do {
		m=0;		
		printf("\n1.	INSERT KEY");
		printf("\n2.	FIND KEY");
		printf("\n3.	EXIT");
		printf("\nPlease enter one of the above options: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1: printf("\nEnter the key you want to insert: ");
				scanf("%d",&key);
				insert(key,key%size,key%size);
				break;
			case 2: printf("\nEnter the key you want to find: ");
				scanf("%d",&key);
				find(key,key%size,key%size);
				break;
		}
	} while(ch != 3);
}
