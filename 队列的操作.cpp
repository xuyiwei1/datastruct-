/*

	2019��3��24�� 20:03:25��̬ѭ�����еĸ�ϰ  ��̬ѭ�������б���һ��Ԫ�������ж϶����Ƿ����� 

*/

#include <stdio.h>
#include <malloc.h>

struct Queue{
	int * pBase; //��һ��Ԫ�صĵ�ַ
	int rear;
	int front; 
	
}QUEUE;

void init_queue(struct Queue * pQ){
	pQ->pBase = (int *)malloc(sizeof(int)*6);//�������������ռ�
	pQ->front = 0;
	pQ->rear = 0;
	return; 
}

bool en_queue(Queue * pQ,int val ){
	if((pQ->rear+1)%6 == pQ->front){ //ע���ƶ�Ԫ���±�Ҫ�����ƶ���Ϊ�Ƕ�����ѭ���� 
		printf("��������\n");
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
		printf("����Ϊ��\n");
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
	int * pBase;//��һ��Ԫ�صĵ�ַ 
	int front; //ǰ���������±�
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
		printf("���ӵ�Ԫ����%d\n",val);
	}else{
		printf("����ʧ��");
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
	while(i!=pQ->rear){//����һ���������������һ������һ������ 
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
