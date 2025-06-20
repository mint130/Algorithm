#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int T, n, cnt;
int arr[100002];
bool visited[100002];
bool done[100002];
void dfs(int cur)
{
    visited[cur] = true;
    int nxt = arr[cur];
    if (!visited[nxt])
    {
        dfs(nxt);
    }
    else if (!done[nxt])
    {
        // 다시 방문했을 때 끝나지 않으면 cycle
        for (int i = nxt; i != cur; i = arr[i])
        {
            cnt++;
        }
        cnt++; // 시작점
    }
    done[cur] = 1; // 더이상 cur 방문 x
}
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n;
        fill(arr, arr + n + 2, 0);
        fill(visited, visited + n + 2, 0);
        fill(done, done + n + 2, 0);
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
        }
        cout << n - cnt << "\n";
    }
}