#include <iostream>
using namespace std;
int n, k;
int arr[100002];
int sum[100002]; // i까지의 누적 합 저장
int ans = -987654321;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    for (int i = k; i <= n; i++)
    {
        // i-k+1부터 k개의 누적합 구하기
        ans = max(ans, sum[i] - sum[i - k]);
    }
    cout << ans;
}