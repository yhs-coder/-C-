#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
/*
只有唯一路径，无需考虑最短路径的问题
思路：
1.创建一个指针数组，存放数据
2.寻找可走的路，通过在当前位置上下左右移动，来判断下一点是否可以通过
3.如果可以通过，则继续寻找可以通过的点，知道找到出口处
4.将每次可通的点存入栈中，如果发现不可行，再依次将数据弹栈
5.创建另一个栈，来输出路径
*/

/*
//======================================================================
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

void StackInit(ST* ps) {
    assert(ps);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

void StackDestroy(ST* ps) {
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x) {
    assert(ps);
    //如果栈满了，扩容
    if (ps->top == ps->capacity) {
        int newCapacity = (ps->capacity) == 0 ? 4 : 2 * (ps->capacity);
        STDataType* tmp = realloc(ps->a, newCapacity * sizeof(STDataType));
        if (tmp == NULL) {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;

}

void StackPop(ST* ps) {
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

//返回栈顶的数据
STDataType StackTop(ST* ps) {

    assert(ps);
    //栈为空
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}
bool StackEmpty(ST* ps) {
    return ps->top == 0;
}

int StackSize(ST* ps) {
    assert(ps);
    return ps->top;
}

//======================================================================
*/
ST Path; //存数据
ST rPath; //用来打印数据

bool IsPass(int** maze, int n, int m, PT cur) {
    if (cur.row >= 0 && cur.row < n
        && cur.col >= 0 && cur.col < m
        && maze[cur.row][cur.col] == 0)
        return true;
    else
        return false;
}



bool GetMazePath(int** maze, int n, int m, PT cur) {
    StackPush(&Path, cur);
    if (cur.row == n - 1 && cur.col == m - 1 && maze[cur.row][cur.col] == 0) //找到出口
        return true;

    maze[cur.row][cur.col] = 2; //打标志，防止回溯死循环
    //当前位置往上走
    PT next = cur;
    next.row -= 1;
    //判断往上走后是否可以通过
    if (IsPass(maze, n, m, next)) {
        //寻找当前位置是否有通路
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //当前位置往下走
    next = cur;
    next.row += 1;
    //判断往上走后是否可以通过
    if (IsPass(maze, n, m, next)) {
        //寻找当前位置是否有通路
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //当前位置往左走
    next = cur;
    next.col -= 1;
    //判断往上走后是否可以通过
    if (IsPass(maze, n, m, next)) {
        //寻找当前位置是否有通路
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //当前位置往右走
    next = cur;
    next.col += 1;
    //判断往上走后是否可以通过
    if (IsPass(maze, n, m,next)) {
        //寻找当前位置是否有通路
        if (GetMazePath(maze, n, m, next))
            return true;
    }
    StackPop(&Path);
    
    return false;
}

void PrintStack(ST Path)
{
    StackInit(&rPath);
    //将迷宫数据存入rPath
    while (!StackEmpty(&Path))
    {
        StackPush(&rPath, StackTop(&Path));
        StackPop(&Path);
    }
    while (!StackEmpty(&rPath))
    {
        PT top = StackTop(&rPath);
        printf("(%d,%d)\n", top.row, top.col);
        StackPop(&rPath);
    }

    StackDestroy(&rPath);
}
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) 
    {
        //创建指针数组
        int** maze = (int**)malloc(sizeof(int*) * n);
        assert(maze);
        int i, j;
        for (i = 0; i < n; i++) {
            maze[i] = (int*)malloc(sizeof(int) * m);
        }

        //存放数据
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &maze[i][j]);
            }
        }
        PT cur = { 0, 0 };
        StackInit(&Path);
        GetMazePath(maze, n, m, cur);
        PrintStack(Path);

        StackDestroy(&Path);
        for (i = 0; i < n; i++) {
            free(maze[i]);
        }
        free(maze);
        maze = NULL;

    }
    return 0;
}