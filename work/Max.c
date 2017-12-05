/*最大字段问题,分别用蛮力法,分治法,动态规划法设计最大子段问题*/
//测试时间性能
//测试数据
#include <stdio.h>
#include <stdlib.h>
//使用蛮力法求解最大值
void Brute_force(int *a,int n){
int max=0;
int now=0;
printf("-------------------蛮力法----------------------\n");
for(int i=0;i<n;i++){
  for(int j=i;j>=0;j--){
    now+=a[j];
    if(now>max){
      max=now;
    }
  }
  now=0;
}
printf("最大值为%d\n",max );
}

void Divide(int *a,int n){
printf("---------------------分治法-----------------------\n");
int mid;
mid=n/2;
int max=0;//最大值
int left=0;
int right=0;
int now=0;
int now1=0;
int left1=0;
int right1=0;
//计算左边
for(int i=0;i<mid;i++){
  for(int j=i;j>=0;j--){
    now+=a[j];
    if(now>left){
      left=now;
    }
  }
  now=0;
}
for(int i=mid;i<n;i++){
  for(int j=i;j>=mid;j--){
    now+=a[j];
    if(now>right){
      right=now;
    }
  }
now=0;
}

for(int i=mid+1;i<n;i++){
now+=a[i];
  if(now>left1){
    left1=now;
  }
}

for(int i=mid;i>=0;i--){
now1+=a[i];
  if(now1>right1){
    right1=now1;
  }
}
max=left1+right1;
if(right>left){
  left=right;
}
else if(left>max){
  max=left;
}


printf("最大值为%d\n",max );
}

int DP(int *a,int n){
printf("dp\n");

}

int main(void){
int len;
int *a;
int select;
printf("输入数据的长度:   \n");
scanf("%d",&len);
a=(int *)malloc(len*sizeof(int));
for(int i=0;i<len;i++){
  printf("请输入数字\n");
  scanf("%d",&a[i] );
}
printf("输入的数据为:  ");
for(int i=0;i<len;i++){
  printf("%d  ",a[i] );
}
printf("请输入选项\n1:蛮力法\n2:分治法\n3:动态规划法\n");
scanf("%d",&select);
if(select==1){
  Brute_force(a,len);
}
else if(select==2){
  Divide(a,len);
}
else if(select==3){
  DP(a,len);
}
  return 0;
}
