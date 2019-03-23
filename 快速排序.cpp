#include <stdio.h>

void QuickSort(int * , int , int );
int FindPos(int * , int ,int );
int main(void){
	
	int a[6]={3,1,0,-2,9,6};
	int i;
	QuickSort(a,0,5);
	for(i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
void QuickSort(int * a, int low, int high){
	int pos;
	if(low<high){
		pos=FindPos(a,low,high);//�ҵ���һ��Ԫ��׼ȷλ�� 
		QuickSort(a,low,pos-1);//�ֳ����룬������� 
		QuickSort(a,pos+1,high);//�ұ����� 
	}
}
int FindPos(int * a, int low,int high) {
	int val=a[low];
	while(low<high){
		while(low<high&&a[high]>=val){
			--high;
		}
		a[low]=a[high];
		while(low<high&&a[low]<=val){
			++low;
		}
		a[high]=a[low];
	}//��ֹѭ����low��highһ����� 
	a[low]=val;
	return high;//����low; 
}
