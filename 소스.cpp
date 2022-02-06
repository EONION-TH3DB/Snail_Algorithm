#include <stdio.h>
#include <stdlib.h>

int main() {

	int x, y;
	scanf_s("%d %d", &x, &y);

	int** arr = (int**)malloc(sizeof(int*) * x);
	for (int i = 0; i < x; i++) {
		arr[i] = (int*)malloc(sizeof(int) * y);
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; i < y; j++) {
			arr[i][j] = i + j;
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; i < y; j++) {
			printf("%d \n", arr[i][j]);
		}
	}

	for (int i = 0; i < x; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}