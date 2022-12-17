#include<stdio.h>
#include<stdlib.h>
#define max 20
struct stack{
	int data;
	struct stack *next;
};
typedef struct stack stack;
int isempty(stack *st){
	if(st==NULL){
		return 1;
	}
	return 0;
}
int isfull(stack *st){
	if(st==NULL){
		return 1;
	}
	return 0;
}
stack* push(stack *st,int item){
	stack *p;
	p=(stack*)malloc(sizeof(stack));
	if(!isfull(p)){
		if(st==NULL){
			p->data=item;
			p->next=NULL;
			st=p;	
		}
		else{
			p->data=item;
			p->next=st;
			st=p;	
		}	
	}
	return st;
}
int pop(stack **st){
	if(isempty(*st)){
		printf("Stack Underflow");
	}
	else{
		int p;
		stack *q;
		p=(*st)->data;
		q=*st;
		*st=(*st)->next;
		free(q);
		return p;
	}
}
void printstack(stack *start){
	if(start==NULL){
		printf("No stack is created for printing.....");
	}
	else{
		stack *p;
		p=start;
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
int main(){
	stack *top;
	top=NULL;
	top=push(top,100);
	top=push(top,500);
	top=push(top,600);
	top=push(top,700);
	printstack(top);
	printf("\nThe top element is %d\n",top->data);
	pop(&top);
	printf("The top element is %d\n",top->data);
	pop(&top);
	pop(&top);
	printf("The top element is %d\n",top->data);
	top=push(top,800);
	top=push(top,900);
	top=push(top,1000);
	printstack(top);
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	return 0;
}
