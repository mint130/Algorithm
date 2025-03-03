#include <iostream>
#include <vector>

using namespace std;

int n;
string s1, s2, s3;
bool visited[201][201];
bool ans = 0;
void dfs(int idx1, int idx2, int idx3)
{
    if (idx3 == s3.length()) // 마지막
    {
        ans = 1;
        return;
    }
    if (visited[idx1][idx2])
    {
        return;
    }
    visited[idx1][idx2] = true;
    if (idx1 < s1.length() && s3[idx3] == s1[idx1])
    {
        dfs(idx1 + 1, idx2, idx3 + 1);
    }
    if (idx2 < s2.length() && s3[idx3] == s2[idx2])
    {
        dfs(idx1, idx2 + 1, idx3 + 1);
    }
}
void init()
{
    ans = 0;
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            visited[i][j] = false;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        init();

        cin >> s1 >> s2 >> s3;
        dfs(0, 0, 0);

        cout << "Data set " << i << ": ";
        if (ans)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
}