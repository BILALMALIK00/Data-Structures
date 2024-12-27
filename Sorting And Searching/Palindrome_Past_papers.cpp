#include <iostream>
using namespace std;
#define N 3  
bool isPalindrome(string st, int s, int e) {
    if (s >= e) {
        return true;
    }
    if (st[s] != st[e]) {
        return false;
    }
    return isPalindrome(st, s + 1, e - 1);
}
bool check_horizontally(char c[N][N], int row) {
    if (row == N) {
        return true;
    }
    string s = "";  
    for (int j = 0; j < N; j++) {  
        s += c[row][j];
    }
    
    if (!isPalindrome(s, 0, s.length() - 1)) {
        return false;
    }
    return check_horizontally(c, row + 1);
}

bool check_vertically(char c[N][N], int col) {
    if (col == N) {
        return true;
    }
    string s = "";  
    for (int i = 0; i < N; i++) { 
        s += c[i][col];
    }

    if (!isPalindrome(s, 0, s.length() - 1)) {
        return false;
    }
    return check_vertically(c, col + 1);
}

int main() {
    char c[N][N] = {
        {'a', 'b', 'a'},
        {'b', 'a', 'b'},
        {'c', 'a', 'c'}
    };
    
    bool hor = check_horizontally(c, 0);
    bool ver = check_vertically(c, 0);

    if (hor) {
        cout << "Palindrome present horizontally" << endl;
    } else {
        cout << "No palindrome found horizontally" << endl;
    }

    if (ver) {
        cout << "Palindrome present vertically" << endl;
    } else {
        cout << "No palindrome found vertically" << endl;
    }
}

