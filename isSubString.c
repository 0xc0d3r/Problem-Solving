#include<stdio.h>
#include<string.h>
void to_upper(char s[]){
	int i;
	for(i=0;s[i];i++){
		if(s[i]>=97 && s[i]<=122)
			s[i]-=32;
	}
}
int is_sub_string(char str[],char substr[]){
	int len1 = strlen(str),len2 = strlen(substr),isSub = 0;
	if(len1>=len2 && str && substr){
		int find = 0,check,i,j;
		for(i=0;i<=(len1-len2);i++){
			if(str[i] == substr[0]){
				check=0;
				for(j=0;j<len2;j++){
					if(str[i+j]!=substr[j]){
						check=0;
						isSub = 0;
					}
					else{
						if(++check == len2) isSub=1;
					}
				}
			}
		}
	}
	return isSub;
}
int main(void) {
	char str[128],substr[128];
	scanf("%s %s",str,substr);
	to_upper(str);
	to_upper(substr);
	puts(is_sub_string(str,substr) ? "Yes" : "No");
	return 0;
}
