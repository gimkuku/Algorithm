#include <iostream>
#include <vector>
using namespace std;

void buildList(vector<int> &A, int n) {
	for (int i = 0; i < n; i++) {
		A.push_back(i + 1);
	}
}

int runSimulation1(vector<int> &A, int n, int k) {
	int r = 0;
	int N = A.size(); //양초의 총 개수
	while (n > 1) {
		int i = 0;
		while(i<k) {
			r = (r + 1) % N; //다음거
			if (A[r] != 0){ //켜져있는 촛불이 K개를 지날때까지 패스
				i++;
			}
		}
		A[r] = 0; //해당되는 촛불끄기
		n--; //켜저있는 촛불 하나 제거
		while (A[r] == 0) {
			r = (r + 1) % N; //켜진 촛불이 남아있으면 다시 r로 잡고 리셋
		}
	}
	return A[r];
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

	int answer1 = runSimulation1(A, n, k);
	cout <<"runSimulation1 의 결과 : "<< answer1;
}
