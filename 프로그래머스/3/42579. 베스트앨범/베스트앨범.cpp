#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> genre_idx; // 장르별로 idx
int genre_play[101]; // 장르 종류별 재생 횟수
int n;
vector<pair<int, int>> v[101]; // v[장르] -> {노래별 재생 횟수, 그 노래의 번호}
vector<pair<int, int>> g; // 재생횟수, 장르번호
bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    else return p1.first>p2.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    n = genres.size();
    for(int i=0;i<n;i++){
        string s = genres[i];
        int play = plays[i];
        int num = genre_idx[s];
        if(num==0){
            int new_num = genre_idx.size();
            genre_idx[s] = new_num;
            genre_play[new_num]+=play;
            v[new_num].push_back({play, i});
        }
        else {
            genre_play[num]+=play;
            v[num].push_back({play, i});
        }
    }

    for(auto i:genre_idx){
        int idx = i.second;
        int p = genre_play[idx];
        g.push_back({p, idx});
    }
    // g -> 장르 총 재생 횟수, 장르 번호 내림차순 정렬
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    
    for(int i=0;i<g.size();i++){
        //cout<<g[i].first<<" "<<g[i].second<<endl;
        int num = g[i].second;
        sort(v[num].begin(), v[num].end(), cmp);
        if(v[num].size()==0) continue;
        if(v[num].size()==1){
            answer.push_back(v[num][0].second);
        }
        else if(v[num].size()>1){
            answer.push_back(v[num][0].second);
            answer.push_back(v[num][1].second);
        }
        // for(int i=0;i<v[num].size();i++){
        //     cout<<v[num][i].first<<" "<<v[num][i].second<<endl;
        // }
        // for(auto node:v[num]){
        //     cout<<node.first<<" "<<node.second<<endl;
        // }
    }
    return answer;
}