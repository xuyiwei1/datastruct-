/*

	2019��3��22�� 18:36:04  ��̬ջ�Ĳ��� v2.0 

*/


#include <stdio.h>	
#define MaxSize 50
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top; //ָ��ջ��Ԫ�� 
}SqStack;

void InitSack(SqStack &S){
	
	S.top= -1;
	
} 

bool IsEmpty (SqStack &S){
	if(S.top == -1){
		return true;
	}
	else
	{
		return false;
	}
}

bool Push(SqStack &S,ElemType x){
	if(S.top == MaxSize - 1){
		printf("��̬ջ����\n");
		return false;
	}else{
		S.data[++S.top] = x;
		return true;
	}
}


bool Pop(SqStack &S, ElemType * x){
	if(S.top == -1){
		printf("��̬ջΪ\n");
		return false;
	}
	
	*x = S.data[S.top--];
	
	return true;
}

ElemType GetElem(SqStack &S){
	if(S.top == -1){
		printf("��̬ջΪ��\n");
		return NULL;
	}else{
		return S.data[S.top];
	}
}


int main(void){
	
	
	
	return 0;
}




















/*

	2019��3��21�� 22:58:58 review 

*/ 

/*

#include <stdio.h>
#define MaxSize 50
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;//�洢ջ��Ԫ�ص��±� 
}SqStack;

void InitStack(SqStack &S){ //�β�Ϊȡ��ַ����ʱ�����ýṹ���е�Ԫ��Ҫ��. 
	S.top = -1; //ָ��ջ�׵������һ��Ԫ��
	return; 
}

bool IsEmpty(SqStack S){//����Ҫ��ջ�ڵ�Ԫ�ؽ��в��������Բ��ü�ȡ��ַ�� 
	if(S.top == -1){
		return true;
	}else{
		return false;
	}
}

bool Push(SqStack &S , ElemType x){
	if(S.top == MaxSize-1){
		printf("��̬ջ�������޷�ѹջ\n");
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

ElemType Pop(SqStack &S){ //��pop��ֵ���� 
	ElemType x;
	if(IsEmpty(S)){
		return NULL;//���ص�ʱEmelType���� ����������ķ���ֵ�ǿɱ仯�� 
	}
	x = S.data[S.top--] ;//�����S.top--��ʾ�Ȱ�S.top��ֵ��ֵ��x�������1 
	return x;
}


bool GetElem(SqStack S , ElemType &x){
	if(S.top == -1){
		return false;
	}
	x = S.data[S.top];
	return true;
}

int main(void) {
	
	ElemType x;
	SqStack S;
	InitStack(S);
	Push(S,1);
	Push(S,2);
	Push(S,3);
	Push(S,4);
	x=Pop(S);
	printf("��ջ��ֵΪ %d\n",x) ;
	
	
	return 0;
}

*/

/*
	
	2019��3��21�� 22:34:11  ת��csdn 
	
*/
/*

//˳��ջ�Ļ�������
#include<stdio.h>
#define MaxSize 50
typedef int ElemType;

//����ջ�ṹ��
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;


//��ʼ��ջ
void InitStack(SqStack &S) //ԭ�򣺣�SqStack &S �������ڵ����β�ʱ����дȡ��ַ����& InitStack(S) 
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
bool Pop(SqStack &S,ElemType x)
{
	if(S.top == -1)
	return false;
	x = S.data[S.top--];
	printf("%d\n",x); //Ϊ�鿴ջ�ĳ�ջԪ��
	return true;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack S,ElemType &x)
{
	if(S.top == -1)//ջΪ�� 
	return false;
	x = S.data[S.top];
	printf("%d\n",x); //Ϊ�鿴ջ��ջ��Ԫ��
	return true;
}


int main()
{
	SqStack s;
	int m,x;
	InitStack(s);
	Push(s,3);
	Push(s,9);
	Push(s,17);
	Pop(s,x);
	m = StackEmpty(s);
	GetTop(s,x);
	printf("%d\n",m);
	
	return 0;
}


*/
