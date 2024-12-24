#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> p1;
pair<int, int> p2;
pair<int, int> p3;
int main()
{
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;

    int res = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    res -= p2.first * p1.second + p3.first * p2.second + p1.first * p3.second;
    if (res > 0)
        cout << 1;
    else if (res == 0)
        cout << 0;
    else
        cout << -1;
}