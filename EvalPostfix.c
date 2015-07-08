#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
	
}stack;

stack *top=NULL;

int isNull() {
    if(top == NULL) return 1;
    else return 0;
}

int pop(){
	stack *temp = top;
	int num = temp->data;
	top = top->next;
	return num;
}

void push(int num) {
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->data = num;
    newNode->next = NULL;
    if(isNull()) top = newNode;
    else {
        newNode->next = top;
        top = newNode;
    }
}

int eval(int a,int b,char ch[]){
	return (ch[0] == '+') ? a+b : (ch[0] == '-') ? a-b : (ch[0] == '*') ? a*b : (ch[0] == '/') ? (b!=0) ? a/b: -1 : -1;
}


int main(void) {
	char ch[1],ohNoo,res = 0;
	do{
		scanf("%s%c",ch,&ohNoo);
		if(isdigit(ch[0])){
			push(atoi(ch));
		}
		else{
			res=eval(pop(),pop(),ch);
			push(res);
		}
	}while(ohNoo!='\n');
	printf("%d", res);
	return 0;
}
