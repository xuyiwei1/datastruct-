/*
	2019年3月16日 20:00:12 

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * pNext;
}NODE , *PNODE;

PNODE create_list(void) ;//创建一个链表，不用传递参数，因为不用改变结构体变量里面的值，只需要返回头指针就可以操作数组了 
void traverse_list(PNODE) ;//遍历数组 
bool insert_list(PNODE , int , int) ;//插入一个节点
bool delete_list(PNODE , int , int *) ;//删除一个节点 
int length_list(PNODE);
void sort_list(PNODE); 

int main(void){
	PNODE pHead = NULL;
	int val;
	
	pHead=create_list();
	traverse_list(pHead);
	
	insert_list(pHead , 3 , 9);
	traverse_list(pHead);
	if(delete_list(pHead, 1, & val)){
		printf("删除成功,值为%d \n", val );
		
	}else{
		printf("删除失败！");
	}
	traverse_list(pHead);
	printf("链表的长度为 %d \n",length_list(pHead));
	
	sort_list(pHead);
	traverse_list(pHead);
	
	return 0;
} 

PNODE create_list(void){
	int len,i,val;
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE)); //给头结点分配内存 pHead指向头结点的头指针 
	if(NULL==pHead){   //每次分配内存后都要判断一下内存是否分配成功 
		printf("动态分配内存失败！");
		exit(-1);
	}
	PNODE pTail = pHead; //刚开始尾指针和头指针都指向头结点 
	pTail->pNext = NULL; //刚开始头结点不指向任何结点 
	
	
	printf("请输入您要创建的链表的长度： ");
	scanf("%d",&len);
	
	for(i = 0 ;i<len;i++){
		PNODE pNew = (PNODE)malloc(sizeof(NODE)); //给新结点动态分配一块内存空间 pNew 为指向新节点的指针 
		if(pNew == NULL){
			printf("动态分配内存失败！\n");
			exit(-1); 
		}
		printf("请输入第%d个结点的值",i+1);
		scanf("%d",&val) ;
		
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
		
	}
	return pHead;
}

void traverse_list(PNODE pHead){
	PNODE p = NULL;
	p = pHead->pNext;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return ;
}

bool insert_list(PNODE pHead , int pos , int val) {
	int i = 0;
	PNODE p = pHead;
	while (p!=NULL && i<pos-1) { //将指针移动到pos的前一个节点的位置上 
		p = p->pNext;
		i++;
	}
	if(p==NULL || i>pos-1){
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("动态分配内存失败！ \n");
		exit(-1) ;
	}
	
	pNew->data = val; 
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	
	return true; 
	
}

bool delete_list(PNODE pHead , int pos , int * val){
	int i = 0;
	PNODE p = pHead;
	while(p!=NULL && i<pos-1){
		p = p->pNext;
		i++;
	}
	if(p==NULL || i>pos-1){
		return false;
	}
	
	PNODE r = p->pNext;
	p->pNext = r->pNext;
	*val = r->data;
	free(r);
	r = NULL; 
	return true;
	
}

int length_list(PNODE pHead){
	int i =0 ;
	PNODE p = pHead->pNext;
	
	while(p!=NULL){
		p = p->pNext;
		i++;
	}
	return i;
}

void sort_list(PNODE pHead){
	int i;
	int j;
	int t;
	PNODE p = NULL;
	PNODE q = NULL;
	for(i = 0 ,p=pHead->pNext ; i<length_list(pHead) ; p= p->pNext,i++){
		for(j = i+1 , q = p->pNext; j<length_list(pHead); q= q->pNext,j++){
			if(p->data > q->data){
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return ;
}







































/*
#include <stdio.h>
#include <malloc.h>
# include <stdlib.h>


typedef struct Node {
	int data;
	struct Node * pNext;
}NODE , *PNODE;

PNODE CreateList() ;//创建一个链表 
void traverseList(PNODE);//循环遍历链表 
bool Is_Empty(PNODE);
int ListLength(PNODE);
bool InsertList(PNODE,int,int);
bool DelectList(PNODE,int , int *) ;
void SortList(PNODE);

int main(void){
	PNODE pHead=NULL;
	pHead=CreateList();//创建一个链表,返回一个头指针，指向第一个头结点 
	traverseList(pHead);
	InsertList(pHead,3,9);
	traverseList(pHead);
	
}
PNODE CreateList(){
	int len;//创建链表有多长
	int val;//val用来存放用户输入的每一个节点的数据域的值 
	int i;
	PNODE pHead=(PNODE)malloc(sizeof(NODE));//给头结点分配一块动态内存，pHead指向它，头结点不存放有效地址
	if(pHead==NULL){
		printf("分配内存失败！") ;
		exit(-1) ;
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入链表的长度：") ;
	scanf("%d",&len);
	//遍历链表中所有结点，并给结点的数据域赋值 
	for(i=0;i<len;i++){
		printf("请输入第%d个结点的值",i+1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//给新的结点动态分配一块空间pNew指向这块空间的地址
		if (NULL == pNew)
		{
			printf("分配失败, 程序终止!\n");
			exit(-1);
		}
		
		pNew->data=val;//给新的结点数据域赋值 
		pTail->pNext=pNew;//链接两个结点 
		pNew->pNext=NULL;//给新结点的指针域赋值为空 
		pTail=pNew;//尾结点指向新结点 
				 
	}
	return pHead; 
}
void traverseList(PNODE pHead){
	PNODE p = pHead->pNext;
	while(p!=NULL)	{
		printf("%d ",p->data);
		p=p->pNext;
	}
	printf("\n");
} 
bool Is_Empty(PNODE pHead){
	if(pHead->pNext!=NULL){
		return false;
	}else{
		return true;
	}
}
int ListLength(PNODE pHead){
	int len=0;
	PNODE p = pHead->pNext;
	while(p!=NULL){
		len++;
		p=p->pNext;
	}
	return len;
} 
bool InsertList(PNODE pHead,int pos,int val){
	PNODE p=pHead;
	int i=0;
	while(p!=NULL&&i<pos-1){
		p=p->pNext;//找到指向pos位置的指针
		i++; 
	}
	if(p==NULL&&i>pos-1){
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew==NULL){
		printf("分配内存失败");
		exit(-1) ;
	}
	pNew->data=val;
//	PNODE q=p->pNext;//存放指向pos位置结点的地址 以此获得pos位置的结点（q->pNext）
//	p->pNext=pNew;
//	pNew->pNext=q; 
//两种写法 
	pNew->pNext=p->pNext;
	p->pNext=pNew;
	return true;
} 
bool DelectList(PNODE pHead,int pos, int * pVal){
	int i=0;
	PNODE p = pHead;
	while(NULL!=p->pNext&&i<pos-1){
		p=p->pNext;
		++i;
	}
	if(NULL==p->pNext&&i>pos-1){
		return false;
	}
	PNODE q = p->pNext;
	*pVal = q->data;
	p->pNext=p->pNext->pNext;
	free(q);
	q=NULL;
	return true;
	
}
void SortList(PNODE pHead) {
	int i;
	int j;
	PNODE p,q;
	len=ListLength(pHead);
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext){
		for(j=i+1,q=p->pNext;i<len;++j,q=q->pNext){
			if(p->data>q->data){
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
		}
	}
}
*/
