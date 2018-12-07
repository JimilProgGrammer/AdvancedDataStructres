#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node {
	int row, col, data;
	struct Node *right, *down, *next;
};

void printRowList(struct Node* first) {	
	struct Node* temp = first;
	if(first != NULL) {
		do {
			printf(" %d,%d:%d --> ",temp->row,temp->col,temp->data);
			temp = temp->right;		
		} while(temp != first);
	}
}

void printColList(struct Node* first) {
	struct Node* temp = first;
	if(first != NULL) {
		do {
			printf(" %d,%d:%d --> ",temp->row,temp->col,temp->data);
			temp = temp->down;
		} while(temp != first);
	}
}

void main() {
	int count,m,n,headNodes,temp,i,j,k,x,p,q,r,prev;
	count = 0;
	printf("\nEnter the number of rows and columns: ");
	scanf("%d%d",&m,&n);
	if(m >= n)
		headNodes = m;
	else 
		headNodes = n;

	struct Node* main;
	main = (struct Node*)malloc(sizeof(struct Node));
	main->data = 0;
	main->row = m;
	main->col = n;
	
	struct Node* head[headNodes];
	for(i = 0; i < headNodes; i++) {
		head[i] = (struct Node*)malloc(sizeof(struct Node));
		head[i]->data = 0;
		head[i]->row = i+1;
		head[i]->col = i+1;
		head[i]->right = head[i];
		head[i]->down = head[i];
	}

	for(i = 0; i < headNodes-1; i++) {
		head[i]->next = head[i+1];
	}
	head[i]->next = main;
	main->next = head[0];

	printf("\nEnter total number of non-zero elements");
	scanf("%d",&x);

	struct Node* elements[x];
	for(i = 0; i < x; i++) {
		printf("\nEnter row index, column index, and data for non-zero element %d: ",(i+1));
		scanf("%d%d%d",&p,&q,&r);
		if(p > m || q > n) {
			printf("\nPlease enter a correct combination");
			i--;
			continue;
		}
		elements[i] = (struct Node*)malloc(sizeof(struct Node));
		elements[i]->row = p;
		elements[i]->col = q;
		elements[i]->data = r; 
	}
	
	for(i = 0; i < m; i++) {
		count = 0;
		prev = 0;
		for(j = 0; j < x; j++) {
			if(elements[j]->row == (i+1) && count == 0) {
				count++;
				head[i]->right = elements[j];
				elements[j]->right = head[i];
				prev = j;
			}
			if(elements[j]->row == (i+1) && count > 0) {
				count++;
				elements[prev]->right = elements[j];
				elements[j]->right = head[i];
				prev = j;
			}
		}
	}

	for(i = 0; i < n; i++) {
		count = 0;
		prev = 0;
		for(j = 0; j < x; j++) {
			if(elements[j]->col == (i+1) && count == 0) {
				count++;
				head[i]->down = elements[j];
				elements[j]->down = head[i];
				prev = j;
			}
			if(elements[j]->col == (i+1) && count > 0) {
				count++;
				elements[prev]->down = elements[j];
				elements[j]->down = head[i];
				prev = j;
			}
		}
	}

	printf("\nROW WISE TRAVERSAL -->\n");
	for(i = 0; i < headNodes; i++) {
		printRowList(head[i]);
		printf("\n");
	}
	printf("\nCOLUMN WISE TRAVERSAL -->\n");
	for(i = 0; i < headNodes; i++) {
		printColList(head[i]);
		printf("\n");
	}
}
