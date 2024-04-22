#include <iostream>
#include <algorithm>
using namespace std;
int arr[1002];
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int T = 10;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		int N;
		cin >> N;
		int answer = 0;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			arr[i] = num;
		}
		int prev = 0;
		int cur = 0;
		for (int i = 2; i < N - 2; i++) {
			prev = cur;
			cur = arr[i];
			if (cur < prev) continue;
			//i-2 i-1 i+1 i+2 중 가장 큰 값 찾아서 cur보다 크면 continue, 작으면 answer+=cur-maxheight
			
			int maxheight = max({ arr[i - 2], arr[i - 1], arr[i + 1], arr[i + 2]});
		
			if (maxheight < cur) answer = answer + cur - maxheight;
			
		}
		cout << "#" << test_case << " " << answer << "\n";
		fill(arr, arr + 1002, 0);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}