#include <stdio.h>

void hannuota(int n,char A,char B,char C){ //A->起始柱子 B->中间柱子 C->目标柱子 
	//如果A柱子上只有一个盘子就直接从A移动到C
	//否则 将A上的n-1个盘子 借助 C 移动到 B(借助调用函数hannuota()) 
	//在把 A上的第n个盘子 从A移动到C(不借助用printf) 
	//最后把 B上的n-1个盘子借助A 移动到 C  
	if(1==n){
		printf("将编号为%d的盘子从%c柱子移动到%c柱子\n",n,A,C);
	}else{
		hannuota(n-1,A,C,B);
		printf("将编号为%d的盘子从%c柱子移动到%c柱子\n",n,A,C);
		hannuota(n-1,B,A,C);
		
	}
	
	
}

int main(){
	int n;
	char A='A';
	char B='B';
	char C='C';
	printf("请输入移动盘子的个数:");
	scanf("%d",&n);
	hannuota(n,A,B,C);
	
	return 0;
}
