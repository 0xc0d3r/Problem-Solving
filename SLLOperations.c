#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node *next;
}node;

node *head;

int length(void){
	if(!(head->next)) return 0;
	node *temp = head->next;
	int len = 1;
	for(;temp->next;temp=temp->next) len++;
	return len;
}

void display(void){
	node *temp = head->next;
	while(temp->next){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
}

void insert(int val){
	node *temp,*newNode,*prev=NULL;
	prev=head;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = val;
	newNode->next = NULL;

	for(temp=head->next;temp;temp=temp->next){
		if(temp->data >= val)
			break;
		prev=temp;
	}
	newNode->next=temp;
	prev->next=newNode;
}

void delete(int pos){
	if(pos > length() || pos < 0) {
		return;
	}
	node *temp,*prev;
	int p=1;
	if(pos == 1){
		head = head->next;
	}
	else{
		for(temp=head->next;temp->next && p<pos;temp=temp->next,p++) prev = temp;
		prev->next = temp->next;
	}

}
int main(void){
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	int data,flag=1;
	char op[4];
	while(flag){
		scanf("%s",op);
		switch(op[0]){
			case 'I':
				scanf("%d",&data);
				insert(data);
				break;
			case 'D':
				scanf("%d",&data);
				delete(data);
				break;
			case 'd':
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