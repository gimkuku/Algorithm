#include <iostream>
#include <vector>
using namespace std;

int n;
int m;

int main(){
	vector <vector <int >>spiralArr;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector <int> element(m);
		spiralArr.push_back(element);
	}

	int left = 0;
	int right = m-1;
	int top = 0;
	int bottom = n-1;

	int index = 1;
	while (left <= right && top<= bottom) {
		for (int j = left; j < right; j++) {
			spiralArr[top][j] = index;
			index++;
		}

		for (int i = top; i < bottom; i++) {
			spiralArr[i][right] = index;
			index++;
		}

		for (int j = right; j > left; j--) {
			spiralArr[bottom][j] = index;
			index++;
		}

		for (int i = bottom; i > top; i--) {
			spiralArr[i][left] = index;
			index++;
		}
		left = left + 1;
		right = right - 1;
		top = top + 1;
		bottom = bottom - 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << spiralArr[i][j];
		}
		cout << "\n";
	}

	return 0;
}