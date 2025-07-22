#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, N;
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        int minA = 100001; // 지금까지 나왔던 순위들 중 제일 높은 순위
        int minB = 100001;
        int cnt = 0;
        for (auto i : v)
        {

            int a = i.first;
            int b = i.second;
            if (a < minA && b < minB)
            {
                minA = a;
                minB = b;
                // 선발할 수 있음
                cnt++;
            }
            else if (a < minA && b > minB)
            {
                minA = a;
                // 선발할 수 있음
                cnt++;
            }
            else if (a > minA && b < minB)
            {
                minB = b;
                // 선발할 수 있음
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}