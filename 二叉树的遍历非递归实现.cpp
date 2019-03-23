/*
	
	2019年3月21日 22:31:05 v1.0 实现非递归的前序输出 
	bug:输出树节点的数据的同时会输出树节点的地址 2019年3月21日 22:32:32解决：Pop()函数中多谢了一个输出语句 

*/
//顺序栈的基本操作
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

//定义栈结构体
typedef struct
{
	ElemType data[MaxSize];
	int top;
	
}SqStack;


//初始化栈
void InitStack(SqStack &S)
{
	S.top = -1;	
}

//判断栈是否为空
bool StackEmpty(SqStack S)
{
if(S.top == -1)
	return true; //栈为空
	else
	return false;
}

//入栈
bool Push(SqStack &S,ElemType x)
{
if(S.top == MaxSize-1)
	return false;
	S.data[++S.top] = x;
	return true;
}

//出栈
struct BTNode *  Pop(SqStack &S)
{
	ElemType x;
	if(S.top == -1)
	return NULL;
	x = S.data[S.top--];
	return x;
}

//获取栈顶元素
bool GetTop(SqStack S,ElemType x)
{
	if(S.top == -1)
	return false;
	x = S.data[S.top];
	//printf("%d\n",x); //为查看栈的栈顶元素
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



void PreOrderTravserse(struct BTNode * b){ //根节点传入根节中 
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
			Push(S,p);//找到二叉树的最左边的左子树 
			p = p->pLchild;
		}
		p = Pop(S);//找到最左边的左子树然的根节点
		printf("%c \n",p->data);//然后输出节点的值 
		p = p->pRchild;//中序遍历右子树 
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


