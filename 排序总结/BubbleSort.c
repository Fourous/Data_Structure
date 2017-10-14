/*冒泡排序是将序列中相邻两位逐一比较，如果比较大，则交换向后，直到没有数字可以比较为止。*/
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *a,int n){
    int bound=0;
    int exchange=n-1;
    while (exchange!=0) {
      exchange=bound;
      for(int i=0;i<n;i++){
      if (a[i]>a[i+1]) {
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=a[i];
        exchange=i;
      }
    }
   }
}

int main(void) {
  int a[]={3,6,1,9,8,7};
  BubbleSort(a,6);
  for (int i=0;i<6; i++) {
    printf("%d  ",a[i]);
  }
  return 0;
}
