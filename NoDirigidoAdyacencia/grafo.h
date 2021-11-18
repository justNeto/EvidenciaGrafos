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
    bool set_vertices(int *keys){
        LinkedList<N> empty_linked_list;
        for(int i = 0; i < number_vertices-1;i++) adj_list.put(keys[i], empty_linked_list);
        return true;
    }
    bool empty_row(N k){
        if(adj_list.get(k).is_empty()) return true;
        return false;
    }
    bool live_edge(N key_one){
        if(adj_list.get_record(key_one).contains(key_one)) return true;
        return false;
    }
    bool add_edge(N key_one, N key_two){
        if(adj_list.contains_key(key_one)!= false) return false;
        if(live_edge(key_one)) return true;
        LinkedList<N> k_one = adj_list.get_record(key_one);
        k_one.addLast(key_two);
        adj_list.update_record(key_one, k_one);
        LinkedList<N> k_two = adj_list.get_record(key_two);
        k_one.addLast(key_one);
        adj_list.update_record(key_one, k_two);
        return true;
    }

};