#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
map<long long, int> m;
map<long long, int> first; //숫자가 처음 나온 idx
vector<long long> v;
bool cmp(long long a, long long b) {
	if (m[a] != m[b]) {
		return m[a] > m[b];
		//빈도수가 많은 것부터
	}
	else {
		return first[a] < first[b];
		//빈도수가 같다면 처음 숫자가 나온 idx가 작은 것부터
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		if (m[num] == 0) {
			first[num] = i;
			//처음 나오면 v에 저장
			v.push_back(num);
		}
		m[num]++;
		
		//정렬 할 때 m[num]이 더 큰 것이 앞에 오게

	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		int size = m[v[i]]; //v[i](long long)의 빈도수 찾기 
		for (int j = 0; j < size; j++) {
			cout << v[i] << " ";
		}
		
	}


}