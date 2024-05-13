#include<stdio.h>

int mergeCount;
int sortCount;

void merge(int arr[], int begin, int middle, int end){
	int i,j,k;
	int n1 = middle-begin+1;
	int n2 = end-middle;
	int left[n1];
	int right[n2];
	for(i=0; i<n1; i++){
		left[i]=arr[begin+i];
	}
	for(j=0;j<n2;j++){
		right[j]=arr[middle+j+1];
	}
	i=0;
	j=0;
	k=begin;
	
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			i++;
		}
		else{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	
	while(j<n2){
		arr[k]=right[j];
		j++;
		k++;
	}
	while(i<n1){
		arr[k]=left[i];
		i++;
		k++;
	}
	mergeCount++;
}

void mergeSort(int arr[], int begin, int end){
	if(begin<end){
		int middle=(begin+end)/2;
		mergeSort(arr,begin,middle);
		mergeSort(arr,middle+1,end);
		merge(arr,begin,middle,end);
	}
	if(begin<=end)
		sortCount++;
}

void main(){
	printf("\nEnter the number of elements");
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int m=0;m<size;m++){
		if(!(m==0 || m==1 || m==2)){
			printf("\nEnter %dth element\t",m+1);
			scanf("%d",&arr[m]);
		}
		else if(m==1){
			printf("\nEnter %dnd element\t",m+1);
			scanf("%d",&arr[m]);
		}
		else if(m==2){
			printf("\nEnter %drd element\t",m+1);
			scanf("%d",&arr[m]);
		}
		else{
			printf("\nEnter %dst element\t",m+1);
			scanf("%d",&arr[m]);
		}
	}
	mergeSort(arr,0,size-1);
	printf("\nSorted array is:\n");
	for(int m=0;m<size;m++){
		printf("%d\t",arr[m]);
	}
	printf("\nMerge function was called %d times recursively",mergeCount);
	printf("\nMergeSort function was called %d times recursively\n",sortCount);
	
}
	
		
	
