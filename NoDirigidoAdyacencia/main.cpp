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

    GraphAL<char> grafo(4);
    int vertex[4] = {'A', 'B', 'C', 'D'};
    cout << "creating vertices: "<< grafo.set_vertices(vertex) << endl;
    cout << "live vertex: " << grafo.check_vertex('A')<< endl;
    cout << "key row list: " ; grafo.print_row('A'); cout<< "========" <<endl;
    cout << "Adding A-B edge: " <<grafo.add_edge('A', 'B') <<endl;
    cout << "key row A list: "; grafo.print_row('A');
    cout << "key row B list: "; grafo.print_row('B');
    return 0;
}