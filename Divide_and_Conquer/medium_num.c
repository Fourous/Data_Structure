#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	int n;
	float med;
	printf("please enter the number:    \n");
	scanf("%d",&n);
	srand((unsigned)time(NULL));
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		a[i]=rand()%100;
		printf("%d\n", a[i]);
	}
	quicksort(a,0,n);
	if (n%2==0)
	{
		med=(a[n/2]+a[(n/2)+1])/2;
		printf("%f\n",med );
	}else
printf("the medium number is  %d\n",a[n/2] );

	return 0;

}