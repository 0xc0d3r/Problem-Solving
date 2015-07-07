#include<stdio.h>
#include<string.h>
int search(int a[],int n,int target){
	int i;
	for(i=0;i<n;i++){
		if(a[i] == target) 
			return i;
	}
	return -1;
}
void sort_by_frequency(int a[],int n){
	int ele[32],freq[32],i,j,len = 1,temp;
	memset(freq,0,32*sizeof(int));
	ele[0] = a[0];
	freq[0] = 1;
	for(i=1;i<n;i++){
		temp = search(ele,len,a[i]);
		if(temp!=-1) freq[temp]++;
		else{
			ele[len] = a[i];
			freq[len++]++;
		}
	}
	//bubble sort
	int changed = 1;
	while(changed){
		changed = 0;
		for(i=0;i<len-1;i++){
			if(freq[i] <  freq[i+1]){
				freq[i] = freq[i] + freq[i+1] - (freq[i+1] = freq[i]);
				ele[i] = ele[i] + ele[i+1] - (ele[i+1] = ele[i]);
				changed = 1;
			}
		}
	}
	
	for(i=0;i<len;i++){
		for(j=0;j<freq[i];j++){
			printf(i|j?" %d":"%d", ele[i]);
		}
	}

}
int main(void) {
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort_by_frequency(arr,n);
	return 0;
}
