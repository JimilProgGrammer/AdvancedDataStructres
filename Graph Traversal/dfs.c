#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node* first) {
	while(first != NULL) {
		printf("%d --> ",first->data);
		first = first->next;
	}
	printf("\n");
}

void main() {
	int i,j,k,m,n,x,from,to,val,num,v,e;
	int dfs[20] = {-1}, stk[20] = {0}, visited[20] = {0};
	int counter = 0, top = 0, element = 0, current = 0;
	
	struct Node *head[20], *sourceToDest[20], *destToSource[20], *temp;

	printf("\nEnter the total number of vertices and edges in the graph: ");
	scanf("%d%d",&v,&e);

	for(i = 0; i < v; i++) {
		head[i] = (struct Node*)malloc(sizeof(struct Node));
		head[i]->data = i;
		head[i]->next = NULL;
	}

	printf("\nEnter the edge data as requested: ");
	for(i = 0; i < e; i++) {
		printf("\nEnter source and destination for edge %d: ",i);
		scanf("%d%d",&from,&to);
		
		sourceToDest[i] = (struct Node*)malloc(sizeof(struct Node));
		sourceToDest[i]->data = to;
		sourceToDest[i]->next = NULL;
		if(head[from]->next == NULL) {
			head[from]->next = sourceToDest[i];
		} else {
			temp = head[from];
			while(temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = sourceToDest[i];
		}

		destToSource[i] = (struct Node*)malloc(sizeof(struct Node));
		destToSource[i]->data = from;
		destToSource[i]->next = NULL;
		if(head[to]->next == NULL) {
			head[to]->next = destToSource[i];
		} else {
			temp = head[to];
			while(temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = destToSource[i];
		}
	}

	for(i = 0; i < v; i++) {
		printList(head[i]);
	}

	printf("\nEnter the starting node for DFS: ");
	scanf("%d",&num);

	top++;
	stk[top] = num;
	visited[num] = 1;

	while(top != 0) {
		element = stk[top];
		top--;
		
		printf("\nTraversed node: %d",element);
		dfs[counter] = element;
		counter++;
		printf("\n%d nodes traveresed",counter);

		if(head[element]->next == NULL) {
			printf("\nIsolated node: %d reached",element);
			exit(0);
		} else {
			temp = head[element]->next;
			while(temp != NULL) {
				if(visited[temp->data] == 0) {
					top++;
					stk[top] = temp->data;
					visited[temp->data] = 1;
					printf("\nAdded neighbour, node: %d",temp->data);
				}
				temp = temp->next;
			}
		}
	}

	printf("\n---------------------DFS---------------------\n");
	for(i = 0; i < counter; i++) {
		printf("%d\t",dfs[i]);
	}
}
