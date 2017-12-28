#ifndef C101loadGraph
#define C101loadGraph

#include <stdio.h>
#include <stdlib.h>
#include "intVec.h"
#include "scc03.h"

//Contructs a empty vectors
IntVec* initEdges(int n);

//Pushes vectors with data to other vectors
int loadEdges(FILE *fp, IntVec * adjVertices);

//Pushes undirected vectors with data to other vectors
int loadUndEdges(FILE *fp, IntVec * adjVertices);

//Reads the first line of the text file
int parseN(char line[]);

//Makes a 2D array showing edges
int * * makeAdjMatrix(IntVec * adjVertices, int n);

//Switches the direction of edges
IntVec* transposeGraph(IntVec* origGraph, int n);

//Prints a list of adjacent vertices
void printAdjVerts(IntVec* adjVertices, int n);

//Prints a matrix from the 2D array
void printAdjMatrix(int ** adjMatrix, int n);

void printTime1Matrix(Time t, int n);

void printTime2Matrix(Time t, int n);

//void printFSTK(Time t);

void printFSTK();

#endif