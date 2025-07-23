#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int N;
int main()
{
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 현재 사용중인 강의실 저장, 일찍 끝나는 순서대로 저장
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int num, st, en;
        cin >> num >> st >> en;
        v.push_back({st, en});
    }
    sort(v.begin(), v.end()); // 시작 시간 순으로 정렬
    int ans = 0;
    for (auto i : v)
    {
        int st = i.first;  // 시작 시간
        int en = i.second; // 끝나는 시간
        if (pq.empty())
        {
            pq.push({en, st});
            ans++;
        }
        else
        {
            int last = pq.top().first; // 끝나는 시간이 제일 짧은 강의실 끝 시각
            if (last <= st)
            {
                // 시작 시간이 기존 강의실의 끝나는 시간보다 늦거나 같음
                // 강의실 빼고 거기에 넣음
                pq.pop();
                pq.push({en, st});
            }
            else
            {
                // 시작 시간이 기존 강의실의 끝나는 시간보다 빠름
                // 들어갈 강의실 x -> 강의실 추가
                pq.push({en, st});
                ans++;
            }
        }
    }
    cout << ans;
}