#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, r, q;
int cnt[100002]; // 루트번호가 n일때 서브트리 정점의 수
bool visited[100002];
vector<int> v[100002];
void dfs(int cur)
{
    cnt[cur] = 1;
    visited[cur] = 1;
    for (int nxt : v[cur])
    {
        if (visited[nxt])
            continue;
        dfs(nxt);
        cnt[cur] += cnt[nxt];
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int st, en;
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);
    }
    dfs(r);
    for (int i = 0; i < q; i++)
    {
        int num;
        cin >> num;
        cout << cnt[num] << "\n";
    }
}