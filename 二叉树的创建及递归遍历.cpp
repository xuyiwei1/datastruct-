/*

	��̬��ʵ��һ���������н����������ȸ���,�����û����룩���ȸ�����������Ϣ����ʼ� 
	2019��3��19�� 22:45:16 

*/
#include <stdio.h> 
#include <malloc.h>

struct BTNode {
	char data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
};

struct BTNode * CreateBTree(void);
void PretraverseBTree(struct BTNode *);
void IntraverseBTree(struct BTNode *);
void PostraverseBTree(struct BTNode *);

int main(void){
	
	struct BTNode * pT = CreateBTree();
	//PretraverseBTree(pT);
	//IntraverseBTree(pT);
	PostraverseBTree(pT);
	
	return 0;
}

struct BTNode * CreateBTree(void){
	//�����ڵ� 
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));//���ĸ��ڵ�A
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	
	//���ڵ��������ֵ 
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';

	
	//���ӽڵ㣨���ڵ�ӻ��� 
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;
	
	return pA; 
	
}

void PretraverseBTree(struct BTNode * pT){
	if(pT != NULL){
		printf("%c\n",pT->data);
		if(pT != NULL){
			PretraverseBTree(pT->pLchild);
		}
		if(pT != NULL){
			PretraverseBTree(pT->pRchild);
		}
	}
}

void IntraverseBTree(struct BTNode * pT){
	if(pT != NULL){
		
		if(pT != NULL){
			IntraverseBTree(pT->pLchild);
		}
		
		printf("%c\n",pT->data);
		
		if(pT != NULL){
			IntraverseBTree(pT->pRchild);
		}
	}
}

void PostraverseBTree(struct BTNode * pT){
	if(pT != NULL){
		
		if(pT != NULL){
			PostraverseBTree(pT->pLchild);
		}
		
		if(pT != NULL){
			PostraverseBTree(pT->pRchild);
		}
		
		printf("%c\n",pT->data);
	}
}













































/*
#include <stdio.h>
#include <malloc.h>

struct BTNode {
	char data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
}; 
struct BTNode * CreateBTree();
void PretraverseBTree(struct BTNode *);
void IntraverseBTree(struct BTNode *);
void PostraverseBTree(struct BTNode *);
int main(){
	struct BTNode * pT = CreateBTree();//����ָ����ڵ��ָ�룬���ڵ����������ܴ�źܶ����ݣ�ռ�ÿռ������ʹ��ָ��ָ����ڵ�
	PretraverseBTree(pT);
	//IntraverseBTree(pT);
	//PostraverseBTree(pT);
	
	return 0;
}
struct BTNode * CreateBTree(void) {
	struct BTNode * pA =(struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB =(struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC =(struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD =(struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE =(struct BTNode *)malloc(sizeof(struct BTNode));
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';
	pA->pLchild=pB;
	pA->pRchild=pC;
	pB->pLchild=pB->pRchild=NULL;
	pC->pLchild=pD;
	pC->pRchild=pD->pLchild=NULL;
	pD->pRchild=pE;
	pE->pLchild=pE->pRchild=NULL;
	return pA;
	
}
void PretraverseBTree(struct BTNode * pT){
//	�ȷ��ʸ��ڵ�
//���������������
//���������������
	if(pT!=NULL) {
		printf("%c ",pT->data);
		 if(pT->pLchild!=NULL){
		 	PretraverseBTree(pT->pLchild); //���Դ�������������pT->pLchild 
		 }
		 if(pT->pRchild!=NULL){
		 	PretraverseBTree(pT->pRchild);
		 }
	}
}
void IntraverseBTree(struct BTNode *pT){
	if(pT!=NULL) {
		 if(pT->pLchild!=NULL){
		 	PretraverseBTree(pT->pLchild); //���Դ�������������pT->pLchild 
		 }
		 printf("%c ",pT->data);
		 if(pT->pRchild!=NULL){
		 	PretraverseBTree(pT->pRchild);
		 }
	}
}
void PostraverseBTree(struct BTNode *pT){
	if(pT!=NULL) {
		 if(pT->pLchild!=NULL){
		 	PretraverseBTree(pT->pLchild); //���Դ�������������pT->pLchild 
		 }
		 if(pT->pRchild!=NULL){
		 	PretraverseBTree(pT->pRchild);
		 }
		 printf("%c ",pT->data);
	}
}
*/
