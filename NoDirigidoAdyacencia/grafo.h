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
    Hashtable<N, LinkedList<N>> adj_list =  Hashtable<N, LinkedList<N>>();
    public:
    GraphAL(int number_vertices){
        this->number_vertices = number_vertices;
        int initial_table_size = (int)pow(3, number_vertices); 
        adj_list = Hashtable<N, LinkedList<N>>(initial_table_size);              // creating hastable accoring to size
    }
    GraphAL(){
      this->number_vertices = 0;
    }
    int get_number_vertices(){
        int num_vertices = adj_list.the_size();
        if(number_vertices != num_vertices) return num_vertices;
        return number_vertices;
    }

    /*
    add vertices to hashtable in a vertices.
    set value as an empty LinkedList<N>
    */
    bool set_vertices(N *keys, int size_array){
        LinkedList<N> empty_linked_list;
        for(int i = 0; i < size_array;i++) adj_list.put(keys[i], empty_linked_list);
        return true;
    }
    bool check_vertex(N k){
        return adj_list.contains_key(k);
    }
    LinkedList<N> get_row(N k){
        return adj_list.get(k);
    }
    bool empty_row(N k){
        if(adj_list.get(k).is_empty()) return true;
        return false;
    }
    void print_row(N k){
        adj_list.get(k).print();
    }
    bool add_edge(N key_one, N key_two){
        if(adj_list.contains_key(key_one)== false) return false;
        if(adj_list.live_edge(key_one, key_two)==true) return true;
        adj_list.add_value_to_row(key_one, key_two);
        adj_list.add_value_to_row(key_two, key_one);
        return true;
    }
    bool add_vertex(N k){
        LinkedList<N> empty_linked_list;
        adj_list.put(k, empty_linked_list);
        return true;
    }

    LinkedList<N> bfs(N k){
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

    LinkedList<N> auxiliar_visited = LinkedList<N>();
    void auxiliar_dfs(N k){
        auxiliar_visited.push(k); // make current node as discovered or pushed.
        LinkedList<N> l = adj_list.get(k); // list of current key.
        for(int i = 0; i < l.length(); i++) if(!auxiliar_visited.contains(l.get(i))) auxiliar_dfs(l.get(i));
    }
    LinkedList<N> dfs(N k){
        LinkedList<N> reboot = LinkedList<N>();
        auxiliar_visited = reboot;
        auxiliar_dfs(k);
        return auxiliar_visited;

    }

    friend ostream& operator<<(ostream& os,const GraphAL<N> &dt){
        os << dt.adj_list;
        return os; 
    }

};