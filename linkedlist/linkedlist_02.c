#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[10];
    int age;
    float height;
    char gender[10];
    struct Person *link;
} Person;

// ����Ʈ �ڿ� �� ��� ����
Person* insert_last(Person *head, char *name, int age, float height, char *gender) {
    Person *new_node = (Person *)malloc(sizeof(Person));	// ���� �޸� �Ҵ� ��  
    strcpy(new_node->name, name);		// �̸� 
    new_node->age = age;				// ���� 
    new_node->height = height;			// Ű 
    strcpy(new_node->gender, gender);	// ���� 
    new_node->link = NULL;				// ���ο� ��ũ�� NULL�� �����(������ ��带 ǥ��) 

    if (head == NULL) return new_node;

    Person *current = head;
    while (current->link != NULL)
        current = current->link;
    current->link = new_node;
    return head;
}

// ����Ʈ ���
void print_list(Person *head) {
    Person *p = head;
    int index = 0;
    while (p != NULL) {
        printf("[%d] Name: %s, Age: %d, Height: %.2f, Gender: %s\n",
               index, p->name, p->age, p->height, p->gender);
        p = p->link;
        index++;
    }
}

// ����� �Է����� ��� �߰�
Person* input_people(int count) {
    Person *head = NULL;
    for (int i = 0; i < count; i++) {
        char name[10], gender[10];
        int age;
        float height;

        printf("\n[%d��° ��� ���� �Է�]\n", i + 1);
        printf("�̸�: ");
        scanf("%s", name);
        printf("����: ");
        scanf("%d", &age);
        printf("Ű(m): ");
        scanf("%f", &height);
        printf("����: ");
        scanf("%s", gender);

        head = insert_last(head, name, age, height, gender);
    }
    return head;
}

// ã���� �ϴ� ����� �����͸� ���
void print_person_info(Person *head, const char *target_name)
{
    Person *p = head;
    while (p != NULL) {
        if (strcmp(p->name, target_name) == 0) {
            printf("\n �˻� ���\n");
            printf("�̸�: %s\n", p->name);
            printf("����: %d\n", p->age);
            printf("Ű: %.2f\n", p->height);
            printf("����: %s\n", p->gender);
            return;
        }
        p = p->link;
    }
    printf("\n �̸���%s �� ����� ã�� �� �����ϴ�.\n", target_name);
}

// Ư�� ����� ������ ������ ���� 
Person* delete_person(Person *head, const char *target_name)
{
    Person *prev = NULL;
    Person *curr = head;

    while (curr != NULL) {
        if (strcmp(curr->name, target_name) == 0) {
            if (prev == NULL) {
                // ù ��° ��� ����
                head = curr->link;
            } else {
                prev->link = curr->link;
            }
            free(curr);
            printf("? '%s' ������ �����߽��ϴ�.\n", target_name);
            return head;
        }
        prev = curr;
        curr = curr->link;
    }

    printf("'%s' �̸��� ���� ����� ã�� �� �����ϴ�.\n", target_name);
    return head;
}

// �̸����� ��� �����ϱ� 
void modify_person(Person *head, const char *target_name)
{
    Person *p = head;
    while (p != NULL) {
        if (strcmp(p->name, target_name) == 0) {
            printf("\n %s �� �� ������ �Է��ϼ���:\n", target_name);
            printf("�� �̸�: ");
            scanf("%s", p->name);
            printf("�� ����: ");
            scanf("%d", &p->age);
            printf("�� Ű(m): ");
            scanf("%f", &p->height);
            printf("�� ����: ");
            scanf("%s", p->gender);
            printf("������ �Ϸ�Ǿ����ϴ�.\n");
            return;
        }
        p = p->link;
    }
    printf("? '%s' �̸��� ���� ����� ã�� �� �����ϴ�.\n", target_name);
}

// �Է¹��� ����� ������ ��� 
void find_person_by_name_with_age(Person *head, const char *target_name)
{
    Person *matches[10];  // �ִ� 10����� �̸��� ���� ��� ����
    int count = 0;

    Person *p = head;
    while (p != NULL) {
        if (strcmp(p->name, target_name) == 0) {
            matches[count++] = p;
        }
        p = p->link;
    }

    if (count == 0) {
        printf("? �̸��� '%s'�� ����� ã�� �� �����ϴ�.\n", target_name);
        return;
    }

    if (count == 1) {
        // �̸��� �ϳ��� ���� ��� �ٷ� ���
        p = matches[0];
        printf("\n �˻� ���\n");
        printf("�̸�: %s\n", p->name);
        printf("����: %d\n", p->age);
        printf("Ű: %.2f\n", p->height);
        printf("����: %s\n", p->gender);
        return;
    }

    // �̸��� ���� �� ���� ���
    printf("�̸��� '%s'�� ����� %d�� �ֽ��ϴ�.\n", target_name, count);
    printf("��Ȯ�� ����� ã�� ���� ���̸� �Է��ϼ���: ");
    int target_age;
    scanf("%d", &target_age);

    for (int i = 0; i < count; i++) {
        if (matches[i]->age == target_age) {
            p = matches[i];
            printf("\n �˻� ���\n");
            printf("�̸�: %s\n", p->name);
            printf("����: %d\n", p->age);
            printf("Ű: %.2f\n", p->height);
            printf("����: %s\n", p->gender);
            return;
        }
    }

    printf("? �̸��� '%s'�̰� ���̰� %d�� ����� ã�� �� �����ϴ�.\n", target_name, target_age);
}

int main(void) {
    int n;
    printf("�Է��� ��� ��: ");
    scanf("%d", &n);

    Person *head = input_people(n);

    printf("\n[��ü ����Ʈ ���]\n");
    print_list(head);

    // ����
    char name_to_delete[20];
    printf("\n������ ��� �̸�: ");
    scanf("%s", name_to_delete);
    head = delete_person(head, name_to_delete);

    printf("\n[���� �� ����Ʈ ���]\n");
    print_list(head);

    // ����
    char name_to_modify[20];
    printf("\n������ ��� �̸�: ");
    scanf("%s", name_to_modify);
    modify_person(head, name_to_modify);

    printf("\n[���� �� ����Ʈ ���]\n");
    print_list(head);

	
	// �̸� �˻��Ͽ� ���� ��� 
	char search_name[20];
	printf("\n�˻��� ��� �̸��� �Է��ϼ���: ");
	scanf("%s", search_name);

	find_person_by_name_with_age(head, search_name);

    return 0;
}
