#include <bits/stdc++.h>
using namespace std;

// The "Merge" step: counts inversions between the two sorted halves
long long combine_inversions(int i, int m, int j, vector<int> &A) {
    vector<int> temp;
    int left = i;
    int right = m + 1;
    long long cross_inversions = 0;

    while (left <= m && right <= j) {
        if (A[left] <= A[right]) {
            temp.push_back(A[left]);
            left++;
        } else {
            // A[left] > A[right], so every element from A[left] to A[m] 
            // forms an inversion with A[right]
            temp.push_back(A[right]);
            cross_inversions += (m - left + 1);
            right++;
        }
    }

    // Clean up remaining elements
    while (left <= m) temp.push_back(A[left++]);
    while (right <= j) temp.push_back(A[right++]);

    // Copy sorted elements back to original array
    for (int k = 0; k < temp.size(); k++) {
        A[i + k] = temp[k];
    }

    return cross_inversions;
}

long long count_inversions(int i, int j, vector<int> &A) {
    if (i >= j) {
        return 0;
    }

    int m = i + (j - i) / 2;
    long long inversions = 0;

    inversions += count_inversions(i, m, A);
    inversions += count_inversions(m + 1, j, A);
    inversions += combine_inversions(i, m, j, A);

    return inversions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Using long long because inversions can exceed INT_MAX for large N
    // Max inversions for N elements is N*(N-1)/2
    long long total_inversions = count_inversions(0, n - 1, A);

    cout << total_inversions << endl;
    return 0;
}