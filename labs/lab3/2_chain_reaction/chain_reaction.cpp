#include <bits/stdc++.h>
using namespace std;

typedef struct{
  int pos; 
  int power;
} beacon; 

int main(){
  int n;
  cin >> n;
  
  vector<beacon> beacons(n);
  beacon temp;

  for(int i = 0; i < n; i++){
    cin >> temp.pos >> temp.power;
    beacons[i] = temp;
  }

  //make a list of the compatible beacons
  vector<beacons> com_beacons(n);

  com_beacons[0] = 0;

  for(int i = 1; i < n; i++){
    int power = beacons[i].power;
    int position = beacons[i].pos;
    


  }

  



  return 0;
}