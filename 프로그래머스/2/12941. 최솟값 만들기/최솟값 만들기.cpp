#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int n=A.size();
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
   
    
    for(int i=0;i<n;i++){
        answer+=A[i]*B[i];
    }
    

    
    
    return answer;
}