#include <stdio.h>
#include <stdlib.h>

typedef int element;

// ����ü ���� : ��Ʈ Ÿ�� 
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

// ����Ʈ�� �׸� ���
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // ������ ��� ���
	printf("NULL\n");
}

//����Ʈ ù �κп� ���ο� ��� �߰� 
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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

// ����Ʈ ������ �κп� ���ο� ��� �߰� 
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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

// ������ �ʵ� ���� ��� ���ϴ� �Լ� 
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

// main �Լ� 
int main(void)
{
	ListNode *head = NULL;
	int count, input;
	
	// ����ڿ��� �� �� �Է� ���� ���� �Է� �ޱ�
	printf("����ڿ��� �Է��� �޽��ϴ�.\n");
	printf("����� ������ �Է��ϼ��� : ");
	scanf("%d", &count);
	
	// ����ڿ��� �Է� ���� ��ŭ �ݺ��ϱ� 
	for (int i=0; i<count; i++){
		printf("��� %d ������ : ", i+1);
		scanf("%d", &input);
		head = insert_last(head, input);
	}
	
	// ����ϱ� 
	printf("\n����Ʈ ���\n");
	print_list(head);

    int total = sum_list(head);		// ������ �ʵ� ���� ���ϴ� �Լ� ȣ�� 
    printf("���� ����Ʈ�� ������ �� : %d\n", total);

	return 0;
}
