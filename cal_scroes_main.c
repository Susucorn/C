#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100  // 상수 선언 - 배열 사용을 위함
 
/*
	신라대학교 컴퓨터공학부 202395016 박수연
	- 최고성적을 구하는 프로그램
	
	1) main 함수
		- 학생수와, 학생 수 만큼 성적을 입력받은 후, 배열에 저장한다
	2) 최고 성적을 구하는 기능을 가진 함수 
		- 인자값인 학생 수를 받는다
		- 학생 수 만큼 반복하여 배열의 요소에 접근한다 (for문 필요)
		- 배열의 첫번째 값을 변수의 초깃값으로 설정한다 (비교)
		- 첫번째 값이 할당된 변수와 배열의 요소들을 차례대로 검사한다(if 조건문 필요)
			변수 VS 배열의 n번째 요소 비교한다
				-- 변수가 크면 최대값은 변수, n번째 요소가 크면 최대값은 n번째 요소가 됨
		- 최대값을 함수를 호출한 곳으로 리턴
	 
*/

int scores[MAX_ELEMENTS]; // 자료구조

// 최고 성적을 구하는 기능을 가진 함수 - 학생 수(길이)를 받는다 
int get_max_score(int n){
	int i, largest; 				// 반복문 사용, 최대값 할당할 변수 선언
	largest =  scores[0];			// 비교를 위해 첫번째 요소 값으로 초기화
	
	for (i=1; i<n; i++){			// 1번째 요소부터 비교해야 함 
		if (scores[i]>largest){		// 최대값이 되기 위한 조건 
			largest = scores[i];
		}
	}
	return largest;
} 
 
int main(int argc, char *argv[]) {
	int length, i;	// 학생 수, 반복문 활용 
	
	printf("성적을 입력할 학생 수 : ");
	scanf("%d", &length);
	
	printf("\n학생 수 입력 완료, 점수 입력 시작합니다.\n");
	 
	// 학생 수(길이)만큼 반복하여 점수 저장하기 
	for (i=0; i<length; i++){
		printf("%d번째 학생의 점수를 입력하세요 : ", i+1);
		scanf("%d", &scores[i]); 	// 차례대로 저장함 
	}
	
	// 함수 호출하여 최대값 리턴받기
	printf("제일 높은 점수 : %d\n", get_max_score(length)); 
	return 0;
}
