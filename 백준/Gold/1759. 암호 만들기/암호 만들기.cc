#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
char arr[16];
bool isVow[16];
void dfs(int idx, int cnt, string str, int vow)
{
    if (cnt == L && vow >= 1 && L - vow >= 2)
    {
        cout << str << "\n";
        return;
    }
    for (int i = idx; i < C; i++)
    {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
        {

            dfs(i + 1, cnt + 1, str + arr[i], vow + 1);
        }
        else
            dfs(i + 1, cnt + 1, str + arr[i], vow);
    }
}
int main()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + C);
    dfs(0, 0, "", 0);
}