/*

	动态的创建一个二叉树 有误2019年3月24日 16:00:56 

*/

#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode * pRchild;
	struct BiTNode * pLchild;
}BiTree, * pBiTree;

//默认为先序遍历动态创建一个二叉树 
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
//访问二叉树节点的具体操作 
void visit(ElemType data , int level){
	printf("二叉树节点 %c 位于第 %d 层\n",data,level);
}

//前序遍历二叉树 
void PreBiTravserse(pBiTree pT , int level){
	//二叉树存在 不为 null 
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
