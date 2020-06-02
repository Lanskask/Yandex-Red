#include<iostream>
#include<vector>
#include<queue>
#include<memory>
#include<algorithm>
#include <new>

using namespace std;

// Basic Classes
template <typename T>
class Vertex {
public:
    Vertex(T data_) : data(data_) {}
    Vertex() {}
    Vertex(const Vertex& vertx) : data(vertx.data), neighbours(vertx.neighbours) {
//        data = vertx.data;
//        copy(begin(vertx.neighbours), end(vertx.neighbours), neighbours);
//        neighbours = vertx.neighbours;
    }

    bool operator==(const Vertex<T>& a) const {
        return
                a.data == data
                && a.neighbours == neighbours;
    }

//    Vertex<T>& operator=(const Vertex<T> a) {
//        Vertex result(a.data, a.neighbours);
//        *this;
//    }
    T getData() const;

    vector<Vertex<T>> &getNeighbours();
    const vector<Vertex<T>> &getNeighbours() const;

    void operator=(const Vertex& rhs);
private:
    T data; // for little data
    vector<Vertex<T>> neighbours;
};

template<typename T>
void Vertex<T>::operator=(const Vertex &rhs) {
    Vertex<T> tmp(rhs);
    swap(tmp.data, data);
    swap(tmp.neighbours, neighbours);
}

template<typename T>
T Vertex<T>::getData() const {
    return data;
}

template<typename T>
vector<Vertex<T>> &Vertex<T>::getNeighbours() {
    return neighbours;
}

template<typename T>
const vector<Vertex<T>> &Vertex<T>::getNeighbours() const {
    return neighbours;
}

using CharVertex = Vertex<char>;


template <typename T>
class Graph {
public:
    Graph<T>() {}
    Graph<T>(size_t size_) : graph_size(size_) {
        listOfVertexes.reserve(graph_size);
    }

//    void AddVertex(Vertex<T> add_to, Vertex<T> add_what) {
//        listOfVertexes.insert(add_to);
//        auto it = find(listOfVertexes.begin(), listOfVertexes.end(), add_to);
////        shared_ptr<vector<Vertex<char>>> neighboursList = it->neighbours;
//        it->neighbours.push_back(add_what);
//    }
    void AddVertex(Vertex<T>& new_vertex) {
        ++graph_size;
        listOfVertexes.push_back(new_vertex);
    }

    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
            func();
            cerr << test_name << " OK" << endl;
    }

    void BFS(Vertex<T> start_vertex) {
        /*a - b - d
           \ |
             c - e*/
        vector<Vertex<T>> visited;
        queue<Vertex<T>> working_queue;

        visited.push_back(start_vertex);
        working_queue.push(start_vertex);

        while(!working_queue.empty()) {
//            shared_ptr<Vertex<T>> vert = working_queue.front();
            Vertex<T> vert = working_queue.front();
//            cout << "Front of the Working Queue: " << working_queue.front() << endl;
            working_queue.pop(); // put out current processed vertex from working queue

            cout << "Current vertex: " << vert << endl;
//            process_functions(vert);
            for(Vertex<T> neib : vert.getNeighbours()) {
                if(find(visited.begin(), visited.end(), neib) == visited.end()) { // if not visited
                    cout << "It's a neib: " << neib << endl;
                    visited.push_back(neib);
                    working_queue.push(neib);
                }
            }
        }
        cout << "-- End of BFS --" << endl;
    }

    [[nodiscard]] const vector<Vertex<T>> &getListOfVertexes() const {
        return listOfVertexes;
    }
    void setListOfVertexes(const vector<Vertex<T>> &listOfVertexes_) {
        Graph::listOfVertexes = listOfVertexes_;
    }

private:
    vector<Vertex<T>> listOfVertexes;
    size_t graph_size;
};
// End Of Basic Classes

// PrintFunctions
template <typename T>
ostream& operator<<(ostream& os, const Vertex<T>& vertex) {
    os << "{" << vertex.getData();
    if (!vertex.getNeighbours().empty()) {
        os  << ": [" << vertex.getNeighbours() << "]";
    }
    os << "}";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& collection) {
    bool first = true;
    for(const auto& x : collection) {
        if(!first)  os << ", ";
        os << x;
        first = false;
    }
    return os;
}
// End Of Print Functions

template <typename T>
void WorkingFunction(Vertex<T> vertex) {
    cout << "Vertex: " << vertex.data;
}


int main() {
/*a - b - d
   \ |
     c - e*/
    size_t size__ = 5;

    CharVertex a('a');
    CharVertex b('b');
    CharVertex c('c');
    CharVertex d('d');
    CharVertex e('e');
    a.getNeighbours().push_back(b);
    a.getNeighbours().push_back(c);
    b.getNeighbours().push_back(d);
    b.getNeighbours().push_back(c);
    c.getNeighbours().push_back(e);
//    vector<CharVertex> allVertexes(size__);
    vector<CharVertex> allVertexes;
    allVertexes.push_back(a);
    allVertexes.push_back(b);
    allVertexes.push_back(c);
    allVertexes.push_back(d);
    allVertexes.push_back(e);

    Graph<char> graph(size__);
    graph.setListOfVertexes(allVertexes);

//    cout << graph.getListOfVertexes() << endl;
    graph.BFS(a);
//    graph.BFS<WorkingFunction>(WorkingFunction, a);

//    graph.AddVertex(Vertex<char>('a'), Vertex<char>('b'));
//    graph.AddVertex(Vertex<char>('a'), Vertex<char>('c'));

    return EXIT_SUCCESS;
}


