#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int n;
bool zero;
vector<int> v1;
vector<int> v2;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num <= 0)
            v1.push_back(num);
        else if (num > 0)
            v2.push_back(num);
    }
    sort(v1.begin(), v1.end());   // 음수는 오른차순
    sort(v2.rbegin(), v2.rend()); // 양수는 내림차순
    int sum = 0;
    for (int i = 0; i < v2.size(); i += 2)
    {
        if (i == v2.size() - 1)
        {
            sum += v2[i];
        }
        else
        {
            int tmp = max(v2[i] * v2[i + 1], v2[i] + v2[i + 1]);
            sum += tmp;
        }
    }
    for (int i = 0; i < v1.size(); i += 2)
    {
        if (i == v1.size() - 1)
        {
            sum += v1[i];
        }
        else
        {
            int tmp = max(v1[i] * v1[i + 1], v1[i] + v1[i + 1]);
            sum += tmp;
        }
    }
    cout << sum;
}