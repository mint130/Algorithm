#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v1;
    vector<int> v2;
    int tmp1 = 0, tmp2 = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            v1.push_back(x);
            tmp1 = max(tmp1, x);
        }
        else
        {
            v2.push_back(-x);
            tmp2 = max(tmp2, -x);
        }
    }
    // 정렬
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = 0;

    for (int i = v1.size() - 1; i >= 0; i -= m)
    {
        ans += v1[i] * 2;
    }
    for (int i = v2.size() - 1; i >= 0; i -= m)
    {
        ans += v2[i] * 2;
    }
    // 가장 큰 값 뺌
    ans -= max(tmp1, tmp2);
    cout << ans;
}
