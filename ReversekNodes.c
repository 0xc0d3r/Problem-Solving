#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	int rem;
	struct Node *next;
}node;

node *start = NULL;
int length = 0,space = 0;

int isNull() {
    if(start == NULL) return 1;
    else return 0;
}

void display(node *start) {
    if(!isNull()) {
        node *temp = start;;
        for(;temp;temp=temp->next){
        	if(space && !temp->next) printf("%d",temp->data);
        	else printf("%d ",temp->data);
        }
    }
}

void insertAtEnd(int num) {
    node *temp,*newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    newNode->rem = num&1;
    newNode->next = NULL;
    if(isNull()) start = newNode;
    else {
        for(temp = start;temp->next;temp=temp->next);
        temp->next = newNode;
    }
    length++;
}

void reverse(int k){
	node *temp = start,*prev = NULL;
	int i;
	for(i=0;i<k&&temp;i++){
		node *nextNode = temp->next;
		temp->next = prev;
		prev = temp;
		temp = nextNode;
	}
	start = prev;
	display(start);
	start = temp;
}

int main(void) {
	int k,num,temp;
	char ohNoo;
	scanf("%d",&k);
	do{
		scanf("%d%c",&num,&ohNoo);
		insertAtEnd(num);
	}while(ohNoo!='\n');
	temp = length/k;
	if( length%k ) temp++;
	while(temp--){
		if(temp == 0)
			space = 1;
		reverse(k);
	}
	return 0;
}