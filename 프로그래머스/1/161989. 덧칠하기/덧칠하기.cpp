#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int blank[200002]; //비어있으면 1
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    //1부터 n까지 전체 길이
    for(int i=0;i<section.size();i++){
        int num=section[i];
        blank[num]=1; 
    }
    //blank[i]가 1이면 i부터 i+m-1까지 0으로 바꿈
    for(int i=1;i<=n;i++){
        if(blank[i]){
            answer++;
            for(int j=0;j<m;j++){
                blank[i+j]=0;
            }
        }
    }
    return answer;
}