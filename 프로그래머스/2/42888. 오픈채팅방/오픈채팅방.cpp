#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
map<string, string> m;
vector<pair<string, bool>> v; // uid, 들어오면 1 나가면 0 
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        stringstream ss(record[i]);
        string s, id, name;
        ss>>s>>id>>name;
        
        if(s=="Change"){
            m[id]=name;
        }
        else if(s=="Enter"){
            // 들어옴
            m[id]=name;
            v.push_back({id, 1});
        }
        else {
            v.push_back({id, 0});
        }
    }
    for(auto i:v){
        string id = i.first;
        string name = m[id];
        bool enter = i.second;
        if(enter){
            // 님이 들어왔습니다
            answer.push_back(name+"님이 들어왔습니다.");
        }
        else {
            // 님이 나갔습니다
            answer.push_back(name+"님이 나갔습니다.");
        }
    }
    return answer;
}