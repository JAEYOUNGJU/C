//���̰��� ��� ��� 
#include <stdio.h>
#include <time.h>

int main () {
	//����
	int ticketStyle, enterStyle, ticketDigit, treatment, age, ticketCase, ticketPrice, totalTicketPrice, today, yyyymmdd, ageType;
	int	idFront, idFrontMonth, idFrontDay, idBack, idBackFirst;
	int	next, again, counter=0;
		
	const int ADULT_DAY = 56000, TEEN_DAY = 50000, CHILD_DAY = 46000, BABY_DAY = 15000,
	    	  ADULT_DAY_ALL = 59000, TEEN_DAY_ALL = 52000, CHILD_DAY_ALL = 47000, BABY_DAY_ALL = 15000,
	    	  AFTER4_ADULT = 45000, AFTER4_TEEN = 40000, AFTER4_CHILD = 35000, AFTER4_BABY = 15000,
	    	  AFTER4_ADULT_ALL = 48000, AFTER4_TEEN_ALL = 42000, AFTER4_CHILD_ALL = 36000, AFTER4_BABY_ALL = 15000,
	    	  OLDMAN_AGE=65, TEEN_AGE_MAX=18, TEEN_CHILD_AGE=13, CHILD_BABY_AGE=3, BABY_AGE_MIN=1;


	time_t timer;
	struct tm* t;
	timer = time(NULL); 
	t = localtime(&timer);

	do { 
		int ticketCaseArr[20]={0}, treatmentArr[20]={0}, ageTypeArr[20]={0}, ticketPriceArr[20]={0}, ticketDigitArr[20]={0}, todayArr[20]={0};
		 
		FILE *filePointer = fopen("report1.csv","a");
		
		do {
			printf("================= poly land =================\n") ;
			// �̿�� ���� (���� or ��ũ)
			do {
				printf("\n�̿���� ������ �������ּ���.\n");
				printf("1. �����̿�� (�Ե�����+�μӹڹ���)\n2. ��ũ�̿�� (�Ե�����)\n");
				scanf("%d",&ticketStyle);
			} while(ticketStyle >2) ;
			
			//��,�߰��� ����
			do {
				printf("\n����ð��� ���� �̿���� ������ �ּ���.\n");
				printf("1. 1Day 2. After4 (����4�ú��� ����)\n");
				scanf("%d",&enterStyle);
			} while(enterStyle >2) ;
			
			//�ֹι�ȣ
			do {
				printf("\n�ֹε�Ϲ�ȣ 13�ڸ��� �Է����ּ���. ('-'��� ��ĭ ����ּ���.)\n");
				scanf("%6d %7d",&idFront, &idBack);
				
				idBackFirst = idBack/1000000;
				idFrontMonth = (idFront/100)%100;
				idFrontDay = idFront%100;
			} while(idBackFirst >4 || idBackFirst<1 || idFrontDay>31 || idFrontDay<1 || idFrontMonth >12 ||
						idFrontDay <1 || idBack > 9999999 || idFront>999999 ||(idFrontMonth = 2 && idFrontDay>29)) ;	
			
			//������
			do {	
				printf("\n�������� �������ּ���.\n");
				printf("1.����(*�� 65�� �̻��� ��̿�� ����)\n2.����� ���\n3.���������� ���\n");
				printf("4.�ް��庴 ���\n5.�ӻ�� ���\n6.�ٵ��� �ູī�� ���\n");
				scanf("%d",&treatment);
			} while(treatment>6) ;
	
			//���ż� 
			do {
				printf("\n������ Ƽ���� �� �� �����Ͻðڽ��ϱ�?.\n");
				scanf("%d",&ticketDigit);
				
				if ( ticketDigit>10 ){
					printf("�ִ� 10�� ������ �� �ֽ��ϴ�.\n\n");
				} 
			} while(ticketDigit>10) ;
	
			
			today= (t->tm_year + 1900)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;  
			
			//1900���, 2000��� 
			if (idBackFirst ==3 || idBackFirst == 4) { 
				yyyymmdd = idFront + 20000000;
			} else {                  
				yyyymmdd = idFront + 19000000;
			} 
		
			//�� ����
			age = (today - yyyymmdd)/10000;
			
			
			if ( age <CHILD_BABY_AGE && age >=BABY_AGE_MIN) { 
				ageType=4; 
			} else if ((age >= CHILD_BABY_AGE && age <TEEN_CHILD_AGE)) {
				ageType = 3; 
			} else if (age >= TEEN_CHILD_AGE && age <= TEEN_AGE_MAX) {
				ageType = 2; 
			} else if ( age >= OLDMAN_AGE ) {
				ageType = 5;  
			} else {
				ageType = 1; 
			}
			
			 
			if (ticketStyle==1 && enterStyle==1) {
				ticketCase = 1; 
			} else if (ticketStyle==1 && enterStyle==2) {
				ticketCase =2; 
			} else if (ticketStyle == 2 && enterStyle == 1) {
				ticketCase = 3; 
			} else {
				ticketCase = 4;  
			} 
			
			//������ ���� ��
			if ( ageType == 1) { 
				if (ticketCase== 1) {        
					ticketPrice= ADULT_DAY_ALL;
				} else if (ticketCase==2) {  
					ticketPrice= AFTER4_ADULT_ALL;
				}else if (ticketCase ==3) {  
					ticketPrice= ADULT_DAY;
				} else {                         
					ticketPrice= AFTER4_ADULT;
				}
			} else if ( ageType == 2) {  
				if (ticketCase== 1) {
					ticketPrice=TEEN_DAY_ALL;
				} else if (ticketCase==2) {
					ticketPrice=AFTER4_TEEN_ALL;
				}else if (ticketCase ==3) {
					ticketPrice=TEEN_DAY;
				} else {
					ticketPrice=AFTER4_TEEN;
				}
			} else if ( ageType == 3) { 
				if (ticketCase== 1) {
					ticketPrice=CHILD_DAY_ALL;
				} else if (ticketCase==2) {
					ticketPrice=AFTER4_CHILD_ALL;
				}else if (ticketCase ==3) {
					ticketPrice=CHILD_DAY;
				} else {
					ticketPrice=AFTER4_CHILD;
				}
			} else if (ageType == 5) { 
				if (ticketCase== 1) {
					ticketPrice=CHILD_DAY_ALL;
				} else if (ticketCase==2) {
					ticketPrice=AFTER4_CHILD_ALL;
				}else if (ticketCase ==3) {
					ticketPrice=CHILD_DAY;
				} else {
					ticketPrice=AFTER4_CHILD;
				}
			} else {                  
				if (ticketCase== 1) {
					ticketPrice=BABY_DAY_ALL;
				} else if (ticketCase==2) {
					ticketPrice=AFTER4_BABY_ALL;
				}else if (ticketCase ==3) {
					ticketPrice=BABY_DAY;
				} else {
					ticketPrice=AFTER4_BABY;
				}
			}
			
			//������ ����
			if (treatment == 2) {
				ticketPrice = ticketPrice/2 ; 
			} else if (treatment == 3) {
				ticketPrice = ticketPrice/2 ;
			} else if (treatment == 4 && ticketStyle==1) { 
				ticketPrice = (int)(ticketPrice*0.51);
			} else if (treatment == 5 && ticketStyle==1 ) {
				ticketPrice = ticketPrice/2;
			} else if (treatment == 6 && ticketStyle==1) {
				ticketPrice = (int)(ticketPrice*0.7);
			}
			//���� ����
			ticketPrice *= ticketDigit;
			
			//�Ѿ� ���
			if (ticketPrice==0){
				printf("\n���� ���� �Դϴ�.\n");
			}
			else {
				printf ("\n%d����  �ѱݾ��� %d�� �Դϴ�.\n",ticketDigit,ticketPrice) ;
			}
			
			ticketCaseArr[counter] = ticketCase;
			treatmentArr[counter] = treatment;
			ageTypeArr[counter] = ageType;
			ticketPriceArr[counter] = ticketPrice;
			ticketDigitArr[counter]=ticketDigit;
			totalTicketPrice += ticketPrice; 
			todayArr[counter]=today; 
			
			counter++;
			
			printf("\n�̾ �̿���� �����Ͻðڽ��ϱ�?\n1.��\n2.�ƴϿ�\n");
			scanf("%d",&again); 
			
			//���� �ʱ�ȭ
			ticketStyle=0, enterStyle=0, treatment=0, ticketDigit=0, idFront=0, idBack=0, ageType=0, ticketPrice=0;  

		} while(again == 1);
		
		printf("\n�̿����ּż� �����մϴ�.\n");
		
		// ������ ���
		printf("\n\n==================================== %s ====================================\n","poly land") ;
		printf("%s\t\t%s\t     %s\t  %s\t\t%s\n\n","���û���","��  ��","�ż�","����","������");
		for (int i =0; i<counter; i++) {
			//������ �������� ���� 
			fprintf(filePointer,"%d,%d,%d,%d,%d,%d\n",
								todayArr[i],ticketCaseArr[i],treatmentArr[i],ageTypeArr[i],ticketDigitArr[i],ticketPriceArr[i]);
			switch (ticketCaseArr[i]) {
				case 1:
					printf("%s\t%s","�����̿��","1Day");
					break;
				case 2:
					printf("%s\t%s","�����̿��","After4");
					break;
				case 3:
					printf("%s\t%s","��ũ�̿��","1Day");
					break;
				case 4:
					printf("%s\t%s","��ũ�̿��","After4");
					break;
				default:
					break;
			}
			
			switch (ageTypeArr[i]) {
				case 1:
					printf("\t%s","��  ��");
					break;
				case 2:
					printf("\t%s","û�ҳ�");
					break;
				case 3:
					printf("\t%s","���");
					break;
				case 4:
					printf("\t%s","��  ��");
					break;
				case 5:
					printf("\t%s","��  ��");
					break;
				case 6:
					printf("\t%s","��  ��");
					break;
				default:
					break;
			}
			
			printf("%10d%14d��\t",ticketDigitArr[i],ticketPriceArr[i]) ;
			
			switch (treatmentArr[i]) {
				case 1:
					printf("%s\n","������ ����");
					break;
				case 2:
					printf("%s\n","����� ���");
					break;
				case 3:
					printf("%s\n","���������� ���");
					break;
				case 4:
					printf("%s\n","�ް��庴 ���");
					break;
				case 5:
					printf("%s\n","�ӻ�� ���");
					break;
				case 6:
					printf("%s\n","�ٵ��� �ູī�� ���");
					break;
				default:
					break;
			}
		}
		printf("\n����� �Ѿ��� %d�� �Դϴ�.", totalTicketPrice);
		printf("\n===================================================================================\n") ;
		printf("\n�̾ �ֹ��� �ްڽ��ϱ�?\n1.��\n2.����\n");
		scanf("%d",&next);
		//���� �ʱ�ȭ 
		counter = 0;
		totalTicketPrice=0;
	} while(next == 1);
	
	return 0; 
} 
