#include <bits/stdc++.h>
using namespace std;

struct Request{
    int money, size, id;
};

bool compare_requests(const Request& a, const Request& b) {
    if (a.money != b.money) return a.money > b.money;
    return a.size < b.size;
}

int main(){

  int n;
  cin >> n;
  vector<Request> requests; //{number of people, money}

  for(int i = 0; i < n; i++){
    Request request;
    cin >> request.size >> request.money;
    request.id = i + 1;
    requests.push_back(request);
  }

  int k;
  cin >> k;
  vector<pair<int, int>> tables;
  for(int i = 0; i < k; i++){
    pair <int, int> table;
    cin >> table.first;
    table.second = i + 1;
    tables.push_back(table);
  }

  sort(requests.begin(), requests.end(), compare_requests);
  sort(tables.begin(), tables.end());

  int attended_requests = 0;
  int total_money = 0;

  //main loop
  for(int i = 0; i < n; i++){
    


  }
  


  return 0;
}