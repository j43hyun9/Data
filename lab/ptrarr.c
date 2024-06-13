#include <stdio.h>
#include <stdlib.h>

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;
	graphNode* adjList_H[30];
}graphType;

int main(void) {
	graphType* G1 = (graphType*)malloc(sizeof(graphType));
	G1->n = 5;
	graphType G2 = { 7 };
	int a = 5;

	printf("\t\n a : %%p %p", a);
	printf("\t\t\n &a : %%p %p", &a);
	printf("\t\n *(&a) : %%p %p", *(&a));

	printf("\n\t * G1 : % %p % p", G1);
	printf("\n\t\tG1->n : %%p %p  a", G1->n);
	printf("\n\t\t&(G1->n) : %%p %p  a", &(G1->n) );
	printf("\n\t\t*&(G1->n) : %%p %p  a", *&(G1->n));
	printf("\n\t\t*(G1) : %%p %p  n", *(G1));
	printf("\n\t\t&(*(G1)) : %%p %p n", &(*(G1)));
	printf("\n\t\t&(G1) : %%p %p  b", &(G1));
	printf("\n\t\t*(&(G1)) : %%p %p  b", *(&(G1)));

	printf("\n\tG2 : %%p %p", G2);
	printf("\n\t\tG2.n : %%p %p", G2.n);
	printf("\n\t\t&(G2.n) : %%p %p", &(G2.n) );
}