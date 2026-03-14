#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey) {
        int n = storey%10;
        storey/=10;
        // 지금 마지막 한 자릿수
        if(n==0) continue; // 바로 다음 자릿수로 넘어감
        else if(n>=5) {
            // 올림
            answer+= 10-n;
            if(n==5) {
                if(storey%10>=5) {
                    storey++;
                }
                continue;
            }
            storey++;
        }
        else if(n<5) {
            // 버림
            answer+=n;
        }
    }
    return answer;
}