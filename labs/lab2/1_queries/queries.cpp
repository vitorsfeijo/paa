#include <bits/stdc++.h>
using namespace std;

int bsearch(vector<int>& A, int i, int j, int b);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;
  vector<int> A(a), B(b);
  for(int i = 0; i < a; i++){
    cin >> A[i];
  }
  for(int i = 0; i < b; i++){
    cin >> B[i];
  }

  sort(A.begin(), A.end());

  for(int i = 0; i < b; i++){
    int result = bsearch(A, 0, A.size() - 1, B[i]);
    cout << " " << result + 1;
  }

  return 0;
}

int bsearch(vector<int>& A, int i, int j, int b){

  if(i > j){
    return -1;
  }

  int m = (i + j) / 2;

  if(A[m] <= b){
    int result = bsearch(A, m + 1, j, b);

    if(result == -1){
      return m;
    } else {
      return result;
    }
  } else {
    return bsearch(A, i, m - 1, b);
  }

}