#include <bits/stdc++.h>
using namespace std;


void dfs(int start_node, const vector<vector<int>>& adj, vector<bool>& visited) {
  stack<int> s;
  s.push(start_node);
  visited[start_node] = true;

  while (!s.empty()) {
    int current = s.top();
    s.pop();

    for (int neighbor : adj[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        s.push(neighbor);
      }
    }
  }
}

int main() {
  int n_employees, m_languages;
  cin >> n_employees >> m_languages;

  vector<vector<int>> adj(n_employees + m_languages + 1);
  bool any_language_known = false;

  for (int i = 1; i <= n_employees; i++) {
    int count;
    cin >> count;

    if (count > 0){
      any_language_known = true;
    }

    for (int j = 0; j < count; j++) {
      int language_id;
      cin >> language_id;
      int language_node = n_employees + language_id;
      adj[i].push_back(language_node);
      adj[language_node].push_back(i);
    }
  }

  if (!any_language_known) {
    cout << n_employees;
    return 0;
  }

  int connected_components = 0;
  vector<bool> visited(n_employees + m_languages + 1, false);

  for (int i = 1; i <= n_employees; i++) {
    if (!visited[i]) {
      connected_components++;
      dfs(i, adj, visited);
    }
  }

  cout << connected_components - 1 << endl;

  return 0;
}