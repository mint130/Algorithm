#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<int> top;
vector<int> bottom;
int N, H;
int arr[500001];
int ans = 987654321;
int main()
{
    cin >> N >> H;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (i % 2 == 0)
        {
            // 아래
            bottom.push_back(num);
        }
        else
        {
            // 위
            top.push_back(num);
        }
    }
    // 정렬
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    // 1부터 H까지
    for (int i = 1; i <= H; i++)
    {
        int t = top.end() - lower_bound(top.begin(), top.end(), H - i + 1);  // H-i+1 이상인 갯수
        int b = bottom.end() - lower_bound(bottom.begin(), bottom.end(), i); // i 이상인 갯수

        // 높이가 i일때 몇개의 장애물을 파괴하는지
        arr[i] = t + b;
        ans = min(ans, arr[i]); // 최소값 갱신
    }

    int cnt = 0; // 최소값을 가지는 갯수 찾기
    for (int i = 1; i <= H; i++)
    {
        if (ans == arr[i])
            cnt++;
    }
    cout << ans << " " << cnt << "\n";
}