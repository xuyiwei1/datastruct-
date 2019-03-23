#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int data ;//��Ž�������
	struct Node * pNext ;//�����һ�����ĵ�ַ ָ���� 
}NODE, * PNODE;  //NODE���� struct Node PNODE����struct Node * 

PNODE createList(void);
void traverseList(PNODE pHead);
bool is_empty(PNODE pHead);
int lengthList(PNODE);
bool insertList(PNODE,int,int);
bool deleteList(PNODE,int,int *);
void sortList(PNODE);
int main(){
	//����һ������
	PNODE pHead = NULL; //����һ��ָ��ͷ����ָ��pHead 
	pHead=createList(); //����һ����ѭ������ �����������ͷ��ַ���ظ�pHead�� 
	traverseList(pHead); //��������
	insertList(pHead,3,9);
	traverseList(pHead);
	return 0;
}
PNODE createList(void){
	int len;//������ 
	int val; //�û������ֵ
	int i;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//����һ���������Ч��ַ��ͷ���
	if(pHead==NULL) {
		printf("����ʧ��");
		exit(-1);
	}
	PNODE pTail = pHead;//����һ��ָ��β�ڵ��ָ�룬��ʱ���pHead�ĵ�ַ 
	pTail->pNext=NULL;
	printf("��������ĳ���");
	scanf("%d",&len);
	for(i=0;i<len;i++) {
		printf("�������%d������ֵ",i+1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(pNew==NULL){
			printf("�����ڴ�ʧ��");
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
		printf("��̬�����ڴ�ʧ��");
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
	//ɾ��p֮��Ľ�� 
	PNODE q = p->pNext;
	*pVal=q->data;
	p->pNext=p->pNext->pNext;
	free(q);
	q=NULL;
	return true; 
}
