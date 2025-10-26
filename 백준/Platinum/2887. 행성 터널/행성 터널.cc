#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
int parent[100001];
vector<pair<int, int>> xx;
vector<pair<int, int>> yy;
vector<pair<int, int>> zz;
vector<pair<int, pair<int, int>>> edge; // {거리, {시작, 끝}}
int find_parent(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find_parent(parent[x]);
}
void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);
    if (a != b)
    {
        if (a < b)
            parent[a] = b;
        else
            parent[b] = a;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        parent[i] = i;
        xx.push_back({x, i});
        yy.push_back({y, i});
        zz.push_back({z, i});
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    sort(zz.begin(), zz.end());
    for (int i = 1; i < n; i++)
    {
        // i-1번째, i번째 작은 x, y, z
        edge.push_back({abs(xx[i].first - xx[i - 1].first), {xx[i - 1].second, xx[i].second}});
        edge.push_back({abs(yy[i].first - yy[i - 1].first), {yy[i - 1].second, yy[i].second}});
        edge.push_back({abs(zz[i].first - zz[i - 1].first), {zz[i - 1].second, zz[i].second}});
    }
    sort(edge.begin(), edge.end());
    int ans = 0;
    for (auto e : edge)
    {
        int from = e.second.first;
        int to = e.second.second;
        int dist = e.first;
        if (find_parent(from) == find_parent(to))
            continue;
        else
            union_parent(from, to);
        ans += dist;
    }
    cout << ans;
}