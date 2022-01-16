#pragma once

#define OK      0
#define ERROR   1
#define FALSE   0
#define TRUE    1

typedef int status;

//排序算法中默认使用顺序表
#define SORTMAXSIZE     100
typedef int SortKeyType;
typedef char SortOtherInfoType;

typedef struct
{
    SortKeyType key;
    SortOtherInfoType otherInfo;
}SortElem;

typedef struct
{
    SortElem* Arry;
    int Length;
}SortSeqList;
