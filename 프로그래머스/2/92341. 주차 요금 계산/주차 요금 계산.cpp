#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;
vector<pair<int, int>> v[10001]; // 시간, 입차면 0 출차면 1
int totime(string s){
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h*60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int atime = fees[0]; // 기본 시간
    int afee = fees[1]; // 기본 요금
    int btime = fees[2]; // 단위 시간
    int bfee = fees[3]; // 단위 요금
    sort(records.begin(), records.end()); // 시간 순
    for(int i=0;i<records.size();i++){
        stringstream ss(records[i]);
        string s1, s2, s3;
        ss>>s1>>s2>>s3;
        
        int num = stoi(s2); // 현재 차량 번호 
        int tt = totime(s1); // 현재 시간
        if(s3=="IN"){
            // 입
            v[num].push_back({tt, 0});
        }
        else {
            // 출
            v[num].push_back({tt, 1});
        }
    }
    for(int i=0;i<=9999;i++){
        if(v[i].size()==0) continue;
        int sum = afee;
        int t= 0;
        cout<<i<<endl;
        for(int j=0;j<v[i].size();j+=2){
            int in = v[i][j].first;
            int out = 23*60 + 59;
            if(j!=v[i].size()-1) out = v[i][j+1].first;
            t+= out - in; // 주차 시간
        }
        if(t>atime){
            // 기본 시간보다 많다 
            int tmp = t - atime; // 더 있었던 시간
            if((tmp%btime)==0) sum += (tmp/btime)*bfee;
            else sum += ((tmp/btime)+1)*bfee; // 올림
        }  
        //cout<<"시간 요금 "<<t<<" "<<sum<<endl;
        answer.push_back(sum);
    }
        
    return answer;
}