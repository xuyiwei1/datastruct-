
/*

	2019��3��23�� 10:53:16 

*/
#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>

typedef int ElemType;

struct Arr {
	ElemType * pBase;
	int len;
	int cnt;
}; 

void initArr(struct Arr * pArr, int length){
	pArr->pBase = (ElemType *) malloc(sizeof(ElemType)*length);
	if(pArr->pBase == NULL){
		printf("�����ʼ��ʧ�ܣ�\n");
	}
	pArr->cnt = 0;
	pArr->len = length;
} 

bool IsEmpty(struct Arr * pArr){
	if(pArr->cnt == 0){
		printf("����Ϊ�� \n");
		return true;
	}else{
		return false;
	}
}

bool IsFull(struct Arr * pArr){
	if(pArr->cnt == pArr->len){
		printf("�������� \n");
		return true;
	}else{
		return false;
	}
	 
}

bool insertArr(struct Arr * pArr,ElemType x ,ElemType pos){
	int i;
	if(IsFull(pArr)){
		printf("�������� \n");
		return false;
	}
	
	if(pos<1 || pos>pArr->len+1){
		printf("�����λ�ó������� \n");
		return false;
	}
	
	for( i = pArr->cnt-1 ; i>=pos-1;i--){ //��pos֮���Ԫ�غ��� 
			pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = x;//������Ϊpos-1��λ�ò���Ԫ�� 
	pArr->cnt++;
	pArr->len++;
	return true;
	
}

bool appendArr(struct Arr * pArr , ElemType val){
	if(IsFull(pArr)){
		printf("arry is full \n");
		return false;
	}
	pArr->pBase[pArr->cnt] = val;
	pArr->cnt++;
	return true;
}

void travserseArr(struct Arr * pArr){
	int i;
	if(IsEmpty(pArr)){
		printf("arry is empty, no value\n");
	}else{
		for(i = 0 ; i<pArr->cnt ; i++){
			printf("��%d��ֵΪ%d \n",i+1,pArr->pBase[i]);
		}
	}
}

int main(void){
	
	struct Arr arr;
	int val;
	initArr(&arr,8);
	appendArr(&arr, 1);
	appendArr(&arr, 2);
	appendArr(&arr, 3);
	appendArr(&arr, 4);
	appendArr(&arr, 5);
	
	travserseArr(&arr);
	return 0;
}
















/*
*
*2019��3��15�� 22:20:44 
*
*/ 

/*
#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>

struct Arr {
	int * pBase; //������׵�ַ ������������int a[len] ;  �Ȱ����׵�ַ �ְ�������ĳ��� 
	int len;  //����ĳ��� 
	int cnt; //��������ЧԪ�صĸ��� ��1��ʼ 
};

void init_arr(struct Arr * ,int );//��ʼ��˳��洢������
bool append_arr(struct Arr *, int) ;//���������һ��Ԫ��׷��һ��Ԫ��
void show_arr(struct Arr *) ;//�����������Ԫ�� 
bool is_full(struct Arr *);
bool insert_arr(struct Arr *, int , int ); //����һ��Ԫ�� ���ĸ�λ�ò��� �����ֵ�Ƕ��� 
bool is_empty(struct Arr *) ;
bool delete_arr(struct Arr *,int ,int *);//ɾ��һ��Ԫ��  ɾ���ĸ�λ�õ�Ԫ�� ɾ��Ԫ�ص�ֵ�Ƕ��� 
void sort_arr(struct Arr *);//�������е�Ԫ������ 
void inversion_arr(struct Arr * pArr);//���������е�����Ԫ�� 


int main(void) 
{
	struct Arr arr;
	int val;
	
	init_arr(&arr,6) ; 
	append_arr(&arr, 3);
	append_arr(&arr, 1);
	append_arr(&arr, 5);
	append_arr(&arr, 6);
	append_arr(&arr, 8);
	append_arr(&arr, 0);
	
	
	show_arr(&arr);
	
	if(delete_arr(&arr, 3 , &val)){
		printf("ɾ���ɹ���ɾ����Ԫ����%d \n",val);
	}else{
		printf("ɾ��ʧ�ܣ�\n"); 
	}
	inversion_arr(&arr);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);

	show_arr(&arr);
	
	return 0;
}

void init_arr(struct Arr * pArr , int length){
	pArr->pBase = (int *)malloc(sizeof(int)*length);
	if(pArr->pBase == NULL){
		printf("��̬�����ڴ�ʧ�ܣ�");
		exit(-1);
	}
	else{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool is_full(struct Arr * pArr){
	if(pArr->cnt == pArr->len){
		return true;
	}else{
		return false;
	}
}

bool is_empty(struct Arr * pArr) {
	if(pArr->cnt == 0){
		return true;
	}else{
		return false;
	}
}

bool append_arr(struct Arr * pArr, int val){
	if(is_full(pArr)){
		return false;
	}else{
		pArr->pBase[pArr->cnt] = val;
		(pArr->cnt)++; 
		
		return true;
	}
}

void show_arr(struct Arr * pArr){
	int i; 
	if(is_empty(pArr)){
		printf("����Ϊ�գ���ֵ��� \n");
		return; 
	}else{
		for(i=0;i<pArr->cnt;i++){
			printf("%d ",pArr->pBase[i]);
		}
		printf("\n");
	}
	return;
}

bool insert_arr(struct Arr * pArr, int pos, int val){
	int i;
	if(is_full(pArr)){
		return false;
	}
	
	if(pos<1||pos>pArr->cnt+1){ //�ڵ�һ��Ԫ��֮ǰ����Ԫ�غ������һ��Ԫ�صĺ�һ��Ԫ��֮ǰ����һ��Ԫ���ǺϷ��� 
		return false; 
	}
	
	for(i=pArr->cnt-1;i>=pos-1;i--){
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	
	pArr->pBase[pos-1] = val;
	(pArr->cnt)++;
	
	return true;
}

bool delete_arr(struct Arr * pArr , int pos , int * pVal) {
	
	int i;
	
	if(is_empty(pArr)){
		return false;
	}
	
	if(pos<1 || pos>pArr->cnt){ //ֻ��ɾ����һ��Ԫ�غ����һ��Ԫ�� 
		return false;
	}
	
	*pVal = pArr->pBase[pos-1];
	for(i=pos;i<pArr->cnt;i++){  
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	(pArr->cnt)--;
	
	return true; 
}

void sort_arr(struct Arr * pArr) {
	int i,j,t;
	for(i=0;i<pArr->cnt;i++) {
		for(j=i+1;j<pArr->cnt;j++){
			if(pArr->pBase[i]>pArr->pBase[j]){
				t=pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	return;
}

void inversion_arr(struct Arr * pArr) { //��һ��Ԫ�غ����һ��Ԫ�ؽ���˳�� �ڶ���Ԫ�غ͵����ڶ���Ԫ�ؽ���˳�� �Դ����� 
	int i;
	int j=pArr->cnt-1;
	int t;
	while(i<j){ //iС��jʱ���н��� 
		t=pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
	return ; 
}

*/




























/*


#include <stdio.h>
#include <malloc.h> //������malloc���� 
#include <stdlib.h> //������exit()���� 

struct Arr {
	int * pBase;//ָ������������׵�ַ 
	int len;//�������󳤶� 
	int cnt;//��ǰ�������Ч���� 
};

void init_arr(struct Arr *,int ) ;
void traverse_arr(struct Arr *);
bool is_empty(struct Arr *);

int main(){
	struct Arr array;
	init_arr(&array,6);
	traverse_arr(&array);
	
	return 0;
}

void init_arr(struct Arr * pArr,int length) {
	pArr->pBase = (int *) malloc(sizeof(int)*length);
	if(pArr->pBase == NULL){
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}else{
		pArr->cnt = 0;
		pArr->len = length;
	}
	
	return ;
}

bool is_empty(struct Arr * pArr){
	if(pArr->cnt==0){
		return true;
	}else{
		return false;
	}
}

void traverse_arr(struct Arr * pArr){
	if(is_empty(pArr)){
		printf("����Ϊ��");
	}else{
		for(int i=0;i<pArr->cnt;i++){
			printf("%d ",pArr->pBase[i]);
			
		}
		printf("\n");
	}
}

*/
