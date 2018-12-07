#include<stdio.h>
#include<stdbool.h>

//status flags:
//0 - Empty
//1 - Occupied
int value[50], status[50], count;
bool flag;

//Util Functions
void insert(int key, int pos, int size) {
	flag = false;
	if(status[pos] == 0) {
		value[pos] = key;
		status[pos] = 1;
		flag = true;
		count++;
		printf("\n%d was inserted at %d position",key,pos);
		printf("\n%d elements are present in the array",count);
		if(count >= (size/2)) {
			printf("\nWARNING : Upto half of the table is filled...it is advisable to stop inserting more elements to prevent the implementation from failing\n");
		}
	}
	if(status[pos] != 0) {
		while(flag != true) {
			if((pos+1) <= (size-1)) {
				insert(key, pos+1, size);
			} else if((pos+1) > (size-1)) {
				pos = 0;
				insert(key,pos,size);
			}
		}
	}
}
void find(int key, int pos, int size) {
	flag = false;
	printf("\nTrying to search at position : %d",pos);
	if(status[pos] == 0) {
		printf("\nERROR: Search Unsuccessful!");
	}
	else if(status[pos] == 1) {
		if(value[pos] == key) {
			flag = true;
			printf("\nSearch successful! Found %d at %d",key,pos);
		}
		else if(value[pos] != key) {
			while(flag != true) {
				find(key,(pos+1)%size,size);
			}
		}
	}
}

void main() {
		int key, ch, pos, x, size;
		flag = false;
		count=0;
		size=0;
		printf("Enter the size of hash table: ");
		scanf("%d",&size);
		printf("\n");
		//Insert operations
		do {
			printf("Enter the key you want to insert... ");
			scanf("%d",&key);
			pos=key%size;
			insert(key,pos,size);
			printf("\nEnter 1 to insert more elements and 2 to stop inserting elements");
			scanf("%d",&ch);
		} while(ch != 2);
		ch = 0;
		//Search Operations
		do {		
			printf("\nEnter the key that you want to find... ");
			scanf("%d",&key);
			pos=key%size;
			find(key,pos,size);
			printf("\nEnter 1 to find more elements and 2 to stop search operations");
			scanf("%d",&ch);
		} while(ch != 2);
}
