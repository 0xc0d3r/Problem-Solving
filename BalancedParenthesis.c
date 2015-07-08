#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char bracket;
	struct Node *next;
	
}stack;

stack *top=NULL;

int isNull() {
    if(top == NULL) return 1;
    else return 0;
}

int pop(){
	stack *temp = top;
	if(!isNull()){
		char ch;
		ch = temp->bracket;
		top = top->next;
		return ch;
	}
	
}

void push(char ch) {
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->bracket = ch;
    newNode->next = NULL;
    if(isNull()) top = newNode;
    else {
        newNode->next = top;
        top = newNode;
    }
}
char getOpenBrace(char ch){
	if(ch == ')')
		return '(';
	else if (ch == '}')
		return '{';
	else if(ch == ']')
		return '[';
}

int main(void) {
	char str[128],temp;
	scanf("%s",str);
	int i;
	for(i=0;str[i];i++){
		switch(str[i]){
			case '(':
			case '{':
			case '[':
				push(str[i]);
				break;
			case ')':
			case '}':
			case ']':
				if(isNull()){
					printf("false");
					return 0;
				}
				else if(top->bracket != getOpenBrace(str[i])){
					printf("false");
					return 0;
				}
				else{
					temp = pop();
				}
		}
	}
	puts(isNull() ? "true" : "false");

	return 0;
}
