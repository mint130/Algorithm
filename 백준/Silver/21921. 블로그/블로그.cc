#include <iostream>
using namespace std;
int n, x; // n은 지난 일수, x일 동안 가장 많이 들어온 방문자 수
int arr[250001];
long long sum[250001]; // i일까지 방문자 수의 합
int main()
{
    cin >> n >> x;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        tmp = max(tmp, arr[i]);
    }
    if (tmp == 0)
    {
        // 모두 0인 경우
        cout << "SAD";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }
    // 1일부터 x일까지-> sum[x]
    // 2일부터 x+1일까지 -> sum[x+1]-sum[1]
    // 3일부터 x+2일까지 -> sum[x+2]-sum[2]
    long long ans = 0; // 최대 방문자 수
    int cnt = 0;       // 최대 방문자 수가 나온 횟수
    for (int i = x; i <= n; i++)
    {
        // 현재-x일부터 현재일까지(기간 x) 방문자 수
        long long visit = sum[i] - sum[i - x];
        if (visit > ans)
        {
            // 최대 방문자 수 갱신
            ans = visit;
            cnt = 1;
        }
        else if (visit == ans)
        {
            // 최대 방문자 수 증가
            cnt++;
        }
    }
    cout << ans << "\n";
    cout << cnt;
}