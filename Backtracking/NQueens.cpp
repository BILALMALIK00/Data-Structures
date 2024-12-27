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
}
bool is_safe(int row,int col,int board[N][N]){
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
bool solve(int board[N][N],int col){
	if(col==N){
		cout<<"solution found:"<<endl;
		print(board);
		return true;
	}
	bool found=false;
	for(int rows=0;rows<N;rows++){
		if(is_safe(rows,col,board)){
			board[rows][col]=1;
			if(solve(board,col+1)){
				found=true;
			}
			board[rows][col]=0;
		}
	}
	return found;
}
int main(){
//	if(N==2||N==3){
//		cout<<"NO SOLUTION"<<endl;
//		return -1;
//	}
	int board[N][N]={0};
	if(!solve(board,0)){
	cout<<"NO SOLUTION "<<endl;	
	};
}
