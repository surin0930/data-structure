#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	struct  DlistNode* llink;
	struct DlistNode* rlink;
	element data;
}DlistNode;

void init(DlistNode* head) {
	head->rlink = head;
	head->llink = head;
}

void dinsert(DlistNode* prev, element data) {
	DlistNode* new = (DlistNode*)malloc(sizeof(DlistNode));
	new->data = data;

	new->rlink = prev->rlink;
	new->llink = prev;

	prev->rlink->llink = new;
	prev->rlink = new;
}

void ddelete(DlistNode* head, DlistNode* removed) {
	if (removed == head) return;
	else {
		removed->llink->rlink = removed->rlink;
		removed->rlink->llink = removed->llink;
		free(removed);
	}
}

void free_node(DlistNode* head) {
	DlistNode* p = head->rlink,  * next;
	while (p != head) {
		next = p->rlink;
		free(p);
		p = next;
	}
}

void print_dlist(DlistNode* head) {
	DlistNode* p = head->rlink; //ù��° ����� �ּ� ����
	for (; p != head; p = p->rlink) {
		printf("%d -> ", p->data);

	}
	printf("\n");
}
int main(){
	DlistNode * head = (DlistNode*)malloc(sizeof(DlistNode));
	init(head);

	printf("insert\n");
	for (int i = 0; i < 5; i++) {
		dinsert(head, i); //��� ����� �����ʿ� ����
		print_dlist(head);
	}
	printf("\n\ndelete\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink); //��� ����� ������ ��ũ�� ��带 ����
	}
	free(head);
	return 0;

}
