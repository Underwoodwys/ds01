
#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef int Status;
typedef struct{
  ElemType *elem;//基地址
  int length;//线性表的长度
  int listsize;//当前分配的储存容量
}SqList;



Status InitList_Sq(SqList *L,int n){//构造一个空的顺序表L
    int i;
    ElemType x;
    (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!(*L).elem) return 0;
    (*L).length=n;
    (*L).listsize=LIST_INIT_SIZE;
    for(i=1;i<=n;++i){
        scanf("%d",&x);
        (*L).elem[i-1]=x;
    }
    return 1;
}

Status ListInsert_Sq(SqList *L,int i,ElemType e){//插入函数
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

Status ListDelete_Sq(SqList *L,int i,ElemType *e){//删除函数
    if(i<1||i>(*L).length) return 0;
    *e=(*L).elem[i-1];
    for(int j=i;j<(*L).length;j++)
        (*L).elem[j-1]=(*L).elem[j];
    (*L).length--;
    return 1;
}
/*
Status GetElem_Sq(SqList L,int i,ElemType *e){//按位查找
    if(i<1||i>L.length) return 0;
    *e=L.elem[i-1];
    return 1;
}
*/
int LocateElem_Sq(SqList L,ElemType e){//按值查找
    for(int i=1;i<=L.length;i++)
        if(e==L.elem[i-1]) return i;
    return 0;
}


void PrintList_Sq(SqList L){//打印
    if(L.length==0) printf("顺序表中没有元素！\n");
    else{
        printf("顺序表中的元素为\n");
        for(int i=0;i<L.length;i++){
            printf("%d ",L.elem[i]);
        }
        printf("\n");
    }
}


int main(void){
    SqList L1,L2;
    ElemType qq;
    int n1,n2,n;

    scanf("%d",&n1);
    scanf("%d",&n2);

    InitList_Sq(&L1,n1);
    InitList_Sq(&L2,n2);

    PrintList_Sq(L1);
    PrintList_Sq(L2);

   /* n=L1.length;
    for(int i=0;i<L2.length;++i){
        if(0==LocateElem_Sq(L1,L2.elem[i])) {
                ListInsert_Sq(&L1,n+1,L2.elem[i]);
        n++;}

    }
    PrintList_Sq(L1);*/

    n=L2.length;
    for(int i=0;i<n;i++){
        if(0==LocateElem_Sq(L1,L2.elem[i])){
            ListDelete_Sq(&L2,i+1,&qq);
            n--;
            i--;
            }
        }
    PrintList_Sq(L2);

    return 0;

}

