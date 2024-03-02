#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ��� Ÿ���� ����ü�� �����Ѵ�.
typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;


// �պκп� ��� ����
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); 
	p->data = value;
	p->link = head; 
	head = p; 
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; 
	p->link = pre->link; 
	pre->link = p; 
	return head; 
}

// �պκ��� ��� ����
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head; 
	head = removed->link; 
	free(removed); 
	return head; 
}

// pre�� ����Ű�� ����� ���� ��带 ����.
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link; 
	free(removed); 
	return head; 
}

// ����Ʈ ���
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// Ư���� ���� Ž��
ListNode* search_list(ListNode* head, element x)
{
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == x)  return p;
		p = p->link;
	}
	return  NULL;	// Ž�� ����
}

// ����
int main(void)
{
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	if (search_list(head, 3) != NULL)
		printf("����Ʈ���� 3�� ã�ҽ��ϴ�. \n");
	else
		printf("����Ʈ���� 3�� ã�� ���߽��ϴ�. \n");

	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;


}



