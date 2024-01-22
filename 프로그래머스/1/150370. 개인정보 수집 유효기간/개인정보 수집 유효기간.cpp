#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int today_y, today_m, today_d; //오늘 날짜

map<char, int> m; //약관의 종류와 유효기간
int find_m(char c){
    auto it=m.find(c);
    if(it!=m.end()) return it->second;
}
void today_string(string today){
    string y_s, m_s, d_s;
    for(int i=0;i<4;i++){
        y_s+=today[i];
    }
    today_y=stoi(y_s);
    //yy
    
    for(int i=5;i<=6;i++){
        m_s+=today[i];
    }
    today_m=stoi(m_s);

    //mm
    
    for(int i=8;i<=9;i++){
        d_s+=today[i];
    }
    today_d=stoi(d_s);

}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    //2023.05.19
    //0123456789
    vector<int> answer;
    today_string(today); //오늘 날짜 구함
    int now=today_y*12*28 + today_m*28 + today_d;
    cout<<now<<endl;
  
    for(int i=0;i<terms.size();i++){
        string s=terms[i];
        char alphabet=s[0];
        string month;
        for(int j=2;j<s.length();j++){
            month+=s[j];
        }
        m[alphabet]=stoi(month)*28;
        //v.push_back({alphabet, stoi(month) * 28});
        //약관 종류와 일 기준 유효기간 * 28(일)
    }
    
  
    
    for(int i=0;i<privacies.size();i++){
        string s=privacies[i];
        cout<<i+1<<"번째"<<endl;
        string y_s, m_s, d_s;
        int yy, mm, dd;
        for(int j=0;j<4;j++){
            y_s+=s[j];
        }
        yy=stoi(y_s);
        cout<<"yy "<<yy<<endl;
        //yy

        for(int j=5;j<=6;j++){
            m_s+=s[j];
        }
        mm=stoi(m_s);
        cout<<"mm "<<mm<<endl;
        //mm

        for(int j=8;j<=9;j++){
            d_s+=s[j];
        }
        dd=stoi(d_s);
        cout<<"dd "<<dd<<endl;
        
        char alphabet=s[11]; //이용약관 종류
        
        int day= yy*12*28 + mm*28 + dd;
        int len=find_m(alphabet);
        cout<<"len " <<len<<endl;
        cout<<"day+len "<<day+len<<endl;
        if(day > now) answer.push_back(i+1);
        else {
            if(day+len<=now) answer.push_back(i+1);    
        }
        
        cout<<endl;
    }
    
    //오늘 날짜가 2022.05.19라면 2022*12*28 + 28*5 + 19
    //약관이 6딜: 6*28
    //약관이 12달: 28*12
    //약관이 3달: 28*3

 
    return answer;
    //terms A 유효기간(string 유의)
    //privacies는 개인정보 수집 날짜 약관종류(string)
    //answer은 파기해야 할 개인정보 번호 -> privacies의 idx+1을 answer에 넣음
    //오늘 날짜로 파기해야 할 개인정보 번호
}