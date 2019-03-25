


/*

	2019年3月25日 21:09:09 正确算法 可能是因为文件的后缀名引起的c++不行 

*/


#include <stdio.h>
#include <malloc.h>

typedef char ElemType;

typedef struct BiTNode {
	char data;
	struct BiTNode * lchild, *rchild;
}BiTNode , *BiTree;

CreateBiTree(BiTree * T){
	char c;
	
	scanf("%c",&c);
	
	if(' ' == c){
		*T = NULL;
	}
	else
	{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

visit(char c , int level){
	
	printf("%c位于第%d层\n",c,level);
}

PreOrderTraverse(BiTree T , int level){
	
	if(T){
		visit(T->data , level);
		PreOrderTraverse(T->lchild , level+1);
		PreOrderTraverse(T->rchild , level+1);
		
	}
	
}

int main(){
	
	int level = 1;
	BiTree T = NULL;
	CreateBiTree(&T);
	PreOrderTraverse(T,level); 
	
	return 0;
}


/*
	
	 2019年3月25日 21:10:34 尝试先序创建二叉树时不写 * 失败 
	
	
*/
/* 
#include <stdio.h>
#include <malloc.h>

typedef char ElemType;

typedef struct BiTNode {
	char data;
	struct BiTNode * lchild, *rchild;
}BiTNode , *BiTree;

CreateBiTree(BiTree T){
	char c;
	
	scanf("%c",&c);
	
	if(' ' == c){
		T = NULL;
	}
	else
	{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		T->data = c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

visit(char c , int level){
	
	printf("%c位于第%d层\n",c,level);
}

PreOrderTraverse(BiTree T , int level){
	
	if(T){
		visit(T->data , level);
		PreOrderTraverse(T->lchild , level+1);
		PreOrderTraverse(T->rchild , level+1);
		
	}
	
}

int main(){
	
	int level = 1;
	BiTNode T ;
	CreateBiTree(&T);
	PreOrderTraverse(&T,level); 
	
	return 0;
}

*/

