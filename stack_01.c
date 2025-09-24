#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100	// ������ ũ�� 100 

/* 
	�Ŷ���б� 202395016 ��ǻ�Ͱ��к� �ڼ���
	--> ���� �迭 ���� ���α׷�
	
	: ���������� �����ϴ� ��� 

*/

typedef int element;		// �������� �ڷ���
element  stack[MAX_STACK_SIZE]; // 1���� �迭
int  top = -1;			

// ������ ���� �������� �˻� 
int is_empty()
{
	return (top == -1);	// ������ �������(top == -1)���� �����Ѵ� 
}
// ������ ��ȭ �������� �˻� 
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));	// ������ ��ȭ���� top == (MAX_STACK_SIZE - 1)���� �����Ѵ� 
}
// ���ÿ� ��Ҹ� ����(push����) 
void push(element item)
{
	// ��Ҹ� �����ϱ� ���� ������ ��ȭ�������� ���� �˻��Ѵ� 
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;	// top�� -1�̶��(�������), ��Ҹ� �߰��ϱ����� ���� �ε��� 0���� ���� �� ��� ���� 
}
// ���ÿ� ��Ҹ� ����(pop����) 
element pop()
{
	// ��Ҹ� �����ϱ� ���� ������ ����������� ���� �˻��Ѵ�
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];	// ���ÿ� �ִ� ��Ҹ� �ϳ��� ���ʴ�� ���� 
}
// ��ũ �Լ� - ������ ���� ���� �ִ� ���� �������� �˻� 
element peek()
{
	// ������ ����������� ���� �˻��Ѵ� 
	if (is_empty()) {
		fprintf(stderr, "���ÿ� ��Ұ� �������� �ʽ��ϴ�.\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	int i;
	
	//���� ���� �Է� 
	for (i=0; i<3; i++){
		push(i+1);
	}
	
	/* 
	push(1);
	push(2);
	push(3);
	*/
	
	// ��� 
	printf("������ pop���� ����\n");
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
