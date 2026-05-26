#include <bits/stdc++.h>
using namespace std;

int main(){
  string m;
  cin >> m;
  long long max = 0;
  long long cur_max = 1;

  if(m.length() == 1){
    cout << "1";
    return 0;
  }

  for(long long i = 0; i < m.length() - 1; i++){
    if(m[i] == m[i + 1]){
      cur_max++;
    }
    if(m[i] != m[i + 1]){
      cur_max = 1;
    }
    if(cur_max > max){
      max = cur_max;
    }
    
  }

  cout << max;

  
}