#include <vector>
#include <list>

class GrafoMAY{
   private:
    int nVertices;
    vector<int>* matriz;
    bool *siu;
    
    int inf = std::numeric_limits<int>::max();

  public:
    GrafoMAY(int nVertices){
     this->nVertices = nVertices;
     matriz = new vector<int>[nVertices];
     for(int i  = 0; i < nVertices; i++){
       for(int j = 0; j < nVertices; j++){
         matriz[i].push_back(0);
       }
     }
    }

    void addEdge(int s, int d, int c){
       matriz[s][d] = c;
       matriz[d][s] = c;
    }

    void addEdgeOnes(int s, int d){
       matriz[s][d] = 1;
       matriz[d][s] = 1;
    }

    void addEdgeDirected(int s, int d, int c){
       matriz[s][d] = c;
    }

    void imprimeGrafo(){
      for(int i  = 0; i < nVertices; i++){
       for(int j = 0; j < nVertices; j++){
         cout << matriz[i][j] << "\t";
       }
       cout << endl;
     }
    }

    int minDis(int dis[], bool ss[]){
    int min = inf, mini;
 
    for (int i = 0; i < nVertices; i++)
        if (ss[i] == false && dis[i] <= min)
            min = dis[i], mini = i;
 
    return mini;
    }

    void printDK(int dis[], int nv){
        cout<<"Vertice  Distancia\n";
        for (int i = 0; i < nv; i++){
            cout<<i<<'\t'<< dis[i]<<"\n";
        }
    }

    void DK(int nv,int s){
        matriz[nv][nv];
        int dis[nv];
        bool ss[nv];

        for (int i = 0; i < nv; i++){
            dis[i] = inf, ss[i] = false;
        }

        dis[s] = 0;

        for (int j = 0; j < nv-1; j++){
            int nu = minDis(dis, ss);

            ss[nu] = true;

            for (int k = 0; k < nv; k++){
                if ((!ss[k] && matriz[nu][k] && dis[nu] != inf) && dis[nu] + matriz[nu][k] < dis[k]){
                    dis[k] = dis[nu] + matriz[nu][k];
                }

            }
            printDK(dis, nv);
        }
    }

    void dfs(int s){
      
      
      cout<<endl;
      for(int i=0;i<nVertices;i++){
          siu[i]=false;
        }            
      dfsRec(s);
      }

    void dfsRec(int s){
      siu[s] = true;
      cout<<s;
      for(int i = 0; i < nVertices; i++){
        if(!siu[i] && matriz[s][i] > 0){
          dfsRec(i);
        }
                
      }
      cout<<endl; 
    }


    void bfs(int inicio){
      bool *vi=new bool[nVertices];
        for(int i=0;i<nVertices;i++){
          vi[i]=false;
        }
        list<int> fila;
        vi[inicio]=true;
        fila.push_back(inicio);

        while(!fila.empty()){
          int aVisitar=fila.front();
          cout<<aVisitar<<"";
          fila.pop_front();
          for(int i = 0; i < nVertices; i++){
            if(!vi[i] && matriz[aVisitar][i] > 0){
                vi[i]=true;
                fila.push_back(i);
            }
          }
        }
          cout<<endl;
    }

};