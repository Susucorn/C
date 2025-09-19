#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

/* 
	신라대학교 202395016 컴퓨터공학부 박수연 
	--> 배열의 키 값을 찾는 프로그램 
*/


// 키 값을 찾는 함수
int seq_search(int list[], int key){
	int i;
	
	for (i=0; i<SIZE; i++){
		if (list[i] == key){	// 배열의 i번째 요소가 키 값과 값으면 인덱스 반환 
			return i;
		}
	}
	printf("찾고자 하는 key값이 없습니다.\n");
	exit(1);  // 비정상 종료
} 
 
int main(int argc, char *argv[]) {
	int i, k;
	int arr[SIZE];
	
	// 사용자에게 배열 요소 입력받기
	printf("----- 총 %d개의 값을 입력 받습니다. -----\n", SIZE);
	for (i=0; i<SIZE; i++){
		printf("%d번째의 값 : ", i+1);
		scanf("%d", &arr[i]);
	}
	
	// 입력 확인하기
	printf("\n----- 현재 입력된 값을 확인 -----\n");
	for (i=0; i<SIZE; i++){
		printf("%d번째 값 : %d\n", i+1, arr[i]);
	}
	
	// 사용자에게 키 값 입력받기
	printf("\n찾고자 하는 key 값을 입력하세요 : ");
	scanf("%d", &k);
	
	// 키 값의 인덱스 구하기
	printf("%d의 인덱스 값 : %d\n", k, seq_search(arr, k));
	
	return 0;
}
