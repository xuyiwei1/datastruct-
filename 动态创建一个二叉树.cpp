/*

	��̬�Ĵ���һ�������� ����2019��3��24�� 16:00:56 

*/

#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode * pRchild;
	struct BiTNode * pLchild;
}BiTree, * pBiTree;

//Ĭ��Ϊ���������̬����һ�������� 
void CreateBiTree(pBiTree &pT){
	ElemType c;
	scanf("%c",&c);
	if(' ' == c){
		pT == NULL;
	}else{
		pT = (pBiTree)malloc(sizeof(BiTree));
		pT->data = c;
		CreateBiTree(pT->pLchild);
		CreateBiTree(pT->pRchild);
	}
}
//���ʶ������ڵ�ľ������ 
void visit(ElemType data , int level){
	printf("�������ڵ� %c λ�ڵ� %d ��\n",data,level);
}

//ǰ����������� 
void PreBiTravserse(pBiTree pT , int level){
	//���������� ��Ϊ null 
	if( pT ){ 
		visit(pT->data , level);
		PreBiTravserse(pT->pLchild , level + 1); 
		PreBiTravserse(pT->pRchild , level + 1); 
	}
} 

int main(void){
	
	pBiTree T = NULL;
	int level = 1;
	CreateBiTree(T);
	PreBiTravserse(T,level);
	
	return 0;
}
