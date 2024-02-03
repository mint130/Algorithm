#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> answer;
map<string, int> m;
int num; //조합 구하는 문자열의 길이
string s; //백트래킹 하려는 문자열
int visit[11]; //i번째 문자열이 쓰였는지

void dfs(string tmp, int idx){

    if(tmp.length()==num){
        //길이가 num(course)와 같아질 때까지 백트래킹
        //cout<<tmp<<endl;
        m[tmp]++;
        //map의 갯수가 제일 큰 것
        return;
    }
    
    for(int i=idx;i<s.length();i++){
        if(!visit[i]){
            //중복 x 조합
            visit[i]=1;
            dfs(tmp+s[i], i);  
            visit[i]=0;
        }
        
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {

    
    for(int i=0;i<course.size();i++){
        num=course[i];
        for(int j=0;j<orders.size();j++){
            s=orders[j];
            sort(s.begin(), s.end());
            dfs("", 0);
        }
        int maxcount=0;
        for(auto it=m.begin();it!=m.end();it++){
            maxcount=max(maxcount, it->second);
        }
        cout<<maxcount<<endl;
        for(auto it=m.begin();it!=m.end();it++){
            if(maxcount<2) break; //2 이하이면 아무것도 집어넣지 않는다
            if(it->second==maxcount) {
                answer.push_back(it->first);
            }
        }
        m.clear();
    }
    sort(answer.begin(), answer.end());
    return answer;
}