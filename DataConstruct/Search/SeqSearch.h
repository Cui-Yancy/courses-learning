#pragma once

typedef int SeqKeyType;

typedef struct
{
    SeqKeyType* Key;
    int Length;
}SeqSearchTable;

int SeqSearch(SeqSearchTable T, SeqKeyType key);
int BinSearch(SeqSearchTable T, SeqKeyType key);
