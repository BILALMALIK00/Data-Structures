#include<iostream>
#include<vector>
using namespace std;

const int Max = 1000;

class Grph {
public:
    vector<int> Adjacencylist[Max];
    bool visited[Max];
    int numofvertices;

    Grph(int verti) {
        numofvertices = verti;
        for (int i = 0; i < verti; i++) {
            visited[i] = false;
        }
    }

    void add_edge(int src, int dest) {
        Adjacencylist[src].push_back(dest);
        Adjacencylist[dest].push_back(src);
    }

    void dfs(int vertix) {
        visited[vertix] = true;
        cout << vertix << " -> ";
        for (int i = 0; i < Adjacencylist[vertix].size(); i++) {
            int vertex = Adjacencylist[vertix][i];
            if (!visited[vertex]) {
                dfs(vertex);
            }
        }
    }

    void PrintAdjacencylist() {
        for (int i = 0; i < numofvertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int j = 0; j < Adjacencylist[i].size(); j++) {
                cout << Adjacencylist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Grph g1(5);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(3, 4);
    g1.add_edge(4, 5);
     g1.add_edge(1, 7);
    

    g1.PrintAdjacencylist();
    cout << endl;
    
    cout << "DFS traversal starting from vertex 0: ";
    g1.dfs(0);
    cout << endl;

    return 0;
}

