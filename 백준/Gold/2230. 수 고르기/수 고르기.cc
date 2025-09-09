#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
long long arr[100001];
long long ans = 2000000001;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int st = 0;
    int en = 0;
    while (st <= en && en < n)
    {
        long long tmp = arr[en] - arr[st]; // 두 수의 차
        if (tmp < m)
        {
            // 차이가 m보다 작으면 en 증가
            en++;
        }
        else
        {
            // 차이가 m보다 크거나 같으면
            if (tmp == m)
            {
                cout << m;
                return 0;
            }
            ans = min(ans, tmp);
            st++;
        }
    }
    cout << ans;
}