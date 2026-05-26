#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int s;
  int e;
  int w;
} interval;

int scheduling(vector<interval> &I);
void print_interval(interval i);
bool interval_sort(const interval &a, const interval &b);



int main(){
  int n;
  cin >> n;

  vector<interval> I;
  while(n--){
    interval temp;
    cin >> temp.s;
    cin >> temp.e;
    cin >> temp.w;
    I.push_back(temp);
  }

  sort(I.begin(), I.end(), interval_sort);

  vector<int> P(n, 0);

  for(int i = 0; i < n; i++){
    P[i] = -1;
    for(int j = i - 1; j > 0; j--){
      if(I[j].e <= I[i].s){
        P[i] = i;
        break;
      }
    }
  }

  int value = scheduling(I, P);


  for(int i = 0; i < size(I); i++){
    print_interval(I[i]);
  }

  return 0;
}

int scheduling(vector<interval> &I, vector<int> &P){
  int n = size(I) - 1;

  vector<int> opt(n, 0);

  for(int i = 0; i < n; i++){
    if(i == 0){
      opt[i] = I[i].w;
    } else {
      opt[i] = max(I[i].w + opt[P[i]],opt[i - 1]);
    }
  }

  return opt[n];
}

void print_interval(interval i){
  cout << "start: " << i.s;
  cout << " end: " << i.e;
  cout << " weight: " << i.w << endl;
}

bool interval_sort(const interval &a, const interval &b){
  return a.e < b.e;
}