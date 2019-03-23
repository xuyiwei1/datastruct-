
/*

	2019年3月23日 10:53:16 

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
		printf("数组初始化失败！\n");
	}
	pArr->cnt = 0;
	pArr->len = length;
} 

bool IsEmpty(struct Arr * pArr){
	if(pArr->cnt == 0){
		printf("数组为空 \n");
		return true;
	}else{
		return false;
	}
}

bool IsFull(struct Arr * pArr){
	if(pArr->cnt == pArr->len){
		printf("数组已满 \n");
		return true;
	}else{
		return false;
	}
	 
}

bool insertArr(struct Arr * pArr,ElemType x ,ElemType pos){
	int i;
	if(IsFull(pArr)){
		printf("数组已满 \n");
		return false;
	}
	
	if(pos<1 || pos>pArr->len+1){
		printf("插入的位置超出界限 \n");
		return false;
	}
	
	for( i = pArr->cnt-1 ; i>=pos-1;i--){ //将pos之后的元素后移 
			pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = x;//在索引为pos-1的位置插入元素 
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
			printf("第%d个值为%d \n",i+1,pArr->pBase[i]);
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
*2019年3月15日 22:20:44 
*
*/ 

/*
#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>

struct Arr {
	int * pBase; //数组的首地址 或者这样定义int a[len] ;  既包含首地址 又包含数组的长度 
	int len;  //数组的长度 
	int cnt; //数组中有效元素的个数 从1开始 
};

void init_arr(struct Arr * ,int );//初始化顺序存储的数组
bool append_arr(struct Arr *, int) ;//给数组最后一个元素追加一个元素
void show_arr(struct Arr *) ;//遍历输出数组元素 
bool is_full(struct Arr *);
bool insert_arr(struct Arr *, int , int ); //插入一个元素 在哪个位置插入 插入的值是多少 
bool is_empty(struct Arr *) ;
bool delete_arr(struct Arr *,int ,int *);//删除一个元素  删除哪个位置的元素 删除元素的值是多少 
void sort_arr(struct Arr *);//给数组中的元素排序 
void inversion_arr(struct Arr * pArr);//倒置数组中的所有元素 


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
		printf("删除成功！删除的元素是%d \n",val);
	}else{
		printf("删除失败！\n"); 
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
		printf("动态分配内存失败！");
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
		printf("数组为空，无值输出 \n");
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
	
	if(pos<1||pos>pArr->cnt+1){ //在第一个元素之前插入元素和在最后一个元素的后一个元素之前插入一个元素是合法的 
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
	
	if(pos<1 || pos>pArr->cnt){ //只能删除第一个元素和最后一个元素 
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

void inversion_arr(struct Arr * pArr) { //第一个元素和最后一个元素交换顺序 第二个元素和倒数第二个元素交换顺序 以此类推 
	int i;
	int j=pArr->cnt-1;
	int t;
	while(i<j){ //i小于j时进行交换 
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
#include <malloc.h> //包含了malloc函数 
#include <stdlib.h> //包含了exit()函数 

struct Arr {
	int * pBase;//指向整型数组的首地址 
	int len;//数组的最大长度 
	int cnt;//当前数组的有效长度 
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
		printf("分配内存失败！\n");
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
		printf("数组为空");
	}else{
		for(int i=0;i<pArr->cnt;i++){
			printf("%d ",pArr->pBase[i]);
			
		}
		printf("\n");
	}
}

*/
