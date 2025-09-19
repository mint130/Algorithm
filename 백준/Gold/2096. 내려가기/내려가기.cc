#include <iostream>
#include <algorithm>
using namespace std;
int n;
int pm[3], pM[3];
int cm[3], cM[3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    pm[0] = pM[0] = a;
    pm[1] = pM[1] = b;
    pm[2] = pM[2] = c;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 최소값 dp
        cm[0] = min(pm[0], pm[1]) + a;
        cm[1] = min({pm[0], pm[1], pm[2]}) + b;
        cm[2] = min(pm[1], pm[2]) + c;

        // 최대값 dp
        cM[0] = max(pM[0], pM[1]) + a;
        cM[1] = max({pM[0], pM[1], pM[2]}) + b;
        cM[2] = max(pM[1], pM[2]) + c;

        // 현재 값 이전으로
        for (int j = 0; j < 3; j++)
        {
            pm[j] = cm[j];
            pM[j] = cM[j];
        }
    }
    cout << max({pM[0], pM[1], pM[2]}) << " " << min({pm[0], pm[1], pm[2]});
}