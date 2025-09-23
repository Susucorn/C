#include <stdio.h>
#include <stdlib.h>

/*
	신라대학교 202395016 박수연
	--> 팩토리얼을 계산하는 프로그램 
	
	: 재귀호출 - 조건이 만족될 때 까지 호출하여 수행한다 
*/

// 팩토리얼 값을 계산하는 함수
int get_fac(int n){
	if (n<=1)
		return 1;			// 0 or 1이면 1을 리턴
	else return (n * get_fac(n-1));	// 조건이 만족할 때 까지 자신을 호출하여 수행 
} 

int main(int argc, char *argv[]) {
	int num;
	// 사용자에게 입력받기
	printf("구하고자 하는 팩토리얼 값 : ");
	scanf("%d", &num);
	
	// 함수 호출하여 값을 리턴받는다
	printf("%d의 팩토리얼 값 : %d\n", num, get_fac(num));
	
	/*
		--> 값을 변수에 저장시켜 출력하는 방법 
		result = get_fac(num);
		printf("%d의 팩토리얼 값 : %d\n", result);
		
		--> if (n<=1) return 1; 이 부분이 없다면? 
			: 무한 루프로 인한 오류 발생, 순환은 종료 문장이 반드시 있어야 한다 
	*/
	return 0;
}
