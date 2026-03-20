#include <bits/stdc++.h>
using namespace std;


int main(){

  int n_tests;
  cin >> n_tests;

  while(n_tests--){

    int len;
    cin >> len;

    vector<int> arr(len);
    //putting integers in the vector
    int i = 0;
    while(i < len){
      cin >> arr[i];
      i++;
    }

    //solution for each case

    //sort
    sort(arr.begin(), arr.end());

    //counting duplicates
    int duplicates = 0;
    for(int i = 0; i < len - 1; i++){
      if(arr[i] == arr[i + 1]){
        duplicates++;
      }
    }
    
    if(duplicates % 2 == 0){
      cout << len - duplicates << endl;
    }
    else{
      cout << len - (duplicates + 1) << endl;
    }

  }

}