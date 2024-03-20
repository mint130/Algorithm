#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n;
char lc[28];
char rc[28];
void preorder(char cur) {
	cout << cur;
	if (lc[cur] != '.') preorder(lc[cur]);
	if (rc[cur] != '.') preorder(rc[cur]);
}
void inorder(char cur) {
	if (lc[cur] != '.') inorder(lc[cur]);
	cout << cur;
	if (rc[cur] != '.') inorder(rc[cur]);
}
void postorder(char cur) {
	if (lc[cur] != '.') postorder(lc[cur]);
	if (rc[cur] != '.') postorder(rc[cur]);
	cout << cur;

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c, l, r;
		cin >> c >> l >> r;
		lc[c] = l;
		rc[c] = r;
	
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}