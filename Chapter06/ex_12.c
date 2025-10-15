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

// Ž���� ���� ��ȯ�ϴ� �Լ� 
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

    return -1; // ã�� ���� ���
}



// main �Լ� 
int main(void)
{
	ListNode *head = NULL;
	int count, input, search;
	
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

	// Ž���� �� �Է¹ޱ�
	printf("Ž���� ���� �Է��ϼ��� : ");
	scanf("%d", &search);
	
	int position = search_list(head, search);	// ���� Ž���ϴ� �Լ� ȣ��
	
	// ����ϱ� 	
	if (position == -1)	// -1�� ��ȯ���� --> �Է¹��� ���� ����Ʈ�� ���� ��� 
    	printf("�Է¹��� %d�� ����Ʈ�� �����ϴ�.\n", search);
	else
    	printf("%d�� ����Ʈ�� %d��° ��忡 �ֽ��ϴ�.\n", search, position);

	 

	return 0;
}
