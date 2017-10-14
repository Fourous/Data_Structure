/*归并排序是稳定的，如果要求其他信息按输入的排列顺序排列，则这时比快速排序优势*/
//速度上仅次于快速排序
//将相邻两个数字进行归并操作，递归，直到所有序列排序完毕。
//注意区分快速排序
#include <stdio.h>
#include <stdlib.h>
void Merge(int *SouceArray,int *IndexArray,int start,int mid,int end){
  int i,j;
  i=start,j=mid;
  int k=end;
  while (i<mid+1&&j<end+1) {
    if (SouceArray[i]<SouceArray[j]) {
      IndexArray[k++]=SouceArray[i++];
    }else
    IndexArray[k++]=SouceArray[j++];
  }
  while (i=mid+1) {
    IndexArray[k++]=SouceArray[j++];
  }
  while (j=end+1) {
    IndexArray[k++]=SouceArray[i++];
  }
  for (int i = start; i < end; i++) {
    SouceArray[i]=IndexArray[i];
  }
}

void MergeSort(int *SouceArray,int *IndexArray,int start,int end) {
      int mid=(start+end)/2;
      if (start<end) {
        MergeSort(SouceArray,IndexArray,start,mid);
        MergeSort(SouceArray,IndexArray,mid+1,end);
        Merge(SouceArray,IndexArray,start,mid,end);
      }

}

int main(void){
  int a[]={3,2,7,5,9,4};
  int b[6];
  MergeSort(a,b,0,6);
  for (int i = 0; i < 6; i++) {
    printf("%d\n",a[i] );
  }
  return 0;
}
