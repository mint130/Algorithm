#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;
	vector<int> p;
	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;
		p.push_back(n);
	}
	sort(p.begin(), p.end());
	int sum = 0;
	int result = 0;
	for (int i = 0; i < p.size(); i++)
	{
		sum=p[i] + sum;
		result = result + sum;
		
	}
	cout << result << '\n';
	


}