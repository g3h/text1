#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000

/*
Author:xyf
Topic:文章编辑
Data:2019-12-10
*/

typedef char DataType;
typedef struct
{
    DataType data[MAXSIZE],del[MAXSIZE];
    int Length,delLength;
} SeqList;

void CreatList(SeqList *L)//创建
{
    int i=0;
    while(1)
    {
        scanf("%c",&L->data[i]);
        if(L->data[i]=='\n')
            break;
        i++;
    }
    L->Length=i;
}

void Display (SeqList *L)//显示
{
    int j;
    printf("每行字符数不超过80：\n");
    for(j=0; j<L->Length; j++)
    {
        printf("%c",L->data[j]);
        if(j%80==79&&j>0)//余数79因为0在数里面，空行是79,159,239，+80以此类推
        {
            printf("\n");
        }
    }
}

int Letter(SeqList *L)//字母计数
{
    int i,j=0;
    for(i=0; i<L->Length; i++)
    {
        if(L->data[i]>='A'&&L->data[i]<='Z'||L->data[i]>='a'&&L->data[i]<='z')
            j++;
    }
    return j;
}

int Space (SeqList *L)//空格计数
{
    int i,j=0;
    for(i=0; i<L->Length; i++)
    {
        if(L->data[i]==' ')
            j++;
    }
    return j;
}


int Number(SeqList *L)//数字计数
{
    int i,j=0;
    for(i=0; i<L->Length; i++)
    {
        if(L->data[i]>='0'&&L->data[i]<='9')
            j++;
    }
    return j;
}

void DeleteList(SeqList *L)//存储要删除的字符串
{
    int i=0;
    while(1)
    {
        scanf("%c",&L->del[i]);
        if(L->del[i]=='\n')
            break;
        i++;
    }
    L->delLength=i;
}

void Del(SeqList *L)//删除字符串
{
    int i,j,a,d,e,f=0;
    for(i=0; i<L->Length; i++)
    {
        j=0;
        if(L->data[i]==L->del[j])
        {
            e=0;//e用来判断是否存在删除的字符串
            a=i;//a用来判断需要删除字符串所在的位置
            for(j=0; j<L->delLength; j++)
            {
                if(L->data[a]==L->del[j])
                {
                    a++;
                    e++;
                }
                if(e==L->delLength)
                {
                    for(d=i; d<L->Length; d++) //将删除字符串后的文章前移直接覆盖需要删除的
                    {
                        L->data[d]=L->data[d+L->delLength];
                    }
                    L->Length=L->Length-L->delLength;//删除字符串后该文章长度减去删除的字符串长度
                    f++;//f用来判断是否删除了该字符串
                }
            }
        }
    }
    if(f==0)
        printf("\n没有该字符串，及删除后还是原文章，");
    else
        printf("\n删除字符串后的文章，");

    /*for(i=0; i<L->Length; i++)//后面前移 这是单个字符
    {
        for(j=0; j<L->delLength; j++)
        {
            if(L->data[i]==L->del[j])
            {
                L->data[i]=0;
                for(a=i; a<L->Length; a++)
                {
                    L->data[a]=L->data[a+1];
                }
                L->Length--;//每次前移长度-1
            }
        }
    }*/
}

int main()
{
    SeqList L;
    printf("请输入文章：");
    CreatList(&L);

    printf("\n输入的文章，");
    Display(&L);

    printf("\n\n全部字母数：%d\n",Letter(&L));
    printf("\n数字个数：%d\n",Number(&L));
    printf("\n空格个数：%d\n",Space(&L));
    printf("\n文章总字数：%d\n",L.Length);

    printf("\n请输入删除的字符串：");

    DeleteList(&L);
    Del(&L);
    Display(&L);

    printf("\n删除结束。\n");

    return 0;
}
