#include <stdio.h>

int main(void){
	
	int n;
	int f1,f2,f3;
	int i;
	f1=1;
	f2=2;
	printf("请输入您需要求的项的序列 ");
	scanf("%d",&n) ;
	if(1==n){
		printf("1");
	} else if(2 == n){
		printf("2");
	} else {
		for(i=3;i<=n;++i) {
			f3=f1+f2;
			f1=f2;
			f2=f3;
		}
	}
	printf("%d ",f3);
	
	return 0;
}
