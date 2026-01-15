#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, int> m;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n =want.size();
    for(int i=0;i<want.size();i++){
        string s= want[i];
        int num = number[i];
        m[s]=num;
    }
    for(int i=0;i+9<discount.size();i++){
        map<string, int> m2;
        for(int j=0;j<10;j++){
            string s = discount[i+j];
            m2[s]++;
        }
        bool flag = 1;
        for(auto i:m2){
            if(i.second != m[i.first]){
                flag = 0;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}