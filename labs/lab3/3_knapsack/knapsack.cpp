#include <bits/stdc++>
using namespace std;

struct item{
  int weight;
  int value;
}


int main(){
  int n, weight;
  cin >> n >> weight;

  vector<item> itens(n);
  item temp;
  
  for(int i = 0; i < n; i++){
    cin >> temp.weight >> temp.value;
    itens[i] = temp;
  }

  vector<vector<int>> opt(weight, vector<int>(n, 0));

  for(int w = 0; w < weight; w++){
    for(int i = 0; i < n; i++){
      
    }
  }


}