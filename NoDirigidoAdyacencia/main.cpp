/*
===========================================================
UNDIRECTED GRAPH WITH ADYENCY LIST - MAIN
Héctor Miranda García   A01658845
===========================================================
https://www.programiz.com/dsa/graph-adjacency-list
https://gist.github.com/JackyLoo/b1f404c9239898d3fbc7
https://www.youtube.com/watch?v=DBRW8nwZV-g&ab_channel=freeCodeCamp.org
===========================================================
*/
#include <iostream>
#include <cstddef>
using namespace std;
#include <vector>
#include <algorithm>
#include <math.h>
#include "linkedlist.h"
#include "hashTable.h"
#include "grafo.h"



int main(){
    /*
    0   1   2   3   4
    A   B   C   D   E
    */

    GraphAL<char> grafo(5);


    char vertex[5] = {'0', '1', '2', '3', '4'};
    cout << "creating vertices: "<< grafo.set_vertices(vertex, sizeof(vertex)/sizeof(vertex[0])) << endl;
    grafo.add_edge('0', '1');
    grafo.add_edge('2', '0');
    grafo.add_edge('1', '2');
    grafo.add_edge('1', '3');
    grafo.add_edge('2', '4');
    grafo.add_edge('3', '4');
    cout << grafo << endl;
    cout << grafo.bfs('2') << endl;
    cout << grafo.dfs('2')<<endl;

    return 0;
}