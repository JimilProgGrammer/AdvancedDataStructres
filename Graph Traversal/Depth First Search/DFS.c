#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct Node{
	int val;
	struct  Node* next;
};

// Function to traverse a given Circular linked list and print nodes 
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d --> ", head->val);
        head = head->next;
    }
    printf("\n");
}

//Util function to print stack
void printstack(int stack[], int top) {
	int i;
	for(i = 1; i <= top; i++) {
		printf("%d\t",stack[i]);
	}
}

void main() {
	int m,n,i,head_nodes,from,to,visited[20]={0},top=-1,start,element=0;
	int dfs[20]={-1};
	
	struct Node *head[20],*temp,*new[20],*bidirect[20];
	struct Node *dest, *source;
	
	temp = (struct Node*)malloc(sizeof(struct Node));
	dest = (struct Node*)malloc(sizeof(struct Node));		
	source = (struct Node*)malloc(sizeof(struct Node));
	
	//Input the number of vertices and edges
	printf("Enter number of vertices and edges");
	scanf("%d%d",&m,&n);
	for (i=0;i<m;i++)
	{
    		head[i] = (struct Node*)malloc(sizeof(struct Node));
		head[i]->val = i;
    		head[i]->next=NULL;		
	}
	
	//Input the edges	
	printf(" -------- Enter edge data ---------\n");
	for (i=0;i<n;i++)
	{
		printf("Enter data for edge %d:",i);
		scanf("%d%d",&from,&to);
		//Creating the adjacency list for source node
		new[i] = (struct Node*)malloc(sizeof(struct Node));
		new[i]->val=to;
		new[i]->next=NULL;
		//Enter edge from source to destination
		if (head[from]->next == NULL)
		{
			head[from]->next = new[i]; 
		}
		else{
			temp=head[from];
			while(temp->next != NULL)
			{
				temp=temp->next;
			}
			temp->next=new[i];
		}
		//Creating adjacency list from destination to source
		bidirect[i] = (struct Node*)malloc(sizeof(struct Node));
		bidirect[i]->val=from;
		bidirect[i]->next=NULL;
		//Enter edge for destination to source
		if (head[to]->next == NULL)
		{
			head[to]->next = bidirect[i]; 
		}
		else{
			temp=head[to];
			while(temp->next != NULL)
			{
				temp=temp->next;
			}
			temp->next=bidirect[i];
		}
	}
	
	//Test adjacency list
	for (i=0;i<m;i++) {
		printList(head[i]);
	}
	
	top=0;

	//Get starting node from user
	printf("\nEnter the starting node");
	scanf("%d",&start);

	//Push start node onto the stack and mark it as visited
	top++;
	dfs[top] = start;
	visited[start] = 1;
	while(top != 0) {		
		//Pop the top node on the stack
		element = dfs[top];
		top--;
		printf("\nVisited %d node",element);
		//Traverse it's adjacency list
		temp=head[element]->next;
		while(temp != NULL) {
			//If node is not visited, add it to stack and mark it as visited 			
			if(visited[temp->val] == 0) {
				printf("\nAdding %d node onto stack",temp->val);
				top++;
				dfs[top] = temp->val;
				visited[temp->val] = 1;
				//Print the stack
				printf("\n---------------STACK---------------\n");
				printstack(dfs, top);
			}
			temp = temp->next;
		}
	}
	printf("\n");	
}
