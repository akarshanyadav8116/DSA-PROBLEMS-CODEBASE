#include<stdio.h>
#include<stdlib.h>
#define max 20
struct stack{
	int a[max];
	int top;
};
typedef struct stack stack;
int isempty(stack *st){
	if(st->top<0){
		return 1;
	}
	return 0;
}
int isfull(stack *st){
	if(st->top==max-1){
		return 1;
	}
	return 0; 
}
void push(stack *st,int item){
	if(isfull(st)){
		printf("Overflow");
	}
	else{
		st->top=st->top+1;
		st->a[st->top]=item;
	}
}
int pop(stack *st){
	if(isempty(st)){
		printf("Stack Underflow");
	}
	else{
		int temp=st->a[st->top];
		st->top=st->top-1;
		return temp;
	}
}
int top(stack *st){
	if(isempty(st)){
		printf("Stack Underflow");
	}
	return st->a[st->top];
}
void printstack(stack *st){
	if(isempty(st)){
		printf("Stack Underflow");
	}
	else{
		int i=st->top;
		while(i!=-1){
			printf("%d ",st->a[i--]);
		}
		printf("\n");
	}
}
int main(){
	stack *st;
	st=(stack*)malloc(sizeof(stack));
	st->top=-1;
	push(st,100);
	push(st,500);
	push(st,600);
	push(st,700);
	printstack(st);
	printf("The top element is %d\n",top(st));
	pop(st);
	printstack(st);
	printf("The top element is %d\n",top(st));
	pop(st);
	pop(st);
	printstack(st);
	pop(st);
	pop(st);
	return 0;
}
