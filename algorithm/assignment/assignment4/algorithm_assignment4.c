#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct cell {//각 셀 구조체 선언
	int key;
	int tag;//0 empty, 1 active, 2 inactive
}cell;
void insertItem(cell A[], int key, int M) {//삽입 함수
	int v = key % M;//해쉬 함수
	for (int i = 0; i < M; i++) {//M개의 셀을 검사
		if (A[v].tag !=1) {//비어 있거나 비활성인 셀이라면 key 저장후 활성화
			A[v].key = key;
			A[v].tag = 1;
			printf("%d\n", v);
			return;
		}
		printf("C");//충돌시 C 출력
		v = (v + 1) % M;//선형조사
	}
	printf("-1\n");//삽입 실패

}
void searchItem(cell A[], int key, int M) {//탐색 함수
	int v = key % M;//해쉬 함수
	for (int i = 0; i < M; i++) {//M개의 셀을 검사
		if (A[v].tag == 0) {//비어 있는 셀시 탐색 실패
			break;
		}
		if (A[v].tag == 1 && A[v].key == key) {//활성 셀을 만날시 주소 출력
			printf("%d\n", v);
			return;
		}
		printf("C");//충돌시 C 출력
		v = (v + 1) % M;//선형조사
	}
	printf("-1\n");//탐색 실패
}
void removeItem(cell A[], int key, int M) {//삭제 함수
	int v = key % M;//해쉬 함수
	for (int i = 0; i < M; i++) {//M개의 셀을 검사
		if (A[v].tag == 0) {//비어 있는 셀시 삭제 실패
			break;
		}
		if (A[v].tag == 1 && A[v].key == key) {//활성 셀을 만날시 셀 비활성화 및 주소 출력
			A[v].tag = 2;
			printf("%d\n", v);
			return;
		}
		printf("C");//충돌시 C 출력
		v = (v + 1) % M;//선형 조사
	}
	printf("-1\n");//탐색 실패
}
int main() {
	int M;//해쉬 테이블 크기
	scanf("%d", &M);
	getchar();
	cell* A = (cell*)malloc(sizeof(cell) * M);//해쉬테이블 셀 동적 할당
	for (int i = 0; i < M; i++) {//각 셀 키, 태그 값 0으로 초기화
		A[i].key = 0;
		A[i].tag = 0;
	}
	char select = -1;//명령어 함수 초기화
	while (select != 'e') {
		scanf("%c", &select);//명령어 입력
		int key;
		if (select == 'i') {
			scanf("%d", &key);//key 값 입력
			getchar();
			insertItem(A, key, M);//삽입 함수 수행
		}
		else if (select == 's') {
			scanf("%d", &key);//key 값 입력
			getchar();
			searchItem(A, key, M);//탐색 함수 수행

		}
		else if (select == 'd') {
			scanf("%d", &key);//key 값 입력
			getchar();
			removeItem(A, key, M);//삭제 함수 수행
		}
		else if (select == 'e') {//프로그램 종료
			free(A);//동적 할당 메모리 해제
			break;
		}

	}


}