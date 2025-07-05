#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    left=left-1;
    right=right-1;
    long long idx = left;
    while(idx++<=right){
        int row = idx/n;
        int col = idx%n;
        answer.push_back(max(row, col)+1);
    }
    return answer;
}