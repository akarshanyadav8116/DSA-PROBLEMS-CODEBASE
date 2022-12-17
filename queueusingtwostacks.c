#include<stdio.h>
#include<stdlib.h>
#define max 6
struct stack{
	int a[max];
	int top;
};
typedef struct stack stack;
struct queue{
	stack *s1;
	stack *s2;
};
typedef struct queue queue;
int isempty(queue *q){
	if(q->s1->top<0){
		return 1;
	}
	return 0;
}
int isfull(queue *q){
	if(q->s1->top==max-1){
		return 1;
	}
	return 0; 
}
void enqueue(queue *q,int item){
	if(isfull(q)){
		printf("Queue full\n");
	}
	else{
		q->s1->top=q->s1->top+1;
		q->s1->a[q->s1->top]=item;
	}
}
int dequeue(queue *q){
	int copy;
	if(isempty(q)){
		printf("Queue Empty\n");
	}
	else{
		while(!isempty(q)){
			q->s2->top=q->s2->top+1;
			q->s2->a[q->s2->top]=q->s1->a[q->s1->top];
			q->s1->a[q->s1->top]=0;
			q->s1->top--;
		}
		copy=q->s2->a[q->s2->top];
		q->s2->a[q->s2->top]=0;
		q->s2->top--;
		while(q->s2->top>=0){
			enqueue(q,q->s2->a[q->s2->top]);
			q->s2->a[q->s2->top]=0;
			q->s2->top--;
		}
	}
	return copy;
}
void printqueue(queue *q){
	if(isempty(q)){
		printf("Queue Empty\n");
	}
	else{
		int i=0;
		while(i<=q->s1->top){
			printf("%d ",q->s1->a[i]);
			i++;
		}
		printf("\n");
	}
}
int main(){
	queue *q;
	q=(queue*)malloc(sizeof(queue));
	q->s1->top=-1;
	q->s2->top=-1;
	enqueue(q,100);
	enqueue(q,200);
	enqueue(q,300);
	enqueue(q,400);
	enqueue(q,500);
	printqueue(q);
	enqueue(q,600);
	enqueue(q,700);
	enqueue(q,800);
	printqueue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	printqueue(q);
	enqueue(q,500);
	enqueue(q,600);
	enqueue(q,700);
	enqueue(q,800);
	printqueue(q);
	dequeue(q);
	dequeue(q);
	printqueue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	printqueue(q);
	return 0;
}
