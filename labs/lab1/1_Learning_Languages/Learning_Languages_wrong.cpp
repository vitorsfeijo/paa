#include <bits/stdc++.h>
using namespace std;

bool is_graph_empty(const vector<vector<int>>& graph, int employees, int languages){

  for(int i = 0; i < employees; i++){
    for(int j = 0; j < languages; j++){
      if(graph[i][j] == 1){
        return false;
      }
    }
  }

  return true;
}

vector<int> neighbors_nodes(const vector<vector<int>>& graph, vector<int>& neighbors, int node){
  vector<int> neighbors;

  for(int i = 0; i < graph.size(); i++){
    if(graph[node][i] > 0 || graph[i][node] > 0){
      neighbors.push_back(i);
    }
  }

  return neighbors;
}

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int start_node){
  stack<int> path;
  path.push(start_node);
  visited[start_node] = true;

  vector<int> neighbors;

  while(!path.empty()){
    int current_node = path.top();
    path.pop();

    neighbors_nodes(graph, neighbors, current_node);

    for (int neighbor : neighbors) {
      if (visited[neighbor] == false){
        visited[neighbor] = true;
        path.push(neighbor);
      }
    }
  }
}

int main(){

  int employees, languages;

  cin >> employees >> languages;

  vector<vector<int>> graph(employees, vector<int>(languages, 0));

  int n_language, language;

  for(int employee = 0; employee < employees; employee++){
    cin >> n_language;
    for(int i = 0; i < n_language; i++){
      cin >> language;
      language--;
      graph[employee][language] = 1;
    }
  }

  // if graph is empty -> return employees
  if(is_graph_empty(graph, employees, languages) == true){
    cout << employees;
  }

  //test how many connected graphs there is -> return connected graphs - 1

  int connected_graphs_count = 0;

  vector<bool> visited(employees);
  for(int i = 0; i < visited.size(); i++){
    if(visited[i] == 0){
      dfs(graph, visited, visited[i]);
      connected_graphs_count++;
    }
  }

  cout << connected_graphs_count - 1;

  return 0;
}