#include<stdio.h>
#include<stdlib.h>

struct Node{
	int row,col,val1;
	struct  Node *right,*down,*val2;
};

void printList(struct Node *first);
void printList2(struct Node *first);
void main(){
	int m,n,i,j,k,head_nodes,prev,x,p,q,r,count;	
	count=0;
	printf("Enter number of rows and columns:");
	scanf("%d%d",&m,&n);

	if (m>=n){
		head_nodes=m;
	}
	else {
		head_nodes=n;
	}
	//Step 1: Create Dimension Node
	struct Node* main;
	main = (struct Node*)malloc(sizeof(struct Node));

	//Array of header nodes	
	//Step 1: Create
	struct Node* head[head_nodes];
	//Step 2: Init	
	for (i=0;i<head_nodes;i++) {
    		head[i] = (struct Node*)malloc(sizeof(struct Node));
    		head[i]->row=i+1;   
    		head[i]->col=i+1;    
		head[i]->right=head[i];
		head[i]->down=head[i];
		head[i]->val1=0;
	}
	//Step 2: Init Dimension Nodes
	main->row=m;
	main->col=n;
	main->val2=head[0];
	//Set header nodes to point to next header node
	for (i=0;i<head_nodes-1;i++) {
    		head[i]->val2=head[i+1];
	}
	//Set last header node to point to the dimension node
	head[i]->val2=main;

	//---------------------------------------------------CHECKPOINT 1---------------------------------------------------------------
	
	printf("Enter number of non zero elements:");
	scanf("%d",&x);
	//Step 1: Create array of data nodes that store the non-zero elements	
	struct Node* elements[x];
	//Step 2: Init element nodes with the row, col index and data
	for (i=0;i<x;i++) {
    		printf("Enter row column and val for Node%d",i+1);
    		scanf("%d%d%d",&p,&q,&r);
		if(p > m || q > n) {
			printf("\nEnter a valid row-column pair");
			i--;
			continue;
		}
    		elements[i]=(struct Node*)malloc(sizeof(struct Node));
    		elements[i]->row=p;
    		elements[i]->col=q;
    		elements[i]->val1=r;        
	}
	
	//--------------------------------------------------ALGORITHM--------------------------------------------------------------------
	// *************************************************** ROW **********************************************************************
	for (i=0;i<m;i++) {
		//Traversing the array of header nodes row-wise
    		count=0;
		prev=0;
		for (j=0;j<x;j++) {
			//If j element node has the same row value as the header node, j element node is the first node 			//and j element node is not yet visited -> increment count, set flag, set this row's header
			if (elements[j]->row == (i+1) && count==0) {
        			count+=1;
        			head[i]->right=elements[j];
				elements[j]->right=head[i];
				prev=j;
    			} 
			//If j node has same row value, is not first node and is not yet visited, increment count, set 				//flag, set previous node's right pointer to this node, set current to this node
			else if (elements[j]->row == (i+1) && count>0) {
        			count+=1;
				elements[prev]->right=elements[j];
				elements[j]->right=head[i];
				prev=j;
    			}
		}
	}
	// ********************************************** COLUMN **********************************************************************
 	for (i=0;i<n;i++) {
		//Traversing the array of header nodes row-wise
    		count=0;
		prev=0;
		for (j=0;j<x;j++) {
			//If j element node has the same col value as the header node, j element node is the first node 			//and j element node is not yet visited -> increment count, set flag, set this row's header 		
			if (elements[j]->col == (i+1) && count==0) {
        			count+=1;
        			head[i]->down=elements[j];
				elements[j]->down=head[i];
				prev=j;
    			} 
			//If j node has same col value, is not first node and is not yet visited, increment count, set 				//flag, set previous node's down pointer to this node, set current to this node
			else if (elements[j]->col == (i+1) && count>0) {
        			count+=1;
				elements[prev]->down=elements[j];
				elements[j]->down=head[i];
				prev=j;
			}    			
		}
	}
	
	//--------------------------------------------------CHECKPOINT 2: VERIFY-----------------------------------------------------------
	printf("\n\n ** Row wise Traversal ** \n");
	for (i=0;i<head_nodes;i++) {
		printf("\n");
    		printList(head[i]);
	}
	printf("\n\n ** Column wise Traversal ** \n");
	for (i=0;i<head_nodes;i++) {
		printf("\n");
    		printList2(head[i]);
	}
	printf("\n");
}	
/* Function to traverse a given Circular linked list and print nodes */
void printList(struct Node *first) {
    struct Node *temp = first; 
    // If linked list is not empty
    if (first != NULL) {
        // Keep printing nodes till we reach the first node again
        do{
            printf(" %d %d %d -->", temp->row,temp->col,temp->val1);
            temp = temp->right;
        }while (temp != first);
    }
}

void printList2(struct Node *first) {
    struct Node *temp = first; 
    // If linked list is not empty
    if (first != NULL) {
        // Keep printing nodes till we reach the first node again
        do{
            printf(" %d %d %d -->", temp->row,temp->col,temp->val1);
            temp = temp->down;
        }while (temp != first);
    }
}
