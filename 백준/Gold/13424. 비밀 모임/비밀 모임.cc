#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, N, M, K;
int dp[101][101];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dp[i][j] = 987654321;
                dp[i][i] = 0;
            }
        }
        for (int i = 0; i < M; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            dp[a][b] = c;
            dp[b][a] = c;
        }
        for (int k = 1; k <= N; k++)
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
                }
            }
        }

        cin >> K;
        vector<int> r;
        for (int i = 0; i < K; i++)
        {
            int num;
            cin >> num;
            r.push_back(num);
        }
        int ans = 987654321; // 이동 거리의 총합
        int num = 101;       // 방의 번호
        for (int i = N; i >= 1; i--)
        {
            // i번 방에 모일 때 총 합 길이
            int sum = 0;
            for (int j = 0; j < r.size(); j++)
            {
                int st = r[j];
                sum += dp[st][i];
            }
            if (ans >= sum)
            {
                ans = sum;
                num = i;
            }
        }
        cout << num << "\n";
    }
}