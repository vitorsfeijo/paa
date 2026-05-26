/*
Um par (ai , aj ) apresenta uma invers˜ao forte se i < j e ai > 2 · aj . Para um vetor de n n´umeros
⟨a1, a2, . . . , an⟩. Apresente um algoritmo O(n log n) que conta o n´umero de invers˜oes fortes no vetor.
*/

#include <bits/stdc++.h>
using namespace std;


int combine_hard_inversions(int i, int m, int j, vector<int>& A){
  int inversions = 0;
  vector<int> temp;
  

  //inversions counting
  int left = i;
  int right = m + 1;
  while(left <= m && right <= j){
    if(A[left] > 2 * A[right]){
      inversions += (m - left + 1);
      right++;
    } else {
      left++;
    }
  }

  //ordering the subvector
  int left = i;
  int right = m + 1;
  while(left <= m && right <= j){
    if(A[left] > A[right]){
      temp.push_back(A[right++]);
    } else {
      temp.push_back(A[left++]);
    }
  }
  
  while(left <= m){
    temp.push_back(A[left++]);
  }
  while(right <= j){
    temp.push_back(A[right++]);
  }


  for(int k = i; k < j + 1; k++){
    A[k] = temp[k - i];
  }

  return inversions;
}

int count_hard_inversions(int i, int j, vector<int>& A){
  if(i >= j){
    return 0;
  }
  if(i == j + 1){
    if(A[i] > 2 * A[j]){
      swap(A[i], A[j]);
      return 1;
    }
  }
  
  int m = (i + j) / 2;
  int inversions = 0;
  inversions += count_hard_inversions(i, m, A);
  inversions += count_hard_inversions(m + 1, j, A);
  inversions += combine_hard_inversions(i, m, j, A);

  return inversions;
}

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  int total = count_hard_inversions(0, n - 1, A);

  cout << total << endl;
}