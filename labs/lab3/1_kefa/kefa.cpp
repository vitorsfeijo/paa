#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin >> n;
  vector<int> money(n);
  for(int i = 0; i < n; i++){
    cin >> money[i];
  }

  vector<int> dp(n);

  for(int i = 0; i < n; i++){
    if(i == 0){
      dp[i] = 1;
    } else if(money[i-1] <= money[i]){
      dp[i] = dp[i-1] + 1;
    } else {
      dp[i] = 1;
    } 
  }

  int max = 0;

  for(int i = 0; i < n; i++){
    if(max < dp[i]){
      max = dp[i];
    }
  }

  cout << max << endl;

  return 0;
}