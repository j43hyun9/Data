#include <stdio.h>

typedef struct _Node {
	int a;
} Node;

int main() {
	int* ptr = NULL;
	Node* n = NULL;

	printf("int* ptr: %%d %d %%p %p\n", ptr, ptr);
	printf("Npde* n: %%d %d %%p %p\n", n, n);

	if (ptr == 0) {
		printf("null == 0");
	}

}

