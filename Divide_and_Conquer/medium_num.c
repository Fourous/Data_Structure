#include <stdio.h>
//first quicksort
//second find the medium number

int partition(int a[],int first,int end){
	int i=first;
	int j=end;
	while(i<j){
		while(i<j&&a[i]<=a[j])	j--;
		if(i<j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
		}
		while(i<j&&a[i]<=a[j])	i++;
		if (i<j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			j--;
		}
	}
	return i;
}
void quicksort(int *a,int first,int end){
	int pivot;
	if(first<end){
		pivot=partition(a,first,end);
		quicksort(a,first,pivot-1);
		quicksort(a,pivot+1,end);
	}
}
int main (void){
	int a[5]={3,5,2,9,4};
	quicksort(a,0,4);
printf("the medium number is  %d\n",a[4/2] );

	return 0;

}