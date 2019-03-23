#include <stdio.h>
#include <malloc.h>

typedef struct Queue {
	int * pBase;
	int rear; //存储队列的队尾元素的下一个元素的下标（数组中有一个元素不存放数据，用来判断数组是否已满） 
	int front; //存储队列队首元素 
} QUEUE; 

void init(QUEUE *);//因为要改变结构体变量中的值，所以要传递结构体指针QUEUE *
bool en_queue(QUEUE *, int ); //入队 int 为要入队的值 
void traverse_queue(QUEUE *); 
bool full_queue(QUEUE *);
bool out_queue(QUEUE * , int *); //int * pVal 保存了出队元素的值 要从函数中带出值必须使用指针类型变量 
bool empty_queue(QUEUE *) ;

int main(void){
	
	QUEUE Q; //声明了一个结构体变量 里面有三个变量
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
	
	if(out_queue(&Q,& val)){ //注意要传给函数val的地址否则无法返回出队的值（无法改变val的值） 
		printf("静态队列出队成功！出队的值为%d \n",val);
	}else{
		printf("静态队列出队失败！");
	}
	traverse_queue(&Q);
	
	return 0;
}
void init(QUEUE * pQ){
	pQ->pBase = (int *)malloc(sizeof(int)*6); //假设动态分配一个整型数组 长度为6 pBase是第一个元素的首地址
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
	while(i != pQ->rear ){ //当索引i不等于 尾部索引时 输出数组的值  PS:数组尾部索引的值为空 
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





