#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int totime(string s){
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h*60+m;
}
vector<pair<pair<int, int>, string>> ans;
bool cmp(pair<pair<int, int>, string> p1, pair<pair<int, int>, string> p2){
    // 길이가 더 긴 팀, 길이가 같으면 index가 작은거
    if(p1.first.first == p2.first.first){
        return p1.first.second<p2.first.second;
    }    
    else return p1.first.first>p2.first.first;
    
}
string normalize(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && s[i + 1] == '#') {
            res += tolower(s[i]); // C# → c
            i++;                  // # 건너뛰기
        } else {
            res += s[i];
        }
    }
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    m = normalize(m);
    for(int i=0;i<musicinfos.size();i++){
        stringstream ss(musicinfos[i]);
        string str;
        vector<string> v;
        while(getline(ss, str, ',')){
            v.push_back(str);
        }
        int st = totime(v[0]);
        int en = totime(v[1]);
        int len = en-st;
        string title = v[2];
        string info = normalize(v[3]);
        string tmp = "";
        if(len>info.length()){
            // 길이에 맞게 더 늘림
            int a = len/info.length();
            int b = len%info.length();
           
            for(int j=0;j<a;j++){
                tmp+=info;
            }
            tmp+=info.substr(0, b);
        }
        else {
            // 길이에 맞게 자름
            tmp = info.substr(0, len);
        }
        if(tmp.length()>=m.length()){
            if(tmp.find(m)!=string::npos){
                // 찾으면 
                ans.push_back({{len, i}, title});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
    }
    return ans.size()==0?"(None)":ans[0].second;
}