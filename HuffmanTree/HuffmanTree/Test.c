#define _CRT_SECURE_NO_WARNINGS
#include"HuffmanTree.h"

int main()
{

	int n = 0;
	printf("���������ݸ���:>");
	scanf("%d", &n);

	//wΪ���Ȩֵ��Ԫ��

	DataType* w = (DataType*)malloc(sizeof(DataType) * n);

	if (w == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	printf("����������:>");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &w[i]);
	}
	HuffmanTree HT=NULL;
	CreateHuffmanTree(&HT, w, n);//������������

	//��������������
	HuffmanCode HCO = NULL;
	HuffmanCoding(HT, &HCO, n);
	for (int i = 1; i <= n; i++)//��ӡ����������
	{
		printf("����%.2lf�ı���Ϊ:%s\n", HT[i].weight, HCO[i]);
	}
	free(w);
	
	
	return 0;
}