#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> l;
vector<int> r;
int solution(vector<int> a) {
    int answer = 0;
    int n = 1000000001;
    // 왼쪽이 자기보다 작다 -> 오른쪽은 다 나보다 커야함 
    // 오른쪽이 자기보다 작다 -> 왼쪽은 다 나보다 커야함 
    for(int i=0;i<a.size();i++){
        //i까지 왔을때 제일 작은 값 n
        n = min(a[i], n);
        l.push_back(n);
    }
    n = 1000000001;
    for(int i=a.size()-1;i>=0;i--){
        // 거꾸로 i까지 왔을때 제일 작은 값 n
        n = min(a[i], n);
        r.push_back(n);
    }
    reverse(r.begin(), r.end());
    for(int i=0;i<a.size();i++){
        //i까지왔을때 l[i-1] r[i+1]보다 둘다 크면 안됨
        int left = 1000000000;
        int right = 1000000000;
        if(i!=0) left = l[i-1];
        if(i!=a.size()-1) right = r[i+1];
        if(a[i]<left || a[i]<right) answer++;
    }
    return answer;
}