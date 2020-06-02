#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <memory>

using namespace std;

// Basic Classes
template <typename T>
struct Vertex {
    Vertex(T data_) : data(data_) {}
    Vertex() {}
    T data;
    mutable vector<Vertex> neighbours;
};


template <typename T>
class Graph {
public:
    void AddVertex(Vertex<T> add_to, Vertex<T> add_what) {
        listOfVertexes.insert(add_to);
        auto it = find(listOfVertexes.begin(), listOfVertexes.end(), add_to);
//        shared_ptr<vector<Vertex<char>>> neighboursList = it->neighbours;
        it->neighbours.push_back(add_what);
    }

    template <typename ProcessFunction>
    void BFS(Vertex<T> start_vertex, ProcessFunction process_functions) {

    }
    [[nodiscard]] const set<Vertex<T>> &getListOfVertexes() const {
        return listOfVertexes;
    }

private:
    set<Vertex<T>> listOfVertexes;
};
// End Of Basic Classes

// Print Functions
template <typename T>
bool operator<(const Vertex<T>& a, const Vertex<T>& b) {
    return a.data > b.data;
}
template <typename T>
bool operator==(const Vertex<T>& a, const Vertex<T>& b) {
    return a.data > b.data;
}
template <typename T>
ostream& operator<<(ostream& os, const Vertex<T>& vertex) {
    os << "Vertex: " << vertex.data;
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& collection) {
    for(const auto& x : collection) {
        os << x << ", ";
    }
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& collection) {
    for(const auto& x : collection) {
        os << x << ", ";
    }
    return os;
}
// End Of Print Functions

template <typename T>
void WorkingFunction(Vertex<T> vertex) {
    cout << "Vertex: " << vertex.data;
}

int main() {
    Graph<char> graph;

    graph.AddVertex(Vertex<char>('a'), Vertex<char>('b'));
    graph.AddVertex(Vertex<char>('a'), Vertex<char>('c'));

    cout << "graph.getListOfVertexes(): " << graph.getListOfVertexes() << endl;
}