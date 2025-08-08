#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, num;
int parent[51];
bool visited[51];
vector<int> v[51];
vector<int> root;
int r = 0;
void dfs(int cur)
{
    visited[cur] = 1;
    root.push_back(cur);
    for (auto nxt : v[cur])
    {
        if (visited[nxt])
            continue;
        dfs(nxt);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
        if (parent[i] == -1)
            r = i;
    }
    cin >> num;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
            continue;      // 부모 없으면 넘어감
        int p = parent[i]; // i의 부모 노드
        v[p].push_back(i);
    }
    dfs(num); // num 밑에 있는 리프 노트 없앰
    if (num == r)
    {
        cout << 0;
        return 0;
    }
    reverse(root.begin(), root.end()); // 뒤집음
    for (auto i : root)
    {
        int p = parent[i];
        v[p].pop_back(); // 자기 자신 제거
        parent[i] = -1;
    }
    int ans = 0;
    if (v[r].size() == 0)
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1 && v[i].size() == 0) // 자식 갯수가 0이면서 없어지지 않음
            ans++;
    }
    cout << ans;
}