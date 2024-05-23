#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    for(int i=0;i<weights.size();i++){
        int w1=weights[i];
        for(int j=i+1;j<weights.size();j++){
            int w=weights[j];
            if(w1==w) answer++;
            if(w1*2==w) answer++;
            if(w1%2==0){
                if(w1*3/2==w) answer++;
            }
            if(w1%3==0){
                if(w1*4/3==w) answer++;
            }
        }
    }
    return answer;
}