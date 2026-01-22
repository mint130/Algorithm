#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <iostream>
#include <set>
using namespace std;
map<string, int> m;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    for(int i=0;i<words.size();i++){
        // 순서
        int idx = i%n;
        int num = i/n;
        string cur = words[i];
        if(i==0){
            m[cur]=1;
            continue;
        }
        
        string pre = words[i-1];
        int len = pre.length();
        char c = pre[len-1];
        if(cur[0]==c && m[cur]==0){
            m[cur]=1;
        }
        else {
            answer[0]=idx+1;
            answer[1]=num+1;
            return answer;
        }
        
    }

    return answer;
}