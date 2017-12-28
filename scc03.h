#ifndef C101scc03
#define C101scc03

#include "intVec.h"

typedef struct Time {
	int *dTime1, *dTime2, *fTime1, *fTime2, *color1, *color2;
	int *parent1, *parent2, *dfstRoot2;
	int time1, time2;
} Time;

IntVec finishStk1;

void findSCCs(IntVec * adjVertices, int n);

#endif