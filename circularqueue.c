#include<stdio.h>
#include<stdlib.h>
#define max 5
struct queue{
	int a[max];
	int front;
	int rear;
};
typedef struct queue queue;
int isempty(queue *q){
	if(q->front==-1&&q->rear==-1){
		return 1;
	}
	return 0;
}
int isfull(queue *q){
	if(q->front==(q->rear+1)%max){
		return 1;
	}
	return 0;
}
void enque(queue *q,int item){			//performed at rear of the queue
	if(isfull(q)){
		printf("Overflow\n");
	}
	else if(q->front==-1&&q->rear==-1){
		q->front=q->rear=0;
		q->a[q->front]=item;
	}
	else{
		q->rear=((q->rear+1)%max);
		q->a[q->rear]=item;
	}
}
int deque(queue *q){
	if(isempty(q)){
		printf("Underflow\n");
	}
	else if(q->front==q->rear){
		q->a[q->front]=0;
		q->front=q->rear=-1;
	}
	else{
		int temp=q->a[q->front];
		q->a[q->front]=0;
		q->front=((q->front+1)%max);
		return temp;
	}
}
void printqueue(queue *q){
	int i;
	if(isempty(q)){
		printf("Underflow\n");
	}
	else{
		for(i=q->front;(i%max)!=q->rear;i++){
			printf("%d ",q->a[i%max]);
		}
		printf("%d ",q->a[i%max]);
		printf("\n");
	}
}
int main(){
	queue *q;
	q=(queue*)malloc(sizeof(queue));
	q->front=-1;
	q->rear=-1;
	enque(q,100);
	enque(q,200);
	enque(q,300);
	printqueue(q);
	enque(q,400);
	enque(q,500);
	printqueue(q);
	enque(q,600);
	printqueue(q);
	enque(q,700);
	enque(q,800);
	deque(q);
	deque(q);
	deque(q);
	printqueue(q);
	enque(q,700);
	enque(q,800);
	enque(q,900);
	printqueue(q);
	enque(q,1000);
	printqueue(q);
	return 0;
}
