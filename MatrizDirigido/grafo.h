template<typename T>
class NodeGraf{
    private:
    
    public:
        T data;
        int costo;
        NodeGraf(T data, int costo = 0){
            this->data = data; //O(1)
            this->costo = costo; //o(1)                                                                  //O(1)
        }
        friend ostream &operator<<(ostream & os, const NodeGraf<T> & DAM){
          
          os<<DAM.data<<", "<< DAM.costo;
          return os;
        }
        /*
        bool operator>=(const NodeGraf<T> & DAM){
          if (DAM.costo >= costo){
            return true;
          }
          else{
            return false;
          }
        }

        bool operator<(const NodeGraf<T> & DAM){
          if (DAM.costo < costo){
            return true;
          }
          else{
            return false;
          }
        }

        bool operator>(const NodeGraf<T> & DAM){
          if (DAM.costo > costo){
            return true;
          }
          else{
            return false;
          }
        }

        int operator+=(const NodeGraf<T> & DAM){
          costo += DAM.costo;
          return costo;
        }

        int operator-=(const NodeGraf<T> & DAM){
          costo -= DAM.costo;
          return costo;
        }
*/

    NodeGraf(){
      this->costo = 0;
    }
};



template<typename T>
class GrafoMa{
  private:
  int nvertex;
  public:
  NodeGraf<T> * status;
  LinkedList<T> * matriz;
  GrafoMa(int nvertex){                           //Se crea la matriz con Listas ligadas
    this->nvertex = nvertex;
    matriz = new LinkedList<T>[nvertex];
    for(int i = 0; i < nvertex; i++){
      for(int j = 0;j < nvertex; j++){
        matriz[i].addLast(T());
      }
    }
  }

  GrafoMa(){

  }

  

  

  void addEdge (int s, int d, T dato){          //En caso de se Matriz de adyacencia NO dirigido, usar esta funcion
    matriz[s].set(d, dato);
    matriz[d].set(s, dato);
  }

  void addEdgeD(int s, int d, T dato){          //En caso de se Matriz de adyacencia dirigido, usar esta funcion
    matriz[s].set(d, dato);
  }

  void imprimeGrafo(){                          //impresion de la Matriz creada
      for(int i  = 0; i < nvertex; i++){
       for(int j = 0; j < nvertex; j++){
         cout << matriz[i].get(j) << "\t";
       }
       cout << endl;
     }
    }

  //void dijktrasearch(int nvertex,


  void imprimeGrafo1(int i, int j){
    cout << matriz[i].get(j) <<endl;
  }


 friend ostream &operator<<(ostream & os, const GrafoMa<T> &im){

  for (int i = 0; i < im.nvertex; i++){
    os << im.matriz[i] << endl;
  }
  return os;
 }


  
};

