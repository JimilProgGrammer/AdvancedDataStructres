#include<stdio.h>
#include<stdlib.h>

int a[50];
int l, r, largest, size, heapsize;

void maxHeapify(int i) {
	int l = 2*i;
	int r = 2*i + 1;
	if(l <= heapsize && a[l]>a[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if(r <= heapsize && a[r]>a[largest]) {
		largest = r;
	}
	if(largest != i) {
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		maxHeapify(largest);
	}
}

void buildMaxHeap() {
	int i = size/2;
	while(i >= 1) {
		maxHeapify(i);
		i--;
	}
}

void heapsort() {
	buildMaxHeap();
	int i;
	for(i = size; i >= 2; i--) {
		int temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		heapsize--;
		maxHeapify(1);
	}
}

void printarray() {
	int i;
	for(i = 1; i <= size; i++) {
		printf("%d\t",a[i]);
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
