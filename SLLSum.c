node *sum(node *n1, node *n2){
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