#include<stdio.h>
#include<stdlib.h>

int a[50];
int size;
int heapsize;
int l, r, largest;

void printarray() {
	int i;
	for(i = 1; i <= size; i++) {
		printf("%d\t",a[i]);
	}
}

int getLeft(int i) {
	return 2*i;
}

int getRight(int i) {
	return 2*i + 1;
}

void maxHeapify(int i) {
	int temp;
	printf("\nMax-Heapify from element --> %d",a[i]);
	l = getLeft(i);
	printf("\nLeft child --> %d",a[l]);
	r = getRight(i);
	printf("\nRight child --> %d",a[r]);
	if(l <= heapsize && a[l] > a[i]) {
		printf("\nLargest Element --> %d",a[l]);
		largest = l;
	} else {
		printf("\nLargest Element --> %d",a[i]);
		largest = i;
	}
	if(r <= heapsize && a[r] > a[largest]) {
		printf("\nLargest Element --> %d",a[r]);
		largest = r;
	}
	if(largest != i) {
		printf("\nExchanging %d and %d",a[i],a[largest]);
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
	}	
	printf("\n--------------UPON MAX-HEAPIFY()--------------\n");
	printarray();
	printf("\n");
	if(largest != i) {
		maxHeapify(largest);
	}
}

void buildMaxHeap() {
	int i;
	i = size/2;
	while(i >= 1) {
		maxHeapify(i);
		i--;
	}
}

void heapsort() {
	int i, temp;
	buildMaxHeap();
	for(i = size; i >= 2; i--) {
		printf("\nExchanging %d and %d",a[1],a[i]);
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		printf("\n%d is sorted in array",a[heapsize]);
		heapsize--;
		printf("\n-------------UPON EXCHANGING FIRST ELEMENT WITH LAST-------------\n");
		printarray();
		printf("\n");
		maxHeapify(1); 
	}	
}

void main() {
	int i;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	heapsize = size;
	if(size >= 0) {
		for(i = 1; i <= size; i++) {
			printf("\nEnter data for element %d",i);
			scanf("%d",&a[i]);
		}
		printf("\nUnsorted array: \n");
		printarray();
		printf("\n");
		heapsort();
		printf("\nSorted array: \n");
		printarray();	
		printf("\n");
	}
}
