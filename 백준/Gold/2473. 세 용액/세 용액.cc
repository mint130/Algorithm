#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long arr[5001];
vector<long long> ans(3);
long long tmp = 9876543210;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int st = i + 1;
        int en = n - 1;
        while (st < en)
        {
            long long sum = arr[i] + arr[st] + arr[en];
            if (abs(sum) < tmp)
            {
                // 갱신
                tmp = min(tmp, abs(sum));
                ans[0] = arr[i];
                ans[1] = arr[st];
                ans[2] = arr[en];
            }
            if (sum < 0)
            {
                // 0보다 작으면 st를 오른쪽으로 옮김
                st++;
            }
            else
            {
                // 0보다 크면 en를 왼쪽으로 옮김
                en--;
            }
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}