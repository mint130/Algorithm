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

    while (t.size() > s.size())
    {
        if (t.back() == 'A')
        {
            t.pop_back();
        }
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if (t == s)
    {
        cout << 1;
    }
    else
        cout << 0;
}