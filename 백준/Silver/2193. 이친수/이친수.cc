#include <iostream>
using namespace std;
int n;
long long dp0[92]; // n자리 문자열이 0로 끝나는 갯수
long long dp1[92]; // n자리 문자열이 1로 끝나는 갯수

int main()
{
    cin >> n;

    dp0[1] = 0;
    dp1[1] = 1;

    dp0[2] = dp0[1] + dp1[1];
    dp1[2] = dp0[1];

    for (int i = 2; i <= n; i++)
    {
        dp1[i] = dp0[i - 1];              // 1로 끝나는 것은 i-1자리 0으로 끝나는 갯수 그대로
        dp0[i] = dp0[i - 1] + dp1[i - 1]; // 0으로 끝나는 것은 i-1자리 0으로 끝나는 것 + 1로 끝나는 것
    }
    cout << dp1[n] + dp0[n];
}