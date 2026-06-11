#include <bits/stdc++>
using namespace std;

struct item{
  int weight;
  int value;
}


int main(){
  int n, weight;
  cin >> n >> weight;

  vector<item> itens(n + 1);
  item temp;
  
  for(int i = 1; i < n; i++){
    cin >> temp.weight >> temp.value;
    itens[i] = temp;
  }

  vector<vector<int>> opt(n, vector<int>(weight, 0));

  //base cases
  //if the weight is zero, zero itens can be carried
  for(int i = 0; i < n; i++){
    opt[i][0] = 0;
  }


  //recursion
  for(int i = 1; i < n; i++){
    for(int w = 0; w < weight; w++){
      //weight of item is bigger than possible(out of bounds check)
      if(itens[i].weight >= w){
        opt[i][w] = opt[i-1][w];
        continue;
      }
      opt[i][w] = max(opt[i-1][w], opt[i-1][w - itens[i].weight] + itens[i].value);
    }
  }

  cout << opt[n][weight] << endl;

}