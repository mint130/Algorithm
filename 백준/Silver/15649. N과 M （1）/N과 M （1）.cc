#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m; //1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
int arr[10];
bool isused[10];

void func(int k)
{
	//현재 k까지 수를 택한 상황에서 arr[k]를 정하는 함수
	//func(0)으로 시작, arr[0]부터 정한다
	if (k == m)
	{
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' '; //수열을 출력(M개를 모두 택함)
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
	
}
int main()
{
	
	cin >> n >> m; //1부터 n까지의 자연수 중에서 중복 없이 m개 고른 수열
	func(0);

}