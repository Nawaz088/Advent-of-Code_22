#include<bits/stdc++.h>
using namespace std;

int main(){
  ifstream infile("input2.txt");
  string line;
  int total = 0;
  while(getline(infile, line)){
    const char *data = line.data();
    const char them = data[0]-'A'+1;
    const char inst = data[2];

    bool win = inst == 'Z';
    bool draw = inst == 'Y';

    char me = draw ? them : (win ? (them + 1)%3 : (them + 2)%3);

    if(me == 0){
      me = 3;
    }
    total += me+(win?6:(draw?3:0));
  }
  cout<<total<<endl;
}