#include <bits/stdc++.h>
using namespace std;

int upper_bound(int i, int j, int k, vector<int>& A){
  if(i > j){
    return -1;
  }

  int m = (i + j) / 2;
  int index1, index2;
  if(A[m] == k){
    index1 = m;
    index2 = upper_bound(m + 1, j, k, A);
    return max(index1, index2);
  }
  if(A[m] > k){
    return upper_bound(i, m - 1, k, A);
  } else {
    return upper_bound(m + 1, j, k, A);
  }
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  int last_appeared_k_index =  upper_bound(0, n - 1, k, A);

  cout << last_appeared_k_index << endl;

}