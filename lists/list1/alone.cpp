/*
Considere um vetor ordenado A de tamanho n com n ́umeros inteiros positivos. Nesse vetor todos os
valores aparecem duas vezes com exce ̧c ̃ao de um  ́unico valor que aparece apenas uma vez. Apresente
um algoritmo o(n) que encontra o valor que aparece uma  ́unica vez.
*/

#include <bits/stdc++.h>
using namespace std;

int find_element_alone(int left, int right, vector<int>& A){
  if(left == right){
    return A[left];
  }

  int m = (left + right) / 2;

  if (m % 2 != 0) {
        m--;
  }

  if(A[m] == A[m + 1]){
    return find_element_alone(m + 2, right, A);
  } else {
    return find_element_alone(left, m, A);
  }

}

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  int alone = find_element_alone(0, size(A) - 1, A);

  cout << alone << endl;
}