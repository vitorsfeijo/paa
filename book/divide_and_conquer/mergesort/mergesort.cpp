#include <bits/stdc++.h>
using namespace std;

void combine(vector<int> list, int start, int mid, int end){
  int a = start;
  int b = mid + 1;

  for()
  
}

void mergesort(vector<int> list, int start, int end){
  //one element
  if(start >= end){ 
    return;
  }

  int middle = (start + end) / 2; //rounds down
  
  mergesort(list, start, middle);
  mergesort(list, middle + 1, end);
  combine(list, start, middle, end);
  return;
}

int main(){
  int n;
  cin >> n;

  vector<int> list(n);
  for(int i = 0; i < n; i++){
    cin >> list[i];
  }

  mergesort(list[i], list.begin(), list.end());

  for(int i = 0; i < n; i++){
    cout << list[i] << " ";
  }
  cout << endl;

  return 0;
}