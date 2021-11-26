#include <vector>
#include <iostream>
#include <list>
#include <limits>
#include <algorithm>
#include <queue>
#include "tablahash.h"

using namespace std;

// O(1)
bool sortbysec(const pair<int,int> &a,
			   const pair<int,int> &b)
{
	return (a.second < b.second);
}

template<typename D>
class GrafoLA_NoDirigido{
	private:
		int numVertice;
		Hashtable<D,vector<pair<D,int>>*> tablaGrafos;
	public:
		// Constructor O(n)
		GrafoLA_NoDirigido<D>(int numVertice){
			this->numVertice = numVertice;
			this->tablaGrafos = Hashtable<D,vector<pair<D,int>>*>(numVertice);
		}

		// Adding vertex with lable 'vertex' O(1)
		bool add_vertex(D vertex){
			return this->tablaGrafos.put(vertex, new vector<pair<D,int>>());
		}

		// Adding edge from vertex 'a' to 'b' with a weight and from b to a with weight O(1)
		bool add_edge(D a, D b, int weight) {
			vector<pair<D,int>>* edgesGo = this->tablaGrafos.get(a); // Gets the empty Hastable vector ptr object
			pair<D,int> edge = pair<D,int>(b,weight);
      			edgesGo->push_back(edge); // Sets edge from a to b

      			vector<pair<D,int>>* edgesBack = this->tablaGrafos.get(b);
      			pair<D,int> edge = pair<D,int>(a,weight);
			edgesBack->push_back(edge); // Sets edge from b to a
			return true;
		}

		// Printing tablaGrafos O(n^2)
		void print(){
			cout << endl;
			cout << "#### IMPRIMIENDO GRAFOS ####" << endl;
			vector<D> vertex = tablaGrafos.keys();
			for (D i : vertex){
				vector<pair<D, int>>* edges = tablaGrafos.get(i);
				cout << "V: " << i << " A: ";
				for(int j  = 0; j < edges->size(); j++){
					// Print edge
					cout << "(" << i;
					cout << "," << edges->at(j).first << ") ";
					// Print weight
					cout << "[w:" << edges->at(j).second << "] ";
				}
				cout << endl;
			}
		}

		// O(n)
		bool has_vertex (list<D> list, D vertex){
			for(D v : list){
				if (v == vertex){
					return true;
				}
			}
			return false;
		}

		// O(n^2)
		list<D> bfs(){
			list<D> res;
			vector<D> vertex = tablaGrafos.keys();
			for (D i : vertex){
				vector<pair<D, int>>* edges = tablaGrafos.get(i);
				for(int j  = 0; j < edges->size(); j++){
					if (has_vertex(res, i)){
						res.push_back(i);
					}
					if (has_vertex(res, edges->at(j).first)){
						res.push_back(i);
					}
				}
			}
			return res;
		}

		// O(n)
		list<D> dfs(){
			list<D> res;
			vector<D> vertex = tablaGrafos.keys();
			for (D i : vertex){
				res.push_back(i);
			}
			return res;
		}
};
