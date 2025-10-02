#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
/* 
	신라대학교 202395016 컴퓨터공학부 박수연
	--> 문제 11번, 수식에 있는 괄호의 번호를 출력하는 프로그램 
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
void push(Stack *s, int item) {
    if (s->top >= MAX_SIZE - 1) {
        printf("스택이 가득 찼습니다.\n");
        exit(1);
    }
    // 비어있으면 값을 차례대로 추가한다, 먼저 1씩 증가시킨 후 값을 넣는다
    s->data[++(s->top)] = item;
}

// 스택에서 값 꺼내기
int pop(Stack *s) {
    if (s->top == -1) {
        printf("스택이 비어 있습니다.\n");
        exit(1);	// 비어있다면 강제 종료 
    }
    // 값을 꺼낸 후 1씩 감소 시킨다
    return s->data[(s->top)--];
}

int main() {
	int i;					// 반복문 활용 
    int count = 0;			// 왼쪽 괄호 확인을 위한 변수 
    char expr[MAX_SIZE];	// 크기가 100인 문자 배열 선언 
    Stack s;				// 타입이 Stack인 변수 s
    
    init(&s);				// 스택 초기화, 스택 변수 s의 주소 전달
	
	// 사용자에게 괄호 입력 받기 
    printf("수식 입력 : ");
    scanf("%s", expr);
	
	// 출력 
    printf("괄호 수 : ");
    // 문자열을 한 글자씩 검사한다, 공백(문자열 끝)을 만나기 전까지
    for (i = 0; expr[i] != '\0'; i++) {		 
        if (expr[i] == '(') {				// expr 의 [i]번째 요소가 왼쪽 소괄호라면...  
            count++;						// 괄호 번호를 하나씩 증가시킴(0으로 초기화 되었으므로 +1 먼저 시켜줌) 
            push(&s, count);				// 번호를 스택에 저장 후 
            printf("%d ", count);			// 출력 
            }
            
		else if (expr[i] == ')') {			// 그렇지 않고 expr의 [i]번째 요소가 오른쪽 소괄호라면...  
            int matched = pop(&s);			// 최근에 저장된 괄호 번호를 꺼낸다 pop() 
            printf("%d ", matched);			// 출력 
        }
    }

    return 0;
}
