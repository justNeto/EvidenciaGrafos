
#include <iostream>
#include <cstddef>
#include <list>

using namespace std;

#include <vector>
#include <algorithm>
#include <math.h>
#include "linkedlist.h"
#include "hashTable.h"
#include "grafo.h"
#include "Grafo2.h"
#include <limits>



int main(){

    GrafoMAY newtest(5);
    newtest.addEdge(0,1,2);
    newtest.addEdge(0,2,3);
    newtest.addEdge(1,3,1);
    newtest.addEdge(1,4,8);
    newtest.addEdge(2,4,6);
    newtest.addEdge(3,4,2);

    //newtest.imprimeGrafo();

    //newtest.DK(5, 0);
    //newtest.dfs(0);

    GrafoMAY Newfile(5);
    Newfile.addEdgeOnes(0, 1);
    Newfile.addEdgeOnes(0, 2);
    Newfile.addEdgeOnes(1, 3);
    Newfile.addEdgeOnes(1, 4);
    Newfile.addEdgeOnes(2, 4);
    Newfile.addEdgeOnes(3, 4);

    Newfile.dfs(0);
    Newfile.imprimeGrafo();
    Newfile.bfs(0);


    /*
    cout<<"Hello World!"<<endl;

    GrafoMa<NodeGraf<char>> GrafoDirigido(5);
    NodeGraf<char>stat = NodeGraf<char>('B', 2);
    GrafoDirigido.addEdgeD(0, 1, stat);
    NodeGraf<char>stat2 = NodeGraf<char>('C', 3);
    GrafoDirigido.addEdgeD(0, 2, stat2);
    NodeGraf<char>stat3 = NodeGraf<char>('A', 2);
    GrafoDirigido.addEdgeD(1, 0, stat3);
    NodeGraf<char>stat4 = NodeGraf<char>('E', 8);
    GrafoDirigido.addEdgeD(1, 4, stat4);
    NodeGraf<char>stat5 = NodeGraf<char>('D', 1);
    GrafoDirigido.addEdgeD(1, 3, stat5);
    NodeGraf<char>stat6 = NodeGraf<char>('E', 6);
    GrafoDirigido.addEdgeD(2, 4, stat6);
    NodeGraf<char>stat7 = NodeGraf<char>('B', 1);
    GrafoDirigido.addEdgeD(3, 1, stat7);
    NodeGraf<char>stat8 = NodeGraf<char>('E', 2);
    GrafoDirigido.addEdgeD(3, 4, stat8);
    NodeGraf<char>stat9 = NodeGraf<char>('C', 6);
    GrafoDirigido.addEdgeD(4, 2, stat9);
    NodeGraf<char>stat10 = NodeGraf<char>('B', 8);
    GrafoDirigido.addEdgeD(4, 1, stat10);
    NodeGraf<char>stat1 = NodeGraf<char>('D', 2);
    GrafoDirigido.addEdgeD(4, 3, stat1);

    cout<<GrafoDirigido<<endl;



    GrafoDirigido.imprimeGrafo();
/*
    GrafoMa<int> nuevoGrafo(3);
    nuevoGrafo.addEdge(0,1,2);
    nuevoGrafo.addEdgeD(2,0,4);
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<GrafoDirigido<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    nuevoGrafo.imprimeGrafo();

    nuevoGrafo.dijktrasearch(1, 2);
    cout<<""<<endl;
    GrafoDirigido.imprimeGrafo1(0, 1);

    cout<<"¿Y los Grafos?"<<endl;
    */
}