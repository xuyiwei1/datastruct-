/*

		2019年3月17日 11:09:00 

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * pNext;
}NODE , * PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
}STACK , * PSTACK;

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK , int *);
bool is_empty(PSTACK);
void clear(PSTACK);


int main(void){
	
	STACK S;
	int val;
	
	init(&S);
	push(&S,1);
	push(&S,2);
	push(&S,3);
	push(&S,4);
	traverse(&S);
	
	if(pop(&S, &val)){
		printf("出栈成功，出栈的元素的值为%d \n",val);
	}else{
		printf("出栈失败  \n");
	}
	traverse(&S);
	clear(&S);
	
	push(&S,3);
	traverse(&S);
	
	return 0;
}

void init(PSTACK pS){
	pS->pBottom = (PNODE)malloc(sizeof(NODE));
	if(pS->pBottom == NULL){
		printf("分配内存失败 \n");
		exit(-1);
	}
	pS->pTop = pS->pBottom;
	pS->pBottom->pNext = NULL;
	
	return ;
}

void push(PSTACK pS,int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("分配内存失败！ \n");
		exit(-1) ;
	}
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	return ;
}

void traverse(PSTACK pS){
	PNODE p = pS->pTop;
	while(p!=pS->pBottom){
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return ; 
}

bool is_empty(PSTACK pS){
	if(pS->pBottom == pS->pTop){
		return true;
	}else{
		return false;
	}
}

bool pop(PSTACK pS , int * val){
	PNODE q = pS->pTop;
	if(is_empty(pS)){
		printf("栈内没有元素 \n");
		return false;
	}else{
		*val = pS->pTop->data;
		pS->pTop = q->pNext;
		free(q);
		q = NULL;
		return true;
	}
}

void clear(PSTACK pS){
	if(is_empty(pS)){
		return;
	}else {
		PNODE p = pS->pTop;
		PNODE q = NULL;
		while(p!=pS->pBottom){
			q = p->pNext ;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
	return ;
}



















































/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct Node{
	char data;
	struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack{
	PNODE pTop;
	PNODE pBottom;
}STACK,* PSTACK;

void init(PSTACK);
void push(PSTACK,char);
void traverse(PSTACK);
bool pop(PSTACK,char *);
void clear(PSTACK);

int main(void){
	STACK S;
	char val;
	
	init(&S);//栈的初始化
	push(&S,'c');//压入栈（进栈）
	push(&S,'d');
	push(&S,'e');
	push(&S,'f');
	traverse(&S);
	if(pop(&S,&val)){
		printf("出栈成功");
}else{
	printf("出栈失败");
}
	traverse(&S);
	clear(&S);
	return 0;
}
void init(PSTACK pS){
	pS->pBottom=(PNODE)malloc(sizeof(NODE));
	if(NULL==pS->pBottom){
		printf("动态分配内存失败");
		exit(-1);
	}else{
		pS->pTop=pS->pBottom;
		pS->pBottom->pNext=NULL;
	}
}
void push(PSTACK pS,char val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data=val;
	pNew->pNext=pS->pTop;
	pS->pTop=pNew;
	return;
}
void traverse(PSTACK pS){
	PNODE p=pS->pTop;
	while(p!=pS->pBottom){
		printf("%d ",p->data);
		p=p->pNext; 
	}
	printf("\n");
	return;
}
//把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中，如果出栈失败，返回false,否则返回true
bool pop(PSTACK pS,char * pVal){ //栈顶的元素出栈出栈  不能指定 
	if(pS->pBottom!=pS->pTop){
		PNODE r= pS->pTop;
		*pVal=r->data;
		pS->pTop=r->pNext;
		free(r);
		r=NULL;
		return true;
	}else{
		printf("出栈失败");
		return false;
	}
}
void clear(PSTACK pS){
	if (pS->pBottom==pS->pTop)
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;

		while (p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
	
}
*/
