#include<iostream>
using namespace std;
#define N 4

bool is_safe(int maze[N][N], int visited[N][N], int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] != 1) {
        return true;
    }
    return false;
}

void print_solution(int visited[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int maze[N][N], int visited[N][N], int x, int y) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        visited[x][y] = 1;  
        cout << "Solution found:" << endl;
        print_solution(visited);
        visited[x][y] = 0;  
        return;
    }

    if (is_safe(maze, visited, x, y)) {
        // Mark the current cell as visited
        visited[x][y] = 1;
        solve(maze, visited, x + 1, y); 
        solve(maze, visited, x, y + 1); // Move right
        solve(maze, visited, x - 1, y); // Move up
        solve(maze, visited, x, y - 1); // Move left

        // Backtrack: Unmark the current cell to allow other paths
        visited[x][y] = 0;
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };

    int visited[N][N] = {0};
    solve(maze, visited, 0, 0);
    return 0;
}

