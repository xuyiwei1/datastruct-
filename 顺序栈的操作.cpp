/*

	2019年3月22日 18:36:04  静态栈的操作 v2.0 

*/


#include <stdio.h>	
#define MaxSize 50
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top; //指向栈顶元素 
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
		printf("静态栈已满\n");
		return false;
	}else{
		S.data[++S.top] = x;
		return true;
	}
}


bool Pop(SqStack &S, ElemType * x){
	if(S.top == -1){
		printf("静态栈为\n");
		return false;
	}
	
	*x = S.data[S.top--];
	
	return true;
}

ElemType GetElem(SqStack &S){
	if(S.top == -1){
		printf("静态栈为空\n");
		return NULL;
	}else{
		return S.data[S.top];
	}
}


int main(void){
	
	
	
	return 0;
}




















/*

	2019年3月21日 22:58:58 review 

*/ 

/*

#include <stdio.h>
#define MaxSize 50
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;//存储栈顶元素的下标 
}SqStack;

void InitStack(SqStack &S){ //形参为取地址符号时，调用结构体中的元素要用. 
	S.top = -1; //指向栈底的下面的一个元素
	return; 
}

bool IsEmpty(SqStack S){//不许要对栈内的元素进行操作，所以不用加取地址符 
	if(S.top == -1){
		return true;
	}else{
		return false;
	}
}

bool Push(SqStack &S , ElemType x){
	if(S.top == MaxSize-1){
		printf("静态栈已满，无法压栈\n");
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

ElemType Pop(SqStack &S){ //将pop的值返回 
	ElemType x;
	if(IsEmpty(S)){
		return NULL;//返回的时EmelType类型 ，所以这里的返回值是可变化的 
	}
	x = S.data[S.top--] ;//这里的S.top--表示先把S.top的值赋值给x在自身减1 
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
	printf("出栈的值为 %d\n",x) ;
	
	
	return 0;
}

*/

/*
	
	2019年3月21日 22:34:11  转自csdn 
	
*/
/*

//顺序栈的基本操作
#include<stdio.h>
#define MaxSize 50
typedef int ElemType;

//定义栈结构体
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;


//初始化栈
void InitStack(SqStack &S) //原因：？SqStack &S 主函数在调用形参时不用写取地址符号& InitStack(S) 
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
bool Pop(SqStack &S,ElemType x)
{
	if(S.top == -1)
	return false;
	x = S.data[S.top--];
	printf("%d\n",x); //为查看栈的出栈元素
	return true;
}

//获取栈顶元素
bool GetTop(SqStack S,ElemType &x)
{
	if(S.top == -1)//栈为空 
	return false;
	x = S.data[S.top];
	printf("%d\n",x); //为查看栈的栈顶元素
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
