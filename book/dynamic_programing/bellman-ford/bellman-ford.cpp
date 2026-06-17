#include <bits/stdc++.h>
using namespace std;

int main(){

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n); //neighboor and weight
  for(int i = 0; i < m; i++){
    int vertex, neighboor, weight;
    cin >> vertex >> neighboor >> weight;
    adj[vertex].push_back({neighboor, weight});
  }




}

