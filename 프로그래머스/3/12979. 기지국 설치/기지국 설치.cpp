#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int st = 1;
    int en = 0;
    int len = 1;
    for(int i=0;i<stations.size();i++){
        int a = max(1, stations[i]-w);
        int b = min(n, stations[i]+w);
        // a부터 b까지는 기지국 설치됨
        en = a-1;
        // 기지국 설치 안된 st en
        len = en-st+1;
        if(st<=en){
            if(len%(2*w+1)==0) {
                answer += len / (2*w+1);
            }
            else {
                answer += (len / (2*w+1))+1;
            }
        
        }
        
        st = b+1;
        
    }
    if(st<=n){
        // 마지막까지 안옴
        en = n;
        len = en-st+1;
        if(len%(2*w+1)==0) {
            answer += len / (2*w+1);
        }
        else {
            answer += (len / (2*w+1))+1;
        }
    }
    return answer;
}