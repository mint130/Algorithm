#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0}; // d l r u
string ds[4] = {"d", "l", "r", "u"};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    priority_queue<pair<string, pair<int, int>>, vector<pair<string, pair<int, int>>>, greater<>> pq;
    pq.push({"", {x-1, y-1}});

    while (!pq.empty()) {
        string str = pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();

        int len = str.length();
        int remaining_distance = abs(r - 1 - cx) + abs(c - 1 - cy);

        // 불가능한 경로 가지치기
        if (remaining_distance > k - len || (k - len - remaining_distance) % 2 != 0) continue;

        // 탈출 조건
        if (cx == r - 1 && cy == c - 1 && len == k) return str;

        // 가능한 경로 탐색
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                pq.push({str + ds[dir], {nx, ny}});
            }
        }
    }

    return "impossible";
}
