#include <stdio.h>
#include <stdlib.h>

/*
	신라대학교 202395016 박수연
	--> 팩토리얼을 계산하는 프로그램 
	
	: 반복문 for 사용
*/

// 거듭제곱의 값을 구하는 함수 
int get_fac(int n1, int n2){
	int i;
	int result = 1;	// 1로 초기화 
	
	for (i=0; i<n2; i++){
		result = result*n1;
	}
	return result;
}
int main(int argc, char *argv[]) {
	int num1, num2;
	// 사용자에게 입력 받기
	printf("밑수 입력 : ");
	scanf("%d", &num1);
	printf("지수 입력 : ");
	scanf("%d", &num2);
	
	// 함수 호출하여 결과값 출력
	printf("\n%d^%d = %d", num1, num2, get_fac(num1, num2));
	return 0;
}
