#include <iostream>

using namespace std;
int n, r, c;


int solution(int size, int row, int column) {

	int half = size / 2;
	//if (half == 2) return solution(half, row, column);
	//출력하는 것은 row, column의 방문 순서

	if (size == 0) {
		return 0;
		
	}
	if (row < half && column < half) {
		//0번
		return solution(half, row, column);
	}
	if (row < half && column >= half) {
		//1번
		return half * half + solution(half, row, column-half);
	}
	if (row >= half && column < half) {
		//2번
		return half * half * 2 + solution(half, row-half, column);
	}
	if (row >= half && column >= half) {
		//3번
		return half * half * 3 + solution(half, row-half, column-half);
	}
	
}
int main() {

	cin >> n >> r >> c;
	cout<<solution(1<<n, r, c);

	//1<<n = 2^n
}