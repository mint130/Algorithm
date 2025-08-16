#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int n;
int half;
int ans = (int)pow(2, 31) * -1;
vector<char> op;
vector<int> num;
int calc(char o, int a, int b)
{
    if (o == '*')
        return a * b;
    if (o == '+')
        return a + b;
    if (o == '-')
        return a - b;
}
void dfs(int idx, int now)
{
    if (idx == half)
    {
        // 마지막 숫자
        ans = max(ans, now);
        return;
    }
    // now 연산자1 숫자2 연산자2 숫자3
    // 순서대로 계산
    dfs(idx + 1, calc(op[idx], now, num[idx + 1])); // now 연산자1 숫자2
    // 괄호를 연산자 2에 씌움
    if (idx + 2 <= half)
    {
        int tmp = calc(op[idx + 1], num[idx + 1], num[idx + 2]); // (숫자2 연산자2 숫자3)
        dfs(idx + 2, calc(op[idx], now, tmp));                   // now 연산자1 (숫자2 연산자 2 숫자3)
    }
}
int main()
{
    cin >> n;
    string s;
    cin >> s;
    half = n / 2;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            // 숫자
            num.push_back({s[i] - '0'});
        }
        else
            // 연산자
            op.push_back(s[i]);
    }
    dfs(0, num[0]);
    cout << ans;
}