#include<iostream>
using namespace std;
class AdjacencyMatrix{
    int vertices;
    int**matrix;
    public:
    AdjacencyMatrix(int v){
        vertices=v;
        matrix=new int*[vertices];
        for(int i=0;i<vertices;i++){
            matrix[i]=new int[vertices];
        for(int j=0;j<vertices;j++){
            matrix[i][j]=0;
        }
        }
    }
    void addedges(int u,int v){
        matrix[u][v]=1;//directed
       // matrix[v][u]=1;//if undirected grph then we also have to do this
    }
    void display() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    AdjacencyMatrix() {
        for (int i = 0; i < vertices; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};
int main(){
int vertices=4;
AdjacencyMatrix m1(vertices);
m1.addedges(0,1);
m1.addedges(0,2);
m1.addedges(1,3);
m1.addedges(3,2);
m1.addedges(2,2);
m1.display();
}