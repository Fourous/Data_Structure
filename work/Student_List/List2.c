#include <stdio.h>
#include <stdlib.h>
#define ERROR 1

typedef struct{
  int no;
  int grade;
}ElemType;

typedef struct ListNode{
  ElemType elem;
  struct ListNode *next;
}List;

void ListInsert(List *pl,ElemType e){
 struct ListNode* node;
  node =(ElemType*)malloc(sizeof(ElemType));
  node->elem=e;
  node->next=pl->next;
  pl->next=node;
}

void ShowList(List *pl){
  struct ListNode *node;
  node=pl->next;
  while (node) {
    printf("(%d,%d)\n",node->elem.no,node->elem.grade );
    node=node->next;
  }
}

void DestroyList(List *pl){
  struct ListNode *node;
  node=pl;
  while (node) {
    pl=pl->next;
    free(node);
    node=pl;
  }
}
