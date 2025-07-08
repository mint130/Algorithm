#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool arr[101][101];
int N, M;
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        // a가 b보다 무거움
        arr[a][b] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (arr[i][k] && arr[k][j])
                {
                    // i>k이고 k>j이면 i>j
                    arr[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if (!arr[i][j] && !arr[j][i])
                cnt++;
        }
        cout << cnt - 1 << "\n";
    }
}