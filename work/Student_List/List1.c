//顺序存储
#include <stdio.h>
#include <stdlib.h>
#define ERROR 1
#define LIST_INCREASE 10
#define LIST_INIT 100

typedef struct {
  int data;
  int length;//数据长度
  int listlen;//分配的是线性表的长度
}ListNode;

bool ListFull(struct ListNode* list){
  if(list->listlen==list->length)
    return true;
}
//线性表的初始化,插入,删除,回收
struct ListNode* ListInit(){
  struct ListNode* list;
  list=malloc(LIST_INIT*sizeof(ListNode));
  if(!list)    exit(ERROR);
  return list;
}

struct ListNode* ListInsert(struct ListNode* list,int data,int index){
  if(ListFull)  {
    list=realloc();//增加分配
    if(!list)     exit(ERROR);
    listlen+=LIST_INCREASE;
  }
  for(int i=0;i<index;i++){

  }

}

struct ListNode* 
