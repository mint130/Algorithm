#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;

int main()
{
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int d, w;
        cin >> d >> w;

        v.push_back({d, w});
    }
    sort(v.begin(), v.end());                       // 마감일 기준
    priority_queue<int, vector<int>, greater<>> pq; // 점수 오름차순
    for (int i = 0; i < v.size(); i++)
    {
        int d = v[i].first;
        int w = v[i].second;
        pq.push(w);
        if (pq.size() > d)
            pq.pop();
    }
    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}