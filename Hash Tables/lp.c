#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int value[50], status[50], size, count;
bool flag;

void insert(int key, int pos) {
	flag = false;
	if(status[pos] == 0) {
		value[pos] = key;
		status[pos] = 1;
		flag = true;
		count++;
		printf("\n%d was inserted at %d position in the hash table",key,pos);
		printf("\n%d elements currently present in the hash table",count);
	} else {
		while(flag != true) {
			insert(key,(pos+1)%size);
		}
	}
}

int find(int key, int pos) {
	flag = false;
	if(status[pos] == 0) {
		printf("\nSEARCH UNSUCCESSFUL");
		return -100;
	} else {
		if(value[pos] == key) {
			printf("\n%d was found at %d slot in the hash table",key,pos);
			flag = true;
			return pos;
		} else {
			while(flag != true) {
				if(find(key,(pos+1)%size) == -100) {
					break;
				}
			}
		}
	}
}

void main() {
	int ch, key;
	ch = key = 0;
	flag = false;
	count = 0;
	printf("\nEnter the size of the hash table: ");
	scanf("%d",&size);
	do {
		printf("\n1.	INSERT KEY");
		printf("\n2.	FIND KEY");
		printf("\n3.	EXIT");
		printf("\nPlease enter one of the above options: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1: printf("\nEnter the key you want to insert: ");
				scanf("%d",&key);
				insert(key,key%size);
				break;
			case 2: printf("\nEnter the key you want to find: ");
				scanf("%d",&key);
				find(key,key%size);
				break;
		}
	} while(ch != 3);
}
