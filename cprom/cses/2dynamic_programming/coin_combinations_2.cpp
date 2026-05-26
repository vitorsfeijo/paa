#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;

  vector<long long> coins(n);
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  } 

  vector<long long> dp(x + 1, 0);
  dp[0] = 1;

  

  cout << dp[x] << endl;

  return 0;
}