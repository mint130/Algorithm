#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;
    map<string, int> m;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    vector<string> ans[n];
    ans[0].push_back(words[0]);
    m[words[0]]++;
    for(int i=1;i<words.size();i++){
        ans[i%n].push_back(words[i]);
        char c1=words[i-1].back();
        char c2=words[i].front();
        m[words[i]]++;
       
        if(c1!=c2 || m[words[i]]>1){
            answer[0]=i%n+1;
            answer[1]=ans[i%n].size();
            break;
        }
    }

    return answer;
}