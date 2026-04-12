#include <bits/stdc++.h>
using namespace std;

int combine_inversions(int i, int m, int j, vector<int> &A){
  vector<int> temp;
  int left = i;
  int right = m + 1;
  int cross_inversions = 0;

  while(left <= m && right <= j){
    if(A[left] <= A[right]){
      temp.push_back(A[left]);
      left++;
    } else {
      temp.push_back(A[right]);
      cross_inversions += (m - left + 1);
      right++;
    }
  }

  while(left <= m ){
    temp.push_back(A[left++]);
  }
  while (right <= j){
    temp.push_back(A[right++]);
  }
  
  for (int k = 0; k < temp.size(); k++) {
    A[i + k] = temp[k];
  }

  return cross_inversions;
}

int count_inversions(int i, int j, vector<int> &A){
  if(i >= j){
    return 0;
  }
  
  int m = (i + j) / 2;
  int inversions = 0;
  inversions += count_inversions(i, m, A);
  inversions += count_inversions(m+1, j, A);
  inversions += combine_inversions(i, m, j, A);

  return inversions;
}

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  int inversions = count_inversions(0, n - 1, A);

  cout << inversions << endl;
  return 0;
}