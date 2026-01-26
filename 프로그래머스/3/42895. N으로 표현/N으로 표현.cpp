#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> dp[9];
int solution(int N, int number) {
    string s ="";
    
    for(int i=1;i<=8;i++){
        // N, NN, NNN, ...
        s+=to_string(N);
        dp[i].push_back(stoi(s));
        for(int j=1;j<i;j++){
            for(auto a:dp[j]){
                for(auto b:dp[i-j]){
                    // a+b
                    dp[i].push_back(a+b);
                    // a-b
                    dp[i].push_back(a-b);
                    dp[i].push_back(b-a);
                    // a*b
                    dp[i].push_back(a*b);
                    if(b!=0) dp[i].push_back(a/b);
                    if(a!=0) dp[i].push_back(b/a);
                }
            }
        }
        if(find(dp[i].begin(), dp[i].end(), number)!=dp[i].end()) return i;
        
    }
    
    return -1;
}