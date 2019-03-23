/*
	2019��3��16�� 20:00:12 

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * pNext;
}NODE , *PNODE;

PNODE create_list(void) ;//����һ���������ô��ݲ�������Ϊ���øı�ṹ����������ֵ��ֻ��Ҫ����ͷָ��Ϳ��Բ��������� 
void traverse_list(PNODE) ;//�������� 
bool insert_list(PNODE , int , int) ;//����һ���ڵ�
bool delete_list(PNODE , int , int *) ;//ɾ��һ���ڵ� 
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
		printf("ɾ���ɹ�,ֵΪ%d \n", val );
		
	}else{
		printf("ɾ��ʧ�ܣ�");
	}
	traverse_list(pHead);
	printf("����ĳ���Ϊ %d \n",length_list(pHead));
	
	sort_list(pHead);
	traverse_list(pHead);
	
	return 0;
} 

PNODE create_list(void){
	int len,i,val;
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE)); //��ͷ�������ڴ� pHeadָ��ͷ����ͷָ�� 
	if(NULL==pHead){   //ÿ�η����ڴ��Ҫ�ж�һ���ڴ��Ƿ����ɹ� 
		printf("��̬�����ڴ�ʧ�ܣ�");
		exit(-1);
	}
	PNODE pTail = pHead; //�տ�ʼβָ���ͷָ�붼ָ��ͷ��� 
	pTail->pNext = NULL; //�տ�ʼͷ��㲻ָ���κν�� 
	
	
	printf("��������Ҫ����������ĳ��ȣ� ");
	scanf("%d",&len);
	
	for(i = 0 ;i<len;i++){
		PNODE pNew = (PNODE)malloc(sizeof(NODE)); //���½�㶯̬����һ���ڴ�ռ� pNew Ϊָ���½ڵ��ָ�� 
		if(pNew == NULL){
			printf("��̬�����ڴ�ʧ�ܣ�\n");
			exit(-1); 
		}
		printf("�������%d������ֵ",i+1);
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
	while (p!=NULL && i<pos-1) { //��ָ���ƶ���pos��ǰһ���ڵ��λ���� 
		p = p->pNext;
		i++;
	}
	if(p==NULL || i>pos-1){
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("��̬�����ڴ�ʧ�ܣ� \n");
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

PNODE CreateList() ;//����һ������ 
void traverseList(PNODE);//ѭ���������� 
bool Is_Empty(PNODE);
int ListLength(PNODE);
bool InsertList(PNODE,int,int);
bool DelectList(PNODE,int , int *) ;
void SortList(PNODE);

int main(void){
	PNODE pHead=NULL;
	pHead=CreateList();//����һ������,����һ��ͷָ�룬ָ���һ��ͷ��� 
	traverseList(pHead);
	InsertList(pHead,3,9);
	traverseList(pHead);
	
}
PNODE CreateList(){
	int len;//���������ж೤
	int val;//val��������û������ÿһ���ڵ���������ֵ 
	int i;
	PNODE pHead=(PNODE)malloc(sizeof(NODE));//��ͷ������һ�鶯̬�ڴ棬pHeadָ������ͷ��㲻�����Ч��ַ
	if(pHead==NULL){
		printf("�����ڴ�ʧ�ܣ�") ;
		exit(-1) ;
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("����������ĳ��ȣ�") ;
	scanf("%d",&len);
	//�������������н�㣬��������������ֵ 
	for(i=0;i<len;i++){
		printf("�������%d������ֵ",i+1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//���µĽ�㶯̬����һ��ռ�pNewָ�����ռ�ĵ�ַ
		if (NULL == pNew)
		{
			printf("����ʧ��, ������ֹ!\n");
			exit(-1);
		}
		
		pNew->data=val;//���µĽ��������ֵ 
		pTail->pNext=pNew;//����������� 
		pNew->pNext=NULL;//���½���ָ����ֵΪ�� 
		pTail=pNew;//β���ָ���½�� 
				 
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
		p=p->pNext;//�ҵ�ָ��posλ�õ�ָ��
		i++; 
	}
	if(p==NULL&&i>pos-1){
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew==NULL){
		printf("�����ڴ�ʧ��");
		exit(-1) ;
	}
	pNew->data=val;
//	PNODE q=p->pNext;//���ָ��posλ�ý��ĵ�ַ �Դ˻��posλ�õĽ�㣨q->pNext��
//	p->pNext=pNew;
//	pNew->pNext=q; 
//����д�� 
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
