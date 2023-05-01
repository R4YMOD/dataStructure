//
// Created by cheng on 2023/4/10.
//
#include "list.h"

// Init the list
void InitList(SqList &L) {
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    L.data = (ElemType *) malloc(sizeof(ElemType) * LIST_INIT_SIZE);

}


// Find the list length
int length(SqList L) {
    return L.length;

}

// Look up base on Value
int LocateElem(SqList L, ElemType e) {
    if (L.length == 0) return -1;
    for (int index = 0; index < L.length; index++) {
        if (L.data[index] == e) {
            return index;

        }
    }
    return -1;

}
//Insert element
void ListInsert(SqList &L, int index, ElemType e) {
    // 插入位置不对
    if (index > L.length + 1) {
        printf("插入位置有误");
        return;
    }
    //没有内存
    if (L.length + 1 > L.listSize) {
        L.data = (ElemType *) realloc(L.data, L.listSize + LIST_INCREMENT);
        L.listSize += LIST_INCREMENT;
    }
    //正常插入
    for (int in = L.length - 1; in > index - 1; --in) {
        L.data[in + 1] = L.data[in];
    }
    L.data[index] = e;
    L.length++;
}

//Delete element and return
void ListDelete(SqList &L, int index, ElemType &e) {
    //判断
    if (L.length == 0) return;
    if (index < 1 || index > L.length)return;
    //执行
    e = L.data[index - 1];
    for (int i = index ; i < L.length ; ++i) {
        L.data[i - 1] = L.data[i];
    }
    L.length--;

}

//Iterate through all elements
void PrintList(SqList L) {
    int index = 0;
    while (index < L.length) {
        printf("%d ", L.data[index++]);
    }
}

//Determine whether it is empty or not
bool Empty(SqList L) {
    return (L.length > 0) ? TURE : FALSE;
}

// Destroy the list
void DestroyList(SqList &L){
    L.length = 0;
    free(L.data);
}