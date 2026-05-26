#include <bits/stdc++.h>
using namespace std;


long long bit[1000005];
int MAX_VAL = 1000001; 

void update(int idx, int val) {
  for (; idx < MAX_VAL; idx += idx & -idx)
    bit[idx] += val;
}

long long query(int idx) {
  long long sum = 0;
  for (; idx > 0; idx -= idx & -idx)
    sum += bit[idx];
  return sum;
}

int main(){
  long long n;
  cin >> n;
  vector<long long> A(n);
  vector<long long> temp(n);
  
  for(long long i = 0; i < n; i++){
    cin >> A[i];
    temp[i] = A[i];
  }

  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());

  for(long long i = 0; i < n; i++){
    A[i] = lower_bound(temp.begin(), temp.end(), A[i]) - temp.begin() + 1;
  }

  vector<long long> cnt(n + 1, 0);

  vector<long long> L(n);
  vector<long long> R(n);


  for (long long i = 0; i < n; i++) {
    cnt[A[i]]++;
    L[i] = cnt[A[i]];
  }

  fill(cnt.begin(), cnt.end(), 0);

  
  for (long long i = n - 1; i >= 0; i--) {
    cnt[A[i]]++;
    R[i] = cnt[A[i]];
  }

  long long total_pairs = 0;

  
  for (long long j = 0; j < n; j++) {
      update(R[j], 1);
  }

  
  for (long long i = 0; i < n; i++) {
      update(R[i], -1);

      total_pairs += query(L[i] - 1);
  }

  cout << total_pairs << endl;


}