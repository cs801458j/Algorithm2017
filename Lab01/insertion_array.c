#define _CRT_SECURE_NO_WARNINGS    
#include<stdio.h>
#include<stdlib.h>
//	�������� ����. (�����ڷ��� �˰����� ���)
void insertionSort(int arr[], int n) {
	int key, j;
	if (n >= 2) {
		for (int i = 1; i < n; i++) {
			key = arr[i];
			j = i - 1;

			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}

}

int main(void) {

	// �迭 ���� (�迭�� ���̿� �°� �����Ͽ� ���)
	int array[1000];
	int i = 0;

	FILE *fp = fopen("C:\\Users\\eunjeong\\Desktop\\Algo1\\test_1000.txt", "r");

	//	���� �о �迭�� �ֱ� 
	while (!feof(fp)) {
		fscanf(fp, "%d", &array[i]);
		insertionSort(array, i+1);
		i++;
	}

	// ��� ��� 
	for (int x = 0; x < 1000; x++) {
		printf("%d \n", array[x]);
	}
	fclose(fp);



	return 0;
}

