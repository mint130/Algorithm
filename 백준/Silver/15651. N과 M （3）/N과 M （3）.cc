#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 9
int n, m;

int arr[MAX] = {0};
bool visited[MAX] = {0};
void dfs(int num)
{
	if (num == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[num] = i;
		dfs(num + 1);
	}

}
int main()
{

	cin >> n >> m;
	dfs(0);
	
}
