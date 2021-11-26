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
class GrafoLA_Dirigido{
	private:
		int numVertice;
		Hashtable<D,vector<pair<D,int>>*> tablaGrafos;
	public:
		// Constructor O(n)
		GrafoLA_Dirigido<D>(int numVertice){
			this->numVertice = numVertice;
			this->tablaGrafos = Hashtable<D,vector<pair<D,int>>*>(numVertice);
		}

		// Adding vertex with lable 'vertex' O(1)
		void add_vertex(D vertex){
			this->tablaGrafos.put(vertex, new vector<pair<D,int>>());
		}

		// Adding edge from vertex 'a' to 'b' with a weight O(1)
		void add_edge(D a, D b, int weight){
			vector<pair<D,int>>* edges = this->tablaGrafos.get(a);
			pair<D,int> edge = pair<D,int>(b,weight);
			edges->push_back(edge);
		}

		// Geting index where 'vertex' is located in 'edges' O(n)
		int index_of_vertex(vector<pair<D, int>> edges, int vertex){
			for(int i = 0; i < edges.size(); i++){
				if(edges[i].first == vertex){
					return i;
				}
			}
			return 0;
		}

		// Dijksta's algorithm to find shortest path
		// Worst case O(n^3)
		// Average case O(n^2)
		void path_dijkstra(D start, D end){
			int inf = numeric_limits<int>::max();
			vector<D> vertices = tablaGrafos.keys();

			// Vector of pair values ('vertex', weight between start and 'vertex')
			vector<pair<D,int>> routes;

			// First fill with vertices and associate inf as weight O(n)
			for(D vertex : vertices){
				routes.push_back(pair<D,int>(vertex,inf));
			}
			// Vertex at start has weight 0
			routes.at(index_of_vertex(routes,start)).second = 0;

			vector<pair<D,int>> destinies;
			D current_vertex;
			// Going through every vertex in the grafo O(n)
			for(int i = 0; i < routes.size(); i++){
				sort(routes.begin(), routes.end(), sortbysec);
				current_vertex = routes.at(i).first;
				// Destiny vertices from current vertex;
				destinies = *tablaGrafos.get(current_vertex);
				// O(n)
				for(pair<D,int> data : destinies){
					// Si el peso del destino es menor al guardado mas el destino acumulado se cambia O(n)
					if(data.second < routes.at(index_of_vertex(routes,data.first)).second){
						routes.at(index_of_vertex(routes,data.first)).second = data.second + routes.at(index_of_vertex(routes,current_vertex)).second;
					}
				}
			}
			cout << "FINAL RESULT" << endl;
			for(auto results : routes){
				cout << "v " << results.first << " -- cum_w: " << results.second << endl;
			}
			cout << endl;
			return;
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
};