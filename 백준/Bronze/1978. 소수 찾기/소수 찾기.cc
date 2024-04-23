#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;

	}
	return true;
}
int main() {
	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		if (isPrime(M) == true) count++;
		
	}
	cout << count;

}
