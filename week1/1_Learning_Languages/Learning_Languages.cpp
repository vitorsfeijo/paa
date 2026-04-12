/*
The "BerCorp" company has got n employees. 
These employees can use m approved official languages for the formal correspondence. 
The languages are numbered with integers from 1 to m. For each employee we have the list of languages, which he knows. 
This list could be empty, i. e. an employee may know no official languages. But the employees are willing to learn any number of official languages, as long as the company pays their lessons.
A study course in one language for one employee costs 1 berdollar.

Find the minimum sum of money the company needs to spend so as any employee could correspond to any other one 
(their correspondence can be indirect, i. e. other employees can help out translating).

Input
The first line contains two integers n and m (2 ≤ n, m ≤ 100) — the number of employees and the number of languages.

Then n lines follow — each employee's language list.
At the beginning of the i-th line is integer ki (0 ≤ ki ≤ m) — the number of languages the i-th employee knows.
Next, the i-th line contains ki integers — aij (1 ≤ aij ≤ m) — the identifiers of languages the i-th employee knows. 
It is guaranteed that all the identifiers in one list are distinct. 
Note that an employee may know zero languages.

The numbers in the lines are separated by single spaces.

Output
Print a single integer — the minimum amount of money to pay so that in the end every employee 
could write a letter to every other one (other employees can help out translating).

*/

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