#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data[10];
    struct  Node* left;
    struct  Node* right;
};
int k;

void printPoint(int data[])
{
	printf("(");
	 for (int j=0;j<k;j++){
        printf(" %d ",data[j]);
        }
	printf(")");
}

int search(struct Node *head, struct Node *new)
{
    int new_val, head_val;
    int flag = 0;
	int cd=0;
    while (flag==0)
    {

        printf("\nCutting dimension: %d",cd%k);
		new_val = new->data[cd%k];
		head_val = head->data[cd%k];
		cd++;
			
        if (new_val < head_val)
        {

			printf("\nValue ");
			printPoint(new->data);
			printf(" is smaller than ");
			printPoint(head->data);
			
            if (head->left==NULL){
            head->left = new;
			printf("\nInserted ");
			printPoint(new->data);
			printf(" as left child of ");
			printPoint(head->data);
			printf("\n");
            return 0;}
			
            else if (head->left!=NULL){
            head = head->left;
            printf("\nGoing into left subtree...\n");
            continue;
            }
        }
        
        if (new_val > head_val)
        {
            
			printf("\nValue ");
			printPoint(new->data);
			printf(" is greater than ");
			printPoint(head->data);
			
            if (head->right==NULL){
            head->right = new;
			printf("\nInserted ");
			printPoint(new->data);
			printf(" as right child of ");
			printPoint(head->data);
			printf("\n");
            return 0;}
			
            else if (head->right!=NULL){
            head = head->right; 
            printf("\nGoing into right subtree...\n");
            continue;}
        }
    
    }
    return 0;
}


void printInorder(struct Node *node)
{
     if (node == NULL)
          return;

     printInorder(node->left);
	 printPoint(node->data);
     printInorder(node->right);
}

void main(){
    int n,val;
    struct Node *nodes[20];
	printf("Enter dimension k for kd tree:");
	scanf("%d",&k);
    printf("Enter number of nodes in %dd tree:",k);
    scanf("%d",&n);
    int flag=0;
    for (int i=0;i<n;i++)
    {
        nodes[i] = (struct Node*)malloc(sizeof(struct Node));
		printf("\nEnter value of point %d:", i+1);
		for (int j=0;j<k;j++){
        scanf("%d",&val);
		nodes[i]->data[j] = val;
        }
        nodes[i]->left=NULL;        
        nodes[i]->right=NULL;
        if (i>0){
        flag = search(nodes[0], nodes[i]);
        if (flag == 1){
            i+=1;
        }}
        
    }
    printf("\nInorder traveral:\n");
    printInorder(nodes[0]);
}
