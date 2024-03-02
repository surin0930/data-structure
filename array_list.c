#include <stdio.h>
#pragma warning(disable : 4996)
#define SIZE 100

typedef int element;
typedef struct {
	element list[SIZE];
	int length;
}List;

//�ʱ�ȭ
void init(List* L) {
	L->length = 0;
}

//����ִ� �� Ȯ��
int empty(List* L) {
	return L->length == 0;
}

//���� á���� Ȯ��
int full(List* L) {
	return L->length == SIZE;
}

//������ ���
void print(List* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d ", L->list[i]);
	}
	printf("\n");
}

//����
void add(List* L, int pos, element item) {
	if (!full(L) && (pos >= 0) && (pos <= L->length)) {
		for (int i = (L->length - 1); i >= pos; i--) {
			L->list[i + 1] = L->list[i];
		}
		L->list[pos] = item;
		L->length++;
	}
}
//���� 
element dellist(List* L, int pos) {
	element item;
	if ((pos >= 0) && (pos <= L->length - 1)) {
		item = L->list[pos];
		for (int i = pos; i < L->length; i++) {
			L->list[i] = L->list[i + 1];
		}
		L->length--;
		return item;
	}
}

int main() {
	
	List L;
	
	init(&L);
	add(&L, 0, 1); print(&L);
	add(&L, 1, 2); print(&L);
	add(&L, 2, 3); print(&L);
	add(&L, 3, 4); print(&L);
	dellist(&L, 3); print(&L);
	dellist(&L, 2); print(&L);
	dellist(&L, 1); print(&L);
	dellist(&L, 0); print(&L);


}
