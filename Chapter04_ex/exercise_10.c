#include <stdio.h>
#define MAX_SIZE 100
/* 
	신라대학교 202395016 컴퓨터공학부 박수연
	--> 문제 10번, 배열에 들어있는 정수의 순서를 반전하는 프로그램 

*/
// 구조체 정의
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 스택 초기화, 현재 배열에 아무것도 없음 --> -1 (인덱스 번호 0부터 시작하기 때문) 
void init(Stack *s) {
    s->top = -1;
}

// 스택이 비었는지 확인 : top이 -1 인지 확인 필요 
int is_empty(Stack *s) {
    return s->top == -1;
}

// 스택이 가득 찼는지 확인
int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 스택에 값 추가
void push(Stack *s, int item) {
	// 조건 : 스택이 가득 찾다면 다시 전으로 돌아간다 
    if (is_full(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    // 비어있으면 값을 차례대로 추가한다, 먼저 1씩 증가시킨 후 값을 넣는다 
    s->data[++(s->top)] = item;
}

// 스택에서 값 꺼내기
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("스택이 비어 있습니다.\n");
        return -1;	// 비어있다면 -1를 반환 
    }
    // 값을 꺼낸 후 1씩 감소 시킨다 
    return s->data[(s->top)--];
}

int main() {
    int arr[6];	// 크기가 6인 정수 배열 선언 
    int i;		// 반복문 활용 
    Stack s;	// 타입이 Stack인 변수 s 
    init(&s);	// 스택 초기화, 스택 변수 s의 주소 전달 

	// 사용자에게 입력받기 
    printf("정수 배열의 크기 : 6\n");
    printf("--------------- 정수 6개를 받습니다. ---------------\n");
    for (i = 0; i < 6; i++) {
    	printf("%d번째 정수 : ", i+1); 
        scanf("%d", &arr[i]);
        push(&s, arr[i]); 		// 입력받은 값을 차례대로 하나씩 스택에 저장
    }
	
	// 출력하기 
	printf("반전된 정수 배열 : ");
	for (i = s.top; i >= 0; i--) {
    printf("%d ", s.data[i]);
	}
	
	/*
	while 문으로 출력하려면...
	 
    printf("반전된 정수 배열 : ");
    while (!is_empty(&s)) {
        printf("%d ", pop(&s)); // 스택에서 하나씩 꺼내어 출력 --> pop()
    }
	*/

    return 0;
}
