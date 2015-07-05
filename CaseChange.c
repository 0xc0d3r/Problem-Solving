#include<stdio.h>
int caseChange(char s[]){
	int i;
	for(i=0;s[i];i++){
		if(!((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)))
			return 0;
		s[i]^=32;
	}
	return 1;
}
int main(void) {
	char str[128];
	scanf("%s",str);
	puts(caseChange(str) ? str : "NONE");
	return 0;
}
