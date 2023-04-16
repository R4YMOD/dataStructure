#include "function.cpp"

int main(void) {

    SqList L;
    //初始化
    InitList(L);
    //判读是否为空
    printf("Empty:%d\n", Empty(L));
    //插入数据
    for (int i = 0; i < 6; ++i) {
        ListInsert(L,i,i);
    }
    //遍历
    PrintList(L);
    printf("\n");
    //判断是否为空
    printf("Empty:%d\n", Empty(L));

    //删除一个元素
    ElemType e;
    ListDelete(L,1,e);
    printf("deleted element is : %d\n",e);
    //销毁
    printf("destroy list\n");
    DestroyList(L);
    return 0;
}
