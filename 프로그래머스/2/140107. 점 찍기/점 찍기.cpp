#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    answer+=d/k+1; //축 위에 있는 점
    for(long long i=0;i<d;i+=k){
        long long y=floor(sqrt((long long)d*d-(long long)i*i))/k;
        answer+=y;
    }
    
    return answer;
}