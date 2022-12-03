#include<bits/stdc++.h>
using namespace std;
using ruck = pair<unordered_set<char>, unordered_set<char>>;
vector<ruck> getfile(ifstream &file){
  vector<ruck> ret{};
  string line;
  while(getline(file, line)){
    ret.emplace_back();
    for(int i = 0; i < line.size()/2; i++){
      ret.back().first.emplace(line[i]);
    }
    for(int i = line.size()/2; i < line.size(); i++){
      ret.back().second.emplace(line[i]);
    }
  }
  return ret;
}
void getcommon(unordered_set<char> &a, unordered_set<char> &b, unordered_set<char> &res){
  for(auto &item:a){
    if(b.find(item) != b.end()){
      res.emplace(item);
    }
  }
}

int getpriority(char item){
  if(isupper(item)){
    return item-'A'+27;
  }
  return item-'a'+1;
}
size_t part2(vector<ruck> somename){
  size_t res = 0;
  for(size_t i = 0; i < somename.size(); i+=3){
    
    unordered_set<char> possible{};
    getcommon(somename[i].first, somename[i+1].first, possible);
    getcommon(somename[i].first, somename[i+1].second, possible);
    getcommon(somename[i].second, somename[i+1].second, possible);
    getcommon(somename[i].second, somename[i+1].first, possible);
    unordered_set<char> result{};
    getcommon(somename[i+2].first, possible, result);
    getcommon(somename[i+2].first, possible, result);
    getcommon(somename[i+2].second, possible, result);
    getcommon(somename[i+2].second, possible, result);

    res += getpriority(*result.begin());
    
  }
  return res;
}
int main(){
  ifstream infile("input2.txt");
  auto ruckstack = getfile(infile);
  int part2res = part2(ruckstack);
  cout<<part2res<<endl;
}