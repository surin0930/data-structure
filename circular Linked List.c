#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		head->link = head;  //���� ���Ե� ù��° ����� ��ũ�� �ڱ� �ڽ��� ����Ų��
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;  //����� ��������� ��ȯ
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;

	if (head == NULL) {
		head = node;
		head->link = head;  //���� ���Ե� ù��° ����� ��ũ�� �ڱ� �ڽ��� ����Ų��
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;  //head�� ��ġ�� ���ο� ���� �ٲپ��ش�. => ���ο� ��尡 ������ ���
	}
	return head;  //����� ��������� ��ȯ

}

void print_list(ListNode* head) {
	ListNode* p = head->link;

	if (head == NULL)return;
	do {
		printf("%d-> ", p->data);
		p = p->link;
	} while (p != head->link);   //ù��° ��� head->link�� �����ϸ� ������ ���
	printf("\n");
}


int main() {
	ListNode* phead = NULL;

	phead = insert_last(phead, 1);
	phead = insert_last(phead, 2);
	phead = insert_first(phead, 3);
	print_list(phead);
}