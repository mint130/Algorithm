#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v1; // i까지 왔을 때 최소값
vector<int> v2; // a.size()-1부터 역으로 오면서 최소값
int solution(vector<int> a) {
    int answer = 0;
    int num = 1000000000;
    
    for(int i=0;i<a.size();i++){
        num = min(num, a[i]);
        v1.push_back(num);
    }
    num = 1000000000;
    for(int i=a.size()-1;i>=0;i--){
        num = min(num, a[i]);
        v2.push_back(num);
    }
    reverse(v2.begin(), v2.end());
    for(int i=0;i<a.size();i++){
        int left = 1000000000;
        int right = 1000000000;
        if(i!=0) left = v1[i-1];
        if(i!=a.size()-1) right = v2[i+1];
        //a[i]가 left, right보다 둘 다 크면 안됨
        if(a[i]<left || a[i]<right) answer++;
    }
    return answer;
}