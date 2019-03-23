#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int data ;//存放结点的数据
	struct Node * pNext ;//存放下一个结点的地址 指针域 
}NODE, * PNODE;  //NODE代表 struct Node PNODE代表struct Node * 

PNODE createList(void);
void traverseList(PNODE pHead);
bool is_empty(PNODE pHead);
int lengthList(PNODE);
bool insertList(PNODE,int,int);
bool deleteList(PNODE,int,int *);
void sortList(PNODE);
int main(){
	//创建一个链表
	PNODE pHead = NULL; //创建一个指向头结点的指针pHead 
	pHead=createList(); //创建一个非循环链表 并将该链表的头地址返回给pHead中 
	traverseList(pHead); //遍历链表
	insertList(pHead,3,9);
	traverseList(pHead);
	return 0;
}
PNODE createList(void){
	int len;//链表长度 
	int val; //用户输入的值
	int i;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//分配一个不存放有效地址的头结点
	if(pHead==NULL) {
		printf("分配失败");
		exit(-1);
	}
	PNODE pTail = pHead;//创建一个指向尾节点的指针，此时存放pHead的地址 
	pTail->pNext=NULL;
	printf("请输入结点的长度");
	scanf("%d",&len);
	for(i=0;i<len;i++) {
		printf("请输入第%d个结点的值",i+1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(pNew==NULL){
			printf("分配内存失败");
			exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
		
	}
	return pHead;
}
void traverseList(PNODE pHead) {
	PNODE p=pHead->pNext;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->pNext;
	}
}
bool is_empty(PNODE pHead){
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}
int lengthList(PNODE pHead){
	PNODE p=pHead->pNext;
	int i=0;
	if(p->pNext!=NULL){
		i++;
		p->pNext;
	}
	return i;
}
void sortList(PNODE pHead){
	int len = lengthList(pHead);
	int i,j,t;
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext){
		for(j=i+1,q=pHead->pNext; i<len;j++,q=q->pNext){
			if(p->data>q->data){
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
		}
	}
}
bool insertList(PNODE pHead,int pos,int val){
	int i=0;
	PNODE p=pHead;
	while(NULL!=p&&i<pos-1){
		p=p->pNext;
		++i;
	}
	if(NULL==p||i>pos-1){
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew==NULL){
		printf("动态分配内存失败");
		exit(-1);
	}
	pNew->data=val;
	PNODE q=p->pNext;
	p->pNext=pNew;
	pNew->pNext=q;
	return true;
}
bool deleteList(PNODE pHead,int pos,int *pVal){
	int i=0;
	PNODE p=pHead;
	while(p->pNext!=NULL&&i<pos-1){
		p=p->pNext;
		++i;
	}
	if(NULL==p->pNext||i>pos-1){
		return false;
	}
	//删除p之后的结点 
	PNODE q = p->pNext;
	*pVal=q->data;
	p->pNext=p->pNext->pNext;
	free(q);
	q=NULL;
	return true; 
}
