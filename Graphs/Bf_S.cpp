#include<iostream>
using namespace std;
const int Max=1000;
class queue{
	public:
		int rear,front;
		int items[Max];
		queue(){
			rear=front=-1;
			for(int i=0;i<Max;i++){
				items[i]=-1;
			}
		}
		void push(int val){
			if(rear==Max-1){
				return;
			}
		  if (front == -1) {
            rear++;
            items[rear] = val;
            front++;
        } else {
            rear++;
            items[rear] = val;
        }
			
		}
		
		int pop(){
			if(isempty()){
				return -1;
			}
			int val=items[front];
			if(front>=rear){
				rear=-1;
				front=-1;
			}else{
				front++;
			}
			return val;
		}
		bool isempty(){
			return front==-1;
		}
};
class Node{
	public:
		int vertix;
		Node*next;
		Node(int c){
			vertix=c;
			next=NULL;
		}
};
class Graph{
	public:
		Node*adjList[Max];
		int numofvertices;
		bool visited[Max];
		Graph(int v){
			numofvertices=v;
			for(int i=0;i<numofvertices;i++){
				adjList[i]=NULL;
				visited[i]=false;
			}
		};
	void add_edge(int src,int dest){
			Node*temp=new Node(dest);
			temp->next=adjList[src];
			adjList[src]=temp;
			
			//for undirected
			temp=new Node(src);
			temp->next=adjList[dest];
			adjList[dest]=temp;
		}
		
		void Bfs(int vertex){
			queue q1;
			visited[vertex]=true;
			q1.push(vertex);
			while(!q1.isempty()){
				int front_node=q1.pop();
				cout<<front_node<< " ";
				Node*temp=adjList[front_node];
				while(temp){
					int adjvertex=temp->vertix;
					if(!visited[adjvertex]){
						visited[adjvertex]=true;
						q1.push(adjvertex);
					}
					temp=temp->next;
				}
			}
			
		}
		void printAdjlist(){
			for(int i=0;i<numofvertices;i++){
				cout<<"Adjacency List for "<<i<<":";
				Node*temp=adjList[i];
				while(temp){
					cout<<temp->vertix<<" ";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
};
int main(){
	Graph g1(5);
	g1.add_edge(0,1);
	g1.add_edge(1,3);
	g1.add_edge(3,4);
	g1.add_edge(4,2);
	g1.add_edge(1,2);
	g1.printAdjlist();
	g1.Bfs(0);
}
