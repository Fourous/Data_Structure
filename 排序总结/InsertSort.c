/*插入排序是看成，数组本来有序，然后插入另一个数，数组仍然保持有序状态*/
#include <stdio.h>
#include <stdlib.h>

void SelectSort(int *a,int n){
  int i,j,temp;
  for (int i = 1; i < n; i++) {
      temp=a[i];
      int j=i-1;//调试发现，这句得加在前面，不然数组会越界，出现段错误。
      for (j=i-1;j>=0&&temp<a[j] ; j--) {
        a[j+1]=a[j];
      }
      a[j+1]=temp;
  }
}

int main(void){
  int a[]={3,5,2,9,1,4};
  SelectSort(a,6);
  for (int i = 0; i < 6; i++) {
    printf("%d  ",a[i] );
  }
  return 0;
}
