#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void Print(HPDataType* a,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TestAdjustUp()
{
	HPDataType a[] = { 1,2,3,4,5,7,9,8,6,0 };
	int size = sizeof(a) / sizeof(a[0]);
	AdjustUp(&a, size - 1);
	Print(&a, size );
}


void TestAdjustDown()
{
	HPDataType a[] = { 11,2,3,4,5,7,9,8,6 };
	int size = sizeof(a) / sizeof(a[0]);
	AdjustDown(&a, size,0);
	Print(&a, size);
}

void TestHeap()
{
	HPDataType a[] = { 9,5,3,2,1,7,-1 };
	int n = sizeof(a) / sizeof(a[0]);
	HP hp;
	HeapInit(&hp, &a, n);
	HeapPrint(&hp);

	HeapUp(&hp);
	//HeapPush(&hp, -1);
	HeapPrint(&hp);
	//ɾ���Ѷ�����
	//HeapPop(&hp);
	//HeapPrint(&hp);

	//��öѶ�����
	printf("�Ѷ�������Ϊ %d \n", HeapTop(&hp));
	printf("�ѵ����ݸ���Ϊ %d \n", HeapSize(&hp));

	HeapDestroy(&hp);
}
int main()
{
	//TestAdjustUp();
	//TestAdjustDown();
	TestHeap();
	return 0;
}