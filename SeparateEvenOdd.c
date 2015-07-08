#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	int rem;
	struct Node *next;
}node;

node *start = NULL;

int isNull() {
    if(start == NULL) return 1;
    else return 0;
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
}

void display() {
    if(!isNull()) {
        node *temp;
        int space = 0;
        for(temp=start;temp;temp=temp->next){
        	if(temp->rem){
        		if(space) 
        			printf(" ");
        		space = 1;
        		printf("%d",temp->data);
        	}
        }
        for(temp=start;temp;temp=temp->next){
        	if(!temp->rem){
        		if(space) 
        			printf(" ");
        		space = 1;
        		printf("%d",temp->data);
        	}
        }
        space = 0;
        printf("\n");
        for(temp=start;temp;temp=temp->next){
        	if(!temp->rem){
        		if(space) 
        			printf(" ");
        		space = 1;
        		printf("%d",temp->data);
        	}
        }
        for(temp=start;temp;temp=temp->next){
        	if(temp->rem){
        		if(space) 
        			printf(" ");
        		space = 1;
        		printf("%d",temp->data);
        	}
        }
        printf("\n");
    }
}

int main(void) {
	int data;
	char ch;
	do{
		scanf("%d%c",&data,&ch);
		insertAtEnd(data);
	}while(ch!='\n');
	display();
	return 0;
}
