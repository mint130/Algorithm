#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t;

int main()
{
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << "\n";
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            auto it = lower_bound(v.begin(), v.end(), x); // x보다 크거나 같은 첫번째 위치에 넣음
            if (it == v.end())
                v.push_back(x);
            else
                *it = x; // 자리 교체
        }

        int len = v.size(); // 가장 긴 증가하는 부분 수열 길이
        if (len < k)
            cout << 0 << "\n";
        else
            cout << 1 << "\n";
    }
}