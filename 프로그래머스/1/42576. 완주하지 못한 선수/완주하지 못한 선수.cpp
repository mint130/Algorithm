#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
unordered_map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(auto it: participant)
    {
        if(m.find(it)==m.end()){
            m[it]=1;
            
        }
        else{
            m[it]++;
        }
        
    }
    for(auto it: completion)
    {
        m[it]--;
    }
    
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second==1) 
        {
            answer=it->first;
            return answer;
        }
    }
    
}