#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef int Status;
typedef struct{
  ElemType *elem;//����ַ
  int length;//���Ա�ĳ���
  int listsize;//��ǰ����Ĵ�������
}SqList;

//SqList L;

Status InitList_Sq(SqList *L){//����һ���յ�˳���L
    (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!(*L).elem) return 0;
    (*L).length=0;
    (*L).listsize=LIST_INIT_SIZE;
    return 1;
}

Status ListInsert_Sq(SqList *L,int i,ElemType e){//���뺯��
    ElemType *newbase;
    if(i<1||i>(*L).length+1) return 0;
    if((*L).length>=(*L).listsize){
        newbase=(ElemType*)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) return 0;
        (*L).elem=newbase;
        (*L).listsize+=LISTINCREMENT;
    }
    for(int j=(*L).length;j>=i;j--)
        (*L).elem[j]=(*L).elem[j-1];
    (*L).elem[i-1]=e;
    (*L).length++;
    return 1;
}

Status ListDelete_Sq(SqList *L,int i,ElemType *e){//ɾ������
    if(i<1||i>(*L).length) return 0;
    *e=(*L).elem[i-1];
    for(int j=i;j<(*L).length;j++)
        (*L).elem[j-1]=(*L).elem[j];
    (*L).length--;
    return 1;
}

Status GetElem_Sq(SqList L,int i,ElemType *e){//��λ����
    if(i<1||i>L.length) return 0;
    *e=L.elem[i-1];
    return 1;
}

int LocateElem_Sq(SqList L,ElemType e){//��ֵ����
    for(int i=1;i<=L.length;i++)
        if(e==L.elem[i-1]) return i;
    return 0;
}


void PrintList_Sq(SqList L){//��ӡ
    if(L.length==0) printf("˳�����û��Ԫ�أ�\n");
    else{
        printf("˳����е�Ԫ��Ϊ\n");
        for(int i=0;i<L.length;i++){
            printf("%d ",L.elem[i]);
        }
        printf("\n");
    }
}

Status InitList_Sq(SqList *L);
Status ListInsert_Sq(SqList *L,int i,ElemType e);
Status ListDelete_Sq(SqList *L,int i,ElemType *e);
Status GetElem_Sq(SqList L,int i,ElemType *e);
int LocateElem_Sq(SqList L,ElemType e);
void PrintList_Sq(SqList L);

#endif // FUNCTIONS_H_INCLUDED
