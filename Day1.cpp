#include <bits/stdc++.h>
using namespace std;

int main() {
  //read the file
	std::ifstream file("input1.txt");
	std::string line;

	int current = 0;
  vector<int> res;
	while(std::getline(file, line)) {
    stringstream geek(line);
    int x = 0;
    geek >> x;
		if(x == 0) {
			res.push_back(current);
			current = 0;
		} else {
			current += x;
		}
	}
  cout<<*max_element(res.begin(), res.end())<<endl;
	
	return 0;
}
