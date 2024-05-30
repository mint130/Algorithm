#include <string>
#include <vector>
#include <iostream>
using namespace std;
int one(int k){
    int cnt=0;
    while(k>0){
        if(k%2==1) cnt++;
        k/=2;
    }
    return cnt;
}
int solution(int n) {
    int answer = 0;
    int ans=one(n);
    for(int i=n+1;i<1000001;i++){
        if(one(i)==ans) {
            return i;
        }
    }
}