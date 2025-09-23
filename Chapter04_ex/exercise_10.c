#include <stdio.h>
#define MAX_SIZE 100
/* 
	�Ŷ���б� 202395016 ��ǻ�Ͱ��к� �ڼ���
	--> ���� 10��, �迭�� ����ִ� ������ ������ �����ϴ� ���α׷� 

*/
// ����ü ����
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// ���� �ʱ�ȭ, ���� �迭�� �ƹ��͵� ���� --> -1 (�ε��� ��ȣ 0���� �����ϱ� ����) 
void init(Stack *s) {
    s->top = -1;
}

// ������ ������� Ȯ�� : top�� -1 ���� Ȯ�� �ʿ� 
int is_empty(Stack *s) {
    return s->top == -1;
}

// ������ ���� á���� Ȯ��
int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// ���ÿ� �� �߰�
void push(Stack *s, int item) {
	// ���� : ������ ���� ã�ٸ� �ٽ� ������ ���ư��� 
    if (is_full(s)) {
        printf("������ ���� á���ϴ�.\n");
        return;
    }
    // ��������� ���� ���ʴ�� �߰��Ѵ�, ���� 1�� ������Ų �� ���� �ִ´� 
    s->data[++(s->top)] = item;
}

// ���ÿ��� �� ������
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("������ ��� �ֽ��ϴ�.\n");
        return -1;	// ����ִٸ� -1�� ��ȯ 
    }
    // ���� ���� �� 1�� ���� ��Ų�� 
    return s->data[(s->top)--];
}

int main() {
    int arr[6];	// ũ�Ⱑ 6�� ���� �迭 ���� 
    int i;		// �ݺ��� Ȱ�� 
    Stack s;	// Ÿ���� Stack�� ���� s 
    init(&s);	// ���� �ʱ�ȭ, ���� ���� s�� �ּ� ���� 

	// ����ڿ��� �Է¹ޱ� 
    printf("���� �迭�� ũ�� : 6\n");
    printf("--------------- ���� 6���� �޽��ϴ�. ---------------\n");
    for (i = 0; i < 6; i++) {
    	printf("%d��° ���� : ", i+1); 
        scanf("%d", &arr[i]);
        push(&s, arr[i]); 		// �Է¹��� ���� ���ʴ�� �ϳ��� ���ÿ� ����
    }
	
	// ����ϱ� 
	printf("������ ���� �迭 : ");
	for (i = s.top; i >= 0; i--) {
    printf("%d ", s.data[i]);
	}
	
	/*
	while ������ ����Ϸ���...
	 
    printf("������ ���� �迭 : ");
    while (!is_empty(&s)) {
        printf("%d ", pop(&s)); // ���ÿ��� �ϳ��� ������ ��� --> pop()
    }
	*/

    return 0;
}
