#include<stdio.h>

void printPattern(int n){
	int i,j,k,l,r=1,rows = 2*n-1,num=1,dn=n;
	while(r<=rows){
		for(i=1;i<=rows;i++){
			if(r<=n){
				for(j=n;j>i;j--)
					printf(" ");
				for(k=1;k<=i;k++)
					printf("%d",num++);
				num--;
				for(l=1;l<i;l++)
					printf("%d",--num);
			}
			else{
				for(j=n;j<i;j++)
					printf(" ");
				for(k=1;k<dn;k++)
					printf("%d", num++);
				num--;
				for(l=1;l<dn-1;l++)
					printf("%d", --num);
				dn--;
			}
			printf("\n");
			r++;
			num=1;
		}
	}
}
int main() {
	int n;
	scanf("%d",&n);
	printPattern(n);

	return 0;
}