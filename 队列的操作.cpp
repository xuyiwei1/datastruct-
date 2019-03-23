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
