#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
string s, t;
int main()
{
    cin >> s >> t;
    vector<char> c;
    vector<char> ans;
    for (int i = 0; i < t.length(); i++)
    {
        c.push_back(t[i]);
    }
    for (int i = 0; i < s.length(); i++)
    {
        ans.push_back(s[i]);
    }
    while (c.size() != 0)
    {
        if (c[c.size() - 1] == 'A')
        {
            c.pop_back();
        }
        else if (c[c.size() - 1] == 'B')
        {
            c.pop_back();
            reverse(c.begin(), c.end());
        }
        if (ans == c)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}