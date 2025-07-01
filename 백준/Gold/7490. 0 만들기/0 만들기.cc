#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, T;
vector<string> ans;
int calc(string str)
{
    string s; // 공백 제거
    for (auto tmp : str)
    {
        if (tmp != ' ')
        {
            s += tmp;
        }
    }
    int tmp = 0;
    int sum = 0;
    char op = '+'; // 초기 연산자
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            tmp = tmp * 10 + (s[i] - '0');
        }
        if (!isdigit(s[i]) || i == s.length() - 1)
        {
            if (op == '+')
                sum += tmp;
            else if (op == '-')
                sum -= tmp;
            op = s[i]; // 현재 연산자 저장
            tmp = 0;   // 숫자 초기화
        }
    }
    return sum;
}
void dfs(int idx, string str)
{
    if (idx == N)
    {
        if (calc(str) == 0)
        {
            ans.push_back(str);
        }
        return;
    }

    dfs(idx + 1, str + " " + to_string(idx + 1));
    dfs(idx + 1, str + "+" + to_string(idx + 1));
    dfs(idx + 1, str + "-" + to_string(idx + 1));
}
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N;
        dfs(1, "1");

        sort(ans.begin(), ans.end());
        for (auto s : ans)
        {
            cout << s << "\n";
        }
        cout << "\n";
        ans.clear();
    }
}