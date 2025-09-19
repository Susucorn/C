#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	신라대학교 202395016 컴퓨터공학부 박수연 
	--> 거듭제곱의 소요시간을 측정하는 프로그램
	
	: 작은 결과값은 출력이 되지만 2^500 일 때 결과값 0이 출력된다
		이유? int 타입의 범위를 초과한 값이기 때문 
*/


// 거듭제곱을 구하는 함수
int get_power(int n1, int n2){
	int i;
	int result = 1;
	
	for (i=0;i<n2; i++ ){
		result *= n1;
	}
	
	return result;
}

int main(int argc, char *argv[]) {
	int num1, num2, i; 
	clock_t start, stop;	// 측정시작과 종료 변수 
	double  duration;		// 걸린 시간
	
	// 사용자에게 입력 받기
	printf("----- 거듭제곱 연산을 수행합니다. -----\n");
	printf("밑수 입력 : ");
	scanf("%d", &num1);
	printf("지수 입력 : ");
	scanf("%d", &num2);
	
	// 측정 
	start = clock(); // 측정 시작
	
	for (i = 0; i < 1000000; i++){
		get_power(num1, num2);
	}
	
	stop = clock();	// 측정 멈춤 
	duration = (double)(stop - start) / CLOCKS_PER_SEC;	// 걸린 시간
	
	// 결과 출력 
	printf("\n----- 거듭제곱 연산결과 -----\n");
	printf("%d^%d의 결과 : %.d\n", num1, num2, get_power(num1, num2));
	printf("%d^%d 연산의 소요 시간 : %.7lf",num1, num2, duration);
	
	return 0;
}
