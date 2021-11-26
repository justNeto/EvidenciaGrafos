#include <iostream>
//#include "grafoLA.h"
#include "grafoLA.h"

int main(){	

	GrafoLA_Dirigido<int> ejemplo = GrafoLA_Dirigido<int>(7);

	for (int i = 0; i < 7; i++){
		ejemplo.add_vertex(i);
	}

	// Ejemplo de grafo

	ejemplo.add_edge(0,1,2);
	ejemplo.add_edge(0,3,1);

	ejemplo.add_edge(1,3,3);
	ejemplo.add_edge(1,4,10);

	ejemplo.add_edge(2,0,4);
	ejemplo.add_edge(2,5,5);

	ejemplo.add_edge(3,2,2);
	ejemplo.add_edge(3,5,8);
	ejemplo.add_edge(3,6,4);
	ejemplo.add_edge(3,4,2);

	ejemplo.add_edge(4,6,6);

	ejemplo.add_edge(6,5,1);

	ejemplo.print();
	ejemplo.path_dijkstra(0,6);
	cout << endl;

	GrafoLA_Dirigido<char> ejemplo2 = GrafoLA_Dirigido<char>(7);

	ejemplo2.add_vertex('a');
	ejemplo2.add_vertex('b');
	ejemplo2.add_vertex('c');
	ejemplo2.add_vertex('d');
	ejemplo2.add_vertex('e');
	ejemplo2.add_vertex('f');
	ejemplo2.add_vertex('g');

	// Ejemplo de grafo

	ejemplo2.add_edge('a','b',2);
	ejemplo2.add_edge('a','d',1);

	ejemplo2.add_edge('b','d',3);
	ejemplo2.add_edge('b','e',10);

	ejemplo2.add_edge('c','a',4);
	ejemplo2.add_edge('c','f',5);

	ejemplo2.add_edge('d','c',2);
	ejemplo2.add_edge('d','f',8);
	ejemplo2.add_edge('d','g',4);
	ejemplo2.add_edge('d','e',2);

	ejemplo2.add_edge('e','g',6);

	ejemplo2.add_edge('g','f',1);

	ejemplo2.print();
	cout << endl;

	// Dijkstra algorithm in action
	ejemplo2.path_dijkstra('a', 'g');
	ejemplo.path_dijkstra(5,6);

	return 0;
}