#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int pre[400000];
long long view[400000];
long long sum[400000]; // 누적 시청 길이
string tos(int t){
    int hh = t/3600;
    t%=3600;
    int mm = t/60;
    int ss = t%60;
    string h = "";
    if(hh<10) h = "0"+to_string(hh);
    else h = to_string(hh);
    string m = "";
    if(mm<10) m = "0"+to_string(mm);
    else m = to_string(mm);
    string s = "";
    if(ss<10) s= "0"+to_string(ss);
    else s=to_string(ss);
    return h+":"+m+":"+s;
    
}
int tos(string s){
    // 초로 바꿈 
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    //cout<<hh<<" "<<mm<<" "<<ss<<endl;
    return hh*3600+mm*60+ss;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int play = tos(play_time); // 동영상 재생 시간
    int adv = tos(adv_time); // 광고 재생 시간
    for(int i=0;i<logs.size();i++){
        int st = tos(logs[i].substr(0, 8));
        int en = tos(logs[i].substr(9, 8));
        int len = en-st; // 재생된 시간
        pre[st]+=1;
        pre[en]-=1; 
    }
    // 누적 시청자수
    view[0]=pre[0];
    for(int i=1;i<=play;i++){
        view[i]=view[i-1]+pre[i];
    }
    // 누적 재생 시간
    sum[0]=view[0];
    for(int i=1;i<=play;i++){
        sum[i]=sum[i-1]+view[i];
    }
    long long mx = sum[adv - 1];
    int res = 0;
    for(int i=adv;i<=play;i++){
        long long cur = sum[i]-sum[i-adv]; // i-adv부터 adv만큼의 누적 재생 수
        if(cur>mx){
            mx = cur;
            // 시작 -> i-adv
            res = i-adv+1;
        }
    }
    
    
    return tos(res);
}