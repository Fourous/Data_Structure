//顺序存储
#include <stdio.h>
#include <stdlib.h>
#define ERROR 1
#define LIST_INCREASE 10
#define LIST_INIT 100

typedef struct {
  int no;
  int grade;
}ElemType;

typedef struct {
  ElemType *elem;
  int length;//数据长度
  int listsize;//分配的是线性表的长度
}ListNode;

int InitList(ListNode *pl){
  pl->listsize=LIST_INIT;
  pl->elem=(ElemType *)malloc(pl->listsize*sizeof(ElemType));
  pl->length=0;
}

void DestroyList(ListNode *pl){
  free(pl->elem);
}

int ListInsert(ListNode *pl,ElemType e){
int i,j;
  if(pl->length=pl->listsize){
    pl->elem=(ElemType *)realloc(pl->elem,(pl->listsize)*sizeof(ElemType));
    if(!pl->elem)     exit(ERROR);
    pl->listsize+=LIST_INCREASE;
  }
  //插入点
  for( i=0;i<pl->length;i++){
    if(e.grade>pl->elem[i].grade){
      break;
    }
  }
  //向后移动数据
  for(j=pl->length+1;j>i;j-- ){
    pl->elem[j]=pl->elem[j-1];
  }
  pl->elem[i]=e;
  pl->length+=1;
  return 1;
}

void ShowList(ListNode *pl){
  for(int i=0;i<pl->length;i++){
    printf("(%d,%d)\n",pl->elem[i].no,pl->elem[i].grade);
  }
}
