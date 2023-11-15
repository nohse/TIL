#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct cell {//�� �� ����ü ����
	int key;
	int tag;//0 empty, 1 active, 2 inactive
}cell;
void insertItem(cell A[], int key, int M) {//���� �Լ�
	int v = key % M;//�ؽ� �Լ�
	for (int i = 0; i < M; i++) {//M���� ���� �˻�
		if (A[v].tag !=1) {//��� �ְų� ��Ȱ���� ���̶�� key ������ Ȱ��ȭ
			A[v].key = key;
			A[v].tag = 1;
			printf("%d\n", v);
			return;
		}
		printf("C");//�浹�� C ���
		v = (v + 1) % M;//��������
	}
	printf("-1\n");//���� ����

}
void searchItem(cell A[], int key, int M) {//Ž�� �Լ�
	int v = key % M;//�ؽ� �Լ�
	for (int i = 0; i < M; i++) {//M���� ���� �˻�
		if (A[v].tag == 0) {//��� �ִ� ���� Ž�� ����
			break;
		}
		if (A[v].tag == 1 && A[v].key == key) {//Ȱ�� ���� ������ �ּ� ���
			printf("%d\n", v);
			return;
		}
		printf("C");//�浹�� C ���
		v = (v + 1) % M;//��������
	}
	printf("-1\n");//Ž�� ����
}
void removeItem(cell A[], int key, int M) {//���� �Լ�
	int v = key % M;//�ؽ� �Լ�
	for (int i = 0; i < M; i++) {//M���� ���� �˻�
		if (A[v].tag == 0) {//��� �ִ� ���� ���� ����
			break;
		}
		if (A[v].tag == 1 && A[v].key == key) {//Ȱ�� ���� ������ �� ��Ȱ��ȭ �� �ּ� ���
			A[v].tag = 2;
			printf("%d\n", v);
			return;
		}
		printf("C");//�浹�� C ���
		v = (v + 1) % M;//���� ����
	}
	printf("-1\n");//Ž�� ����
}
int main() {
	int M;//�ؽ� ���̺� ũ��
	scanf("%d", &M);
	getchar();
	cell* A = (cell*)malloc(sizeof(cell) * M);//�ؽ����̺� �� ���� �Ҵ�
	for (int i = 0; i < M; i++) {//�� �� Ű, �±� �� 0���� �ʱ�ȭ
		A[i].key = 0;
		A[i].tag = 0;
	}
	char select = -1;//��ɾ� �Լ� �ʱ�ȭ
	while (select != 'e') {
		scanf("%c", &select);//��ɾ� �Է�
		int key;
		if (select == 'i') {
			scanf("%d", &key);//key �� �Է�
			getchar();
			insertItem(A, key, M);//���� �Լ� ����
		}
		else if (select == 's') {
			scanf("%d", &key);//key �� �Է�
			getchar();
			searchItem(A, key, M);//Ž�� �Լ� ����

		}
		else if (select == 'd') {
			scanf("%d", &key);//key �� �Է�
			getchar();
			removeItem(A, key, M);//���� �Լ� ����
		}
		else if (select == 'e') {//���α׷� ����
			free(A);//���� �Ҵ� �޸� ����
			break;
		}

	}


}