#include <stdio.h>
#include <stdlib.h>

/*
	�Ŷ���б� 202395016 �ڼ���
	--> ���丮���� ����ϴ� ���α׷� 
	
	: �ݺ��� for ���
*/

// �ŵ������� ���� ���ϴ� �Լ� 
int get_fac(int n1, int n2){
	int i;
	int result = 1;	// 1�� �ʱ�ȭ 
	
	for (i=0; i<n2; i++){
		result = result*n1;
	}
	return result;
}
int main(int argc, char *argv[]) {
	int num1, num2;
	// ����ڿ��� �Է� �ޱ�
	printf("�ؼ� �Է� : ");
	scanf("%d", &num1);
	printf("���� �Է� : ");
	scanf("%d", &num2);
	
	// �Լ� ȣ���Ͽ� ����� ���
	printf("\n%d^%d = %d", num1, num2, get_fac(num1, num2));
	return 0;
}
