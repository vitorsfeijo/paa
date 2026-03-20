#include <bits/stdc++.h>
using namespace std;

void Djikstra(const vector<vector<int>>& graph, vector<int> shortest_path, int start_node, int end_node){

}

int main(){

  int nodes, edges;
  cin >> nodes >> edges;

  vector<vector<int>> graph(nodes + 1, vector<int>(edges + 1, 0));

  //getting edges
  for(int i = 0; i < edges; i++){
    int start, end, value;
    cin >> start >> end >> value;

    graph[start][end] == value;
  }

  vector<int> shortest_path;

  Djikstra(graph, shortest_path, 1, nodes);

  
  return 0;


}