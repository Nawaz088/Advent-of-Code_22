#include <bits/stdc++.h>
using namespace std;
int main() {
    //FILE* fp;
    char str[15];
    std::fstream fin("input2.txt", std::fstream::in);
  
    int cnt1=0, cnt2=0;
    while(fin>>std::skipws>>str) {
        int n[4] = {0,0,0,0};
        n[0] = atoi(strtok(str, "-,"));
        for(int i =1; i<4; i++){
            n[i] = atoi(strtok(NULL, "-,"));
        }
        if(n[0]>=n[2] && n[1]<=n[3] || n[2]>=n[0] && n[3]<=n[1]){
            cnt1 ++;
        }
        if(n[0]>=n[2] && n[0]<=n[3] || n[0]<=n[2] && n[1]>=n[2]){
            cnt2 ++;
        }
        
        
    }
    cout<<cnt1<<" "<<cnt2<<"\n";
    
    return 0;
}
