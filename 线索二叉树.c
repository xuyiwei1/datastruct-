/*

	2019年3月24日 19:18:52 未完成 

*/



#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
//Link(0)表示指向左右孩子的指针
//Thread(1)表示指向前驱后继的线索 
typedef enum {
	Link, 
	Thread
}PointerTag;

BiThrNode pre;//全局变量指向当前节点的前一个节点 （刚刚访问过的结点） 

typedef struct BiThrNode{
	char data;
	struct BiThrTree * lchild;
	struct BiThrTree * rchild;
	PointerTag lTag;
	PointerTag rTag;
}BiThrNode , * BiThrTree;

void CreateBiThrTree(BiThrTree * T){
	char c;
	scanf("%c",&c);
	if(' ' == c){
		*T == NULL;
	}else {
		(*T) = (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data = c;
		(*T)->rTag = Link;
		(*T)->lTag = Link;
		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

void InThreading(BiThrTree T){
	if(T){
		InThreading(T->lchild); //递归线索化左子树 
		//线索化的操作
		if(!T->lchild){ //左子树为空 线索化左子树的lTag,设置lchild指向刚刚访问过的结点 
			T->lTag = Thread;
			T->lchild = pre; 	
		}
		
		if(!pre->rchild){ //右子树为空 线索化右子树 ,
			pre->rTag = Thread;
			pre->rchild = T;  //这里的pre是当前节点的前驱节点，所以要设置pre指向的后继节点为T 
		}
		pre = T; //移动节点到当前的指针的位置
		 
		InThreading(T->rchild); //递归线索化右子树 
	}
}


int main(void){
	
	BiThrTree T = NULL;
	CreateBiTree(); 
	
	return 0;
}


