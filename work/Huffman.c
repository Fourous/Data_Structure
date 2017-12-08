//字符集{d1,d2,........dn},出现频率为{w1,w2,........wn},构造最短不等长编码
//证明Haffman满足最优子结构性质
//设计贪心算法求解Huffman编码方案
//测试数据
#include<stdio.h>
#include<stdlib.h>

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1


typedef struct
{
    int bit[MAXBIT];
    int start;
}HCodeType;

typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
    int value;
}HNodeType;

HNodeType HuffNode[MAXNODE];//定义全局变量和数组可以自动初始化
HCodeType HuffCode[MAXLEAF], cd;//

void HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
    int i, j, m1, m2,x1, x2;
    //m1,m2构造哈夫曼树不同过程中两个最小权值结点的权值
    //x1,x2构造哈夫曼树不同过程种两个最小权值结点在数组中的序号
    //初始化存放哈夫曼数组的结点
    for (i = 0; i < 2 * n - 1; i++)
    {
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
        HuffNode[i].value = i;
    }
    //printf("输入n个叶子结点的权值:\n");
    for (i = 0; i < n; i++)
    {
        printf("Please input weight of leaf node%d:\n", i);
        scanf("%d", &HuffNode[i].weight);
    }
    //循环构造哈夫曼树，n个叶子结点需要n-1次构建
    for (i = 0; i < n - 1; i++)
    {
        m1 = m2 = MAXVALUE;
        x1 = x2 = 0;
        for (j = 0; j < n + i; j++)//新建立的节点的下标是原来的叶子总结点数+i即n+i
        {
            if (HuffNode[j].weight < m1&&HuffNode[j].parent == -1)
            {
                m2 = m1;
                x2 = x1;
                m1 = HuffNode[j].weight;
                x1 = j;
            }
            else if (HuffNode[j].weight < m2&&HuffNode[j].parent == -1)
            {
                m2 = HuffNode[j].weight;
                x2 = j;
            }
        }
        HuffNode[x1].parent = n + i;
        HuffNode[x2].parent = n + i;
        HuffNode[n + i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
        HuffNode[n + i].lchild = x1;
        HuffNode[n + i].rchild = x2;
        printf("x1.weight and x2.weight in round %d:%d,%d\n", i + 1, HuffNode[x1].weight, HuffNode[x2].weight);
        printf("\n");
    }
}
void HuffmanCode(HCodeType HuffCode[MAXLEAF], HNodeType HuffNode[MAXNODE],HCodeType cd, int n)
{
    int i, c, p, j;
    for (i = 0; i < n; i++)
    {
        cd.start = n - 1;
        c = i;
        p = HuffNode[c].parent;
        while (p != -1)
        {
            if (HuffNode[p].lchild == c)
            {
                cd.bit[cd.start] = 0;
            }
            else
            {
                cd.bit[cd.start] = 1;
            }
            cd.start--;
            c = p;
            p = HuffNode[c].parent;
        }
        for (j = cd.start + 1; j < n; j++)
        {
            HuffCode[i].bit[j] = cd.bit[j];
        }
        HuffCode[i].start = cd.start;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d（%c）的Huffman code is:", i+1,i+97);
        for (j = HuffCode[i].start + 1; j < n; j++)
        {
            printf("%d", HuffCode[i].bit[j]);    system("pause");
        }
        printf("  start:%d", HuffCode[i].start);
        printf("\n");
    }
}
int main(void)
{


    int n;
    printf("Please input n:\n");
    scanf("%d", &n);
    HuffmanTree(HuffNode, n);
    HuffmanCode(HuffCode, HuffNode, cd, n);
    return 0;
}
