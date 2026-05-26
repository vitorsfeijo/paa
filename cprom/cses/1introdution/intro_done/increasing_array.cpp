#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;

  vector<long long> A(n);
  for(long long i = 0; i < n; i++){
    cin >> A[i];
  }

  long long m = 0, j = 0;
  for(int i = 0; i < n - 1; i++){
    j = i + 1;
    if(A[i] > A[j]){
      int dif = 0;
      dif = abs(A[i] - A[j]);
      m += dif;
      A[j] += dif;
    }
  }

  cout << m << endl;

  return 0;
}