#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100
/* 
	신라대학교 202395016 컴퓨터공학부 박수연 
	--> 최고 성적을 구하는 프로그램
	
	: 배열과 함수 활용 

*/
int scores[MAX_ELEMENTS];

// 최고 점수를 구하는 함수 
int get_max_score(int n){
	int i, largest;
	largest = scores[0];	// scores배열의 첫번째 요소를 변수에 초기화
	
	for (i = 1; i<n; i++) {
		if (scores[i] > largest) {	// scores의 i번째 요소가 largest에 있는 값보다 크다면 
			largest = scores[i];	// largest 값은 scores의 i번째 요소로 저장된다 
		}
	}
	return largest;
}
// 최고 점수의 인덱스를 구하는 함수
int get_max_index(int n){
	int i, largest;
	int max_index = 0;	// 인덱스 저장할 변수 
	largest = scores[0];
	
	for (i = 1; i<n; i++) {
		if (scores[i] > largest) {
			max_index = i;	// 점수가 높은 학생의 인덱스 번호를 저장 
		}
	}
	return max_index+1;
} 

int main(int argc, char *argv[]) {
	int i, num;
	
	// 학생 수 입력 받기
	printf("이번에 시험에 응시한 학생 수 : ");
	scanf("%d", &num);
	
	// 학생 수 만큼 점수 입력 받기
	printf("\n----- 학생의 점수를 입력하세요 -----\n");
	for (i=0; i<num; i++){
		printf("%d번째 학생 점수 : ", i+1);
		scanf("%d", &scores[i]);
	}
	
	// 학생 점수 출력하기
	printf("\n----- 학생의 점수를 출력합니다 -----\n");
	for (i=0; i<num; i++){
		printf("%d번째 학생의 점수 : %d\n", i+1, scores[i]);
	}
	
	// 점수가 제일 높은 학생 출력하기
	printf("\n\n----- 이번 시험에서 가장 높은 점수를 받은 학생-----\n");
	printf("%d번째 학생 : %d점\n",get_max_index(num), get_max_score(num));
	
	return 0;
}
