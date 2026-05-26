#include <bits/stdc++.h>
using namespace std;

long long solve(int l, int r, long long h, vector<long long> &A) {
  if(l > r){
    return 0;
  }
  
  int m = l;
  for(int i = l + 1; i <= r; i++){
    if(A[i] < A[m]){
      m = i;
    } 
  }

  long long vertical = r - l + 1;

  long long horizontal = (A[m] - h) + solve(l, m - 1, A[m], A) + solve(m + 1, r, A[m], A);

  return min(vertical, horizontal);
}

int main(){
  int n;
  cin >> n;
  vector<long long> A(n); 

  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  long long strokes = solve(0, n - 1, 0, A);

  cout << strokes << endl;

  return 0;
}