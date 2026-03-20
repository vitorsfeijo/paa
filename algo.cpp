#include <bits/stdc++.h>
using namespace std;

vector<int> neighbors_nodes(const vector<vector<int>>& graph, int node){
  vector<int> neighbors;

  for(int i = 0; i < graph.size(); i++){
    if(graph[node][i] > 0 || graph[i][node] > 0){
      neighbors.push_back(i);
    }
  }

  return neighbors;
}

bool depth_first_search_to_target_node(const vector<vector<int>>& graph, int start_node, int target_node){
  int graph_size = (int)graph.size();
  stack<int> path;
  set<int> visited;
  path.push(start_node);

  int current_node;

  while(path.size() > 0){
    current_node = path.top();
    path.pop();

    if(current_node == target_node){
      return true;
    }

    // if node is not in visited_nodes:
    if(visited.find(current_node) == visited.end()){
      visited.insert(current_node);
      
      for(int i = 0; i < graph_size; i++){
        if(graph[current_node][i] > 0 && visited.find(i) == visited.end()){
          path.push(i);
        }
      }

    }

  }

  return false;

}

bool depth_first_search_cicle_check(const vector<vector<int>>& graph, int start_node){
  int graph_size = graph.size();
  stack<int> path;
  set<int> visited;
  path.push(start_node);

  int current_node;
  while(path.size() > 0){
    current_node = path.top();
    path.pop();

    // if node is not in visited_nodes:
    auto iterator = visited.find(current_node);
    if(iterator == visited.end()){
      visited.insert(current_node);
      //process node

    }




  }

}

bool breadth_first_search(vector<vector<int>> graph, int start_node, int target_node){
  int graph_size = (int)graph.size();

  vector<int> visited;
  queue<int> queue;
  
  visited.push_back(start_node);
  queue.push(start_node);

  while(!queue.empty()){
    int current_node = queue.front();
    queue.pop();

    for(int v = 0; v <graph_size; v++);
  }
}

vector<vector<int>> dijkstra(vector<vector<int>> graph){

}