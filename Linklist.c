#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node* createalinklist(Node *start){
	if(start==NULL){
		char ch='Y';
		Node *p=NULL;
		while(ch=='Y'||ch=='y'){
			if(p==NULL){
				p=(Node*)malloc(sizeof(Node));
				printf("\nEnter the data :");
				scanf("%d",&(p->data));
				p->next=NULL;
				start=p;
			}
			else{
				p->next=(Node*)malloc(sizeof(Node));
				p=p->next;
				printf("\nEnter the data :");
				scanf("%d",&(p->data));
				p->next=NULL;
			}
			printf("Do you want to create a new node(Y/N)? :");
			fflush(stdin);
			scanf("\n");
			scanf("%c",&ch);
		}
	}
	else{
		char ch='N';
		printf("\nDo you want to delete the previous link list?(Y/N)");
		fflush(stdin);
		scanf("\n");
		scanf("%c",&ch);
		if(ch=='Y'||ch=='y'){
			Node *temp;
			while(start!=NULL){
				temp=start;
				start=start->next;
				free(temp);
			}
		}
	}
	return start;
}
void printlinklist(Node *start){
	if(start==NULL){
		printf("\nNo link list created to be printed....");
		printf("\nCreate a link list first....");
	}
	else{
		while(start!=NULL){
			printf("%d ",start->data);
			start=start->next;
		}
	}
}
void insertatend(Node *start){
	if(start==NULL){
		printf("\nNo link list created....\n");
		printf("Create a link list first....");
	}
	else{
		char ch='Y';
		while(start->next!=NULL){
			start=start->next;
		}
		while(ch=='Y'||ch=='y'){
			Node *p;
			p=(Node*)malloc(sizeof(Node));
			printf("\nEnter the data of the node to be inserted:");
			scanf("%d",&(p->data));
			start->next=p;
			p->next=NULL;
			start=p;
			printf("Do you want to insert another node at the same position(Y/N)? :");
			fflush(stdin);
			scanf("\n");
			scanf("%c",&ch);
		}
		printf("\nNodes inserted at end successfully....");
	}
}
void insertafterpos(Node *start,int pos){
	int i=1;
	if(start==NULL){
		printf("\nNo link list created....\n");
		printf("Create a link list first....");
	}
	else{
		char ch='Y';
		Node *copyhead=start;
		while(start->next!=NULL&&++i<=pos){
			start=start->next;
		}
		if(i<pos||pos<1){
			printf("\nThe position entered is incorrect......\n");
			return;
		}
		while(ch=='Y'||ch=='y'){
			Node *p;
			p=(Node*)malloc(sizeof(Node));
			printf("\nEnter the data of the node to be inserted:");
			scanf("%d",&(p->data));
			p->next=start->next;
			start->next=p;
			start=p;
			printf("Do you want to insert another node (Y/N)? :");
			fflush(stdin);
			scanf("\n");
			scanf("%c",&ch);
		}
		printf("\nNodes inserted at positions successfully....");
	}
}
Node* insertatpos(Node *start,int pos){
	int i=1;
	if(start==NULL){
		printf("\nNo link list created....\n");
		printf("Create a link list first....");
	}
	else{
		char ch='Y';
		Node *copyhead=start;
		while(start->next!=NULL&&++i<pos){
			start=start->next;
		}
		if(i<pos||pos<1){
			printf("\nThe position entered is incorrect......\n");
			start=copyhead;
			return start;
		}
		while(ch=='Y'||ch=='y'){
			Node *p;
			p=(Node*)malloc(sizeof(Node));
			printf("\nEnter the data of the node to be inserted:");
			scanf("%d",&(p->data));
			p->next=start->next;
			start->next=p;
			start=p;
			printf("Do you want to insert another node (Y/N)? :");
			fflush(stdin);
			scanf("\n");
			scanf("%c",&ch);
		}
		printf("\nNodes inserted at positions successfully....");
		start=copyhead;
	}
	return start;
}
Node* insertatbeg(Node *start){
	if(start==NULL){
		printf("\nNo link list created....\n");
		printf("Create a link list first....");
	}
	else{
		char ch='Y';
		while(ch=='Y'||ch=='y'){
			Node *p;
			p=(Node*)malloc(sizeof(Node));
			printf("\nEnter the data of the node to be inserted:");
			scanf("%d",&(p->data));
			p->next=start;
			start=p;
			printf("Do you want to insert another node at the beginning(Y/N)? :");
			fflush(stdin);
			scanf("\n");
			scanf("%c",&ch);
		}
		printf("\nNodes inserted at beginning successfully....");
	}
	return start;
}
Node* deletenode(Node *start,int pos){
	int i=1;
	if(start==NULL){
		printf("\nNo link list created....\n");
		printf("Create a link list first....");
	}
	else{
		char ch='Y';
		Node *copyhead=start;
		while(start->next!=NULL&&++i<pos){
			start=start->next;
		}
		if(i<pos||pos<1){
			printf("\nThe position entered is incorrect......\n");
			start=copyhead;
			return start;
		}
		Node *temp;
		if(pos==1){
			temp=start;
			start=start->next;
			free(temp);
		}
		else{
			temp=start->next;
			start->next=temp->next;
			free(temp);
			start=copyhead;
		}
	}
	return start;
}
Node* deletell(Node *start){
	if(start==NULL){
		printf("\nNo link list created....\n");
		printf("Create a link list first....");
	}
	else{
		char ch='N';
		printf("\nDo you want to delete the previous link list?(Y/N)");
		fflush(stdin);
		scanf("\n");
		scanf("%c",&ch);
		if(ch=='Y'||ch=='y'){
			Node *temp;
			while(start!=NULL){
				temp=start;
				start=start->next;
				free(temp);
			}
		}
	}
	return start;
}
int searchll(Node *start,int val){
	if(start==NULL){
		printf("\nNo link list created....\n");
		printf("Create a link list first....");
		return -2;
	}
	else{
		int i=1;
		while(start!=NULL){
			if(start->data==val){
			return i;
			}
		start=start->next;
		i++;
		}
	}
	return -1;
}
void swap(Node *p,Node *q){
	int temp;
	temp=p->data;
	p->data=q->data;
	q->data=temp;
}
void sortll(Node *start){
	if(start==NULL){
		printf("\nNo link list created....\n");
		printf("Create a link list first....");
	}	
	else{
		Node *start2,*pos;
		int min;
		while(start!=NULL){
			min=start->data;
			start2=start->next;
			pos=start;
			while(start2!=NULL){
				if(min>start2->data){
					min=start2->data;
					pos=start2;
				}
				start2=start2->next;
			}	
			swap(start,pos);
			start=start->next;
		}
	printf("\nLink list is sorted successfully......");
	}	
}
int main(){
	int op;
	struct node *head=NULL;
	while(1){
	system("cls");
	printf("Name : Akarshan Yadav\n");
	printf("Roll No. :2101640100022\n");
	printf("Section : CS II A\n\n");
	printf("\t\t\t\t\tMAIN MENU");
	printf("\n1)Create a link list");
	printf("\n2)Print all nodes");
	printf("\n3)Insert at beginning in the link list");
	printf("\n4)Insert at end in the link list");
	printf("\n5)Insert before a node in the link list");
	printf("\n6)Insert after a node in the link list");
	printf("\n7)Delete a node in the link list");
	printf("\n8)Delete the link list");
	printf("\n9)Search in link list");
	printf("\n10)Sort the link list");
	printf("\n11)Exit");
	printf("\nEnter the option :");
	scanf("%d",&op);
	switch(op){
		case 1:head=createalinklist(head);
				break;
		case 2:printlinklist(head);
				break;
		case 3:head=insertatbeg(head);
				break;
		case 4:insertatend(head);
				break;
		case 5:
			{
				int n;
				printf("\nEnter the position to insert a new node");
				scanf("%d",&n);	
				if(n==1){
					head=insertatbeg(head);
				}
				else{
					head=insertatpos(head,n);
				}
				break;
			}
		case 6:
			{
				int n;
				printf("\nEnter the position to insert a new node");
				scanf("%d",&n);	
				insertafterpos(head,n);
				break;
			}
		case 7:
			{
				char ch='Y';
				while(ch=='Y'||ch=='y'){
					int n;
					printf("\nEnter the position of the node to delete");
					scanf("%d",&n);
					head=deletenode(head,n);
					printf("Do you want to delete more nodes (Y/N)? :");
					fflush(stdin);
					scanf("\n");
					scanf("%c",&ch);
				}
				break;
			}
		case 8:
			{
				head=deletell(head);
				break;
			}
		case 9:
			{
				int flag=-1,n;
				printf("\nEnter the value you want to search :");
				scanf("%d",&n);
				flag=searchll(head,n);
				if(flag==-1){
					printf("Element not found");
				}
				else if(flag!=-2){
					printf("Element found at node %d",flag);
				}
				break;
			}
		case 10:
			{
				sortll(head);
				break;
			}
		case 11:exit(0);
		}
	getch();
	}
	return 0;
}
