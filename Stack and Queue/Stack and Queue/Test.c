#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

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

int main()
{
	TestStack();
	return 0;
}