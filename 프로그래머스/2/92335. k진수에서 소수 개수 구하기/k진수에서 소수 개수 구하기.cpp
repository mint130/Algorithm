#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
string num="";
void ntok(int n, int k){
    while(n>0){
        num+=to_string(n%k);
        n/=k;
    }
    reverse(num.begin(), num.end());
}
bool isprime(long long num){
    if(num<2) return false;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    // k진수로 변환
    ntok(n,k);
    string ans = "";
    for(auto c:num){
        if(c=='0'){
            if(!ans.empty()){
                long long tmp = stol(ans);
                if(isprime(tmp)) answer++;
                ans = "";
            }
        }
        else {
            ans+=c;
        }
    }
    
    if(!ans.empty()){
        long long tmp = stol(ans);
        if(isprime(tmp)) answer++;     
    }
    return answer;
}