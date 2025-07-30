#include <iostream>
using namespace std;
int n, m;
int arr[100001];
int calc[100001];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int st, en, h;
        cin >> st >> en >> h;
        // 변화량 기록
        if (h < 0)
        {
            calc[st] += h;
            calc[en + 1] += abs(h);
        }
        else
        {
            calc[st] += h;
            calc[en + 1] += h * (-1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        calc[i] = calc[i - 1] + calc[i];
        cout << arr[i] + calc[i] << " ";
    }
}