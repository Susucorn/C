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

// 탐색할 값을 반환하는 함수 
int search_list(ListNode* head, element target) {
    if (head == NULL) return -1;

    ListNode* p = head->link;
    int index = 1;

    do {
        if (p->data == target)
            return index;
        p = p->link;
        index++;
    } while (p != head->link);

    return -1; // 찾지 못한 경우
}



// main 함수 
int main(void)
{
	ListNode *head = NULL;
	int count, input, search;
	
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

	// 탐색할 값 입력받기
	printf("탐색할 값을 입력하세요 : ");
	scanf("%d", &search);
	
	int position = search_list(head, search);	// 값을 탐색하는 함수 호출
	
	// 출력하기 	
	if (position == -1)	// -1을 반환받음 --> 입력받은 값이 리스트에 없는 경우 
    	printf("입력받은 %d는 리스트에 없습니다.\n", search);
	else
    	printf("%d는 리스트의 %d번째 노드에 있습니다.\n", search, position);

	 

	return 0;
}
