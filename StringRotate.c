#include<stdio.h>
#include<string.h>
int get_consonant_count(char s[]){
	int count = 0,i;
	for(i=0; s[i]; ++i){
		if(s[i] =='a' || s[i] =='e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') continue;
		count++;
	}
	return count;
}
char *rotate(char s[], int key){
	int i,j,slen = strlen(s),count = get_consonant_count(s);
	for(i=0;i<key%count;i++){
		
	}
}
int main(void){
	char str[64];
	int key;
	scanf("%s %d",str,&key);
	//printf("%d\n", get_consonant_count(str));
	printf("%s\n",rotate(str,key));
}