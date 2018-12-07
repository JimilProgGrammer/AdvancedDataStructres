#include<stdio.h>
#include<stdbool.h>

//status flags:
//0 - Empty
//1 - Occupied
int value[50], status[50], count, m = 0;
bool flag;

//Util Functions
void insert(int key, int pos, int size, int initpos) {
	int initpos1;
	initpos1 = initpos;
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
			printf("\nCOLLISION OCCURED, GONNA TRY QUADRATIC PROBING");
			if(flag == true) {
				break;
			}
			m++;
			insert(key,(initpos1+(m*m))%size,size,initpos1);
		}
	}
}
void find(int key, int pos, int size, int initpos) {
	int initpos1;
	initpos1 = initpos;
	flag = false;
	printf("\nTrying to search at position : %d",pos);
	if(status[pos] == 0) {
		printf("\nERROR: Search Unsuccessful!");
		flag=true;
		return;
	}
	else if(status[pos] == 1 && flag == false) {
		if(value[pos] == key) {
			flag = true;
			printf("\nSearch successful! Found %d at %d",key,pos);
			return;
		}
		else if(value[pos] != key) {
			while(flag != true) {
				printf("\nCOLLISION OCCURED, GONNA TRY QUADRATIC PROBING");
				if(flag == true) {
					break;
				}
				m++;
				find(key,(initpos1+(m*m))%size,size,initpos1);
			}
		}
	}
}

void main() {
		int key, ch, pos, x, size, initpos;
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
			initpos=key%size;
			m=0;
			insert(key,pos,size,initpos);
			printf("\nEnter 1 to insert more elements and 2 to stop inserting elements");
			scanf("%d",&ch);
		} while(ch != 2);
		ch = 0;
		initpos = 0;
		//Search Operations
		do {		
			printf("\nEnter the key that you want to find... ");
			scanf("%d",&key);
			pos=key%size;
			initpos=key%size;
			m=0;
			find(key,pos,size,initpos);
			printf("\nEnter 1 to find more elements and 2 to stop search operations");
			scanf("%d",&ch);
		} while(ch != 2);
}
