#define _CRT_SECURE_NO_WARNINGS
#include"HuffmanTree.h"

int main()
{

	int n = 0;
	printf("请输入数据个数:>");
	scanf("%d", &n);

	//w为存放权值的元素

	DataType* w = (DataType*)malloc(sizeof(DataType) * n);

	if (w == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	printf("请输入数据:>");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &w[i]);
	}
	HuffmanTree HT=NULL;
	CreateHuffmanTree(&HT, w, n);//构建哈夫曼树

	//构建哈夫曼编码
	HuffmanCode HCO = NULL;
	HuffmanCoding(HT, &HCO, n);
	for (int i = 1; i <= n; i++)//打印哈夫曼编码
	{
		printf("数据%.2lf的编码为:%s\n", HT[i].weight, HCO[i]);
	}
	free(w);
	
	
	return 0;
}