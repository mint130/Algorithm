#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
map<string, int> m; //id목록

vector<int> v1[1002]; //v1[idx]={idx가 신고한 사람들의 번호}
vector<int> v2[1002]; //v2[idx]={idx를 신고한 사람들의 번호}
bool id[1002]; //idx번째 id가 정지되었는지

int n; //id갯수
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    n=id_list.size();
    for(int i=0;i<id_list.size();i++){
        m[id_list[i]]=i;
    }
    for(auto str:report){
        int pos=str.find(" ");
        string a, b;
        a=str.substr(0, pos);
        b=str.substr(pos+1);
        int idx_a=m[a];
        int idx_b=m[b];
        v1[idx_a].push_back(idx_b); //a가 b를 신고
        v2[idx_b].push_back(idx_a); //b는 a에게 신고를 당함
    }
 
    for(int i=0;i<n;i++){ 
        //중복 제거
        sort(v1[i].begin(), v1[i].end());
        sort(v2[i].begin(), v2[i].end());
        v1[i].erase(unique(v1[i].begin(), v1[i].end()), v1[i].end());
        v2[i].erase(unique(v2[i].begin(), v2[i].end()), v2[i].end());
    }
    
    for(int i=0;i<n;i++){
        //정지되는 아이디 찾음
        if(v2[i].size()>=k){
            //i는 정지되는 id의 인덱스
            id[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        //v1[i]를 순회하며 id[j]가 1이면 j를 v1[i]내에 존재하는지 찾고, 존재한다면 cnt++
        int cnt=0; //신고한 id 중 정지당한 id 갯수
        for(int j=0;j<n;j++){
            if(id[j]==1){
                if(find(v1[i].begin(), v1[i].end(), j)!=v1[i].end()){
                    cnt++;
                }
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}