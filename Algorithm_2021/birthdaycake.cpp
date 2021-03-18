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
	int N = A.size(); //������ �� ����
	while (n > 1) {
		int i = 0;
		while(i<k) {
			r = (r + 1) % N; //������
			if (A[r] != 0){ //�����ִ� �к��� K���� ���������� �н�
				i++;
			}
		}
		A[r] = 0; //�ش�Ǵ� �кҲ���
		n--; //�����ִ� �к� �ϳ� ����
		while (A[r] == 0) {
			r = (r + 1) % N; //���� �к��� ���������� �ٽ� r�� ��� ����
		}
	}
	return A[r];
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

	int answer1 = runSimulation1(A, n, k);
	cout <<"runSimulation1 �� ��� : "<< answer1;
}
