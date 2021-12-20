#include "String.h"
#include <iostream>
using namespace std;

status StringInit(String &S)
{
    S.chArry = new char[STRINGMAXSIZE + 1];
    if(S.chArry==NULL)
    {
        return ERROR;
    }
    S.length = STRINGMAXSIZE;
}

int StringBF(String S, String T)
{
    int i = 1;          //如果不从第一个字符开始匹配，可以将i的初始值改为其他值
    int j = 1;
    while(i<=S.length && j<=T.length)
    {
        if(S.chArry[i] == T.chArry[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i-j+2;      //将字符串位置回溯到下一个起始位置
            j = 1;          //模式字符串继续从1号位置开始
        }
    }

    if(j>T.length)  //发现模式字符串已经全部匹配完了
    {
        return i-T.length;
    }
    else
    {
        return 0;
    }
}

static void GetNext(String T, int *Next)
{
    int i = 1;
    Next[1] = 0;
    int j = 0;
    while(i<T.length)
    {
        if(j==0 || T.chArry[i] == T.chArry[j])
        {
            ++i;
            ++j;
            Next[i] = j;
        }
        else
        {
            j = Next[j];
        }
    }
}

//KMP算法，主串不需要回溯，模式串尽量少回溯
int StringKMP(String S, String T, int pos)
{
    int i = pos;
    int j = 1;
    int *next = new int[T.length + 1];
    GetNext(T,next);
    while(i<=S.length && j<=T.length)
    {
        if(S.chArry[i] == T.chArry[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
}