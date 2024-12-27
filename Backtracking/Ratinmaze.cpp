#include<iostream>
using namespace std;
#define N 4
bool is_safe(int arr[N][N],int sol[N][N],int x,int y){
	if(x>=0&&y<N&&y>=0&&y<N&&arr[x][y]==1&&sol[x][y]==0){
		return true;
	}
	return false;
}
void display(int sol[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		cout<<sol[i][j]<<" ";	
		}
		cout<<endl;
	}
	cout<<endl;
}
bool solve(int arr[N][N],int solution[N][N],int x,int y ){
	//base case
	if(x==N-1&&y==N-1&&arr[x][y]==1){
		solution[x][y]=1;
		display(solution);
		return true;
	}
	if(is_safe(arr,solution,x,y)){
		solution[x][y]=1;
		if(solve(arr,solution,x+1,y)){
			return true;
		}
		if(solve(arr,solution,x,y+1)){
			return true;
		}
		if(solve(arr,solution,x,y-1)){
			return true;
		}
		if(solve(arr,solution,x-1,y)){
			return true;
		}
		solution[x][y]=0;
		return false;
	}
	return false;
}
bool queenis_safe(int board[N][N],int row,int col){
int x=row;
int y=col;
while(y>=0){
	if(board[x][y]==1){
		return false;
	}
	y--;
}
x=row;
y=col;
while(x>=0&&y>=0){
	if(board[x][y]==1){
		return false;
	}
	x--;
	y--;
}
x=row;
y=col;
while(x<N&&y>=0){
	if(board[x][y]==1){
		return false;
	}
	x++;
	y--;
}
return true;
}
	bool sol(int board[N][N],int col){
	bool found=false;
	if(col==N){
		cout<<"Sol found"<<endl;
		display(board);
		return true;
	}
	for(int i=0;i<N;i++){
	if(queenis_safe(board,i,col)){
		board[i][col]=1;
		if(sol(board,col+1)){
			found=true;
		}
		board[i][col]=0;
	}
}
return found;
}

int main(){
	int arr[N][N]={{1,0,0},{1,1,0},{1,1,1}};
	int solution[N][N]={0};
	cout<<"ORIGINAL:"<<endl;
	display(arr);
	int board[N][N]={0};
	if(!solve(arr,solution,0,0)){
		cout<<"NO SOLUTION EXIST"<<endl;
	}
	cout<<endl;
	if(!sol(board,0)){
		cout<<"no solution"<<endl;
	}
	
}
