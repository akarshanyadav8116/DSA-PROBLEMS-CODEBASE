#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coeff;
	int pow;
	struct Node *next;
};
typedef struct Node Node;
int main(){
	Node *head=NULL,*head2=NULL,*p=NULL,*p2=NULL,*head3=NULL,*p3=NULL;
	char ch='Y';
	while(ch=='Y'||ch=='y'){
		if(head==NULL){
			head=(Node*)malloc(sizeof(Node));
			printf("Enter the coeff :");
			scanf("%d",&head->coeff);
			printf("Enter the power :");
			scanf("%d",&head->pow);
			p=head;
		}
		else{
			p->next=(Node*)malloc(sizeof(Node));
			p=p->next;
			p->next=NULL;
			printf("Enter the coeff :");
			scanf("%d",&p->coeff);
			printf("Enter the power :");
			scanf("%d",&p->pow);
		}
		printf("Do you want to create more nodes? :");
		fflush(stdin);
		scanf("\n");
		scanf("%c",&ch);
	}
	/*while(p!=NULL){
		printf("%d %d\n",p->coeff,p->pow);
		p=p->next;
	}*/
	printf("\nEnter the 2nd polynomial:\n");
	ch='Y';
	while(ch=='Y'||ch=='y'){
		if(head2==NULL){
			head2=(Node*)malloc(sizeof(Node));
			printf("Enter the coeff :");
			scanf("%d",&head2->coeff);
			printf("Enter the power :");
			scanf("%d",&head2->pow);
			p2=head2;
		}
		else{
			p2->next=(Node*)malloc(sizeof(Node));
			p2=p2->next;
			p2->next=NULL;
			printf("Enter the coeff :");
			scanf("%d",&p2->coeff);
			printf("Enter the power :");
			scanf("%d",&p2->pow);
		}
		printf("Do you want to create more nodes? :");
		fflush(stdin);
		scanf("\n");
		scanf("%c",&ch);
	}
	p=head;
	p2=head2;
	while(p!=NULL&&p2!=NULL){
		if(p->pow==p2->pow){
			if(head3==NULL){
				head3=(Node*)malloc(sizeof(Node));
				head3->coeff=p->coeff+p2->coeff;
				head3->pow=p->pow;
				p3=head3;
			}
			else{
				p3->next=(Node*)malloc(sizeof(Node));
				p3=p3->next;
				p3->coeff=p->coeff+p2->coeff;
				p3->pow=p->pow;
			}
			p=p->next;
			p2=p2->next;
		}
		else if(p->pow<p2->pow){
			if(head3==NULL){
				head3=(Node*)malloc(sizeof(Node));
				head3->coeff=p2->coeff;
				head3->pow=p2->pow;
				p3=head3;
			}
			else{
				p3->next=(Node*)malloc(sizeof(Node));
				p3=p3->next;
				p3->coeff=p2->coeff;
				p3->pow=p2->pow;
			}
			p2=p2->next;
		}
		else{
			if(head3==NULL){
				head3=(Node*)malloc(sizeof(Node));
				head3->coeff=p->coeff;
				head3->pow=p->pow;
				p3=head3;
			}
			else{
				p3->next=(Node*)malloc(sizeof(Node));
				p3=p3->next;
				p3->coeff=p->coeff;
				p3->pow=p->pow;
			}
			p=p->next;
		}
	}
	while(p!=NULL){
		p3->next=(Node*)malloc(sizeof(Node));
		p3=p3->next;
		p3->coeff=p->coeff;
		p3->pow=p->pow;
		p=p->next;
	}
	while(p2!=NULL){
		p3->next=(Node*)malloc(sizeof(Node));
		p3=p3->next;
		p3->coeff=p2->coeff;
		p3->pow=p2->pow;
		p2=p2->next;
	}
	p3->next=NULL;
	p3=head3;
	printf("\nThe sum polynomial is:\n");
	while(p3!=NULL){
		printf("%dx^%d\n",p3->coeff,p3->pow);
		p3=p3->next;
	}
	return 0;
}
