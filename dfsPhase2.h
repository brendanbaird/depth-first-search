#ifndef C101dfsPhase2
#define C101dfsPhase2

#include "scc03.h"
#include "intVec.h"
#include "loadGraph.h"
#include <stdlib.h>

Time dfsSweep2(IntVec* adjVertices, int n, Time t);

Time dfs2(IntVec * adjVertices, int v, int leader, Time t);

#endif