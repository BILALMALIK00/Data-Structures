#include<iostream>
using namespace std;
const int Max=1000;
class Node{
	public:
		int vertix;
		Node*next;
		Node(int v){
			vertix=v;
			next=NULL;
		}
};
class Grph{
	public:
		Node*Adjacencylist[Max];
		bool visited[Max];
		int numofvertices;
		Grph(int verti){
			numofvertices=verti;
			for(int i=0;i<verti;i++){
				Adjacencylist[i]=NULL;
				visited[i]=false;
			}
		}
		void add_edge(int src,int dest){
			Node*temp=new Node(dest);//for directed graph
			temp->next=Adjacencylist[src];//inserting at head
			Adjacencylist[src]=temp;
			
			
			
			temp=new Node(src);//for undirected graph
			temp->next=Adjacencylist[dest];//inserting at head
			Adjacencylist[dest]=temp;
			
		}
		void dfs(int vertix){
			visited[vertix]=true;
			cout<<vertix<<" ->";
			Node*temp=Adjacencylist[vertix];
			while(temp){
				if(!visited[temp->vertix]){
					int vertex=temp->vertix;
				dfs(vertex);
				}
				temp=temp->next;
			}
		}
		
		void PrintAdjacencylist(){
			for(int i=0;i<numofvertices;i++){
				Node*temp=Adjacencylist[i];
				cout<<"Adjacency list of vertex "<<i<<":";
			while(temp){
				cout<<temp->vertix<<" ";
				temp=temp->next;
			}
			cout<<endl;
			}
		}
};


int main(){
	Grph g1(5);
	g1.add_edge(0,1);
	g1.add_edge(1,2);
	g1.add_edge(2,4);
	g1.add_edge(4,3);
	g1.add_edge(3,1);
	
	g1.PrintAdjacencylist();
	cout<<endl;
	g1.dfs(0);
}
