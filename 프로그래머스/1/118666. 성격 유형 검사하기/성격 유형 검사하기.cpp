#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
map<char, int> m;
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int size=survey.size();
    
    for(int i=0;i<size;i++){
        char c1=survey[i][0];
        char c2=survey[i][1];
        bool reverse=0;
        //an cf mj rt na 
        if(c1>c2){
            char tmp;
            tmp=c1;
            c1=c2;
            c2=tmp;
            reverse=1;
        }
       
        //c1이 사전 순으로 앞에 옴
        int score=choices[i]-1;
        
        if(!reverse){
            //사전 순
            if(score<3){
                cout<<c1<<" "<<3-score<<endl;
                m[c1]+=3-score;
            }
            else {
                cout<<c2<<" "<<score-3<<endl;
                m[c2]+=score-3;
            }
        }
        else {
            //역 사전 순
            if(score<3){
                cout<<c2<<" "<<3-score<<endl;
                m[c2]+=3-score;
            }
            else {
                cout<<c1<<" "<<score-3<<endl;
                m[c1]+=score-3;
            }
        }
        
    }
    if(m['R']>=m['T']) answer+='R';
    else answer+='T';
    
    if(m['C']>=m['F']) answer+='C';
    else answer+='F';
    
    if(m['J']>=m['M']) answer+='J';
    else answer+='M';
    
    if(m['A']>=m['N']) answer+='A';
    else answer+='N';

    return answer;
}