#include<iostream>
using namespace std;
#define N 9
bool is_safe(int board[N][N],int row,int col,int val){
	for(int i=0;i<N;i++){
		if(board[row][i]==val){
			return false;
		}
		if(board[i][col]==val){
			return false;
		}
		if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
			return false;
		}
	}
	return true;
} 
bool solve(int board[N][N]){
	for(int row=0;row<N;row++){
		for(int col=0;col<N;col++){
			if(board[row][col]==0){
			for(int val=1;val<=9;val++){
				if(is_safe(board,row,col,val)){
					board[row][col]=val;
						bool found=solve(board);
						if(found){
							return true;
						}
						else{
							board[row][col]=0;
						}
				}
				
			}
			return false;
		}
	}
}
}
void print_board(int board[N][N]){
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}
int main(){
int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
 if (solve(board)) {
        print_board(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
