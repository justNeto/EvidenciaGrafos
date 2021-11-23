/*
===========================================================
UNDIRECTED GRAPH WITH ADYENCY LIST - MAIN
Héctor Miranda García   A01658845
===========================================================
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


   /*
   For this implementation we didn't implemented dijkstra as instructed by professor.
   Thisway we didn't added edge weighs, bacause ther are not neaded for any method in
   our class.
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