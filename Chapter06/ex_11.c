#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 구조체 정의 : 노트 타입 
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
	printf("NULL\n");
}

//리스트 첫 부분에 새로운 노드 추가 
ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

// 리스트 마지막 부분에 새로운 노드 추가 
ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

// 데이터 필드 값을 모두 더하는 함수 
int sum_list(ListNode* head) {
    if (head == NULL) return 0; 

    int sum = 0;
    ListNode* p = head->link; 

    do {
        sum += p->data;
        p = p->link;
    } while (p != head->link);

    return sum;
}

// main 함수 
int main(void)
{
	ListNode *head = NULL;
	int count, input;
	
	// 사용자에게 몇 번 입력 받을 건지 입력 받기
	printf("사용자에게 입력을 받습니다.\n");
	printf("노드의 개수를 입력하세요 : ");
	scanf("%d", &count);
	
	// 사용자에게 입력 받은 만큼 반복하기 
	for (int i=0; i<count; i++){
		printf("노드 %d 데이터 : ", i+1);
		scanf("%d", &input);
		head = insert_last(head, input);
	}
	
	// 출력하기 
	printf("\n리스트 출력\n");
	print_list(head);

    int total = sum_list(head);		// 데이터 필드 값을 더하는 함수 호출 
    printf("연결 리스트의 데이터 합 : %d\n", total);

	return 0;
}
