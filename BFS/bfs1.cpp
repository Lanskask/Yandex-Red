#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

struct Vertex {
    Vertex() {};
    Vertex(int data_) : data(data_) {}
    int data;
    vector<int> adjLists;

    bool operator==(const Vertex& new_vert) {
        return data == new_vert.data
            && adjLists == new_vert.adjLists;
    }
};



class Graph {
    int numVertices;
    vector<Vertex> adjLists;
    vector<bool> visited;
public:
    Graph(int vertices);

    void addEdge(int src, int dest);

    void BFS(int startVertex);
};

Graph::Graph(int numVertices_) {
    numVertices = numVertices_;
    visited.reserve(numVertices_);
    vector<Vertex> adjLists[numVertices_]; // = new list[vertices];
}

void Graph::addEdge(int src, int dest) {
    Vertex x{src};
    Vertex y{dest};
    if (find(adjLists.begin(), adjLists.end(), x) == adjLists.end()) {
        adjLists.push_back(x);
    }
    if (find(adjLists.begin(), adjLists.end(), y) == adjLists.end()) {
        adjLists.push_back(y);
    }
    y.adjLists.push_back(src);
    x.adjLists.push_back(dest);
//    adjLists.push_back(src);
//    adjLists[src].push_back(dest);
//    adjLists[dest].push_back(src);
}

void Graph::BFS(int startVertex) {
//    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

//    list queue;
    queue<int> working_queue;

    visited[startVertex] = true;
    working_queue.push(startVertex);

    list<int>::iterator i;

    while (!working_queue.empty()) {
        int currVertex = working_queue.front();
        cout << "Visited " << currVertex << " ";
        working_queue.pop();

//        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
//            int adjVertex = *i;
//            if (!visited[adjVertex]) {
//
//                visited[adjVertex] = true;
//                working_queue.push(adjVertex);
//            }
//        }
        for (int j = 0; j < adjLists[currVertex].adjLists.size(); ++j) {
            int adjVertex = adjLists[currVertex].adjLists[j];
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                working_queue.push(adjVertex);
            }
        }

    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}