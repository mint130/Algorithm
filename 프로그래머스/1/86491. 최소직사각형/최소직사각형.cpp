#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int n=sizes.size();
    int maxw=0;
    int maxh=0;
    for(int i=0;i<n;i++){
        int w=sizes[i][0];
        int h=sizes[i][1];
        if(h<w) swap(w, h);
        //w를 크게
        if(w>maxw) maxw=w;
        if(h>maxh) maxh=h;
    }
    
    return maxw*maxh;
}