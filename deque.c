#include <stdio.h>
#define MAX 10

typedef int element;
typedef struct {
	element data[MAX];
	int front, rear;
}Deque;

//초기화
void initDeque(Deque* deque) {
	deque->front = deque->rear = 0;
}

//비어있는 지 확인
int isEmpty(Deque* deque) {
	return deque->front == deque->rear;
}

// 꽉 찼는 지 확인
int isFull(Deque* deque) {
	return ((deque->rear + 1) % MAX == deque->front);
}

void add_front(Deque* deque, element item) { //front가 가리키는 곳에 삽입 후 front 1감소

	if (isFull(deque)) {
		printf("꽉찼당..");
		exit(1);
	}
	deque->data[deque->front] = item;
	deque->front = (deque->front - 1 + MAX) % MAX;
}


void add_rear(Deque* deque, element item) { 
	if (isFull(deque)) {
		printf("꽉찼당");
		exit(1);
	}
	else {
		deque->rear = (deque->rear + 1) % MAX;
		deque->data[deque->rear] = item;
	}
}

element  delete_front(Deque* deque) { //front 값 1 증가 후 반환
	if (isEmpty(deque)) {
		printf("비어있당");
		exit(1);
	}
	else {
		deque->front = (deque->front + 1) % MAX;
		return deque->data[deque->front] ;
	}
}


element delete_rear(Deque* deque) { //rear이 가르키는 값 반환 후, rear 값 1 증가
	int prev = deque->rear;
	if (isEmpty(deque)) {
		printf("비었당..");
		exit(1);
	}
	deque->rear = (deque->rear - 1 + MAX) % MAX;
	return deque->data[prev];
}

element get_front(Deque* deque) {  //front 값 1증가시킨 값의 요소를 반환
	if (isEmpty(deque)) {
		printf("비었당..");
		return;
	}
	return deque->data[(deque->front + 1) % MAX];
}

element get_rear(Deque* deque) {
	if (isEmpty(deque)) {
		printf("비었당..");
		return;
	}
	return deque->data[deque->rear ];
}


int main() {
	Deque deque;
	
	initDeque(&deque);

	for (int i = 0; i < 10; i++) { 
		if (i % 2) { // 홀수
			add_rear(&deque, i );
			printf("add_rear(%d) \t front = %d, rear =%d\n",
				get_rear(&deque), deque.front, deque.rear);
		}
		else{		//짝수
			add_front(&deque, i);
			printf("add_front(%d) \t front =%d, rear =%d\n",
				get_front(&deque), deque.front, deque.rear);
		}
		
		
	}
	return 0;
}
