#include <stdio.h>

void hannuota(int n,char A,char B,char C){ //A->��ʼ���� B->�м����� C->Ŀ������ 
	//���A������ֻ��һ�����Ӿ�ֱ�Ӵ�A�ƶ���C
	//���� ��A�ϵ�n-1������ ���� C �ƶ��� B(�������ú���hannuota()) 
	//�ڰ� A�ϵĵ�n������ ��A�ƶ���C(��������printf) 
	//���� B�ϵ�n-1�����ӽ���A �ƶ��� C  
	if(1==n){
		printf("�����Ϊ%d�����Ӵ�%c�����ƶ���%c����\n",n,A,C);
	}else{
		hannuota(n-1,A,C,B);
		printf("�����Ϊ%d�����Ӵ�%c�����ƶ���%c����\n",n,A,C);
		hannuota(n-1,B,A,C);
		
	}
	
	
}

int main(){
	int n;
	char A='A';
	char B='B';
	char C='C';
	printf("�������ƶ����ӵĸ���:");
	scanf("%d",&n);
	hannuota(n,A,B,C);
	
	return 0;
}
