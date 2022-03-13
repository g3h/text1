#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000

/*
Author:xyf
Topic:���±༭
Data:2019-12-10
*/

typedef char DataType;
typedef struct
{
    DataType data[MAXSIZE],del[MAXSIZE];
    int Length,delLength;
} SeqList;

void CreatList(SeqList *L)//����
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

void Display (SeqList *L)//��ʾ
{
    int j;
    printf("ÿ���ַ���������80��\n");
    for(j=0; j<L->Length; j++)
    {
        printf("%c",L->data[j]);
        if(j%80==79&&j>0)//����79��Ϊ0�������棬������79,159,239��+80�Դ�����
        {
            printf("\n");
        }
    }
}

int Letter(SeqList *L)//��ĸ����
{
    int i,j=0;
    for(i=0; i<L->Length; i++)
    {
        if(L->data[i]>='A'&&L->data[i]<='Z'||L->data[i]>='a'&&L->data[i]<='z')
            j++;
    }
    return j;
}

int Space (SeqList *L)//�ո����
{
    int i,j=0;
    for(i=0; i<L->Length; i++)
    {
        if(L->data[i]==' ')
            j++;
    }
    return j;
}


int Number(SeqList *L)//���ּ���
{
    int i,j=0;
    for(i=0; i<L->Length; i++)
    {
        if(L->data[i]>='0'&&L->data[i]<='9')
            j++;
    }
    return j;
}

void DeleteList(SeqList *L)//�洢Ҫɾ�����ַ���
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

void Del(SeqList *L)//ɾ���ַ���
{
    int i,j,a,d,e,f=0;
    for(i=0; i<L->Length; i++)
    {
        j=0;
        if(L->data[i]==L->del[j])
        {
            e=0;//e�����ж��Ƿ����ɾ�����ַ���
            a=i;//a�����ж���Ҫɾ���ַ������ڵ�λ��
            for(j=0; j<L->delLength; j++)
            {
                if(L->data[a]==L->del[j])
                {
                    a++;
                    e++;
                }
                if(e==L->delLength)
                {
                    for(d=i; d<L->Length; d++) //��ɾ���ַ����������ǰ��ֱ�Ӹ�����Ҫɾ����
                    {
                        L->data[d]=L->data[d+L->delLength];
                    }
                    L->Length=L->Length-L->delLength;//ɾ���ַ���������³��ȼ�ȥɾ�����ַ�������
                    f++;//f�����ж��Ƿ�ɾ���˸��ַ���
                }
            }
        }
    }
    if(f==0)
        printf("\nû�и��ַ�������ɾ������ԭ���£�");
    else
        printf("\nɾ���ַ���������£�");

    /*for(i=0; i<L->Length; i++)//����ǰ�� ���ǵ����ַ�
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
                L->Length--;//ÿ��ǰ�Ƴ���-1
            }
        }
    }*/
}

int main()
{
    SeqList L;
    printf("���������£�");
    CreatList(&L);

    printf("\n��������£�");
    Display(&L);

    printf("\n\nȫ����ĸ����%d\n",Letter(&L));
    printf("\n���ָ�����%d\n",Number(&L));
    printf("\n�ո������%d\n",Space(&L));
    printf("\n������������%d\n",L.Length);

    printf("\n������ɾ�����ַ�����");

    DeleteList(&L);
    Del(&L);
    Display(&L);

    printf("\nɾ��������\n");

    return 0;
}
