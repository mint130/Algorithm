#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[10001];
int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    int en=1;int st=1;
    int sum=arr[1];
    while(st<=en && en<=n){
        if(sum<=n){
            if(sum==n) answer++;
            en++;
            sum+=arr[en];
        }
        else if(sum>n){
            sum-=arr[st];
            st++;
        }
    
    }
    return answer;
}