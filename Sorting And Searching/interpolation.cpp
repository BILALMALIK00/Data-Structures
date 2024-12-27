#include <iostream>
using namespace std;

int inter(int *arr, int size, int target) {
    int start = 0;
    int end = size - 1;
    
    while (start <= end && target >= arr[start] && target <= arr[end]) {
        if (start == end) {
            if (arr[start] == target) {
                return start;
            }
            return -1;
        }
        
        // Calculate the position using the interpolation formula
        int position = start + ((target - arr[start]) * (end - start)) / (arr[end] - arr[start]);
        
        if (arr[position] == target) {
            return position;
        } else if (arr[position]>target) {
            end = position - 1;
        } else {
            start = position + 1;
        }
    }
    
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {2, 3, 4, 5, 6};  // Sorted array is required for interpolation search
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target = 5;
    int result = inter(arr, size, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}

