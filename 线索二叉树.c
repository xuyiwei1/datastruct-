/*

	2019��3��24�� 19:18:52 δ��� 

*/



#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
//Link(0)��ʾָ�����Һ��ӵ�ָ��
//Thread(1)��ʾָ��ǰ����̵����� 
typedef enum {
	Link, 
	Thread
}PointerTag;

BiThrNode pre;//ȫ�ֱ���ָ��ǰ�ڵ��ǰһ���ڵ� ���ոշ��ʹ��Ľ�㣩 

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
		InThreading(T->lchild); //�ݹ������������� 
		//�������Ĳ���
		if(!T->lchild){ //������Ϊ�� ��������������lTag,����lchildָ��ոշ��ʹ��Ľ�� 
			T->lTag = Thread;
			T->lchild = pre; 	
		}
		
		if(!pre->rchild){ //������Ϊ�� ������������ ,
			pre->rTag = Thread;
			pre->rchild = T;  //�����pre�ǵ�ǰ�ڵ��ǰ���ڵ㣬����Ҫ����preָ��ĺ�̽ڵ�ΪT 
		}
		pre = T; //�ƶ��ڵ㵽��ǰ��ָ���λ��
		 
		InThreading(T->rchild); //�ݹ������������� 
	}
}


int main(void){
	
	BiThrTree T = NULL;
	CreateBiTree(); 
	
	return 0;
}


