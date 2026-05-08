#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int s;
  int e;
  int w;
} interval;

vector<int> scheduling(vector<interval> &I);
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

  scheduling(I);


  for(int i = 0; i < size(I); i++){
    print_interval(I[i]);
  }

  return 0;
}

vector<int> scheduling(vector<interval> &I){
  int n = size(I);

  sort(I.begin(), I.end(), interval_sort);

  vector<int> P(n);

  for(int i = 0; i < n; i++){
    if(I[0].e >= I[i].s){
      P[i] = 0;
    } 
    for(int j = i - 1; j > 0; j--){
      
    }

  }
  


}

void print_interval(interval i){
  cout << "start: " << i.s;
  cout << " end: " << i.e;
  cout << " weight: " << i.w << endl;
}

bool interval_sort(const interval &a, const interval &b){
  return a.e < b.e;
}