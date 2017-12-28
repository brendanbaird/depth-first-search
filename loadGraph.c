#include "loadGraph.h"

typedef struct Edge
{
	int from, to;
	double weight;
} Edge;

Edge parseEdge(char line[]);

// Constructs empty vectors
IntVec* initEdges(int n)
{
	IntVec *adjVertices = (IntVec*) malloc((n+1)*sizeof(IntVec));
	for (int i = 1; i <= n; i++)
	{
		adjVertices[i] = intMakeEmptyVec();
	}
	return adjVertices;
}

// Pushes vectors with data to other vectors
int loadEdges(FILE *fp, IntVec * adjVertices)
{
	int m;
	char* lPtr;
	char line[1024];

	m = 0;
	lPtr = fgets(line, 1024, fp);
	while (lPtr != NULL)
	{
		Edge e = parseEdge(lPtr);
		intVecPush(adjVertices[e.from], e.to);
		lPtr = fgets(line, 1024, fp);
		m++;
	}
	return m;
}

int loadUndEdges(FILE *fp, IntVec * adjVertices)
{
	int m;
	char* lPtr;
	char line[1024];

	m = 0;
	lPtr = fgets(line, 1024, fp);
	while (lPtr != NULL)
	{
		Edge e = parseEdge(lPtr);
		intVecPush(adjVertices[e.from], e.to);
		intVecPush(adjVertices[e.to], e.from);
		lPtr = fgets(line, 1024, fp);
		m++;
	}
	return m; 
}

// Parses the text file to make an Edge with elements
Edge parseEdge(char line[])
{
	Edge newE;
	int numFields;
	numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
	if (numFields < 2 || numFields > 3)
	{
		printf("Bad edge: %s\n", line);
		exit(2);
	}

	if (numFields == 2)
		newE.weight = 0.0;
	return newE;
}

// Reads the first line of the text file
int parseN(char line[])
{
	int n;
	int numFields;
	numFields = sscanf(line, "%d %*s", &n);
	if (numFields != 1)
	{
		printf("Bad line 1: %s\n", line);
		exit(3);
	}
	return n;
}

int * * makeAdjMatrix(IntVec * adjVertices, int n)
{
	int * * adjMatrix;
	adjMatrix = calloc(n+1, sizeof(int*));
	int found;

	for (int i = 1; i <= n; i++){
		adjMatrix[i] = calloc(n+1, sizeof(int));
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < intSize(adjVertices[i]); k++)
			{
				if (intData(adjVertices[i], k) == j)
				{
					found = 1;
					break;
				}
				else
				{
					found = 0;
				}
			}
			adjMatrix[i][j] = found;
		}
	}
	return adjMatrix;
}

IntVec* transposeGraph(IntVec* origGraph, int n)
{
	IntVec *tranVertices = initEdges(n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < intSize(origGraph[i]); j++)
		{
			int tranI = intData(origGraph[i], j);
			intVecPush(tranVertices[tranI], i);
		}
	}
	return tranVertices;
}

void printAdjVerts(IntVec* adjVertices, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (intSize(adjVertices[i]) == 0)
		{
			printf("%d\t[ ]\n", i);
			continue;
		}
		else
			printf("%d\t[ ", i);

		for (int j = 0; j < intSize(adjVertices[i]); j++)
		{
			if (j == intSize(adjVertices[i]) - 1)
				printf("%d ]", intData(adjVertices[i], j));
			else
				printf("%d, ", intData(adjVertices[i], j));
		}
		printf("\n");
	}
	printf("\n");
}

void printAdjMatrix(int ** adjMatrix, int n)
{
	printf("   ");
	for (int i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");

	for (int i = 1; i <= n; i++)
	{
		printf("%d: ", i);
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", adjMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printTime1Matrix(Time t, int n)
{
	char letter;
	printf("V\tcolor\tdTime\tfTime\tparent\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d\t", i);

		if (t.color1[i] == 0)
			letter = 'W';
		else if (t.color1[i] == 1)
			letter = 'G';
		else if (t.color1[i] == 2)
			letter = 'B';
		printf("%c\t%d\t%d\t%d\n", letter, t.dTime1[i], t.fTime1[i], t.parent1[i]);
	}
	printf("\n");
}

void printTime2Matrix(Time t, int n)
{
	char letter;
	printf("V\tcolor2\tdTime2\tfTime2\tparent2\tdfstRoot2\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d\t", i);

		if (t.color2[i] == 0)
			letter = 'W';
		else if (t.color2[i] == 1)
			letter = 'G';
		else if (t.color2[i] == 2)
			letter = 'B';
		printf("%c\t%d\t%d\t%d\t%d\n", letter, t.dTime2[i], t.fTime2[i], t.parent2[i], t.dfstRoot2[i]);
	}
	printf("\n");
}

void printFSTK()
{
	printf("FSTK:  ");
	for (int i = 0; i < intSize(finishStk1); i++)
	{
		printf("%d  ", intData(finishStk1, i));
	}
	printf("\n\n");
}


