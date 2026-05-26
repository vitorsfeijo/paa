/*
Dado uma sequˆencia de n ́umeros inteiros distintos (sem n ́umeros repetidos) A = ⟨a1, a2, . . . , an⟩, um
n ́umero ai com i ∈ {2, . . . , n −1}  ́e um blip se ai−1 < ai > ai+1, i.e. ai  ́e maior que ai−1 e ai+1, o
n ́umero a1  ́e um blip se a1 > a2 e o n ́umero an  ́e um blip se an > an−1. Encontre um blip em um vetor
de tamanho n. Apresente um algoritmo que resolve o problema em tempo O(log n).
*/

#include <bits/stdc++.h>
using namespace std;

int find_blip(int left, int right, vector<int>& A){

  if(left == right){
    return left;
  }

  int m = (left + right) / 2;
  if(A[m] > A[m + 1]){
    return find_blip(left, m, A);
  } else {
    return find_blip(m + 1, right, A);
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  int blip = find_blip(0, n - 1, A);

  cout << blip << endl;
}