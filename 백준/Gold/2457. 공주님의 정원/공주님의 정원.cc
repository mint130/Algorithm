#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<pair<int, int>> v;
int num(int m, int d)
{
    // m-1까지 일 더함
    //+d로 리턴
    int sum = 0;
    for (int i = 1; i <= m - 1; i++)
    {
        sum += day[i];
    }
    return sum + d;
}

int main()
{
    int n;
    cin >> n;
    int start = num(3, 1);
    int end = num(11, 30);

    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int st = num(a, b);
        int en = num(c, d);

        v.push_back({st, en});
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    int cur = start; // 꽃이 펴져있다고 보장되는 날짜
    while (cur <= end)
    {
        int nxt = cur;
        for (auto i : v)
        {
            if (i.first <= cur && i.second >= nxt)
            {
                // 다음에 심을 꽃->지금 보장된 날짜보다 일찍 피고 가장 늦게 짐
                nxt = i.second;
            }
        }
        if (nxt == cur)
        {
            // 못찾음
            cout << 0;
            return 0;
        }
        cnt++;
        cur = nxt;
    }
    cout << cnt;
}