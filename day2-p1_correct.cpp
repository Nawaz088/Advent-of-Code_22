#include<bits/stdc++.h>
using namespace std;

int main(){
  ifstream infile("input2.txt");
  string line;
  int total = 0;
  while(getline(infile, line)){
    const char *data = line.data();
    const char them = data[0]-'A'+1;
    const char me = data[2]-'X'+1;

    bool win = (me-them+3)%3 == 1;
    bool draw = me == them;

    
    total += me+(win?6:(draw?3:0));
  }
  cout<<total<<endl;
}