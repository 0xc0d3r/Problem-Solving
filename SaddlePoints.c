#include<stdio.h>
int m,n;

void print_saddle_points(int mat[][n]){
	int isSaddle = 0, count = 0,i,j,k;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			for(isSaddle=0,k=0;k<n;k++){
				if(mat[i][j] < mat[i][k]){
					isSaddle = 1;
					break;
				}
			}
			for(k=0;k<m;k++){
				if(mat[i][j] > mat[k][j]){
					isSaddle = 1;
					break;
				}
			}
			if(!isSaddle){
				count++;
				printf("(%d,%d)\n",i,j );
			}
		}
	}
	if(!count) printf("No saddle points");
}

int main(void) {
	int i,j;
	scanf("%d %d",&m,&n);
	int mat[m][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	print_saddle_points(mat);
	return 0;
}
