#include <bits/stdc++.h>
using namespace std;

typedef struct {
  long long x;
  long long y;
} point;

long long find_group(point p){
  return max(p.x, p.y);
}

long long find_value(point p){
  long long gp = find_group(p);
  long long value = (gp - 1) * (gp - 1);
  value++;
  

  point ip;
  if(gp % 2 == 1){
    ip.x = 1;
    ip.y = gp;
    long long dif = 0;
    dif += p.x - ip.x;
    dif += ip.y - p.y;
    value += dif;
    return value;
  } else {
    ip.x = gp;
    ip.y = 1;
    long long dif = 0;
    dif += ip.x - p.x;
    dif += p.y - ip.y;
    value += dif;
    return value;
  }

  return 0;
}



int main(){
  int n;
  cin >> n;
  
  vector<point> A(n);

  for(int i = 0; i < n; i++){
    cin >> A[i].y;
    cin >> A[i].x;
  }

  for(int i = 0; i < n; i++){
    long long value = find_value(A[i]);
    cout << value << endl;
  }

  return 0;
}