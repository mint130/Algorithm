#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[101];
bool visited[101];
vector<int> ans;
void dfs(int cur, int start)
{
    if (visited[cur])
    {
        // 그래프가 시작점으로 돌아오면 하나의 사이클이 된 것
        if (start == cur)
        {
            ans.push_back(cur);
        }
        return;
    }
    visited[cur] = true;
    int nxt = arr[cur];
    dfs(nxt, start);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, i);
        fill(visited, visited + n + 1, 0);
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}
