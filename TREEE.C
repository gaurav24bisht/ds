#include<stdio.h>
#include<conio.h>
typedef struct tree list;
list *root=NULL;
struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
};
list * create(){
	list *node=(list *)malloc(sizeof(list));
	printf("enter the value to insert\n");
	scanf("%d",&node->data);
	node->left=node->right=NULL;
	return(node);
}

void inorder(list *root){
	if(root==NULL)
		return;
	else{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
		}
	}


void preorder(list *root){
	if(root==NULL)
		return;
	else{
		printf("%d",root->data);
		inorder(root->left);
		inorder(root->right);
		}
	}
void postorder(list *root){
	if(root==NULL)
		return;
	else{
		inorder(root->left);
		inorder(root->right);
		printf("%d",root->data);


		}
	}

void insert(){
	list *temp=create(),*a,*b;
	if(root==NULL)
		root=temp;
	else{
		a=root;
		b=root;
		while(a!=NULL){
			if(a->data < temp->data){
				a=a->right;
				if(a!=NULL)
					b=b->right;
			}
			else{
				a=a->left;
				if(a!=NULL)
					b=b->left;
				}
			}
		if(b->data < temp->data)
			b->right=temp;
		else
			b->left=temp;
		}
	}

void main(){
	int i;
	clrscr();
	for(i=1;i<=5;i++){
		insert();
	} /*
	for(i=1;i<=5;i++){
		printf("%d\t",root->data);
		root=root->right;
	}   */
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	getch();
}
