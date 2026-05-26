#include <bits/stdc++.h>
using namespace std;


void xor_strategy(){
  long long n;
  cin >> n;
  long long xored = 0;

  for(int i = 1; i < n + 1; i++){
    xored = xored ^ i;
  }

  for(int i = 0; i < n - 1; i++){
    int m;
    cin >> m;
    xored = xored ^ m;
  }

  cout << xored;

}

void normal(){
  long long n;
  cin >> n;
  vector<long long> nv(n);

}

int main(){
  xor_strategy();
}