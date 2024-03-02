#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 노드 타입을 구조체로 정의한다.
typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;


// 앞부분에 노드 삽입
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); 
	p->data = value;
	p->link = head; 
	head = p; 
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; 
	p->link = pre->link; 
	pre->link = p; 
	return head; 
}

// 앞부분의 노드 제거
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head; 
	head = removed->link; 
	free(removed); 
	return head; 
}

// pre가 가리키는 노드의 다음 노드를 삭제.
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link; 
	free(removed); 
	return head; 
}

// 리스트 출력
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// 특정한 값을 탐색
ListNode* search_list(ListNode* head, element x)
{
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == x)  return p;
		p = p->link;
	}
	return  NULL;	// 탐색 실패
}

// 메인
int main(void)
{
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	if (search_list(head, 3) != NULL)
		printf("리스트에서 3을 찾았습니다. \n");
	else
		printf("리스트에서 3을 찾지 못했습니다. \n");

	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;


}



