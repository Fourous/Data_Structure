#include <stdio.h>
#include <stdlib.h>
#define ERROR 1
typedef struct ListNode{
  int data;
  typedef ListNode *next;
};

struct ListNode *Sqlist;

struct ListNode* ListInit(){
  struct ListNode* list;
  list=malloc(sizeof(ListNode));
  if(!list) exit(ERROR);
  list->next=NULL;
  return list;
}
