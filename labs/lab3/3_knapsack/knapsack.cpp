#include <bits/stdc++.h>
using namespace std;

struct item {
  int weight;
  int value;
};


int main(){
  int n, weight;
  cin >> n >> weight;

  vector<item> itens(n + 1);
  item temp;
  
  for(int i = 1; i < n + 1; i++){
    cin >> temp.weight >> temp.value;
    itens[i] = temp;
  }

  vector<vector<int>> opt(n+1, vector<int>(weight+1, 0));


  //recursion
  for(int i = 1; i <= n; i++){
  for(int w = 1; w <= weight; w++){
      //weight of item is bigger than possible(out of bounds check)
      if(itens[i].weight > w){
        opt[i][w] = opt[i-1][w];
        continue;
      }
      opt[i][w] = max(opt[i-1][w], opt[i-1][w - itens[i].weight] + itens[i].value);
    }
  }

  cout << opt[n][weight] << endl;

}