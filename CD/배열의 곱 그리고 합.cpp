#include <stdio.h>

int main()
{
	
	//�迭�� �� �հ� ���ϱ�
	//�迭�� ����ִ� �� �����͸� ��� 2��� ����� ���� ����ϱ� 
	
	 
	int numArr[10] = {11,22,33,44,55,66,77,88,99,110};
	int sum = 0;
	
	
	for (int i = 0; i<=9; i++)
	{ 
		numArr[i] *= 2;
	}
	for(int i = 0; i <=9  ; i++)
	{ 
	    printf("%d", numArr[i]);
	}
	return 0;
}

