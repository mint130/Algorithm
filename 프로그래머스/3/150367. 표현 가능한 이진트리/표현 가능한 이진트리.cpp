#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
string tobinary(long long num){
    string s = "";
    while(num){
        if(num%2==0) s+="0";
        else s+="1";
        num/=2;
    }
    reverse(s.begin(), s.end());
    return s;
}
bool dfs(string s){
    if(s.size()==1){
        return true;
    }
    int mid = s.size()/2;
    char r = s[mid];
    // 현재 부모 r의 왼쪽과 오른쪽 탐색
    string left = s.substr(0, mid);
    string right = s.substr(mid+1);
    
    // 부모가 0이면 자식에 1이 있으면 안됨
    if(r=='0'){
        if(left.find('1')!=string::npos) return false;
        if(right.find('1')!=string::npos) return false;
    }
    
    return dfs(left) && dfs(right);
    
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto i:numbers){
        string s = tobinary(i);
        
        //s가 가져야 할 노드의 갯수
        int total = 1;
        while(total<s.length()){
            total = total*2+1;
        }
        // 포화 이진트리로 만들기 위해 앞에 0 붙임
        while(s.length()<total){
            s="0"+s;
        }
        if(dfs(s)){
            answer.push_back(1);
        }
        else answer.push_back(0);
    }
    return answer;
}