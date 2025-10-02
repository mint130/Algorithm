#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto it = lower_bound(ans.begin(), ans.end(), x); // x보다 크거나 같은 위치 찾음
        if (it == ans.end())
        {
            // x가 ans에 있는 것 보다 클 떄
            ans.push_back(x);
        }
        else
        {
            *it = x;
        }
    }

    cout << ans.size();
}