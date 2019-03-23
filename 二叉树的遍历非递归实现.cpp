/*
	
	2019��3��21�� 22:31:05 v1.0 ʵ�ַǵݹ��ǰ����� 
	bug:������ڵ�����ݵ�ͬʱ��������ڵ�ĵ�ַ 2019��3��21�� 22:32:32�����Pop()�����ж�л��һ�������� 

*/
//˳��ջ�Ļ�������
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

#define MaxSize 50

struct BTNode {
	char data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
};

typedef struct BTNode * ElemType;

//����ջ�ṹ��
typedef struct
{
	ElemType data[MaxSize];
	int top;
	
}SqStack;


//��ʼ��ջ
void InitStack(SqStack &S)
{
	S.top = -1;	
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
if(S.top == -1)
	return true; //ջΪ��
	else
	return false;
}

//��ջ
bool Push(SqStack &S,ElemType x)
{
if(S.top == MaxSize-1)
	return false;
	S.data[++S.top] = x;
	return true;
}

//��ջ
struct BTNode *  Pop(SqStack &S)
{
	ElemType x;
	if(S.top == -1)
	return NULL;
	x = S.data[S.top--];
	return x;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack S,ElemType x)
{
	if(S.top == -1)
	return false;
	x = S.data[S.top];
	//printf("%d\n",x); //Ϊ�鿴ջ��ջ��Ԫ��
	return true;
}


struct BTNode * CreateBTree(void){

	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pF = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pG = (struct BTNode *)malloc(sizeof(struct BTNode));
	
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pF->data = 'F';
	pG->data = 'G';
	
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pD;
	pB->pRchild = NULL;
	pC->pLchild = pE;
	pC->pRchild = pF;
	pD->pLchild = NULL;
	pD->pRchild = pG;
	pE->pLchild = pE->pRchild = NULL;
	pF->pLchild = pF->pRchild = NULL;
	pG->pLchild = pG->pRchild = NULL;
	
	return pA;
	
}



void PreOrderTravserse(struct BTNode * b){ //���ڵ㴫������� 
	SqStack S;
	InitStack(S);
	struct BTNode * p = b;
	while(p||!StackEmpty(S)){
		while(p){
			printf("%c \n",p->data);
			Push(S,p);
			p = p->pLchild;
		}
		if(!StackEmpty(S)){
			p = Pop(S);
			p = p->pRchild;
		}
	}
}

void InOrderTravserse(struct BTNode * b){
	SqStack S;
	InitStack(S) ;
	struct BTNode * p = b;
	while(p || !StackEmpty(S)){
		while(p){
			Push(S,p);//�ҵ�������������ߵ������� 
			p = p->pLchild;
		}
		p = Pop(S);//�ҵ�����ߵ�������Ȼ�ĸ��ڵ�
		printf("%c \n",p->data);//Ȼ������ڵ��ֵ 
		p = p->pRchild;//������������� 
	}
	return ;
}

void OutOrderTravserse(struct BTNode * b) {
	SqStack S;
	InitStack(S);
	struct BTNode * p = b;
	struct BtNode * r = NULL;
	while(p || !StackEmpty(S)){
		if(p){
			Push(S,p);
			p = p->pLchild;
		}
		else{
			GetTop(S,p);
			if(p->pRchild && p->pRchilid != r){
				p = p->pRchild;
			}else{
				Pop(S)
				printf("%c\n",p->data);
				r = p;
				p = NULL;
			}
		}
		
	}
}

int main()
{
	struct BTNode * pT = CreateBTree();
	PreOrderTravserse(pT);
	printf("\n");
	InOrderTravserse(pT);
	
	return 0;
}


