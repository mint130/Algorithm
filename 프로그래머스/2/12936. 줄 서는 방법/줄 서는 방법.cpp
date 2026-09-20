#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N,  K;
long long cnt = 0;
long long fact[21];

int arr[21];
bool used[21];
vector<int> answer;
void dfs(int num, long long k){
    // 순열
    if(num==N) {
        for(int i=0;i<num;i++) {
            answer.push_back(arr[i]);
        }
        return;
    }
    // N자리의 num번째 숫자 채울때 
    // 4자리 -> 0번째 숫자 채울때 나오는 경우의 수 fact[3]
    // 4자리 -> 1번째 숫자 채울때 나오는 경우의 수 fact[2]
    // 5자리 -> 0번째 숫자 채울때 나오는 경우의 수 fact[4]
    // 5자리 -> 1번째 숫자 채울때 나오는 경우의 수 fact[3]
    long long cnt = fact[N-num-1];
    
    for(int i=1;i<=N;i++){
        if(used[i]) continue;
        
        // num번째 숫자에 i를 사용했을 때 cnt를 통째로 넘어갈 수 있는지
        if(k>cnt) {
            k-=cnt;
            continue;
        }
        used[i]=1;
        arr[num]=i;
        dfs(num+1, k);
        used[i]=0;
        
        return;
    }
    
    
}
vector<int> solution(int n, long long k) {
    N=n;
    K=k;
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=i*fact[i-1];
    }
    dfs(0, k);
    return answer;
}