#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int n=A.size();
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
   
    int sum1=0; int sum2=0;
    for(int i=0;i<n;i++){
        sum1+=A[i]*B[n-1-i];
        sum2+=B[i]*A[n-1-i];
    }
    answer=min(sum1, sum2);

    
    
    return answer;
}