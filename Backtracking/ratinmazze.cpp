#include<iostream>
using namespace std;
#define N 5

bool is_safe(int maze[N][N], int visited[N][N], int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] != 1) {
        return true;
    }
    return false;
}

bool solve(int maze[N][N], int visited[N][N], int x, int y) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        visited[x][y] = 1;
        return true;
    }

    if (is_safe(maze, visited, x, y)) {
        visited[x][y] = 1;
        if (solve(maze, visited, x + 1, y)) return true;
        if (solve(maze, visited, x, y - 1)) return true;
        if (solve(maze, visited, x - 1, y)) return true;
        if (solve(maze, visited, x, y + 1)) return true;
        visited[x][y] = 0;  
        return false;
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
}

int main() {
    int maze[N][N] = {
        {1, 0, 1, 0,1},
        {1, 1, 1, 1,1},
        {0, 1, 0, 1,1},
        {1,0 ,0 ,1,1},
        {1,1,1,0,1},
    };

    int visited[N][N] = {0};
    if (solve(maze, visited, 0, 0)) {
        cout << "Solution exists!" << endl;
        print_solution(visited);
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}

