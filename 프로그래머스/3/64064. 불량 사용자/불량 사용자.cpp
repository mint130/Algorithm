#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;
bool isused[9]; // user_id가 이미 사용되었는지
int answer = 0;
set<set<int>> ss;
bool isbanned(string ban, string user){
    // s1이 *가 있음 
    // s2은 원래
    if(ban.length()!=user.length()) return false; // 길이 다름 
    int len = ban.length();
    for(int i=0;i<len;i++){
        if(ban[i]!='*' && ban[i] != user[i]){
            // 일치하지 않음
            return false;
        }
    }
    return true;
    
}
void dfs(int idx, vector<string> &user_id, vector<string> &banned_id){
    if(idx==banned_id.size()){
        set<int> s;
        for(int i=0;i<user_id.size();i++){
            if(isused[i]) s.insert(i);
        }
        ss.insert(s);
        return;
    }
    for(int i=0;i<user_id.size();i++){
        if(!isused[i] && isbanned(banned_id[idx], user_id[i])){
            isused[i]=1;
            dfs(idx+1, user_id, banned_id);
            isused[i]=0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(0, user_id, banned_id);
    return ss.size();
}