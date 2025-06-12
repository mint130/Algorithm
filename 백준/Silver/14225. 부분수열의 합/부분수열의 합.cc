#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int arr[21];
bool result[2000001]; // 부분 수열의 합이 될 수 있는 수
void dfs(int idx, int sum)
{
    if (idx == N)
    {
        result[sum] = 1;
        return;
    }
    dfs(idx + 1, sum + arr[idx]); // 포함
    dfs(idx + 1, sum);            // 포함 x
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    dfs(0, 0);
    for (int i = 1; i <= 2000000; i++)
    {
        if (!result[i])
        {
            cout << i;
            return 0;
        }
    }
}