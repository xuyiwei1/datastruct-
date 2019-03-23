#include <stdio.h>
#include <malloc.h>

typedef struct Queue {
	int * pBase;
	int rear; //�洢���еĶ�βԪ�ص���һ��Ԫ�ص��±꣨��������һ��Ԫ�ز�������ݣ������ж������Ƿ������� 
	int front; //�洢���ж���Ԫ�� 
} QUEUE; 

void init(QUEUE *);//��ΪҪ�ı�ṹ������е�ֵ������Ҫ���ݽṹ��ָ��QUEUE *
bool en_queue(QUEUE *, int ); //��� int ΪҪ��ӵ�ֵ 
void traverse_queue(QUEUE *); 
bool full_queue(QUEUE *);
bool out_queue(QUEUE * , int *); //int * pVal �����˳���Ԫ�ص�ֵ Ҫ�Ӻ����д���ֵ����ʹ��ָ�����ͱ��� 
bool empty_queue(QUEUE *) ;

int main(void){
	
	QUEUE Q; //������һ���ṹ����� ��������������
	int val;
	
	init(&Q);
	en_queue(&Q , 1);
	en_queue(&Q , 2);
	en_queue(&Q , 3);
	en_queue(&Q , 4);
	en_queue(&Q , 5);
	en_queue(&Q , 6);
	en_queue(&Q , 7);
	en_queue(&Q , 8);
	en_queue(&Q , 9);
	traverse_queue(&Q);
	
	if(out_queue(&Q,& val)){ //ע��Ҫ��������val�ĵ�ַ�����޷����س��ӵ�ֵ���޷��ı�val��ֵ�� 
		printf("��̬���г��ӳɹ������ӵ�ֵΪ%d \n",val);
	}else{
		printf("��̬���г���ʧ�ܣ�");
	}
	traverse_queue(&Q);
	
	return 0;
}
void init(QUEUE * pQ){
	pQ->pBase = (int *)malloc(sizeof(int)*6); //���趯̬����һ���������� ����Ϊ6 pBase�ǵ�һ��Ԫ�ص��׵�ַ
	pQ->rear = 0 ;
	pQ->front = 0; 
}

bool full_queue(QUEUE * pQ){
	if( (pQ->rear+1) % 6 == pQ->front){
		return true;
	}else {
		return false;
	}
}

bool en_queue(QUEUE * pQ , int val) {
	if(full_queue(pQ)){
		return false;
	}else{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1)%6;
		return true;
	}
}

void traverse_queue(QUEUE * pQ){
	int i;
	i = pQ->front;
	while(i != pQ->rear ){ //������i������ β������ʱ ��������ֵ  PS:����β��������ֵΪ�� 
		printf("%d ",pQ->pBase[i]);
		i++;
	}
	printf("\n");
	return;
}

bool empty_queue(QUEUE * pQ){
	if(pQ->front == pQ->rear){
		return true;
	}else{
		return false;
	}
}

bool out_queue(QUEUE * pQ, int * pVal) {
	if(empty_queue(pQ)){
		return false;
	}else {
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1)%6;
		
		return true;
	}
}





