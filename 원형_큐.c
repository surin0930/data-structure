#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef int element;
typedef struct Q{
	element q[MAX];
	int front, rear;
}Q;

//�ʱ�ȭ
void initQueue(Q* queue) {
	queue->front = queue->rear = 0;
}

//����ִ� �� Ȯ��
int isEmpty(Q* queue) {
	return queue->front == queue->rear;
}

// �� á�� �� Ȯ��
int isFull(Q* queue) {
	return ((queue->rear + 1) % MAX == queue->front);
}

void enqueue(Q* queue, int data) {
	if (isFull(queue)) {
		printf("��á��");
	}
	else {
		queue->rear = (queue->rear + 1) % MAX;
		queue->q[queue->rear] = data;
	}
}

int  dequeue(Q* queue) {
	if (isEmpty(queue)) {
		printf("����ִ�");
		exit(1);
	}
	else {
		queue->front = (queue->front+1) % MAX;
		int data = queue->q[queue->front];
		return data;
	}
}

void print(Q* queue) {
	if (isEmpty(queue)) {
		printf("�����");
	}
	if (!isEmpty(queue)) {
		int i = queue->front;
		do {
			i = (i + 1) % MAX;
			printf("%d |", queue->q[i]);
			if (i == queue->rear) {
				break;
			}
		} while (i != queue->front);
		printf("\n");
		return;
	}

}

int main() {
	Q queue;
	int b=0;

	initQueue(&queue);


	for (int i = 0; i < 5; i++) {
		enqueue(&queue, i+1);
		print(&queue);
	}

	for (int i = 0; i < 5; i++) {
		b = dequeue(&queue);
		print(&queue);
	}

	return 0;

}
