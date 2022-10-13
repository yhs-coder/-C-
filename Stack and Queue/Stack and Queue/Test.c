#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
#include"Queue.h"

void TestStack()
{
	ST stack;
	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	StackPush(&stack, 5);


	//StackPop(&stack);
	//StackPop(&stack);
	//StackPop(&stack);
	//StackPop(&stack);
	//StackPop(&stack);

	printf("%d \n", StackSize(&stack));

	while (!StackEmpty(&stack))
	{
		printf("%d ", StackTop(&stack));
		StackPop(&stack);
	}
	StackDestroy(&stack);
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QDataType front = QueueFront(&q);
	printf("%d\n", front);
	QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	//printf("%d ", QueueFront(&q));
	////printf("%d ", QueueBack(&q));
	//printf("%d ", QueueSize(&q));

	//´òÓ¡Êý¾Ý
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}
int main()
{
	//TestStack();
	TestQueue();
	return 0;
}