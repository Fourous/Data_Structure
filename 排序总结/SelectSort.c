/*选择排序，取出最小元素，放在起始位置，直到序列排完*/
//选定第一个作为比较，然后++，从后扫描，遇到小的就将其交换
#include <stdio.h>
#include <stdlib.h>

void SelectSort(int *a,int n){
  int i,j;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (a[i]>a[j]) {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
  }
}

int main(void){
  int a[]={4,2,6,7,1,9};
  SelectSort(a,6);
  for (int i = 0; i <6; i++) {
      printf("%d  ",a[i]);
  }
  return 0;
}
