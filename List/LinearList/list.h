#include <stdio.h>
#include <stdlib.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define Error 0
#define ElemType int

/*
 * TODO: 线性表的动态分配顺序存储结构
 *
 * */

#define  LIST_INIT_SIZE 30    //初始分配存储空间
#define  LIST_INCREMENT 10     //动态增加的长度
typedef struct {
    ElemType *data; //存储空间基地址
    int length; //当前长度
    int listSize; //分配的存储容量
}SqList;

// Init the list
void InitList(SqList &L);

// Find the list length
int length(SqList L);

// Look up base on Value
int LocateElem(SqList  L,ElemType e);

//Insert element
void ListInsert(SqList &L,int index,ElemType e);

//Delete element and return
void ListDelete(SqList &L,int index,ElemType &e);

//Iterate through all elements
void PrintList(SqList L);

//Determine whether it is empty or not
bool Empty(SqList L);

// Destroy the list
void DestroyList(SqList &L);