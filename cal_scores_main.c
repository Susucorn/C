#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100
/* 
	�Ŷ���б� 202395016 ��ǻ�Ͱ��к� �ڼ��� 
	--> �ְ� ������ ���ϴ� ���α׷�
	
	: �迭�� �Լ� Ȱ�� 

*/
int scores[MAX_ELEMENTS];

// �ְ� ������ ���ϴ� �Լ� 
int get_max_score(int n){
	int i, largest;
	largest = scores[0];	// scores�迭�� ù��° ��Ҹ� ������ �ʱ�ȭ
	
	for (i = 1; i<n; i++) {
		if (scores[i] > largest) {	// scores�� i��° ��Ұ� largest�� �ִ� ������ ũ�ٸ� 
			largest = scores[i];	// largest ���� scores�� i��° ��ҷ� ����ȴ� 
		}
	}
	return largest;
}
// �ְ� ������ �ε����� ���ϴ� �Լ�
int get_max_index(int n){
	int i, largest;
	int max_index = 0;	// �ε��� ������ ���� 
	largest = scores[0];
	
	for (i = 1; i<n; i++) {
		if (scores[i] > largest) {
			max_index = i;	// ������ ���� �л��� �ε��� ��ȣ�� ���� 
		}
	}
	return max_index+1;
} 

int main(int argc, char *argv[]) {
	int i, num;
	
	// �л� �� �Է� �ޱ�
	printf("�̹��� ���迡 ������ �л� �� : ");
	scanf("%d", &num);
	
	// �л� �� ��ŭ ���� �Է� �ޱ�
	printf("\n----- �л��� ������ �Է��ϼ��� -----\n");
	for (i=0; i<num; i++){
		printf("%d��° �л� ���� : ", i+1);
		scanf("%d", &scores[i]);
	}
	
	// �л� ���� ����ϱ�
	printf("\n----- �л��� ������ ����մϴ� -----\n");
	for (i=0; i<num; i++){
		printf("%d��° �л��� ���� : %d\n", i+1, scores[i]);
	}
	
	// ������ ���� ���� �л� ����ϱ�
	printf("\n\n----- �̹� ���迡�� ���� ���� ������ ���� �л�-----\n");
	printf("%d��° �л� : %d��\n",get_max_index(num), get_max_score(num));
	
	return 0;
}
