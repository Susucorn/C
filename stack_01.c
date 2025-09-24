#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100	// 스택의 크기 100 

/* 
	신라대학교 202395016 컴퓨터공학부 박수연
	--> 정수 배열 스택 프로그램
	
	: 전역변수로 구현하는 방법 

*/

typedef int element;		// 데이터의 자료형
element  stack[MAX_STACK_SIZE]; // 1차원 배열
int  top = -1;			

// 스택이 공백 상태인지 검사 
int is_empty()
{
	return (top == -1);	// 스택이 공백상태(top == -1)임을 리턴한다 
}
// 스택이 포화 상태인지 검사 
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));	// 스택이 포화상태 top == (MAX_STACK_SIZE - 1)임을 리턴한다 
}
// 스택에 요소를 삽입(push연산) 
void push(element item)
{
	// 요소를 삽입하기 전에 스택이 포화상태인지 먼저 검사한다 
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;	// top이 -1이라면(공백상태), 요소를 추가하기전에 먼저 인덱스 0으로 만든 후 요소 삽입 
}
// 스택에 요소를 삭제(pop연산) 
element pop()
{
	// 요소를 삭제하기 전에 스택이 공백상태인지 먼저 검사한다
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];	// 스택에 있는 요소를 하나씩 차례대로 삭제 
}
// 피크 함수 - 스택의 가장 위에 있는 값이 무엇인지 검사 
element peek()
{
	// 스택이 공백상태인지 먼저 검사한다 
	if (is_empty()) {
		fprintf(stderr, "스택에 요소가 존재하지 않습니다.\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	int i;
	
	//값을 직접 입력 
	for (i=0; i<3; i++){
		push(i+1);
	}
	
	/* 
	push(1);
	push(2);
	push(3);
	*/
	
	// 출력 
	printf("스택의 pop연산 수행\n");
	for (i=0; i<3; i++){
		printf("%d\n", pop());
	}
	
	/*
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	*/
	return 0;
}
