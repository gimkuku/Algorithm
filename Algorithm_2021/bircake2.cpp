#include <iostream>
#include <vector>
using namespace std;

void buildList(vector<int>& A, int n) {
	for (int i = 0; i < n; i++) {
		A.push_back(i + 1);
	}
}

void remove2(vector<int>& A, int r) {
	A[r] = 0; //�� ������
	for (int i = r; i < A.size() - 1; i++) {
		A[i] = A[i + 1]; //������ �ϳ��� �ű��
	}
	A.pop_back(); //�� �� ������
}

int runSimulation2(vector<int> A, int n, int k) {
	int r = 0;
	while (n > 1) {
		r = (r + k) % n;
		remove2(A, r); //�� ������
		n--;
	}
	return A[0]; //�������� ���� ����
}

int main() {
	int n;//�к� �� ����
	cout << "�к� �� ������ �Է��ϼ��� : ";
	cin >> n;
	vector<int> A; //�к��� ���� �迭
	vector<int> B; //�к��� ���� �迭
	int k; //�к� ����
	cout << "�к� ������ �Է��ϼ��� : ";
	cin >> k;

	//����Ʈ ����
	buildList(A, n);
	buildList(B, n);

	int answer2 = runSimulation2(B, n, k);
	cout << "\nrunSimulation2 �� ��� : " << answer2;
}
