#include "dfsTrace1.h"
#include <stdio.h>

Time dfsSweep1(IntVec* adjVertices, int n, Time t)
{
	t.color1 = calloc(n+1, sizeof(int));
	finishStk1 = intMakeEmptyVecN(n);
	t.time1 = 0;

	for (int v = 1; v <= n; v++)
	{
		if (t.color1[v] == 0)
		{
			t.parent1[v] = -1;

			t = dfs1(adjVertices, v, t);
		}
	}

	return t;
}

Time dfs1(IntVec * adjVertices, int v, Time t)
{
	IntVec vAdjs = adjVertices[v];
	int remAdjs;
	int w;

	t.color1[v] = 1;

	t.time1++;

	t.dTime1[v] = t.time1;

	remAdjs = intSize(vAdjs);

	while (remAdjs > 0)
	{
		remAdjs = remAdjs - 1;
		w = intData(vAdjs, remAdjs);
		if (t.color1[w] == 0)
		{
			t.parent1[w] = v;
			t = dfs1(adjVertices, w, t);
		}
	}

	t.time1++;
	t.fTime1[v] = t.time1;

	intVecPush(finishStk1, v);

	t.color1[v] = 2;
	return t;
}
