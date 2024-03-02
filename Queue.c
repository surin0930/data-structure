#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
 int data;
 struct Node *next;
}Node;
 
 
typedef struct Queue 
{
 Node *front;
 Node *rear; 
 int count;    // ť ���� ��� ����
}Queue;
 
void initQueue(Queue *queue)
{
 queue->front = queue->rear = NULL; 
 queue->count = 0;// ť ���� ��� ������ 0���� ����
}
 
int isEmpty(Queue *queue)
{
 return queue->count == 0;    // ť���� ��� ������ 0�̸� �� ����
}
 
void enqueue(Queue *queue, int data)
{
 Node *newNode = (Node *)malloc(sizeof(Node)); // newNode ����
 newNode->data = data;
 newNode->next = NULL;
 
 if(isEmpty(queue)) // ť�� ������� ��
{
 	queue->front = newNode; 
}
else// ������� ���� ��
{
	queue->rear->next = newNode; //�� ���� ������ newNode�� ����
	}
 queue->rear = newNode; //�� �ڸ� newNode�� ����
 queue->count++; //ť���� ��� ������ 1 ����
}

int dequeue(Queue *queue)
{
 int data;
 Node *ptr;
 if (isEmpty(queue))	//ť�� ����� ��
 {
	printf("Error?:?Queue?is?empty!\n");
	return 0;
	}
 ptr = queue->front; 	//�� ���� ��� ptr ���� 
 data = ptr->data; 	// return �� ������
 queue->front = ptr->next;	//�� ���� ptr�� ���� ���� ����
 free(ptr);	//?ptr?����?
 queue->count--;	//ť�� ��� ������ 1 ����
 
 return data;
}
 
int main(void)
{
 int i;
 Queue queue;
 
 initQueue(&queue);//ť�ʱ�ȭ
 
 printf("���� ��: "); 
 
 for (i = 1; i <= 10; i++) 
 {
	enqueue(&queue, i);
	printf("%d ", i);
 }
 
 printf("\n������ ��: "); 
 
 while (!isEmpty(&queue))  	//ť�� ��������
 {
	printf("%d ", dequeue(&queue)); 	//ť���� ������ �� ���
 }
 printf("\n");
 return 0;
}
 
