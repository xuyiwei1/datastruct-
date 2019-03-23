/*

	静态的实现一个树（树中结点的数据事先给出,不用用户输入）事先给出的树的信息详见笔记 
	2019年3月19日 22:45:16 

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
	//创建节点 
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));//树的根节点A
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	
	//给节点的数据域赋值 
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';

	
	//连接节点（给节点加弧） 
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
	struct BTNode * pT = CreateBTree();//创建指向根节点的指针，根节点的数据域可能存放很多数据，占用空间大，所以使用指针指向根节点
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
//	先访问根节点
//再先序访问左子树
//再先序访问右子树
	if(pT!=NULL) {
		printf("%c ",pT->data);
		 if(pT->pLchild!=NULL){
		 	PretraverseBTree(pT->pLchild); //可以代表整个左子树pT->pLchild 
		 }
		 if(pT->pRchild!=NULL){
		 	PretraverseBTree(pT->pRchild);
		 }
	}
}
void IntraverseBTree(struct BTNode *pT){
	if(pT!=NULL) {
		 if(pT->pLchild!=NULL){
		 	PretraverseBTree(pT->pLchild); //可以代表整个左子树pT->pLchild 
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
		 	PretraverseBTree(pT->pLchild); //可以代表整个左子树pT->pLchild 
		 }
		 if(pT->pRchild!=NULL){
		 	PretraverseBTree(pT->pRchild);
		 }
		 printf("%c ",pT->data);
	}
}
*/
