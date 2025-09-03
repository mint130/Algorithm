#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, t, ans;
bool trust[51];
int parent[51];
bool visited[51];
vector<int> party[51]; // 파티 번호
int findParent(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = findParent(parent[x]);
}
void makeUnion(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a < b)
        // 조상을 더 작은 쪽으로
        parent[b] = a;
    else
        parent[a] = b;
}
int main()
{
    cin >> n >> m;
    cin >> t;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        trust[num] = 1; // 진실을 아는 사람 번호
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        int st = 0;
        for (int j = 0; j < num; j++)
        {
            int nxt;
            cin >> nxt;
            party[i].push_back(nxt);
            if (j == 0)
            {
                st = nxt;
            }
            else
            {
                makeUnion(st, nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (trust[i])
        {
            // 대표 노드도 진실을 아는 것으로 바꿈
            int p = findParent(i);
            trust[p] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (party[i].size() == 0)
            continue;
        // 대표 노드가 진실을 아는지만 검사
        int p = findParent(party[i][0]);
        if (!trust[p])
            ans++;
    }
    cout << ans;
}