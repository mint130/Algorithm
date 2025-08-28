#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool isPrime[4000002];
vector<int> v;
int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    fill(isPrime, isPrime + n + 1, 1); // 1로 채움
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            // i가 소수 -> i*i부터 i의 배수로 된 수들은 다 소수가 아니므로 0으로 만듦
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            v.push_back(i);
    }
    // 소수들만 모아둔 vector
    int st = 0;
    int en = 0;
    long long sum = v[0];
    int ans = 0;

    while (st <= en && en < v.size())
    {
        if (sum <= n)
        {
            if (sum == n)
                ans++;
            en++;
            sum += v[en];
        }
        else
        {
            sum -= v[st];
            st++;
        }
    }
    cout << ans;
}