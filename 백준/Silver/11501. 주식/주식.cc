#include <iostream>
#include <algorithm>
using namespace std;
int n, t;
int arr[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        fill(arr, arr + n, 0); // 초기화
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long ans = 0;
        int mx = -1; // 현재 최대값
        for (int i = n - 1; i >= 0; i--)
        {
            if (mx < arr[i])
            {
                mx = arr[i]; // 갱신
            }
            else
            {
                ans += mx - arr[i]; // 이익 더함
            }
        }
        cout << ans << "\n";
    }
}