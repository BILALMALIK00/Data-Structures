#include <iostream>
using namespace std;

// Function to generate permutations
void perm(int nums[], int n, int ans[][10], int& ansIndex, int index) {
    if (index >= n) {
        // Add the current permutation to the answer
        for (int j = 0; j < n; j++) {
            ans[ansIndex][j] = nums[j];
        }
        ansIndex++;
        return;
    }

    // Try all permutations by swapping elements
    for (int i = index; i < n; i++) {
        swap(nums[index], nums[i]);
        perm(nums, n, ans, ansIndex, index + 1);
        // Backtracking step
        swap(nums[index], nums[i]);
    }
}

// Function to initialize permutation generation
void permute(int nums[], int n, int ans[][10], int& ansIndex) {
    perm(nums, n, ans, ansIndex, 0);
}

int main() {
    int nums[] = {1, 2, 3};  // Example input
    int n = sizeof(nums) / sizeof(nums[0]);
    int ans[100][10];  // Assuming maximum 100 permutations, each with a maximum size of 10 elements
    int ansIndex = 0;

    permute(nums, n, ans, ansIndex);

    // Print the results
    for (int i = 0; i < ansIndex; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

