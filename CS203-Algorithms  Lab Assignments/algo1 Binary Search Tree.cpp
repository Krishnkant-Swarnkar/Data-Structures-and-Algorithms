#include<iostream>
#include <stdio.h>
using namespace std;

struct node{
	char info;
	node*left;
	node*right;
};  
	
void insert(node**root,char i){
	if(*root==NULL){
		node*np=new node;
		np->info=i;
		np->right=np->left=NULL;
		*root=np;
		return;
	}
	
	if((*root)->info > i){
		insert(&((*root)->left),i);
		return;
	}
	
	if((*root)->info < i){
		insert(&((*root)->right),i);
		return;
	}
	
}

void preorder(node*root){
	if(root==NULL){
		return ;
	}
	/*if(root->left==NULL&&root->right==NULL){
		cout<<root->info<<" ";
		return;
	}*/
	cout<<root->info<<" ";
	preorder(root->left);
	preorder(root->right);
	
}

void inorder(node*root){
		if(root==NULL){
		return ;
	}
	/*if(root->left==NULL&&root->right==NULL){
		cout<<root->info<<" ";
		return;
	}*/
	inorder((root)->left);
	cout<<root->info<<" ";
	inorder((root)->right);
	
}

void postorder(node*root){
	if(root==NULL){
		return ;
	}
	/*if(root->left==NULL&&root->right==NULL){
		cout<<root->info<<" ";
		return;
	}*/
	postorder(root->left);
	postorder(root->right);
	cout<<root->info<<" ";
}


int search( node*root,char key ) {// ........... find an element ..........
if(root==NULL)
return 0;

if(root->left==NULL &&root->right==NULL)
{
	if(root->info==key)
	return 1;
	else
	return 0;
}

if(root->info==key)return 1;


if(root->info< key)
return search(root->right,key);

if(root->info > key)
return search(root->left,key);

return 0;
}

void search_for_delete(node*root,node**cur,node**parent,char key,int *found){
	
	*found=0;
	while(root!=NULL){
		*found=0;
		if(root->info > key){
			*parent=root;
			root=root->left;
		}
		else if(root->info < key){
			*parent=root;
			root=root->right;
		}
		else if(root->info==key){
			*cur=root;
			*found=1;
			break;
		}
	}
	
}

void Delete(node*root,char key){
	node*parent=NULL;
	node*cur=NULL;
	node*temp1=NULL;
	node*temp2=NULL;
	int found;
	search_for_delete(root,&cur,&parent,key,&found);
	if(found==0){cout<<"trying to delete data at unexisting key\n";return;}
	if(cur->left==NULL && cur->right==NULL){//CASE 1
	if(parent->left==cur)parent->left=NULL;
		if(parent->right==cur)parent->right=NULL;
		}
	else if(cur->left!=NULL && cur->right==NULL){//CASE 2.1
			if(parent->left==cur)parent->left=cur->left;
			if(parent->right==cur)parent->right=cur->left;
	}
	else if(cur->left==NULL && cur->right!=NULL){//CASE 3
			if(parent->left==cur)parent->left=cur->right;
			if(parent->right==cur)parent->right=cur->right;
	}
	/* STANDARD DELETE CODE
	    
		in case else if(cur->left!=NULL && cur->right!=NULL){
		parent=cur;
		temp2=cur->right ;
		while(temp2->left!=NULL){
		parent=temp2;
		temp2=temp2->left;
		} 
		cur->data=temp2->data;
		cur=temp2;
	}*/
		

	else if(cur->left!=NULL && cur->right!=NULL){//CASE 4
		if(parent->right==cur){
		temp1=cur->left;
		}
	/*MY ALTERNATIVE(NOT ROBUST)*/	
	if(parent->right==cur){
			temp1=cur->left;
			parent->right=cur->right;
			cur=cur->right;
			temp2=cur->left;
			while(temp2!=NULL){
				cur=temp2;
				temp2=temp2->left;
			}
			cur->left=temp1;
		
		}
		if(parent->left==cur){
			temp1=cur->left;
			parent->left=cur->right;
			cur=cur->right;
			temp2=cur->left;
			while(temp2!=NULL){
				cur=temp2;
				temp2=temp2->left;
			}
			cur->left=temp1;
		
		}
	}
	cout<<"deletion successful..\n";
}

int main(){
	node*root=NULL;
	char c=0;
	int i=0;
	cout<<"\t\t\tBST Implementation\n\n";
	cout<<" 1.) Insert a character to BST.\n";
	cout<<" 2.) Print the BST in INORDER Transversal.\n";
	cout<<" 3.) Print the BST in PREORDER Transversal.\n";
	cout<<" 4.) Print the BST in POSTORDER Transversal.\n";
	cout<<" 5.) Search a character in the BST.\n";
	cout<<" 6.) Quit.\n";
	int flag=1;
	while(i!=6){
		cout<<"\nEnter the function you want to use : ";
		cin>>i;
		
		if(i==1||i==2||i==3||i==4||i==5||i==6||i==7){
		if(i==6){
		flag=0;break;}
		switch(i){
			case 1 : cout<<"Enter the character to be inserted : ";cin>>c;insert(&root,c);break;
			case 2 : if(root!=NULL){cout<<"Inorder : ";inorder(root);cout<<endl;}else cout<<"no element in the BST\n";break;
			case 3 : if(root!=NULL){cout<<"Preorder : ";preorder(root);cout<<endl;}else cout<<"no element in the BST\n";break;
 			case 4 : if(root!=NULL){cout<<"Postorder : ";postorder(root);cout<<endl;}else cout<<"no element in the BST\n";break;
 			case 5 : cout<<"enter the element to be searched : ";cin>>c;if(search(root,c))cout<<"Element found\n";else cout<<"element not found\n";break;
		 	case 7 : cout<<"enter the element to be deleted : ";cin>>c;Delete(root,c);break;
			case 6 : flag=0;
		 }
		 fflush(stdin);
		 }
		 else
		 {
		 cout<<"unappropriate function used terminating the program\n";break;}
		 if(flag==0)break;
	}
	return 0;
}
