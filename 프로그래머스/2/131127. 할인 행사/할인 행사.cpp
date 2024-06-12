#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n=want.size();
    int idx=0;
    vector<int> num(number.begin(), number.end());
    while(idx+10<=discount.size()){
        //idx부터 10개씩 want에 있는거 확인하고 want에 1이라도 남아 있으면 idx++, 원래대로 want 복구
        for(int i=0;i<10;i++){
            string s=discount[idx+i];
            for(int j=0;j<n;j++){
                if(want[j]==s){
                    num[j]--;
                }
            }
        }
        bool flag=0;
        for(int j=0;j<n;j++){
            if(num[j]!=0) flag=1;
            num[j]=number[j]; //복구
        }
        if(!flag) answer++;
        idx++;
    }
    return answer;
}