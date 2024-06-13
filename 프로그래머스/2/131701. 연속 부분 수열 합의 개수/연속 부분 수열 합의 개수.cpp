#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
set<int> s;
int solution(vector<int> elements) {
    int n=elements.size();
    for(int i=0;i<n;i++){
        //i번째 숫자부터 j개까지
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=elements[(i+j)%n];
            s.insert(sum);
        }
    }
    return s.size();
}