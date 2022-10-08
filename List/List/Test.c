#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

void TestList()
{
	LTNode* plist = NULL;
	plist = ListInit();
	//ListPushBack(plist, 1);
	//ListPushBack(plist, 2);
	//ListPushBack(plist, 3);
	//ListPushBack(plist, 4);
	
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);

	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);

	//ListPopFront(plist);
	//ListPopFront(plist);
	//ListPopFront(plist);
	//ListPopFront(plist);
	//ListPopFront(plist);
	

	//LTNode* pos = ListFind(plist, 2);
	//ListInsert(pos, 66);
	//ListPrint(plist);
	//ListEase(pos);
	ListDestroy(plist);
	
	plist = NULL;
	


}

int main()
{
	TestList();
	return 0;
}