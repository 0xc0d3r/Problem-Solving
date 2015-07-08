#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *start = NULL,*end = NULL;

int isNull() {
    if(start == NULL) return 1;
    else return 0;
}

int length(void){
	node *temp = start;
	int len=1;
	for(;temp->next!=start;temp=temp->next) 
		len++;
	return len;
}

void display(){
	printf("%d", start->data);
}

void insert(int num) {
    node *temp = start,*newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = start;
    if(isNull()) {
    	start = newNode;
    	end = newNode;
    }
	else{
    	end->next = newNode;
    	end = newNode;
	}
}
void execute(int skip){
	node *temp = start,*prev = end;
	int i=1;
	while(length()!=1){
		if(i<skip){
			prev = temp;
			temp=temp->next;
			i++;
		}
		else{
			prev->next = temp->next;
			if(temp == start)
				start = temp->next;
			temp = prev->next;
			i=1;
		}
	}
	display();
}
int main(void) {
	int n,skip,i;
	scanf("%d %d",&n,&skip);
	for(i=1;i<=n;i++)
		insert(i);
	execute(skip);
	return 0;
}