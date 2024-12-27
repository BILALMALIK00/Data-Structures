#include<iostream>
using namespace std;
#define N 3
void print(int arr[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool is_safe(int arr[N][N],int solution[N][N],int x,int y){
	if(x>=0&&x<N&&y>=0&&y<N&&arr[x][y]==1&&solution[x][y]!=1){
		return true;
	}
	return false;
}
void solve(int arr[N][N],int sol[N][N],int x,int y){
	//base case
	if(x==N-1&&y==N-1&&arr[x][y]==1){
		sol[x][y]=1;
		cout<<"SOl found"<<endl;
		print (sol);
		sol[x][y]=0;
		return;
	}
	if(is_safe(arr,sol,x,y)){
		sol[x][y]=1;
	solve(arr,sol,x+1,y);
	solve(arr,sol,x-1,y);
	solve(arr,sol,x,y+1);
	solve(arr,sol,x,y-1);
		sol[x][y]=0;
	}
}
int main(){
	int arr[N][N]={{1,0,0},{1,1,1},{1,1,1}};
print(arr);
cout<<endl;
	int sol[N][N]={0};
	solve(arr,sol,0,0);
}
