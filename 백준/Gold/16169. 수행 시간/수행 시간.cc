#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;
int n;
int arr[101];                  // 해당 번호에 왔을 때 제일 오래 걸리는 시간
vector<pair<int, int>> v[101]; // v[계급]에 번호, 속도
int main()
{
    int max_c = 0; // 가장 높은 계급
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c, s;
        cin >> c >> s;
        max_c = max(c, max_c);
        v[c].push_back({i, s});
        arr[i] = s;
    }

    int ans = 0;
    for (int i = 1; i <= max_c; i++)
    {
        for (auto cur : v[i])
        {
            // 현재 계급에 들어가있는
            int num = cur.first;    // 번호
            int speed = cur.second; // 속도

            for (auto prev : v[i - 1])
            {
                int prev_num = prev.first;
                int prev_speed = arr[prev_num];
                arr[num] = max(arr[num], prev_speed + (prev_num - num) * (prev_num - num) + speed);
            }
            ans = max(arr[num], ans);
        }
    }
    cout << ans;
}