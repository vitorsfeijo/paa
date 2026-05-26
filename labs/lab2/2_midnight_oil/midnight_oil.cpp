#include <bits/stdc++.h>
using namespace std;

int soma(int mid, int k){
  int resultado = 0;
  int atual = mid;

  while(atual > 0){
    resultado += atual;
    atual /= k;
  }

  return resultado;
}

int itbsearch(int low, int high, int n, int k){
  int resultado = high;

  while(low <= high){
    int mid = (low + high) / 2;
    int sum = soma(mid, k);

    if(sum >= n){
      resultado = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return resultado;
}

int main(){
  int n, k;
  cin >> n >> k;

  int resultado = itbsearch(1, n, n, k);

  cout << resultado;

  return 0;  
}