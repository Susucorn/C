#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	�Ŷ���б� 202395016 ��ǻ�Ͱ��к� �ڼ��� 
	--> �ŵ������� �ҿ�ð��� �����ϴ� ���α׷�
	
	: ���� ������� ����� ������ 2^500 �� �� ����� 0�� ��µȴ�
		����? int Ÿ���� ������ �ʰ��� ���̱� ���� 
*/


// �ŵ������� ���ϴ� �Լ�
int get_power(int n1, int n2){
	int i;
	int result = 1;
	
	for (i=0;i<n2; i++ ){
		result *= n1;
	}
	
	return result;
}

int main(int argc, char *argv[]) {
	int num1, num2, i; 
	clock_t start, stop;	// �������۰� ���� ���� 
	double  duration;		// �ɸ� �ð�
	
	// ����ڿ��� �Է� �ޱ�
	printf("----- �ŵ����� ������ �����մϴ�. -----\n");
	printf("�ؼ� �Է� : ");
	scanf("%d", &num1);
	printf("���� �Է� : ");
	scanf("%d", &num2);
	
	// ���� 
	start = clock(); // ���� ����
	
	for (i = 0; i < 1000000; i++){
		get_power(num1, num2);
	}
	
	stop = clock();	// ���� ���� 
	duration = (double)(stop - start) / CLOCKS_PER_SEC;	// �ɸ� �ð�
	
	// ��� ��� 
	printf("\n----- �ŵ����� ������ -----\n");
	printf("%d^%d�� ��� : %.d\n", num1, num2, get_power(num1, num2));
	printf("%d^%d ������ �ҿ� �ð� : %.7lf",num1, num2, duration);
	
	return 0;
}
