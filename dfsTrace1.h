#ifndef C101dfsTrace1
#define C101dfsTrace1

#include "scc03.h"
#include "intVec.h"
#include "loadGraph.h"
#include <stdlib.h>

Time dfsSweep1(IntVec* adjVertices, int n, Time t);

Time dfs1(IntVec * adjVertices, int v, Time t);

#endif