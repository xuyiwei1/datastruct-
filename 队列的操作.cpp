/*

	2019年3月24日 20:03:25静态循环队列的复习  静态循环队列中保留一个元素用来判断队列是否已满 

*/

#include <stdio.h>
#include <malloc.h>

struct Queue{
	int * pBase; //第一个元素的地址
	int rear;
	int front; 
	
}QUEUE;

void init_queue(struct Queue * pQ){
	pQ->pBase = (int *)malloc(sizeof(int)*6);//给整型数组分配空间
	pQ->front = 0;
	pQ->rear = 0;
	return; 
}

bool en_queue(Queue * pQ,int val ){
	if((pQ->rear+1)%6 == pQ->front){ //注意移动元素下标要这样移动因为是队列是循环的 
		printf("队列已满\n");
		return false;
	}
	else{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1)%6;
		return true;
	}
}

bool out_queue (Queue * pQ , int *  val){
	if(pQ->rear == pQ->front){
		printf("队列为空\n");
		return false; 
	}
	else{
		*val = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1)%6;
		return true;
	}
}

void travserse_queue(Queue * pQ){
	int i = pQ->front;
	while(i!=pQ->rear){
		printf("%d ",pQ->pBase[i]);
		i = (i+1)%6;
	}
	printf("\n");
	return ;
}


int main(void){
	
	
	return 0;
}










/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Queue{
	int * pBase;//第一个元素的地址 
	int front; //前面的数组的下标
	int rear; 
}QUEUE; 

void init(QUEUE *);
bool en_queue(QUEUE *,int);
void traverse_queue(QUEUE *);
bool out_queue(QUEUE *, int *);
int main(void){
	
	QUEUE Q; 
	int val;
	init(&Q);
	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);
	en_queue(&Q,7);
	traverse_queue(&Q);
	if(out_queue(&Q,& val)){
		printf("出队的元素是%d\n",val);
	}else{
		printf("出队失败");
		exit(-1);
	}
	traverse_queue(&Q);
	return 0;
}
void init(QUEUE * pQ){
	pQ->pBase=(int *)malloc(sizeof(int)* 6);
	pQ->front=0;
	pQ->rear=0;
}
bool en_queue(QUEUE * pQ,int val){
	if((pQ->rear+1)%6==pQ->front){
		return false;
	}else{
		pQ->pBase[pQ->rear]=val;
		pQ->rear=(pQ->rear+1)%6;
		return true;
	}
}
void traverse_queue(QUEUE * pQ){
	int i = pQ->front;
	while(i!=pQ->rear){//当第一个索引不等于最后一个的下一个索引 
		printf("%d ",pQ->pBase[i]);
		i=(i+1)%6;
	}
	printf("\n");
}
bool out_queue(QUEUE * pQ, int * pVal){
	if(pQ->front==pQ->rear){
		return false;
	}else{
		*pVal=pQ->pBase[pQ->front];
		pQ->front=(pQ->front+1)%6;
		return true;
	}
}
*/
