#include <iostream>
#include <vector>
using namespace std;

void print_combinations(vector<int>& arr, vector<int>& chosen, int start, int n, int k) {
    // base case: we have selected k elements, so print the chosen combination
    if (chosen.size() == k) {
        for (int num : chosen) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // recursive case: choose the next element to include in the combination
    for (int i = start; i < n; i++) {
        chosen.push_back(arr[i]);
        print_combinations(arr, chosen, i + 1, n, k); // try all combinations with the current element included
        chosen.pop_back(); // backtrack by removing the current element from the combination
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    vector<int> chosen;
    int k = 2;

    print_combinations(arr, chosen, 0, arr.size(), k);

    return 0;
}