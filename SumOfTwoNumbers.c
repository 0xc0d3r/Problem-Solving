#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

node *num1 = NULL,*num2 = NULL,*res = NULL;

int isNull(node *start) {
    if(start == NULL) return 1;
    else return 0;
}

void display(node *start) {
    if(!isNull(start)) {
        node *temp;
        for(temp=start;temp->next;temp=temp->next) 
            printf("%d ",temp->data);
        printf("%d\n",temp->data);
    }
}


node *insertAtEnd(node *start, int num) {
    node *temp,*newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = NULL;
    // printf("insertAtEnd\n");
    if(isNull(start)) start = newNode;
    else {
        for(temp = start;temp->next;temp=temp->next);
        temp->next = newNode;
    }
    return start;
}

void sum(node *n1, node *n2){
    node *temp1 = n1, *temp2 = n2;
    int output,carry = 0,rem;
    while(temp1&&temp2){
        output = temp1->data + temp2->data + carry;
        rem = output%10;
        carry = output/10;
        res = insertAtEnd(res,rem);
        temp1=temp1->next;
        temp2=temp2->next;
    }

    for(;temp1;temp1=temp1->next){
        rem = (temp1->data + carry)%10;
        carry = (temp1->data +carry)/10;
        res = insertAtEnd(res,rem);
    }

    for(;temp2;temp2=temp2->next){
        rem = (temp2->data + carry)%10;
        carry = (temp2->data +carry)/10;
        res = insertAtEnd(res,rem);
    }
    if(carry) res = insertAtEnd(res,carry);
}

int main(void){
    int val;
    char ch;
    do{
        scanf("%d%c",&val,&ch);
        num1 = insertAtEnd(num1,val);
        //display(num1);
    }while(ch!='\n');

    do{
        scanf("%d%c",&val,&ch);
        num2 = insertAtEnd(num2,val);
    }while(ch!='\n');

    sum(num1,num2);
    display(res);
    return 0;
}