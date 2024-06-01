#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string w[5]={"A", "E", "I", "O", "U"};
vector<string> s;
void dfs(string str, int cnt){
    s.push_back(str);
    //cnt가 5가 되면 종료
    if(cnt==5){
        return;
    }
    for(int i=0;i<5;i++){
        dfs(str+w[i], cnt+1);
    }    
}
int solution(string word) {
    dfs("", 0);
    return find(s.begin(), s.end(), word)-s.begin();
}