#include<iostream>
using namespace std;

int main() {
    int rows;
        cout << "Enter the number of rows: ";
    cin >> rows;
    
    int** arr = new int*[rows];  
        int* size = new int[rows];
        for (int i = 0; i < rows; i++) {
        cout << "Enter the number of elements in row " << i + 1 << ": ";
        cin >> size[i];
                arr[i] = new int[size[i]];
        
        cout << "Enter " << size[i] << " elements for row " << i + 1 << ": ";
        for (int j = 0; j < size[i]; j++) {
            cin >> arr[i][j];
        }
    }
        cout << "\nThe jagged array is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < size[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];  
    }
    delete[] arr;  
    delete[] size; 
    return 0;
}

