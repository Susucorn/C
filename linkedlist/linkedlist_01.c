#include <stdio.h>
#include <stdlib.h>


typedef int element;
// ListNode 구조체: 연결 리스트의 각 노드를 정의함 
typedef struct ListNode {
	element data;			// 노드가 저장하는 값 
	struct ListNode *link;	// 다음 노드를 가리키는 포인터 
} ListNode;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 맨 앞에 새 노드 삽입 
ListNode* insert_first(ListNode *head, int value)
{
	// 1) 리스트의 맨 앞에 새 노드를 삽입한다 
	// 2) 새 노드를 생성하고, 기존 head를 새 노드의 link로 연결한 뒤, head를 새 노드로 갱신한다 
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;	
	head = p;
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입 - 특정 위치에 삽입할 떄 
ListNode*  insert(ListNode *head, ListNode *pre, element value)
{
	// 1) pre 노드 뒤에 새 노드를 삽입한다.
	// 2) 새 노드를 생성하고, pre->link를 새 노드로 연결한다 
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	
	p->data = value;
	p->link = pre->link;	
	pre->link = p;	
	return head;	
}

// 리스트 맨 끝에 새 노드 삽입 
ListNode* insert_last(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = NULL;

    if (head == NULL) {
        return p;  // 리스트가 비어있으면 새 노드가 head가 됨
    }

    ListNode *current = head;
    while (current->link != NULL) {
        current = current->link;  // 마지막 노드까지 이동
    }
    current->link = p;  // 마지막 노드의 link에 새 노드 연결
    return head;
}


// 리스트의 첫 번째 노드 삭제 
ListNode* delete_first(ListNode *head)
{
	// 1) 리스트의 첫 번째 노드를 삭제한다 
	// 2) head가 가리키는 노드를 제거하고, 다음 노드를 새 head로 설정한다 
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;	
	head = removed->link;
	free(removed);	
	return head;
}

// 리스트의 마지막 노드부터 삭제하는 함수 
ListNode* delete_last(ListNode *head)
{
    if (head == NULL) return NULL;           // 빈 리스트
    if (head->link == NULL) {                // 노드가 하나뿐인 경우
        free(head);
        return NULL;
    }

    ListNode *prev = NULL;
    ListNode *curr = head;

    // 마지막 노드까지 이동
    while (curr->link != NULL) {
        prev = curr;
        curr = curr->link;
    }

    // curr은 마지막 노드, prev는 그 앞 노드
    prev->link = NULL;
    free(curr);
    return head;
}


// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete(ListNode *head, ListNode *pre)
{
	// 1) pre 노드 뒤의 노드를 삭제한다 
	// 2) pre->link를 제거할 노드의 다음 노드로 연결하고, 제거된 노드를 메모리 해제한다 

	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);	
	return head;
}

// 연결리스트 출력 함수 
void print_list(ListNode *head)
{
	// 리스트의 모든 노드를 순회하며 값을 출력
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// 함수 추가하기

// 1. 특정 값을 탐색하는 함수
ListNode* search(ListNode *head, element target)
{
    ListNode *p = head;
    while (p != NULL) {
        if (p->data == target)
            return p;  	// 찾은 노드 반환
        p = p->link;
    }
    return NULL;  		// 못 찾은 경우
}

// 2. 사용자에게 노드 값을 입력받는 함수
void input_insert(ListNode **head)
{
    int value;
    printf("삽입할 값을 입력하세요: ");
    scanf("%d", &value);

    *head = insert_first(*head, value);
    printf("삽입 후 리스트: ");
    print_list(*head);
}

// 3. 특정 위치의 노드를 찾기 
int find_index(ListNode *head, element target)
{
    int index = 0;
    ListNode *p = head;

    while (p != NULL) {
        if (p->data == target)
            return index;  // 찾으면 위치 반환
        p = p->link;
        index++;
    }

    return -1;  // 못 찾으면 -1 반환
}

// 4. 연결리스트의 데이터를 모두 합하기 
int sum_list(ListNode *head)
{
    int sum = 0;
    ListNode *p = head;

    while (p != NULL) {
        sum += p->data;
        p = p->link;
    }

    return sum;
}

// 5. 사용자가 입력한 특정 값을 삭제 
ListNode* delete_by_value(ListNode *head, element target)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL) {
        if (curr->data == target) {
            if (prev == NULL) {
                // 첫 번째 노드가 삭제 대상인 경우
                head = curr->link;
            } else {
                prev->link = curr->link;
            }
            free(curr);
            printf("값 %d를 삭제했습니다.\n", target);
            return head;
        }
        prev = curr;
        curr = curr->link;
    }

    printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", target);
    return head;
}

// 테스트 프로그램
int main(void)
{
	ListNode *head = NULL;
	
	// -------- 값을 for문으로 추가하고 삭제하는 부분 --------
	// 1. for문으로 값을 앞에서부터 차례대로 넣고 출력하기 - insert_first 함수 사용
	printf("[노드을 리스트 앞에 추가]\n"); 
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	printf("\n"); 
	
	// 2. for문으로 값을 차례대로 삭제하고 출력하기 - delete_first 함수 사용 
	printf("[노드를 리스트 앞에서부터 삭제]\n");
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	printf("\n");
	
	// 3. for문으로 값을 뒤에서부터 차례대로 넣고 출력하기 - insert_last 함수 사용
	printf("[값을 리스트 뒤에 추가]\n"); 
	for (int i = 0; i < 5; i++) {
		head = insert_last(head, i);
		print_list(head);
	}
	printf("\n"); 
	
	// 4. for문으로 값을 뒤에서부터 차례대로 삭제하고 출력하기 - delete_last 함수 사용 
	printf("[값을 리스트 뒤에서부터 삭제]\n");
	for (int i = 0; i < 5; i++) {
		head = delete_last(head);
		print_list(head);
	}
	printf("\n");
	
	
	// -------- 추가한 함수를 활용하는 부분 --------
	// 1. 사용자가 입력하는 값으로 노드 설정하기 -  input_insert 함수 사용
	int n;
	printf("입력할 노드 개수 : ");
	scanf("%d", &n);
	for (int i = 0; i<n; i++){
		input_insert(&head);
	} 
	printf("\n\n");
	
    // 2. 사용자로부터 찾고 싶은 값 입력받기 - find_index 함수 사용 
	int target;
	printf("찾고 싶은 값을 입력하세요: ");
	scanf("%d", &target);

	int position = find_index(head, target);
	if (position != -1)
    	printf("값 %d는 리스트의 %d번째 위치에 있습니다.\n", target, position);
	else
    	printf("값 %d는 리스트에 없습니다.\n", target);
    	
    printf("\n");

	
	// 3. 연결리스트의 노드의 모든 데이터 합 구하기 
	int total = sum_list(head);
		printf("리스트의 모든 노드 값의 합: %d\n", total);
		
	printf("\n");
	
	// 4. 사용자에게 삭제할 값 입력받기 
	int del_value;
	printf("\n삭제할 값을 입력하세요: ");
	scanf("%d", &del_value);

	head = delete_by_value(head, del_value);

	printf("[삭제 후 리스트 출력]\n");
	print_list(head);

	
	return 0;
}
