#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <time.h>
int main()
{
    const int MAX = 100; 
    FILE *filePointer = fopen("report2.csv", "r");
  
    int count = 0;
    time_t timer;
	struct tm* t;
	timer = time(NULL); 
	t = localtime(&timer);

  
	//입력부
	int  todayArr[MAX], ticketCaseArr[MAX],treatmentArr[MAX],ageTypeArr[MAX],ticketDigitArr[MAX],ticketPriceArr[MAX];
    while (fscanf(filePointer, "%d,%d,%d,%d,%d,%d", &todayArr[count], &ticketCaseArr[count],&treatmentArr[count],
	                   &ageTypeArr[count],&ticketDigitArr[count],&ticketPriceArr[count])!= -1){
	                   	count++;
	}
	fclose(filePointer);
	
	
	
    //출력부
	printf("=============report.csv===========\n");
	for (int i= 0; i < count; i++){
		printf("%d %d %d %d %d %d\n", todayArr[i], ticketCaseArr[i],treatmentArr[i],ageTypeArr[i],ticketDigitArr[i],ticketPriceArr[i]);
	}
	printf("==================================\n");
	
    return 0;
 } 
