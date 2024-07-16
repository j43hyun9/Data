#pragma once
#define MAX_VER 10
typedef struct graphNode{
	int vertex;
	struct graphNode* link;
 } graphNode;

typedef struct graphType {
	int v;
	graphNode* adjMatrix_H[MAX_VER];
} graphType;

graphType* createGraph();
void insertVertex(graphType* g);
void insertEdge(graphType* g, int from, int to);
void printGraph(graphType* g);