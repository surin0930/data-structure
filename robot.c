#include <stdio.h>

int robot(int n) {
	if (n == 1 || n == 2) return n;
	if (n == 3) return 4;
	return robot(n - 1) + robot(n - 2) + robot(n - 3);
}

int main() {
	int distance, walk;
	printf("�κ��� �̵��� �Ÿ�: ");
	scanf("%d", &distance);
	walk = robot(distance);
	printf("%d", walk);
	return 0;
}
