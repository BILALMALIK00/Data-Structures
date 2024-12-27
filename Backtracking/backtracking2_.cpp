#include<iostream>
using namespace std;
#define N 4
void print(int arr[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool is_safe(int board[N][N],int row,int col){
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
	if(col==N){
		print(board);
		return true;
	}
	bool found=false;
	for(int row=0;row<N;row++){
		if(is_safe(board,row,col)){
			board[row][col]=1;
			if(sol(board,col+1)){
				found=true;
			}
			board[row][col]=0;
		}
	}
	return found;
}
int main(){
	int board[N][N]={0};
	if(!sol(board,0)){
		cout<<"No soltuion"<<endl;
	}
	
}
