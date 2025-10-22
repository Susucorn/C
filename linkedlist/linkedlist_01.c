#include <stdio.h>
#include <stdlib.h>


typedef int element;
// ListNode ����ü: ���� ����Ʈ�� �� ��带 ������ 
typedef struct ListNode {
	element data;			// ��尡 �����ϴ� �� 
	struct ListNode *link;	// ���� ��带 ����Ű�� ������ 
} ListNode;

// ���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ �� �տ� �� ��� ���� 
ListNode* insert_first(ListNode *head, int value)
{
	// 1) ����Ʈ�� �� �տ� �� ��带 �����Ѵ� 
	// 2) �� ��带 �����ϰ�, ���� head�� �� ����� link�� ������ ��, head�� �� ���� �����Ѵ� 
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;	
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ���� - Ư�� ��ġ�� ������ �� 
ListNode*  insert(ListNode *head, ListNode *pre, element value)
{
	// 1) pre ��� �ڿ� �� ��带 �����Ѵ�.
	// 2) �� ��带 �����ϰ�, pre->link�� �� ���� �����Ѵ� 
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	
	p->data = value;
	p->link = pre->link;	
	pre->link = p;	
	return head;	
}

// ����Ʈ �� ���� �� ��� ���� 
ListNode* insert_last(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = NULL;

    if (head == NULL) {
        return p;  // ����Ʈ�� ��������� �� ��尡 head�� ��
    }

    ListNode *current = head;
    while (current->link != NULL) {
        current = current->link;  // ������ ������ �̵�
    }
    current->link = p;  // ������ ����� link�� �� ��� ����
    return head;
}


// ����Ʈ�� ù ��° ��� ���� 
ListNode* delete_first(ListNode *head)
{
	// 1) ����Ʈ�� ù ��° ��带 �����Ѵ� 
	// 2) head�� ����Ű�� ��带 �����ϰ�, ���� ��带 �� head�� �����Ѵ� 
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;	
	head = removed->link;
	free(removed);	
	return head;
}

// ����Ʈ�� ������ ������ �����ϴ� �Լ� 
ListNode* delete_last(ListNode *head)
{
    if (head == NULL) return NULL;           // �� ����Ʈ
    if (head->link == NULL) {                // ��尡 �ϳ����� ���
        free(head);
        return NULL;
    }

    ListNode *prev = NULL;
    ListNode *curr = head;

    // ������ ������ �̵�
    while (curr->link != NULL) {
        prev = curr;
        curr = curr->link;
    }

    // curr�� ������ ���, prev�� �� �� ���
    prev->link = NULL;
    free(curr);
    return head;
}


// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete(ListNode *head, ListNode *pre)
{
	// 1) pre ��� ���� ��带 �����Ѵ� 
	// 2) pre->link�� ������ ����� ���� ���� �����ϰ�, ���ŵ� ��带 �޸� �����Ѵ� 

	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);	
	return head;
}

// ���Ḯ��Ʈ ��� �Լ� 
void print_list(ListNode *head)
{
	// ����Ʈ�� ��� ��带 ��ȸ�ϸ� ���� ���
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// �Լ� �߰��ϱ�

// 1. Ư�� ���� Ž���ϴ� �Լ�
ListNode* search(ListNode *head, element target)
{
    ListNode *p = head;
    while (p != NULL) {
        if (p->data == target)
            return p;  	// ã�� ��� ��ȯ
        p = p->link;
    }
    return NULL;  		// �� ã�� ���
}

// 2. ����ڿ��� ��� ���� �Է¹޴� �Լ�
void input_insert(ListNode **head)
{
    int value;
    printf("������ ���� �Է��ϼ���: ");
    scanf("%d", &value);

    *head = insert_first(*head, value);
    printf("���� �� ����Ʈ: ");
    print_list(*head);
}

// 3. Ư�� ��ġ�� ��带 ã�� 
int find_index(ListNode *head, element target)
{
    int index = 0;
    ListNode *p = head;

    while (p != NULL) {
        if (p->data == target)
            return index;  // ã���� ��ġ ��ȯ
        p = p->link;
        index++;
    }

    return -1;  // �� ã���� -1 ��ȯ
}

// 4. ���Ḯ��Ʈ�� �����͸� ��� ���ϱ� 
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

// 5. ����ڰ� �Է��� Ư�� ���� ���� 
ListNode* delete_by_value(ListNode *head, element target)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL) {
        if (curr->data == target) {
            if (prev == NULL) {
                // ù ��° ��尡 ���� ����� ���
                head = curr->link;
            } else {
                prev->link = curr->link;
            }
            free(curr);
            printf("�� %d�� �����߽��ϴ�.\n", target);
            return head;
        }
        prev = curr;
        curr = curr->link;
    }

    printf("�� %d�� ���� ��带 ã�� �� �����ϴ�.\n", target);
    return head;
}

// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode *head = NULL;
	
	// -------- ���� for������ �߰��ϰ� �����ϴ� �κ� --------
	// 1. for������ ���� �տ������� ���ʴ�� �ְ� ����ϱ� - insert_first �Լ� ���
	printf("[����� ����Ʈ �տ� �߰�]\n"); 
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	printf("\n"); 
	
	// 2. for������ ���� ���ʴ�� �����ϰ� ����ϱ� - delete_first �Լ� ��� 
	printf("[��带 ����Ʈ �տ������� ����]\n");
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	printf("\n");
	
	// 3. for������ ���� �ڿ������� ���ʴ�� �ְ� ����ϱ� - insert_last �Լ� ���
	printf("[���� ����Ʈ �ڿ� �߰�]\n"); 
	for (int i = 0; i < 5; i++) {
		head = insert_last(head, i);
		print_list(head);
	}
	printf("\n"); 
	
	// 4. for������ ���� �ڿ������� ���ʴ�� �����ϰ� ����ϱ� - delete_last �Լ� ��� 
	printf("[���� ����Ʈ �ڿ������� ����]\n");
	for (int i = 0; i < 5; i++) {
		head = delete_last(head);
		print_list(head);
	}
	printf("\n");
	
	
	// -------- �߰��� �Լ��� Ȱ���ϴ� �κ� --------
	// 1. ����ڰ� �Է��ϴ� ������ ��� �����ϱ� -  input_insert �Լ� ���
	int n;
	printf("�Է��� ��� ���� : ");
	scanf("%d", &n);
	for (int i = 0; i<n; i++){
		input_insert(&head);
	} 
	printf("\n\n");
	
    // 2. ����ڷκ��� ã�� ���� �� �Է¹ޱ� - find_index �Լ� ��� 
	int target;
	printf("ã�� ���� ���� �Է��ϼ���: ");
	scanf("%d", &target);

	int position = find_index(head, target);
	if (position != -1)
    	printf("�� %d�� ����Ʈ�� %d��° ��ġ�� �ֽ��ϴ�.\n", target, position);
	else
    	printf("�� %d�� ����Ʈ�� �����ϴ�.\n", target);
    	
    printf("\n");

	
	// 3. ���Ḯ��Ʈ�� ����� ��� ������ �� ���ϱ� 
	int total = sum_list(head);
		printf("����Ʈ�� ��� ��� ���� ��: %d\n", total);
		
	printf("\n");
	
	// 4. ����ڿ��� ������ �� �Է¹ޱ� 
	int del_value;
	printf("\n������ ���� �Է��ϼ���: ");
	scanf("%d", &del_value);

	head = delete_by_value(head, del_value);

	printf("[���� �� ����Ʈ ���]\n");
	print_list(head);

	
	return 0;
}
