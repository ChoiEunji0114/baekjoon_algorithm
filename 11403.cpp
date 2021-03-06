/*
백준 11403
경로 찾기 
*/


#include <iostream>
using namespace std;

int input[101][101];
bool visited[101][101];
int n;

void go(int top, int x, int y) {
	input[top][y] = 1;
	visited[top][y] = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[top][i] && input[y][i]) {
			go(top, y, i);
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) { // ÀÔ·Â¹ÞÀ½
		for (int j = 1; j <= n; j++) {
			cin >> input[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][i] && input[i][j]) {
				go(i, i, j);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
