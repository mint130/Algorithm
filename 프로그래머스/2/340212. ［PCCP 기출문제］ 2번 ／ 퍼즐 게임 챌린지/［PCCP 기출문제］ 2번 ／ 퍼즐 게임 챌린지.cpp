#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {

    long long st = 1;
    long long en = limit;
    long long level = (st+en)/2;
    while(st<=en){
        // 걸리는 시간
        long long t = 0;
        for(int i=0;i<diffs.size();i++){
            if(diffs[i]<=level){
                t+=times[i];
            }
            else {
                if(i==0){
                    t+=(diffs[i]-level)*(times[i])+times[i];
                }
                else {
                    t+=(diffs[i]-level)*(times[i]+times[i-1])+times[i];
                }
            }
        }
        if(t<=limit){
            en = level-1;
        }
        else {
            st = level+1;
        }
        
        level = (st+en)/2;
    }
    return level+1;
}