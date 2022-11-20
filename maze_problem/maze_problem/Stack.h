#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<stdbool.h>
typedef struct Position {
    int row;
    int col;
} PT;
typedef PT  STDataType;

typedef struct Stack {
    STDataType* a;
    int  top;
    int  capacity;
} ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);

//返回栈顶的数据
STDataType StackTop(ST* ps);
bool StackEmpty(ST* ps);
int StackSize(ST* ps);
