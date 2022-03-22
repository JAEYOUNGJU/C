#include <stdio.h>

int main()
{
	int A[3][3]={
	
	{0,0,0},
	{0,3,4},
	{0,5,6}
	};
	int B[3][3] ={
	{0,0,0},
	{0,1,5},
	{0,3,2}
    };
    int AB[3][3] = {0};
	AB[1][1] = A[1][1]*B[1][1]+A[1][2]*B[2][1];
	AB[1][2] = A[1][2]*B[2][1]+A[1][2]*B[2][2];
	AB[2][1] = A[2][1]*B[1][1]+A[2][2]*B[2][1];
	AB[2][2] = A[2][2]*B[2][1]+A[2][2]*B[2][2];
	
	printf("AB = \n");
	for(int index =1; index <= 2; index++){
		for (int index2 =1; index <= 2; index++){
			printf("%d", AB[index][index2]);
	}
	printf("\n");
	}
	return 0;
}
