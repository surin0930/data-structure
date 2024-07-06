#include <stdio.h>

int robot(int n) {
	if (n == 1 || n == 2) return n;
	if (n == 3) return 4;
	return robot(n - 1) + robot(n - 2) + robot(n - 3);
}

int main() {
	int distance, walk;
	printf("로봇이 이동할 거리: ");
	scanf("%d", &distance);
	walk = robot(distance);
	printf("%d", walk);
	return 0;
}
