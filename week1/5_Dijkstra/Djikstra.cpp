/*
You are given a weighted undirected graph. 
The vertices are enumerated from 1 to n. 
Your task is to find the shortest path between the vertex 1 and the vertex n.

Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), 
where n is the number of vertices and m is the number of edges. 
Following m lines contain one edge each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106), 
where ai, bi are edge endpoints and wi is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case. 
If there are many solutions, print any of them.
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1e18

int main(){

  int nodes, edges;
  cin >> nodes >> edges;

  vector<vector<pair<int, int>>> adj(nodes + 1);

  for(int i = 0; i < edges; i++){
    int start, end, value;
    cin >> start >> end >> value;

    adj[start].push_back({end, value});
    adj[end].push_back({start, value});
  }

  vector<long long> distance(nodes + 1, INF);
  vector<int> parent(nodes + 1, -1);
  //Min prio queueu -> stores {distance, node}
  priority_queue<pair<long long, int>, vector <pair<long long, int>>, greater<pair<long long, int>>> prio;

  distance[1] = 0;
  prio.push({0, 1});

  while (!prio.empty()){
    long long dist = prio.top().first;
    int node = prio.top().second;
    prio.pop();

    if(dist > distance[node]){
      continue;
    }

    for(pair<int, int>& edge : adj[node]){
      int edge_node = edge.first;
      int weight = edge.second;

      if(distance[node] + weight < distance[edge_node]){
        distance[edge_node] = distance[node] + weight;
        parent[edge_node] = node;
        prio.push({distance[edge_node], edge_node});
      }
    }
  }
  
  if(distance[nodes] == INF){
      cout << -1;
  } 
  else{
    vector<int> path;
    for(int vertice = nodes; vertice != -1; vertice = parent[vertice]){
      path.push_back(vertice);
    }

    reverse(path.begin(), path.end());

    for(int i = 0; i < path.size(); i++){
      cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
  }

  return 0;
}