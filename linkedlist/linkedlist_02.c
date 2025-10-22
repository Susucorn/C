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

// 리스트 뒤에 새 노드 삽입
Person* insert_last(Person *head, char *name, int age, float height, char *gender) {
    Person *new_node = (Person *)malloc(sizeof(Person));	// 동적 메모리 할당 후  
    strcpy(new_node->name, name);		// 이름 
    new_node->age = age;				// 나이 
    new_node->height = height;			// 키 
    strcpy(new_node->gender, gender);	// 성별 
    new_node->link = NULL;				// 새로운 링크를 NULL로 만든다(마지막 노드를 표현) 

    if (head == NULL) return new_node;

    Person *current = head;
    while (current->link != NULL)
        current = current->link;
    current->link = new_node;
    return head;
}

// 리스트 출력
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

// 사용자 입력으로 노드 추가
Person* input_people(int count) {
    Person *head = NULL;
    for (int i = 0; i < count; i++) {
        char name[10], gender[10];
        int age;
        float height;

        printf("\n[%d번째 사람 정보 입력]\n", i + 1);
        printf("이름: ");
        scanf("%s", name);
        printf("나이: ");
        scanf("%d", &age);
        printf("키(m): ");
        scanf("%f", &height);
        printf("성별: ");
        scanf("%s", gender);

        head = insert_last(head, name, age, height, gender);
    }
    return head;
}

// 찾고자 하는 사람의 데이터를 출력
void print_person_info(Person *head, const char *target_name)
{
    Person *p = head;
    while (p != NULL) {
        if (strcmp(p->name, target_name) == 0) {
            printf("\n 검색 결과\n");
            printf("이름: %s\n", p->name);
            printf("나이: %d\n", p->age);
            printf("키: %.2f\n", p->height);
            printf("성별: %s\n", p->gender);
            return;
        }
        p = p->link;
    }
    printf("\n 이름이%s 인 사람을 찾을 수 없습니다.\n", target_name);
}

// 특정 사람의 데이터 정보를 삭제 
Person* delete_person(Person *head, const char *target_name)
{
    Person *prev = NULL;
    Person *curr = head;

    while (curr != NULL) {
        if (strcmp(curr->name, target_name) == 0) {
            if (prev == NULL) {
                // 첫 번째 노드 삭제
                head = curr->link;
            } else {
                prev->link = curr->link;
            }
            free(curr);
            printf("? '%s' 정보를 삭제했습니다.\n", target_name);
            return head;
        }
        prev = curr;
        curr = curr->link;
    }

    printf("'%s' 이름을 가진 사람을 찾을 수 없습니다.\n", target_name);
    return head;
}

// 이름으로 노드 수정하기 
void modify_person(Person *head, const char *target_name)
{
    Person *p = head;
    while (p != NULL) {
        if (strcmp(p->name, target_name) == 0) {
            printf("\n %s 의 새 정보를 입력하세요:\n", target_name);
            printf("새 이름: ");
            scanf("%s", p->name);
            printf("새 나이: ");
            scanf("%d", &p->age);
            printf("새 키(m): ");
            scanf("%f", &p->height);
            printf("새 성별: ");
            scanf("%s", p->gender);
            printf("수정이 완료되었습니다.\n");
            return;
        }
        p = p->link;
    }
    printf("? '%s' 이름을 가진 사람을 찾을 수 없습니다.\n", target_name);
}

// 입력받은 사람의 정보를 출력 
void find_person_by_name_with_age(Person *head, const char *target_name)
{
    Person *matches[10];  // 최대 10명까지 이름이 같은 사람 저장
    int count = 0;

    Person *p = head;
    while (p != NULL) {
        if (strcmp(p->name, target_name) == 0) {
            matches[count++] = p;
        }
        p = p->link;
    }

    if (count == 0) {
        printf("? 이름이 '%s'인 사람을 찾을 수 없습니다.\n", target_name);
        return;
    }

    if (count == 1) {
        // 이름이 하나만 있을 경우 바로 출력
        p = matches[0];
        printf("\n 검색 결과\n");
        printf("이름: %s\n", p->name);
        printf("나이: %d\n", p->age);
        printf("키: %.2f\n", p->height);
        printf("성별: %s\n", p->gender);
        return;
    }

    // 이름이 여러 개 있을 경우
    printf("이름이 '%s'인 사람이 %d명 있습니다.\n", target_name, count);
    printf("정확한 사람을 찾기 위해 나이를 입력하세요: ");
    int target_age;
    scanf("%d", &target_age);

    for (int i = 0; i < count; i++) {
        if (matches[i]->age == target_age) {
            p = matches[i];
            printf("\n 검색 결과\n");
            printf("이름: %s\n", p->name);
            printf("나이: %d\n", p->age);
            printf("키: %.2f\n", p->height);
            printf("성별: %s\n", p->gender);
            return;
        }
    }

    printf("? 이름이 '%s'이고 나이가 %d인 사람을 찾을 수 없습니다.\n", target_name, target_age);
}

int main(void) {
    int n;
    printf("입력할 사람 수: ");
    scanf("%d", &n);

    Person *head = input_people(n);

    printf("\n[전체 리스트 출력]\n");
    print_list(head);

    // 삭제
    char name_to_delete[20];
    printf("\n삭제할 사람 이름: ");
    scanf("%s", name_to_delete);
    head = delete_person(head, name_to_delete);

    printf("\n[삭제 후 리스트 출력]\n");
    print_list(head);

    // 수정
    char name_to_modify[20];
    printf("\n수정할 사람 이름: ");
    scanf("%s", name_to_modify);
    modify_person(head, name_to_modify);

    printf("\n[수정 후 리스트 출력]\n");
    print_list(head);

	
	// 이름 검색하여 정보 출력 
	char search_name[20];
	printf("\n검색할 사람 이름을 입력하세요: ");
	scanf("%s", search_name);

	find_person_by_name_with_age(head, search_name);

    return 0;
}
