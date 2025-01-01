#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

vector<pair<double, double>> v;
double x1, x2;
double func(pair<double, double> p1, pair<double, double> p2)
{
    return (x1 * p1.second + p1.first * p2.second + p2.first * x2 - (p1.first * x2 + p2.first * p1.second + x1 * p2.second)) / 2;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    double ans = 0;
    x1 = v[0].first;
    x2 = v[0].second;
    for (int i = 1; i < v.size() - 1; i++)
    {
        ans += func(v[i], v[i + 1]);
    }
    printf("%.1f", abs(ans));
}