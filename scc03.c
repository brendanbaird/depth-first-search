
#include "scc03.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intVec.h"
#include "loadGraph.h"
#include "dfsTrace1.h"
#include "dfsPhase2.h"

int main(int argc, char* argv[])
{
	int m, n;
	IntVec *adjVertices;
	char line[1024];
	FILE *fp;
	char* lPtr;
	int * * adjMatrix;


	if (argc == 1)
	{
		printf("No input data\n");
		exit(1);
	}

	if (strcmp(argv[1], "-U") == 0)
	{
		fp = fopen(argv[2], "r");
		printf("Opened %s for input.\n", argv[2]);
	}

	else
	{
		fp = fopen(argv[1], "r");
		printf("Opened %s for input.\n", argv[1]);
	}
	
	lPtr = fgets(line, 1024, fp);
	n = parseN(lPtr);
	printf("n = %d\n", n);

	adjVertices = initEdges(n);

	if (strcmp(argv[1], "-U") == 0)
		m = loadUndEdges(fp, adjVertices);
	else
		m = loadEdges(fp, adjVertices);
	
	fclose(fp);
	
	printf("m = %d\n", m);

	printAdjVerts(adjVertices, n);
	
	adjMatrix = makeAdjMatrix(adjVertices, n);

	if (n <= 20)
		printAdjMatrix(adjMatrix, n);

	findSCCs(adjVertices, n);

	return 0;
}

void findSCCs(IntVec * adjVertices, int n)
{
	Time t;
	t.dTime1 = calloc(n+1, sizeof(int));
	t.fTime1 = calloc(n+1, sizeof(int));
	t.dTime2 = calloc(n+1, sizeof(int));
	t.fTime2 = calloc(n+1, sizeof(int));
	t.parent1 = calloc(n+1, sizeof(int));
	t.parent2 = calloc(n+1, sizeof(int));
	t.dfstRoot2 = calloc(n+1, sizeof(int));

	IntVec * adjVerticesT;
	int * * adjMatrixT;

	t = dfsSweep1(adjVertices, n, t);

	printTime1Matrix(t, n);

	printFSTK();

	adjVerticesT = transposeGraph(adjVertices, n);

	printAdjVerts(adjVerticesT, n);

	adjMatrixT = makeAdjMatrix(adjVerticesT, n);

	if (n <= 20)
		printAdjMatrix(adjMatrixT, n);

	t = dfsSweep2(adjVerticesT, n, t);

	printTime2Matrix(t, n);
}
