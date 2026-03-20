#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> potions(n);

  for(int i = 0; i < n; i++){
    cin >> potions[i];
  }

  //inverse prio queue
  priority_queue<long long,vector<long long>,greater<long long>> potions_drank;

  long long health = 0;
  for(int i = 0; i < n; i++){
    health += potions[i];
    potions_drank.push(potions[i]);

    if(health < 0){
      health -= potions_drank.top();
      potions_drank.pop();
    }
  }

  cout << potions_drank.size() << endl;
}