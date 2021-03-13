#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
    //시작용
	bool flag = true;
    
    //더이상 바뀔게 없을때까지
	while (flag) {
        
		//그 자리에서 바로 바꾸면 다음 비교를 할 수 없으므로
        //똑같이 생긴 배열을 하나 더 만든 뒤 방문했던 곳을 저장한다. 
        //라운드가 끝날때마다 초기화
        vector<vector<bool>> room(m, vector<bool>(n));
        
        //pop시작
        //flag = 바뀜
		flag = false; //바뀐게 없음
		for (int i = 0; i <m-1;i++) {
			for (int j = 0; j < n - 1; j++) {
                char now = board[i][j];
				if (now == 0)
					continue;
				if ((now == board[i][j + 1])&& (now== board[i + 1][j])&&(now== board[i + 1][j + 1])) {
					room[i][j] = 1;
					room[i][j+1] = 1;
					room[i+1][j] = 1;
					room[i + 1][j + 1] = 1;
					flag = true; //바뀌었으므로
				}
			}
		}
        
        //방문했던곳 체크 -> 아래로 끌고오기
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				//바뀐게 있으면
                if (room[i][j]==1) {
					answer++;
                    //앞의 인덱스를 터진곳까지 밀기
					for (int k = i-1; k >=0; k--) {
						board[k + 1][j] = board[k][j];
						board[k][j] = 0; //앞의 인덱스 비우기
					}
				}
			}
		}
	}
	return answer;
}