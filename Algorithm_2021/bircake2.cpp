#include <iostream>
#include <vector>
using namespace std;

void buildList(vector<int>& A, int n) {
	for (int i = 0; i < n; i++) {
		A.push_back(i + 1);
	}
}

void remove2(vector<int>& A, int r) {
	A[r] = 0; //초 날리기
	for (int i = r; i < A.size() - 1; i++) {
		A[i] = A[i + 1]; //앞으로 하나씩 옮기기
	}
	A.pop_back(); //맨 뒤 날리기
}

int runSimulation2(vector<int> A, int n, int k) {
	int r = 0;
	while (n > 1) {
		r = (r + k) % n;
		remove2(A, r); //초 날리기
		n--;
	}
	return A[0]; //마지막에 남은 양초
}

int main() {
	int n;//촛불 총 개수
	cout << "촛불 총 개수를 입력하세요 : ";
	cin >> n;
	vector<int> A; //촛불을 담은 배열
	vector<int> B; //촛불을 담은 배열
	int k; //촛불 간격
	cout << "촛불 간격을 입력하세요 : ";
	cin >> k;

	//리스트 제작
	buildList(A, n);
	buildList(B, n);

	int answer2 = runSimulation2(B, n, k);
	cout << "\nrunSimulation2 의 결과 : " << answer2;
}
