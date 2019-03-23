#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node * pNext;
}NODE , * PNODE; 

typedef struct Stack{
	PNODE pTop;
	PNODE pBottom;
} STACK, * PSTACK;

void init(PSTACK);
void push(PSTACK , char);
bool pop(PSTACK,char *);
void traverse(PSTACK);
int isValid(char* );
bool IsEmpty(PSTACK);

int main(void){
	
	char s[4] = {'(' , '[' , ']' , ')'};
	if(isValid(s)==1){
		printf("true");
	}else{
		printf("false"); 
	}
	
	return 0;
}
int isValid(char* s) {
    Stack S;
	char val;
	int i;
	init(&S); 
	int len = strlen(s);
	for(i=0 ;i<len ;i++){
		switch(s[i]){
			case '[':
			case '(': push(&S,s[i]); break;
			case ')': 
				pop(&S,&val);
				if(val != '(')  return 0;
				break;
			case ']':
				pop(&S,&val);
				if(val != '[') return 0;
				break;
		}
	}
	if(IsEmpty(&S)) {
		return 1;
	}else{
		return 0;
	}
} 
void init (PSTACK pS){
	pS->pTop = (PNODE) malloc(sizeof(NODE));
	if(NULL==pS->pTop){
		printf("·ÖÅäÄÚ´æÊ§°Ü\n");
	}else{
		pS->pBottom=pS->pTop;
		pS->pTop->pNext= NULL;
	}
}
void push (PSTACK pS , char val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	
}
void traverse(PSTACK pS){
    PNODE p = pS->pTop;
    while(p!=pS->pBottom){
        printf("%c",p->data);
        p = p->pNext;
    }
    printf("\n");
}
bool pop(PSTACK pS,char * pVal){
	if(pS->pBottom!=pS->pTop){
		PNODE r = pS->pTop;
		pS->pTop = r->pNext;
		*pVal = r->data;
		free(r);
		r=NULL;
		return true;
	}else{
		printf("³öÕ»Ê§°Ü\n");
		return false;
	}
	
}
bool IsEmpty(PSTACK pS){
	if(pS->pBottom==pS->pTop){
		return true;
	}else{
		return false;
	}
}
