/*
Sho has an array a consisting of nintegers. 
An operation consists of choosing two distinct indices i and j and removing ai and aj from the array.

For example, for the array [2,3,4,2,5], Sho can choose to remove indices 1 and 3. 
After this operation, the array becomes [3,2,5]. 
Note that after any operation, the length of the array is reduced by two.

After he made some operations, Sho has an array that has only distinct elements. 
In addition, he made operations such that the resulting array is the longest possible.

More formally, the array after Sho has made his operations respects these criteria:

No pairs such that (i<j) and ai=aj exist.
The length of a is maximized.
Output the length of the final array.

Input
The first line contains a single integer t (1≤t≤103) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤50) — the length of the array.

The second line of each test case contains n integers ai (1≤ai≤104) — the elements of the array.

Output
For each test case, output a single integer — the length of the final array. 
Remember that in the final array, all elements are different, and its length is maximum.
*/


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