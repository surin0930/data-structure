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
		head->link = head;  //새로 삽입된 첫번째 노드의 링크는 자기 자신을 가르킨다
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;  //변경된 헤드포인터 반환
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;

	if (head == NULL) {
		head = node;
		head->link = head;  //새로 삽입된 첫번째 노드의 링크는 자기 자신을 가르킨다
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;  //head의 위치만 새로운 노드로 바꾸어준다. => 새로운 노드가 마지막 노드
	}
	return head;  //변경된 헤드포인터 반환

}

void print_list(ListNode* head) {
	ListNode* p = head->link;

	if (head == NULL)return;
	do {
		printf("%d-> ", p->data);
		p = p->link;
	} while (p != head->link);   //첫번째 노드 head->link에 도달하면 마지막 노드
	printf("\n");
}


int main() {
	ListNode* phead = NULL;

	phead = insert_last(phead, 1);
	phead = insert_last(phead, 2);
	phead = insert_first(phead, 3);
	print_list(phead);
}