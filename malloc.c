#include <stdio.h>
#include <malloc.h>

int main(){
	int a[5] = {1,2,3,4,5};
	int len;
	int i;
	printf("�����붯̬�����ڴ�ĳ���");
	scanf("%d",&len);
	
	int * pArr=(int *)malloc(sizeof(int) * len);
	//*pArr=4 �൱�� a[0]=4;
	//���ǿ��԰�pArr����һ����ͨ������ʹ��
	for(i=0;i<len;i++) {
		scanf("%d",&pArr[i]);
	}
	for(i=0;i<len;i++) {
		printf("%d\n",pArr[i]);
	}
	free(pArr);  //�ͷ��ڴ� 
	return 0;
}
