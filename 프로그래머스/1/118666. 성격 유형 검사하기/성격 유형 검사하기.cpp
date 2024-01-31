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
        
        int score=choices[i];
        
        if(score>=4){
            m[c2]+=score-4;
        }
        else {
            m[c1]+=4-score;
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