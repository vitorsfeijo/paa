#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<long long> dp(n + 1, 0);

  dp[0] = 1;

  for(int i = 1; i <= n;i++){
    for(long long die = 1; die <= 6; die++){
      if(i - die >= 0){
        dp[i] += dp[i - die];
      }
    }
  }

  cout << dp[n] << endl;

  return 0;
}