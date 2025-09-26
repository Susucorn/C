#include <stdio.h>
#define MAX_SIZE 100
/* 
	신라대학교 202395016 컴퓨터공학부 박수연
	--> 배열에 들어있는 정수의 순서를 반전하는 프로그램 

*/

// 2개의 멤버를 가진 구조체 선언 
typedef struct {
    int data[MAX_SIZE];		// 정수를 저장할 배열 
    int top;				// 스택의 최상위 인덱스 
} Stack;

// 스택을 공백상태로 만듦 
void init(Stack *s) {
    s->top = -1;	// 인덱스 -1은 공백상태를 뜻함 
}

// 스택이 공백상태인지 검사 
int is_empty(Stack *s) {
    return s->top == -1;	// 공백상태라면 참, 아니라면 거짓 
}

// 스택이 포화상태인지 검사 
int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;	// 포화상태라면 참, 아니라면 거짓 
}

// 스택에 요소를 추가--> 먼저 스택이 포화상태인지 검사한다 
void push(Stack *s, int item) { 
    if (is_full(s)) {
        printf("스택이 가득 찼습니다.\n");	// 포화상태라면 요소 삽입 불가 
        return;	// 호출된 곳으로 다시 돌아감 
    } 
    s->data[++(s->top)] = item;	// 포화 상태가 아니라면 인덱스 0번부터 차례대로 요소를 삽입한다 
}

// 스택에 요소를 삭제 --> 먼저 스택이 공백상태인지 검사한다 
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("스택이 비어 있습니다.\n");	// 공백상태라면 요소 삭제 불가 
        return -1;	// -1을 반환하여 스택이 비어있다는 것을 알린다 
    } 
    return s->data[(s->top)--];		// 공백 상태가 아니라면 맨 위에 요소를 먼저 뺀 후 1씩 감소시켜 삭제한다 
}

int main() {
    int arr[6];		// 크기가 6인 배열	 
    int i;			// 반복문 활용 
    Stack s;		// 구조체 타입의 변수
    
    init(&s);		// s의 위치를 전달하여 스택을 공백상태로 만든다(함수호출) 
	
	// 입력받기 
    printf("정수 배열의 크기 : 6\n");
    printf("--------------- 정수 6개를 받습니다. ---------------\n");
    for (i = 0; i < 6; i++) {
    	printf("%d번째 정수 : ", i+1); 
        scanf("%d", &arr[i]);
        push(&s, arr[i]); 
    }
	
	// 출력하기 
	printf("반전된 정수 배열 : ");
	for (i = s.top; i >= 0; i--) {
    printf("%d ", pop(&s));
	}
	
    return 0;
}
