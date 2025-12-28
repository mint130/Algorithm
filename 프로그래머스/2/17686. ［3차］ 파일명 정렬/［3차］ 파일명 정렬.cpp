#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<pair<pair<string, string>, string>, int>> v; //{{{header, num}, s}, idx}
bool cmp(pair<pair<pair<string, string>, string>, int> p1, pair<pair<pair<string, string>, string>, int> p2){
    if(p1.first.first.first==p2.first.first.first){
        // 같으면 숫자로 바꿔서
        if (stoi(p1.first.first.second)==stoi(p2.first.first.second)){
            // 같으면 입력순서
            return p1.second<p2.second;
        }
        else return stoi(p1.first.first.second)<stoi(p2.first.first.second);
    }
    // 사전순
    else return p1.first.first.first<p2.first.first.first;
}
string tolow(string s){
    // 소문자로
    string res="";
    for(int i=0;i<s.length();i++) {
        if(isalpha(s[i])){
            res+=tolower(s[i]);
        }
        else res+=s[i];
    }
    return res;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(int i=0;i<files.size();i++){
        string s = files[i];
        int idx = 0;
        string head = "";
        string num = "";
        string tail = "";
        string tmp = "";
        for(int j=0;j<s.length();j++){
            if(isdigit(s[j])){
                idx = j;
                head = s.substr(0, idx);
                tmp = s.substr(idx);
                break;
            }
        }
        idx = 0;
        bool flag = 0;
        for(int j=0;j<tmp.length();j++){
            if(!isdigit(tmp[j])){
                idx = j;
                num = tmp.substr(0, idx);
                tail = tmp.substr(idx);
                flag = 1; // 뒤에 숫자로만 끝나는 경우 num이 ""됨
                break;
            }
        }
        if(!flag) num = tmp;
        head = tolow(head);

        v.push_back({{{head, num}, s}, i});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i:v){
        answer.push_back(i.first.second);
    }
    
    return answer;
}