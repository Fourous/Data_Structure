/*快速排序是一种分治法，将数列分成两个独立的部分，使其中一边数列其他数大，然后递归，到最后形成
有序的序列，首先将数进行分割partition,然后在quicksort递归调用函数。*/
#include <stdio.h>
#include <stdlib.h>

int partition(int *a,int first,int end){
  int i=first;
  int j=end;
  while (i<j) {
    //先进扫描，从右侧开始
    while (i<j&&a[i]<a[j])  j--;
    if(i<j){
      int temp=a[i];
      a[i]=a[i+1];
      a[i+1]=temp;
    }
    //右侧扫描
    while (i<j&&a[i]<a[j])  i++;
    if(i<j){
      int temp=a[i];
      a[i]=a[i+1];
      a[i+1]=temp;
    }
  }
  return i;
}

void QuickSort(int *a,int first,int end) {
  if(first<end){
    int priv=partition(a,first,end);
    QuickSort(a,first,priv);
    QuickSort(a,priv+1,end);
  }
}

int main(void){
  int a[]={1,3,5,2,8,7};
  QuickSort(a,0,6);
  for (int i = 0; i <6; i++) {
    printf("%d\n",a[i] );
  }
}
