#include<bits/stdc++.h>
using namespace std;
using Rucksack = std::pair<std::unordered_set<char>, std::unordered_set<char>>;
std::vector<Rucksack> getRucksacks( std::ifstream &file ) {
    std::vector<Rucksack> ret{};
    std::string str;
    while ( std::getline( file, str ) ) {
        ret.emplace_back();
        for(size_t i = 0; i < str.length()/2; i++) {
            ret.back().first.emplace(str[i]);
        }
        for(size_t i = str.length()/2; i < str.length(); i++) {
            ret.back().second.emplace(str[i]);
        }
    }
    return ret;
}

size_t getItemPriority(char item) {
    if(item <= 'Z') {
        return item - 'A' + 27;
    }
    return item - 'a' + 1;
}

size_t getPriorityPart1(const std::vector<Rucksack> &rucksacks) {
    size_t res = 0;
    for(auto &rucksack : rucksacks) {
        for(auto &item : rucksack.first) {
            if(rucksack.second.find(item) != rucksack.second.end()) {
                res += getItemPriority(item);
                break;
            }
        }
    }
    return res;
}
int main(){
  ifstream infile("input1.txt");
  string line;
  //string 1half, 2half;
  
  auto rucks = getRucksacks(infile);
  int ans = getPriorityPart1(rucks);
  cout<<ans<<endl;
  
  
  
  
}