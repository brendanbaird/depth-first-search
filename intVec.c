#include "intVec.h"
#include <stdlib.h>

struct IntVecNode
{
	int* data;
	int sz;
	int capacity;
};

int intTop(IntVec myVec)
{
	return myVec->data[(myVec->sz)-1];
}

int intData(IntVec myVec, int i)
{
	return myVec->data[i];
}

int intSize(IntVec myVec)
{
	return myVec->sz;
}

int intCapacity(IntVec myVec)
{
	return myVec->capacity;
}

IntVec intMakeEmptyVec(void)
{
	IntVec newVec = (IntVec) malloc(sizeof(struct IntVecNode));
	newVec->data = malloc(intInitCap * sizeof(int));
	newVec->sz = 0;
	newVec->capacity = intInitCap;
	return newVec;
}

IntVec intMakeEmptyVecN(int np1)
{
	IntVec newVec = (IntVec) malloc(sizeof(struct IntVecNode));
	newVec->data = calloc(np1, sizeof(int));
	newVec->sz = 0;
	newVec->capacity = np1;
	return newVec;
}

void intVecPush(IntVec myVec, int newE)
{
	int newCap;
	int* newData;

	myVec->sz = (myVec->sz)+1;
	myVec->data[(myVec->sz)-1] = newE;
	if (intSize(myVec)+1 > myVec->capacity)
	{
		newCap = 2 * myVec->capacity;
		newData = realloc(myVec->data, newCap * sizeof(int));
		if (newData != myVec->data) { myVec->data = newData; }
		myVec->capacity = newCap;
	}
}

void intVecPop(IntVec myVec)
{
	myVec->sz = (myVec->sz)-1;
}
