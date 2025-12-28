#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long sum1[500001];
long long sum2[500001];
int n;
long long solution(vector<int> sequence) {
    long long answer = 0;
    n = sequence.size();
    vector<int> v1;
    vector<int> v2;
    // 1, -1, 1, -1 .. 홀수는 -1
    // -1, 1, -1, 1 .. 짝수는 -1
    for(int i=0;i<n;i++){
        if(i%2==0){
            // 짝수
            v1.push_back(sequence[i]);
            v2.push_back(sequence[i]*-1);
        }
        else {
            v1.push_back(sequence[i]*-1);
            v2.push_back(sequence[i]);
        }
    }
    sum1[0]=v1[0];
    sum2[0]=v2[0];
    for(int i=1;i<n;i++){
        // i까지 중 누적 제일 큰 것
        sum1[i]=max(sum1[i-1]+(long long)v1[i], (long long)v1[i]);
        sum2[i]=max(sum2[i-1]+(long long)v2[i], (long long)v2[i]);
    }
    
    return max(*max_element(sum1, sum1+n+1), *max_element(sum2, sum2+n+1));
}