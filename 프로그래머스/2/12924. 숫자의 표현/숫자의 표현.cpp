#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[10001];
int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n-1;i++){
        int sum=i;
        for(int j=i+1;j<=n-1;j++){
            sum+=j;
            if(sum==n){
                answer++;
            }
            else if(sum>n) break;
        }
    }
    return answer+1;
}