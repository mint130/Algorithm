#include <iostream>

using namespace std;
int n, m; //1부터 n까지 자연수 중에서 중복 없이 m개 고른 수열
int arr[10];

void func(int num, int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i=num;i<=n;i++)
	{
		arr[k] = i;
		func(i, k + 1);
		
	}

}
int main() {

	cin >> n >> m;
	func(1, 0);
}