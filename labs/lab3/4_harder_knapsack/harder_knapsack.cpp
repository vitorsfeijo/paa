#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct gem {
  long long value;
  long long beauty;
};

bool sortgems(const gem first, const gem second){
  return first.value < second.value;
}

int main() {
  int n, money, free;
  cin >> n >> money >> free;

  vector<gem> gems(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> gems[i].value >> gems[i].beauty;
  }

  sort(gems.begin() + 1, gems.end(), sortgems);

  vector<vector<long long>> dp(n + 1, vector<long long>(money + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int m = 0; m <= money; m++) {
      dp[i][m] = dp[i-1][m];
      if (m >= gems[i].value) {
        dp[i][m] = max(dp[i][m], dp[i-1][m - gems[i].value] + gems[i].beauty);
      }
    }
  }

  priority_queue<long long, vector<long long>, greater<long long>> min_heap;
  long long sum_free = 0;
  long long ans = 0;

  for (int m = n; m >= 0; m--) {
      ans = max(ans, dp[m][money] + sum_free);

      if (m > 0 && free > 0) {
          min_heap.push(gems[m].beauty);
          sum_free += gems[m].beauty;
          if (min_heap.size() > (size_t)free) {
              sum_free -= min_heap.top();
              min_heap.pop();
          }
      }
  }

  cout << ans << "\n";

  return 0;
}
