#include <stdio.h>
#include <malloc.h>

int main(){
	int a[5] = {1,2,3,4,5};
	int len;
	int i;
	printf("请输入动态分配内存的长度");
	scanf("%d",&len);
	
	int * pArr=(int *)malloc(sizeof(int) * len);
	//*pArr=4 相当于 a[0]=4;
	//我们可以把pArr当做一个普通数组来使用
	for(i=0;i<len;i++) {
		scanf("%d",&pArr[i]);
	}
	for(i=0;i<len;i++) {
		printf("%d\n",pArr[i]);
	}
	free(pArr);  //释放内存 
	return 0;
}
