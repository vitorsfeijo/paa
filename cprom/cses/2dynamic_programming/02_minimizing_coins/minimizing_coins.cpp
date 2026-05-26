#include <bits/stdc++.h>
#define MAXINT 1e9
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;

  vector<long long> coins(n);
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }

  vector<long long> dp(x + 1, MAXINT);

  dp[0] = 0;

  for(int i = 1; i <= x; i++){
     for(long long coin : coins){
      if(i - coin >= 0){
        if(dp[i - coin] + 1 < dp[i]){
          dp[i] = dp[i - coin] + 1;
        }
      }
     }
  }

  if(dp[x] == MAXINT) cout << -1 << endl;
  else cout << dp[x] << endl;

  return 0;
}