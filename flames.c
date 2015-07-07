#include<stdio.h>
#include<string.h>

void captilize(char str[]){
	int i;
	for(i=0;str[i]!='\0';i++){
		if( (str[i]>=65 && str[i]<=90) || str[i] == 32) 
			continue;
		str[i]-=32;
	}
}

int sum(int arr[]){
	int i,s=0;
	for(i=0;i<6;i++){
		s+=arr[i];
	}
	return s;
}

int diff(char name1[] , char name2[]){
	int count = 0,i,hash[91];
	memset(hash,0,91*sizeof(int));
	captilize(name1);
	captilize(name2);
	for(i=0;name1[i];i++){
		if(name1[i]!=32){
			hash[name1[i]]++;
			count++;
		}
	}
	for(i=0;name2[i];i++){
		if(name2[i]!=32){
			if( hash[name2[i]] ){
				hash[name2[i]]--;
				count--;
				continue;
			}
			count++;
		}	
	}		
	return count;
}
char flames(int n){
	char s[6] = "FLAMES";
	int len = strlen(s);
	int i=0,j=n,flag[len];
	memset(flag,0,6*sizeof(int));
	do{
		for(i=0;i<len;i++){
			if(flag[i] == 0){
				j--;
				if(!j) {
					flag[i] = 1;
					j=n;
				}
			}
		}
	}while(sum(flag)!=5);
	for(i=0;i<6;i++)
		if(!flag[i])
			return s[i];
}
int main(void) {
	char name1[64],name2[64];
	fgets(name1,sizeof(name1),stdin);
	fgets(name2,sizeof(name2),stdin);
	int d = diff(name1,name2);
	printf("%c",flames(d));
	return 0;
}
