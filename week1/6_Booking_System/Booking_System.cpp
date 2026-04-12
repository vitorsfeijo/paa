/*
Innovation technologies are on a victorious march around the planet. 
They integrate into all spheres of human activity!

A restaurant called "Dijkstra's Place" has started thinking about optimizing the booking system.

There are n booking requests received by now. Each request is characterized by two numbers: 
ci and pi — the size of the group of visitors who will come via this request and the total sum of money 
they will spend in the restaurant, correspondingly.

We know that for each request, all ci people want to sit at the same table and are going to spend the whole evening 
in the restaurant, from the opening moment at 18:00 to the closing moment.

Unfortunately, there only are k tables in the restaurant. For each table, we know ri — the maximum number of people 
who can sit at it. A table can have only people from the same group sitting at it. If you cannot find a large enough table for the whole group, then all visitors leave and naturally, pay nothing.

Your task is: given the tables and the requests, decide which requests to accept and which requests to decline so that 
the money paid by the happy and full visitors was maximum.

Input
The first line of the input contains integer n (1 ≤ n ≤ 1000) — the number of requests from visitors. Then n lines follow. 
Each line contains two integers: ci, pi (1 ≤ ci, pi ≤ 1000) — the size of the group of visitors who will come 
by the i-th request and the total sum of money they will pay when they visit the restaurant, correspondingly.

The next line contains integer k (1 ≤ k ≤ 1000) — the number of tables in the restaurant. 
The last line contains k space-separated integers: r1, r2, ..., rk (1 ≤ ri ≤ 1000) — the maximum number of 
people that can sit at each table.

Output
In the first line print two integers: m, s — the number of accepted requests and the total money you get from these requests, 
correspondingly.

Then print m lines — each line must contain two space-separated integers: the number of the accepted request 
and the number of the table to seat people who come via this request. The requests and the tables are consecutively 
numbered starting from 1 in the order in which they are given in the input.

If there are multiple optimal answers, print any of them.

*/

#include <bits/stdc++.h>
using namespace std;

struct Request{
  int money, size, id;
};

bool compare_requests(const Request& a, const Request& b) {
  if (a.money != b.money){
    return a.money > b.money;
  }else {
    return a.size < b.size;
  }
}

int main(){

  int n;
  cin >> n;
  vector<Request> requests; //{money, number of people, original index}

  for(int i = 0; i < n; i++){
    Request request;
    cin >> request.size >> request.money;
    request.id = i + 1;
    requests.push_back(request);
  }

  int k;
  cin >> k;
  vector<pair<int, int>> tables; // {number of people, original index}

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
  vector<pair<int, int>> assignments;
  vector<bool> table_used(k, false);

  //main loop
  for(int i = 0; i < n; i++){ //iterating through requests
    
    for(int j = 0; j < k; j++){ //iterating through tables
      if(requests[i].size <= tables[j].first && !table_used[j]){
        attended_requests++;
        total_money = total_money + requests[i].money;
        assignments.push_back({requests[i].id, tables[j].second});
        table_used[j] = true;
        break;
      }
    }
  }

  cout << attended_requests << " " << total_money << endl;
  for(int i = 0; i < attended_requests; i++){
    cout << assignments[i].first << " " << assignments[i].second << endl;
  }

  return 0;
}