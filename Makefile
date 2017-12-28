CC = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

scc03: scc03.o intVec.o loadGraph.o dfsTrace1.o dfsPhase2.o
	${CC} 	-o scc03 ${CFLAGS} scc03.o intVec.o loadGraph.o dfsTrace1.o dfsPhase2.o

scc03.o: scc03.c scc03.h
	${CC} 	-c ${CFLAGS} scc03.c

intVec.o: intVec.c intVec.h
	${CC} 	-c ${CFLAGS} intVec.c

loadGraph.o: loadGraph.c loadGraph.h
	${CC}	-c ${CFLAGS} loadGraph.c

dfsTrace1.o: dfsTrace1.c dfsTrace1.h
	${CC}	-c ${CFLAGS} dfsTrace1.c

dfsPhase2.o: dfsPhase2.c dfsPhase2.h
	${CC}	-c ${CFLAGS} dfsPhase2.c
