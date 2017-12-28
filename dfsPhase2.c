#include "dfsPhase2.h"
#include <stdio.h>

Time dfsSweep2(IntVec* adjVertices, int n, Time t)
{
	t.color2 = calloc(n+1, sizeof(int));
	t.time2 = 0;

	while (intSize(finishStk1) > 0)
	{
		int v = intTop(finishStk1);
		intVecPop(finishStk1);

		if (t.color2[v] == 0)
		{
			t.parent2[v] = -1;
			t = dfs2(adjVertices, v, v, t);
		}
	}
	return t;
}

Time dfs2(IntVec * adjVertices, int v, int leader, Time t)
{

	IntVec vAdjs = adjVertices[v];
	int remAdjs;

	t.dfstRoot2[v] = leader;

	t.color2[v] = 1;

	t.time2++;
	t.dTime2[v] = t.time2;

	remAdjs = intSize(vAdjs);

	while (remAdjs > 0)
	{
		remAdjs = remAdjs - 1;

		int w = intData(vAdjs, remAdjs);

		if (t.color2[w] == 0)
		{
			t.parent2[w] = v;
			t = dfs2(adjVertices, w, leader, t);
		}
	}

	t.time2++;
	t.fTime2[v] = t.time2;

	t.color2[v] = 2;

	return t;
}
