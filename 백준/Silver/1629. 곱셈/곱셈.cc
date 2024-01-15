#include <iostream>
using namespace std;
long long solution(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	long long val = solution(a, b / 2, c); //val의 값은 a^b/2가 됨
	val = val * val % c; //a^b/2 * a^b/2 % c => a^b % c
	if (b % 2 == 0) return val; //짝수인 경우 계산된 val(a^b/2) 리턴
	return (val * a) % c; //홀수인 경우 리턴값에 a를 더 곱해줘야함
}
int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << solution(a, b, c);
}