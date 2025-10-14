#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (ans < arr[i])
        {
            break;
        }
        ans += arr[i];
    }
    cout << ans;
}