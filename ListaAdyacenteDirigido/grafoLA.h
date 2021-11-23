#include <vector>
#include <iostream>
#include <list>
#include <limits>
#include "tablahash.h"

using namespace std;

class GrafoMA{
	private:
	int nVertices;
	vector<int>* matriz;

	public:
	// O(n^2)
	GrafoMA(int nVertices){
		this->nVertices = nVertices;
		this->matriz = new vector<int>[nVertices];

		for (int i = 0; i < nVertices; i++){
			for (int j = 0; j < nVertices; j++){
				matriz[i].push_back(0);
			}
		}
	}

	// O(1)
	void add_edge(int s, int d){
		matriz[s][d] = 1;
		matriz[d][s] = 1;
	}// O(1)
	void add_edge_directed(int s, int d){
		matriz[s][d] = 1;
	}

	// O(n^2)
	void print(){
		for (int i = 0; i < nVertices; i++){
			for (int j = 0; j < nVertices; j++){
				cout << matriz[i].at(j) << " ";
			}
			cout << endl;
		}
	}
};

class GrafoLL_Dirigido{
	private:
	int nVertices;
	Hashtable<int, vector<vector<int>>*>* listAD;
	
	public:
	// O(n^2)
	GrafoLL_Dirigido(int nVertices){
		this->nVertices = nVertices;
		this->listAD = new Hashtable<int, vector<vector<int>>*>(nVertices);
	}

	// O(1)
	void add_vertex(int s){
		listAD->put(s, new vector<vector<int>>());
	}

	// O(1)
	void add_edge(int s, int d, int weight){
		vector<vector<int>>* edges = listAD->get(s);
		vector<int> res = {d , weight};
		edges->push_back(res);
	}
	
	// O(1)
	void shortest_path(int end){
		int inf = numeric_limits<int>::max();

		




		return;
	}

	// O(n^2)
	void print(){
		cout << endl;
		vector<int> vertex = listAD->keys();
		for (int i : vertex){
			int vertice = vertex[i];
			vector<vector<int>>* edges = listAD->get(vertice);
			cout << "V: " << vertice << " A: ";
			for(int j  = 0; j < edges->size();j++){
				cout << "(" << vertice;
				cout << "," << edges->at(j).at(0) << ") ";
				cout << "[W: " << edges->at(j).at(1) << "] ";
			}
			cout << endl;
		}
	}
};