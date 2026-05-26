#include <bits/stdc++.h>
using namespace std;

void calc_horse(long long k){
  if (k < 1){
    return;
  }
  if (k == 1){
    cout << 0 << endl;
    return;
  }

  long long t = ((k * k) * ((k * k) - 1)) / 2;
  long long a = 4 * (k - 1) * (k - 2);
  long long value = t - a;
  cout << value << endl;
}

int main(){
  long long n;
  cin >> n;

  for(long long i = 0; i < n + 1; i++){
    calc_horse(i);
  }

}