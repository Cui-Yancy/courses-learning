#pragma once
#include "define.h"

#define STRINGMAXSIZE   100

typedef struct
{
    char *chArry;
    int length;
}String;

status StringInit(String &S);
int StringBF(String S, String T);
int StringKMP(String S, String T, int pos);