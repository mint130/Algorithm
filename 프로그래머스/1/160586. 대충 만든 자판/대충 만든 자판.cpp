#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m; //m['A']=1, m['B']=1 m['C']=2 m['D']=5 ...
    for(int i=0;i<keymap.size();i++){
        string s=keymap[i];
        //keymap을 돌면서 keymap에 포함된 문자의 index 중 최소값을 map에 넣는다
        for(int j=0;j<s.length();j++){
            char c=s[j];
            if(m.find(c)!=m.end()){
                //이미 값이 존재하는 경우
                if(j+1<m[c]) {
                    //지금 값이 더 작은 경우
                    m[c]=j+1;
                }
            }
            else {
                m[c]=j+1;    
            }
            
        }
    }
    /*for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }*/
    for(int i=0;i<targets.size();i++){
        string s=targets[i]; //각각 문자열
        int sum=0;
        bool flag=0; //찾으면 0 못찾으면 1
        for(int j=0;j<s.length();j++){
            char c=s[j];
            if(m.find(c)!=m.end()){
                sum+=m[c];
            }
            else{
                flag=1;
               
            }
            
        }
        if(flag==1) answer.push_back(-1);
        else {
            answer.push_back(sum);
        }
        
    }
    return answer;
}