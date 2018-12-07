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
	int bfs[20] = {-1}, queue[20] = {0}, visited[20] = {0};
	int counter = 0, front = 0, rear = 0, element = 0, current = 0;
	
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

	printf("\nEnter starting node for BFS: ");
	scanf("%d",&num);
	queue[rear]=num;
	rear++;
	visited[num]=1;	

	while(front != rear) {
		element = queue[front];
		front++;
		printf("\nTraversed node: %d",element);
		
		bfs[counter] = element;
		counter++;
		printf("\n%d elements traversed",counter);
				
		if(head[element]->next == NULL) {
			printf("\nIsolated Node reached: %d",element);
			exit(0);
		} else {
			temp = head[element]->next;
			while(temp != NULL) {
				if(visited[temp->data] == 0) {
					queue[rear] = temp->data;
					rear++;
					visited[temp->data] = 1;
					printf("\nAdded neighbour, node: %d",temp->data);
				} else {
					printf("\nNeighbour, node: %d is already visited",temp->data);
				}
				temp = temp->next;
			}
		}
	}
	
	printf("\n-----------------------BFS-----------------------\n");
	for(i = 0; i < counter; i++) {
		printf("%d\t",bfs[i]);
	}
}
