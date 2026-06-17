
/*
A. Chain Reaction
time limit per test2 seconds
memory limit per test256 megabytes
There are n beacons located at distinct positions on a number line. 
The i-th beacon has position ai and power level bi. When the i-th beacon is activated, 
it destroys all beacons to its left (direction of decreasing coordinates) within distance bi inclusive. 
The beacon itself is not destroyed however. 
Saitama will activate the beacons one at a time from right to left. 
If a beacon is destroyed, it cannot be activated.

Saitama wants Genos to add a beacon strictly to the right of all the existing beacons, 
with any position and any power level, such that the least possible number of beacons are destroyed. 
Note that Genos's placement of the beacon means it will be the first beacon activated. 
Help Genos by finding the minimum number of beacons that could be destroyed.

Input
The first line of input contains a single integer n (1 ≤ n ≤ 100 000) — the initial number of beacons.

The i-th of next n lines contains two integers ai and bi (0 ≤ ai ≤ 1 000 000, 1 ≤ bi ≤ 1 000 000) — 
the position and power level of the i-th beacon respectively. No two beacons will have 
the same position, so ai ≠ aj if i ≠ j.

Output
Print a single integer — the minimum number of beacons that could be destroyed if exactly 
one beacon is added.
*/


#include <bits/stdc++.h>
using namespace std;

typedef struct{
  int pos; 
  int power;
} beacon; 

bool beacon_sort(const beacon& first, const beacon& second){
  return first.pos < second.pos; 
}


int main(){
  int n;
  cin >> n;
  
  vector<beacon> beacons(n);
  beacon temp;

  for(int i = 0; i < n; i++){
    cin >> temp.pos >> temp.power;
    beacons[i] = temp;
  }

  //sorting beacons
  sort(beacons.begin(), beacons.end(), beacon_sort);

  //make a list of the compatible beacons
  vector<int> com_beacons(n, -1);

  com_beacons[0] = 0;

  for(int i = 0; i < n; i++){
    // Target position we want to find (>= this value)
    beacon target;
    target.pos = beacons[i].pos - beacons[i].power;

    // Search only in the range before the current beacon i
    auto it = lower_bound(beacons.begin(), beacons.begin() + i, target, beacon_sort);

    // Get the index of the first beacon that is NOT destroyed
    int idx = it - beacons.begin();

    if(idx > 0){
      com_beacons[i] = idx - 1;
    }
  }

  vector<int> dp(n);
  int max_saved = 0;

  for(int i = 0; i < n; i++){
    if(com_beacons[i] != -1){
      dp[i] = 1 + dp[com_beacons[i]];
    } else {
      dp[i] = 1;
    }
    max_saved = max(max_saved, dp[i]);
  }
  
  cout << n - max_saved;


  return 0;
}