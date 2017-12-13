#include <stdio.h>
#include <stdlib.h>

struct BTreeNode {
  int data;//数据的权值
  char ch;//字符
  struct BTreeNode *lchild;
  struct BTreeNode *rchild;
};

struct BTreeNode* CreateHuffman(int a[], int n,char chk[])
{
   int i, j;
   struct BTreeNode **b, *q;
   b = malloc(n*sizeof(struct BTreeNode));
   for (i = 0; i < n; i++)
   {
       b[i] = malloc(sizeof(struct BTreeNode));
       b[i]->data = a[i];
       b[i]->ch=chk[i];
       b[i]->lchild = b[i]->rchild = NULL;
   }
   for (i = 1; i < n; i++)//进行 n-1 次循环建立哈夫曼树
   {
       //k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标
       int k1 = -1, k2;
       for (j = 0; j < n; j++)//让k1初始指向森林中第一棵树，k2指向第二棵
       {
           if (b[j] != NULL && k1 == -1)
           {
               k1 = j;
               continue;
           }
           if (b[j] != NULL)
           {
               k2 = j;
               break;
           }
       }
       for (j = k2; j < n; j++)//从当前森林中求出最小权值树和次最小
       {
           if (b[j] != NULL)
           {
               if (b[j]->data < b[k1]->data)
               {
                   k2 = k1;
                   k1 = j;
               }
               else if (b[j]->data < b[k2]->data)
                   k2 = j;
           }
       }
       //由最小权值树和次最小权值树建立一棵新树，q指向树根结点
       q = malloc(sizeof(struct BTreeNode));
       q->data = b[k1]->data + b[k2]->data;
       q->lchild = b[k1];
       q->rchild= b[k2];

       b[k1] = q;//将指向新树的指针赋给b指针数组中k1位置
       b[k2] = NULL;//k2位置为空
   }
   free(b);
   return q; //返回整个哈夫曼树的树根指针
}

void HuffManCoding(struct BTreeNode* hfm, int len)//len初始值为0
{
   static int a[10];
   if (hfm != NULL)
   {

       if (hfm->lchild == NULL && hfm->rchild == NULL)
       {
           int i;
           printf("%s的编码：",&hfm->ch);
           for (i = 0; i < len; i++)
               printf("%d", a[i]);
               printf("\n");
       }
       else
       {
           a[len] = 0;
           HuffManCoding(hfm->lchild, len + 1);
           a[len] = 1;
           HuffManCoding(hfm->rchild, len + 1);
       }
   }
}

void HuffManEncoding(int *ch,int n ){
printf();
}
void HuffmanDecoding(){
printf("2\n");
}

void printfT(){
  printf("--------------------请输入选项---------------\n");
  printf("1:输入字符,进行编码\n");
    printf("2:输%s入数字,进行译码\n");
      printf("3:退出\n");
}

void main(void){
  struct BTreeNode *hfm;
  int *a;
  char *b;//字符存储数组
  int n;//节点数
  int select;//选项
  int chn;//译码长度
  char *chl;//译码字符串存储数组
  printf("-------------------构造哈弗曼树的字符数--------------------\n");
  scanf("%d",&n );
  a=(int *)malloc(n*sizeof(int));
  b=(char *)malloc(sizeof(char));
  for(int i=0;i<n;i++){
    printf("请输入字符:    \n");
    scanf("%s",&b[i]);
    printf("请输入%s权值:\n",&b[i]);
    scanf("%d",&a[i]);
  }
  hfm=CreateHuffman(a,n,b);
  printf("哈弗曼的编码为:    \n");
  HuffManCoding(hfm,0);
  while(1){
    printfT();
    scanf("%d",&select );
    if(select==3){
      break;
    }
    else if(select==1){
      HuffManEncoding();
      printf("\n");
      continue;
    }
    else if(select==2){
      HuffmanDecoding();
      printf("\n");
      continue;
    }

  }

}
