#include <stdio.h>
#define MAX 10

typedef int element;
typedef struct {
	element data[MAX];
	int front, rear;
}Deque;

//�ʱ�ȭ
void initDeque(Deque* deque) {
	deque->front = deque->rear = 0;
}

//����ִ� �� Ȯ��
int isEmpty(Deque* deque) {
	return deque->front == deque->rear;
}

// �� á�� �� Ȯ��
int isFull(Deque* deque) {
	return ((deque->rear + 1) % MAX == deque->front);
}

void add_front(Deque* deque, element item) { //front�� ����Ű�� ���� ���� �� front 1����

	if (isFull(deque)) {
		printf("��á��..");
		exit(1);
	}
	deque->data[deque->front] = item;
	deque->front = (deque->front - 1 + MAX) % MAX;
}


void add_rear(Deque* deque, element item) { 
	if (isFull(deque)) {
		printf("��á��");
		exit(1);
	}
	else {
		deque->rear = (deque->rear + 1) % MAX;
		deque->data[deque->rear] = item;
	}
}

element  delete_front(Deque* deque) { //front �� 1 ���� �� ��ȯ
	if (isEmpty(deque)) {
		printf("����ִ�");
		exit(1);
	}
	else {
		deque->front = (deque->front + 1) % MAX;
		return deque->data[deque->front] ;
	}
}


element delete_rear(Deque* deque) { //rear�� ����Ű�� �� ��ȯ ��, rear �� 1 ����
	int prev = deque->rear;
	if (isEmpty(deque)) {
		printf("�����..");
		exit(1);
	}
	deque->rear = (deque->rear - 1 + MAX) % MAX;
	return deque->data[prev];
}

element get_front(Deque* deque) {  //front �� 1������Ų ���� ��Ҹ� ��ȯ
	if (isEmpty(deque)) {
		printf("�����..");
		return;
	}
	return deque->data[(deque->front + 1) % MAX];
}

element get_rear(Deque* deque) {
	if (isEmpty(deque)) {
		printf("�����..");
		return;
	}
	return deque->data[deque->rear ];
}


int main() {
	Deque deque;
	
	initDeque(&deque);

	for (int i = 0; i < 10; i++) { 
		if (i % 2) { // Ȧ��
			add_rear(&deque, i );
			printf("add_rear(%d) \t front = %d, rear =%d\n",
				get_rear(&deque), deque.front, deque.rear);
		}
		else{		//¦��
			add_front(&deque, i);
			printf("add_front(%d) \t front =%d, rear =%d\n",
				get_front(&deque), deque.front, deque.rear);
		}
		
		
	}
	return 0;
}
