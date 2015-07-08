#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *start = NULL,*end = NULL;

int isNull() {
    if(start == NULL) return 1;
    else return 0;
}

void insert(int num) {
    node *temp = start,*newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = NULL;
    if(isNull()) {
    	start = newNode;
    	end = newNode;
    }
    else {
    	if(end->data < num) {
    		end->data = num;
    	}
    	else{
        	end->next = newNode;
        	end = newNode;
    	}
    }
}
void display() {
    if(!isNull()) {
        node *temp;
        for(temp=start;temp->next;temp=temp->next) 
        	printf("%d ",temp->data);
        printf("%d\n",temp->data);
    }
}
int main(void) {
	int num;
	char ch;
	do{
		scanf("%d%c",&num,&ch);
		insert(num);
	}while(ch!='\n');
	display();
	return 0;
}
