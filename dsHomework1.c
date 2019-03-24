//建立顺序表
//插入 删除 查找 打印 集合的交 并
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

SqList L;

Status InitList_Sq(SqList *L){//构造一个空的顺序表L
    (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!(*L).elem) return 0;
    (*L).length=0;
    (*L).listsize=LIST_INIT_SIZE;
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

Status GetElem_Sq(SqList L,int i,ElemType *e){//按位查找
    if(i<1||i>L.length) return 0;
    *e=L.elem[i-1];
    return 1;
}

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

void Print(void){
    printf("现在系统已经自动为您生成一个空线性表，请选择您想要进行的操作，q推出本程序\n");
    printf("1.插入\t2.删除\t3.按位查找\t4.按值查找\t5.打印\n");
}

int main(void){
    ElemType e;
    int n,i;
    InitList_Sq(&L);//建立空顺序表
    Print();
    while(scanf("%d",&n)){
        if(n==1){
            printf("请依次输入您选择插入的元素和位置并用空格分开\n位置为小于%d的正整数\n",L.length+1);
            scanf("%d%d",&e,&i);
            if(!ListInsert_Sq(&L,i,e)) printf("位置错误！请重新选择操作\n");
        }
        if(n==2){
            printf("请输入您选则删除的位置\n位置为小于%d的正整数\n",L.length+1);
            scanf("%d",&i);
            if(!ListDelete_Sq(&L,i,&e)) printf("位置错误！请重新选择操作\n");
            printf("您已删除%d\n",e);
        }
        if(n==3){
           printf("请输入您选则查找的位置\n位置为小于%d的正整数\n",L.length+1);
           scanf("%d",&i);
           if(!GetElem_Sq(L,i,&e)) printf("位置错误！请重新选择操作\n\n");
           printf("第%d个位置元素为%d\n",i,e);
        }
        if(n==4){
            printf("请输入您选则查找的元素\n");
            scanf("%d",&e);
            if(!LocateElem_Sq(L,e)) printf("顺序表中无此元素\n");
            printf("元素位置为%d\n",LocateElem_Sq(L,e));
        }
        if(n==5) PrintList_Sq(L);
    }
    printf("再见！\n");

    return 0;
}








