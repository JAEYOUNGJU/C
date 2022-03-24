//놀이공원 요금 계산 
#include <stdio.h>
#include <time.h>

int main () {
	//변수
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
			// 이용권 종류 (종합 or 파크)
			do {
				printf("\n이용권의 종류를 선택해주세요.\n");
				printf("1. 종합이용권 (롯데월드+민속박물관)\n2. 파크이용권 (롯데월드)\n");
				scanf("%d",&ticketStyle);
			} while(ticketStyle >2) ;
			
			//주,야간권 선택
			do {
				printf("\n입장시간에 따른 이용권을 선택해 주세요.\n");
				printf("1. 1Day 2. After4 (오후4시부터 입장)\n");
				scanf("%d",&enterStyle);
			} while(enterStyle >2) ;
			
			//주민번호
			do {
				printf("\n주민등록번호 13자리를 입력해주세요. ('-'대신 한칸 띄어주세요.)\n");
				scanf("%6d %7d",&idFront, &idBack);
				
				idBackFirst = idBack/1000000;
				idFrontMonth = (idFront/100)%100;
				idFrontDay = idFront%100;
			} while(idBackFirst >4 || idBackFirst<1 || idFrontDay>31 || idFrontDay<1 || idFrontMonth >12 ||
						idFrontDay <1 || idBack > 9999999 || idFront>999999 ||(idFrontMonth = 2 && idFrontDay>29)) ;	
			
			//우대사항
			do {	
				printf("\n우대사항은 선택해주세요.\n");
				printf("1.없음(*만 65세 이상은 어린이요금 적용)\n2.장애인 우대\n3.국가유공자 우대\n");
				printf("4.휴가장병 우대\n5.임산부 우대\n6.다둥이 행복카드 우대\n");
				scanf("%d",&treatment);
			} while(treatment>6) ;
	
			//구매수 
			do {
				printf("\n동일한 티켓을 몇 장 구매하시겠습니까?.\n");
				scanf("%d",&ticketDigit);
				
				if ( ticketDigit>10 ){
					printf("최대 10장 구매할 수 있습니다.\n\n");
				} 
			} while(ticketDigit>10) ;
	
			
			today= (t->tm_year + 1900)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;  
			
			//1900년생, 2000년생 
			if (idBackFirst ==3 || idBackFirst == 4) { 
				yyyymmdd = idFront + 20000000;
			} else {                  
				yyyymmdd = idFront + 19000000;
			} 
		
			//만 나이
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
			
			//우대사항 적용 전
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
			
			//우대사항 적용
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
			//최종 가격
			ticketPrice *= ticketDigit;
			
			//총액 출력
			if (ticketPrice==0){
				printf("\n무료 입장 입니다.\n");
			}
			else {
				printf ("\n%d매의  총금액은 %d원 입니다.\n",ticketDigit,ticketPrice) ;
			}
			
			ticketCaseArr[counter] = ticketCase;
			treatmentArr[counter] = treatment;
			ageTypeArr[counter] = ageType;
			ticketPriceArr[counter] = ticketPrice;
			ticketDigitArr[counter]=ticketDigit;
			totalTicketPrice += ticketPrice; 
			todayArr[counter]=today; 
			
			counter++;
			
			printf("\n이어서 이용권을 구매하시겠습니까?\n1.예\n2.아니요\n");
			scanf("%d",&again); 
			
			//변수 초기화
			ticketStyle=0, enterStyle=0, treatment=0, ticketDigit=0, idFront=0, idBack=0, ageType=0, ticketPrice=0;  

		} while(again == 1);
		
		printf("\n이용해주셔서 감사합니다.\n");
		
		// 영수증 출력
		printf("\n\n==================================== %s ====================================\n","poly land") ;
		printf("%s\t\t%s\t     %s\t  %s\t\t%s\n\n","선택사항","연  령","매수","가격","우대사항");
		for (int i =0; i<counter; i++) {
			//데이터 파일형식 저장 
			fprintf(filePointer,"%d,%d,%d,%d,%d,%d\n",
								todayArr[i],ticketCaseArr[i],treatmentArr[i],ageTypeArr[i],ticketDigitArr[i],ticketPriceArr[i]);
			switch (ticketCaseArr[i]) {
				case 1:
					printf("%s\t%s","종합이용권","1Day");
					break;
				case 2:
					printf("%s\t%s","종합이용권","After4");
					break;
				case 3:
					printf("%s\t%s","파크이용권","1Day");
					break;
				case 4:
					printf("%s\t%s","파크이용권","After4");
					break;
				default:
					break;
			}
			
			switch (ageTypeArr[i]) {
				case 1:
					printf("\t%s","어  른");
					break;
				case 2:
					printf("\t%s","청소년");
					break;
				case 3:
					printf("\t%s","어린이");
					break;
				case 4:
					printf("\t%s","유  아");
					break;
				case 5:
					printf("\t%s","노  인");
					break;
				case 6:
					printf("\t%s","영  아");
					break;
				default:
					break;
			}
			
			printf("%10d%14d원\t",ticketDigitArr[i],ticketPriceArr[i]) ;
			
			switch (treatmentArr[i]) {
				case 1:
					printf("%s\n","우대사항 없음");
					break;
				case 2:
					printf("%s\n","장애인 우대");
					break;
				case 3:
					printf("%s\n","국가유공자 우대");
					break;
				case 4:
					printf("%s\n","휴가장병 우대");
					break;
				case 5:
					printf("%s\n","임산부 우대");
					break;
				case 6:
					printf("%s\n","다둥이 행복카드 우대");
					break;
				default:
					break;
			}
		}
		printf("\n입장료 총액은 %d원 입니다.", totalTicketPrice);
		printf("\n===================================================================================\n") ;
		printf("\n이어서 주문을 받겠습니까?\n1.예\n2.종료\n");
		scanf("%d",&next);
		//변수 초기화 
		counter = 0;
		totalTicketPrice=0;
	} while(next == 1);
	
	return 0; 
} 
