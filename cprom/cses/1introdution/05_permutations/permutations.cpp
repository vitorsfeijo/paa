#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;

  if(n == 1){
    cout << 1;
    return 0;
  }

  if(n < 4){
    cout << "NO SOLUTION";
    return 0;
  }

  vector<long long> A(n);  

  int p = 2;
  int i = 0;

  for(; i < n/2; i++){
    A[i] = p;
    p++;
    p++;
  }

  int o = 1;
  for(; i < n; i++){
    A[i] = o;
    o++;
    o++;
  }

  for(i = 0; i < n; i++){
    cout << A[i] << " ";
  }

  cout << endl;

  return 0;
}