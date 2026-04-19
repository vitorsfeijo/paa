/*
Questão 2. Dado um vetor ordenado A de n inteiros distintos (positivos, negativos ou zero), apresente um algoritmo por
divisão e conquista que retorna um ı́ndice i tal que A[i] = i, se tal ı́ndice existir. Se não existir tal ı́ndice, o algoritmo deve
retornar −1 (considere indexação baseada em 1, ou seja, 1 ≤ i ≤ n). Seu algoritmo deve ter custo O(log n).
Exemplo 1: se A = [−3, −1, 3, 5, 8], a resposta deve ser 3, pois A[3] = 3.
Exemplo 2: se A = [−4, −1, 0, 2, 7], a resposta deve ser −1.
*/

#include <bits/stdc++.h>
using namespace std;

int find_index(int left, int right, vector<int>& A){
  if(left > right){
    return -1;
  }

  int m = (left + right) / 2;
  if(A[m] == m){
    return m;
  } else if(A[m] > m){
    return find_index(left, m -1, A);
  } else {
    return find_index(m + 1, right, A);
  }
}


int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  int index = find_index(0, size(A) - 1, A);

  cout << index + 1 << endl;
  return 0;
}