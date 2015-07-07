#include<stdio.h>
int main(void) {
	int m1,n1,m2,n2,i,j;
	scanf("%d %d",&m1,&n1);
	int A[m1][n1];
	for(i=0;i<m1;++i){
		for(j=0;j<n1;++j){
			scanf("%d",&A[i][j]);
		}
	}
	scanf("%d %d",&m2,&n2);
	int B[m2][n2];
	for(i=0;i<m2;++i){
		for(j=0;j<n2;++j){
			scanf("%d",&B[i][j]);
		}
	}
	if(n1!=m2){
		return 0;
	}
	int C[m1][n2],k,sum;
	for(i=0;i<m1;i++){
		for(k=0;k<n2;k++){
			sum=0;
			for(j=0;j<m2;j++)
				sum=sum+(A[i][j]*B[j][k]);
			C[i][k]=sum;
		}
	}

	for(i=0;i<m1;i++){
		for(j=0;j<n2-1;j++){
			printf("%d ", C[i][j]);
		}
		printf("%d\n",C[i][j]);
	}
	printf("\n");

	for(i=0;i<n2;i++){
		for(j=0;j<m1-1;j++){
			printf("%d ", C[j][i]);
		}
		printf("%d\n",C[j][i]);
	}
	printf("\n");
	return 0;
}
