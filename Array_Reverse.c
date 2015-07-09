/*
	Program to reverse given array with O(n). No auxillary space required
*/
#include<stdio.h>
int main(void) {
	int array_size,array_index,first,last;
	scanf("%d",&array_size);
	int array[array_size];
	for(array_index=0;array_index<array_size;array_index++){
		scanf("%d",&array[array_index]);
	}
	for(first=0,last=array_index-1;first<last;first++,last--){
		array[first] = array[first] + array[last] - (array[last] = array[first]); //swapping first and last elements of given array
	}
	for(array_index=0;array_index<array_size;array_index++){
		printf("%d ", array[array_index]);
	}
	return 0;
}
