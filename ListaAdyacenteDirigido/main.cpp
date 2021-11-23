#include <iostream>
#include "grafoLA.h"

int main(){	

	GrafoLL_Dirigido ejemplo = GrafoLL_Dirigido(7);

	for (int i = 0; i < 7; i++){
		ejemplo.add_vertex(i);
	}

	// Ejemplo de <atro

	ejemplo.add_edge(0,1,2);
	ejemplo.add_edge(0,3,1);

	ejemplo.add_edge(1,3,3);
	ejemplo.add_edge(1,4,10);

	ejemplo.add_edge(2,0,4);
	ejemplo.add_edge(2,5,5);

	ejemplo.add_edge(3,5,8);
	ejemplo.add_edge(3,6,4);
	ejemplo.add_edge(3,4,2);

	ejemplo.add_edge(4,6,6);

	ejemplo.add_edge(6,5,1);

	ejemplo.print();

	return 0;
}