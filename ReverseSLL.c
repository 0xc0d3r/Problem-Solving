#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}node;

node *start = NULL;

int isNull() {
    if(start == NULL) return 1;
    else return 0;
}

void display() {
    if(!isNull()) {
        node *temp;
        for(temp=start;temp->next;temp=temp->next) 
        	printf("%d ",temp->data);
        printf("%d\n",temp->data);
    }
}

void insert(int num) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = NULL;
    if(isNull()) start = newNode;
    else {
        newNode->next = start;
        start = newNode;
    }
}


int main(void) {
	int data,flag=1;
	char op[4];
	while(flag){
		scanf("%s",op);
		switch(op[0]){
			case 'I':
				scanf("%d",&data);
				insert(data);
				break;
			case 'r':
				//printf("L = %d\n",length());
				display();
				break;
			case 'E':
				flag=0;
				break;
		}
	}
	return 0;
}
