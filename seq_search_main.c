#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

/* 
	�Ŷ���б� 202395016 ��ǻ�Ͱ��к� �ڼ��� 
	--> �迭�� Ű ���� ã�� ���α׷� 
*/


// Ű ���� ã�� �Լ�
int seq_search(int list[], int key){
	int i;
	
	for (i=0; i<SIZE; i++){
		if (list[i] == key){	// �迭�� i��° ��Ұ� Ű ���� ������ �ε��� ��ȯ 
			return i;
		}
	}
	printf("ã���� �ϴ� key���� �����ϴ�.\n");
	exit(1);  // ������ ����
} 
 
int main(int argc, char *argv[]) {
	int i, k;
	int arr[SIZE];
	
	// ����ڿ��� �迭 ��� �Է¹ޱ�
	printf("----- �� %d���� ���� �Է� �޽��ϴ�. -----\n", SIZE);
	for (i=0; i<SIZE; i++){
		printf("%d��°�� �� : ", i+1);
		scanf("%d", &arr[i]);
	}
	
	// �Է� Ȯ���ϱ�
	printf("\n----- ���� �Էµ� ���� Ȯ�� -----\n");
	for (i=0; i<SIZE; i++){
		printf("%d��° �� : %d\n", i+1, arr[i]);
	}
	
	// ����ڿ��� Ű �� �Է¹ޱ�
	printf("\nã���� �ϴ� key ���� �Է��ϼ��� : ");
	scanf("%d", &k);
	
	// Ű ���� �ε��� ���ϱ�
	printf("%d�� �ε��� �� : %d\n", k, seq_search(arr, k));
	
	return 0;
}
