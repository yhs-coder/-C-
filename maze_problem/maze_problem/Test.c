#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
/*
ֻ��Ψһ·�������迼�����·��������
˼·��
1.����һ��ָ�����飬�������
2.Ѱ�ҿ��ߵ�·��ͨ���ڵ�ǰλ�����������ƶ������ж���һ���Ƿ����ͨ��
3.�������ͨ���������Ѱ�ҿ���ͨ���ĵ㣬֪���ҵ����ڴ�
4.��ÿ�ο�ͨ�ĵ����ջ�У�������ֲ����У������ν����ݵ�ջ
5.������һ��ջ�������·��
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

//����ջ��������
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
    //���ջ���ˣ�����
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

//����ջ��������
STDataType StackTop(ST* ps) {

    assert(ps);
    //ջΪ��
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
ST Path; //������
ST rPath; //������ӡ����

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
    if (cur.row == n - 1 && cur.col == m - 1 && maze[cur.row][cur.col] == 0) //�ҵ�����
        return true;

    maze[cur.row][cur.col] = 2; //���־����ֹ������ѭ��
    //��ǰλ��������
    PT next = cur;
    next.row -= 1;
    //�ж������ߺ��Ƿ����ͨ��
    if (IsPass(maze, n, m, next)) {
        //Ѱ�ҵ�ǰλ���Ƿ���ͨ·
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //��ǰλ��������
    next = cur;
    next.row += 1;
    //�ж������ߺ��Ƿ����ͨ��
    if (IsPass(maze, n, m, next)) {
        //Ѱ�ҵ�ǰλ���Ƿ���ͨ·
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //��ǰλ��������
    next = cur;
    next.col -= 1;
    //�ж������ߺ��Ƿ����ͨ��
    if (IsPass(maze, n, m, next)) {
        //Ѱ�ҵ�ǰλ���Ƿ���ͨ·
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //��ǰλ��������
    next = cur;
    next.col += 1;
    //�ж������ߺ��Ƿ����ͨ��
    if (IsPass(maze, n, m,next)) {
        //Ѱ�ҵ�ǰλ���Ƿ���ͨ·
        if (GetMazePath(maze, n, m, next))
            return true;
    }
    StackPop(&Path);
    
    return false;
}

void PrintStack(ST Path)
{
    StackInit(&rPath);
    //���Թ����ݴ���rPath
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
        //����ָ������
        int** maze = (int**)malloc(sizeof(int*) * n);
        assert(maze);
        int i, j;
        for (i = 0; i < n; i++) {
            maze[i] = (int*)malloc(sizeof(int) * m);
        }

        //�������
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