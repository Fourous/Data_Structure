#include <stdio.h>
#include <stdlib.h>
#include "List1"
#include "List2"

void main(void){
  typedef ElemType e1[4];
  typedef ElemType e2[4];
  //初始化为
  e1[0]->no=1;
  e1[1]->no=2;
  e1[2]->no=3;
  e1[3]->no=4;
  e1[0]->grade=70;
  e1[1]->grade=85;
  e1[2]->grade=75;
  e1[3]->grade=90;
  e2[0]->no=5;
  e2[1]->no=6;
  e2[2]->no=7;
  e2[3]->no=8;
  e2[0]->grade=60;
  e2[1]->grade=80;
  e2[2]->grade=76;
  e2[3]->grade=50;

  printf("------以下数据为了简便,没有排序--------------");

}
