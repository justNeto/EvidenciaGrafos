/*
===========================================================
UNDIRECTED GRAPH WITH ADYENCY LIST - CLASS
Héctor Miranda García   A01658845
===========================================================
===========================================================
*/

/*
STEPS FOR CREATING A GRAPH
    -   define size of hashtable in contructor and create the hashtabla.
    -   auxiliar linked list for thought the hashtable index linkedlist.
    -   add edge function.
EXAMPLE (adyency_list/hashtable)
   key      linked list of connections/edges
    0   |   1
    1   |   0
    2   |
    3   |
    4   |
    5   |
    -> addEdge(vertex_0, vertex_1){
        - check if previous adge
        - add to linked list in hastable key
    }
>> addEdge(0, 1)
when adding and edge we should add two each vertex the opposite vertex.
Also, first check if there is a previous edge connection.
*/
template<typename N>
class GraphAL{
    private:
    int number_vertices;
    Hashtable<N, LinkedList<N>> adj_list =  Hashtable<N, LinkedList<N>>(); // O(1)
    public:
    /*
    Undirected listed graph constructor.
    Recives number of vertices to be added or an aproximate.
    */
    GraphAL(int number_vertices){   //O(1)
        this->number_vertices = number_vertices;
        int initial_table_size = (int)pow(3, number_vertices); 
        adj_list = Hashtable<N, LinkedList<N>>(initial_table_size);              // creating hastable accoring to size
    }
    /*
    Default constructor, sets the number o vertices to cero.
    */
    GraphAL(){  // O(1)
      this->number_vertices = 0;
    }

    int get_number_vertices(){  // O(n)
        int num_vertices = adj_list.the_size();
        if(number_vertices != num_vertices) return num_vertices;
        return number_vertices;
    }

    /*
    add vertices to hashtable in a vertices.
    Recives a list with the vertices to be added and the size of array.
    This makes it easy to add vertices.
    */
    bool set_vertices(N *keys, int size_array){     // O(n)
        LinkedList<N> empty_linked_list;
        for(int i = 0; i < size_array;i++) adj_list.put(keys[i], empty_linked_list);
        return true;
    }
    /*
    This method checks the existance of some vertex in the list.
    Recives the key or value to be searched.
    */
    bool check_vertex(N k){     // O(n)
        return adj_list.contains_key(k);
    }
    /*
    This method returns a row.
    Key or value as parameter to get the selected row
    */
    LinkedList<N> get_row(N k){     // O(n)
        return adj_list.get(k);
    }
    /*
    Checks if the list of adjacent vertex in some key is empty or not.
    Recives key or value as parameter.
    */
    bool empty_row(N k){        // O(n)
        if(adj_list.get(k).is_empty()) return true;
        return false;
    }
    /*
    This method prints the row, depending on inputen 
    key or value as parameter.
    */
    void print_row(N k){        // O(n)
        adj_list.get(k).print();
    }
    /*
    This bethod enables to create an Edge.
    Recives the two value to be linked as parameters.
    returns a boolean condition depending if there was a failure or not
    */
    bool add_edge(N key_one, N key_two){        // O(n)
        if(adj_list.contains_key(key_one)== false) return false;
        if(adj_list.live_edge(key_one, key_two)==true) return true;
        adj_list.add_value_to_row(key_one, key_two);
        adj_list.add_value_to_row(key_two, key_one);
        return true;
    }
    /*
    This method adds a vertex to list.
    Recives the value of the vertex to be added.
    */
    bool add_vertex(N k){       // O(n)
        LinkedList<N> empty_linked_list;
        adj_list.put(k, empty_linked_list);
        return true;
    }
    /*
    Method for moving around the graph and getting in return
    a linked list with all the value on the List, whithout repetitions.
    Recives the stating vertex as parameter.
    */
    LinkedList<N> bfs(N k){     // O(n^2)
        // N k == starting vertex
        LinkedList<N> queue = LinkedList<N>();  // queue to be returned
        LinkedList<N> vertex_list = LinkedList<N>();
        LinkedList<N> adjacent_list = LinkedList<N>();
        queue.push(k);        
        int current_vertex;
        while(!queue.is_empty()){
            current_vertex = queue.pop();
            if(!vertex_list.contains(current_vertex))vertex_list.push(current_vertex);
            adjacent_list = adj_list.get(current_vertex);
            for(int i = 0; i < adjacent_list.length(); i++){
                if(!vertex_list.contains(adjacent_list.get(i))) queue.push(adjacent_list.get(i));
            }
        }
        return vertex_list;
    }

    /*
    The next two method work as one together.
    This methods have the same functionality as the last one.
    This is a recursive method.
    Recives the starting vertex value.
    */
    LinkedList<N> auxiliar_visited = LinkedList<N>();
    void auxiliar_dfs(N k){         // O(n)
        auxiliar_visited.push(k); // make current node as discovered or pushed.
        LinkedList<N> l = adj_list.get(k); // list of current key.
        for(int i = 0; i < l.length(); i++) if(!auxiliar_visited.contains(l.get(i))) auxiliar_dfs(l.get(i));
    }
    LinkedList<N> dfs(N k){         // O(n)
        LinkedList<N> reboot = LinkedList<N>();
        auxiliar_visited = reboot;
        auxiliar_dfs(k);
        return auxiliar_visited;

    }
    /*
    Ostream operator overloading for printing the graph
    */
    friend ostream& operator<<(ostream& os,const GraphAL<N> &dt){       // O(n^2)
        os << dt.adj_list;
        return os; 
    }

};