#include<stdio.h>
#include<string.h>
#define SIZE 123

void toLower(char str[]){
	int i;
	for(i=0;str[i]!='\0';i++){
		if(str[i] != 32 && (str[i]>=65 && str[i]<=90)) 
			str[i]+=32;
	}
}
void frequency(char s[]){
	toLower(s);
	int hash[123],i;
	memset(hash,0,123*sizeof(int));
	for(i=0;s[i];i++){
		if(s[i]!=32)
			hash[s[i]]++;
	}
	for(i=97;i<SIZE;i++){
		if(hash[i])
			printf("%c - %d\n", i,hash[i]);
	}
}
int main(void) {
	char str[128];
	scanf("%[^\n]s",str);
	frequency(str);
	return 0;
}
