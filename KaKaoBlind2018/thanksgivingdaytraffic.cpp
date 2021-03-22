#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    vector <pair<int,int>> times;
    if(lines.size() == 1){return 1;}
    //시작시간 구하기
    for(int i = 0; i < lines.size();i++){
        int start_time = 0;
        int end_time = 0;
        int during_time = 0;
        pair <int,int> p;
        //종료시간 구하기
        end_time += 36000000 * (lines[i][11]-'0');
        end_time += 3600000 * (lines[i][12]-'0');
        end_time += 600000 * (lines[i][14]-'0');
        end_time += 60000 * (lines[i][15]-'0');
        end_time += 10000 * (lines[i][17]-'0');
        end_time += 1000 * (lines[i][18]-'0');
        end_time += 100 * (lines[i][20]-'0');
        end_time += 10 * (lines[i][21]-'0');
        end_time += 1 * (lines[i][22]-'0');
        
        //진행시간 구하기
        for(int j = 24;j<lines[i].length() -1; j++){
            if(j == 24){during_time += (lines[i][j]-'0') * 1000;}
            else if(j == 25){continue;}
            else{during_time += (lines[i][j]-'0') * pow(10, 28 - j);}
        }
        //시작시간 구하기
        start_time = end_time - during_time + 1;
        p = make_pair(start_time,end_time);
        times.push_back(p);
    }
    
    int answer = 0;
    
    //새로운 처리가 생기기 이전 1초
    for(int i = 0; i < times.size();i++){
        int startNum = times[i].first - 999;
        int element = 0;
        for(int j = 0 ; j < times.size();j++){
            // 구간 내에 존재하면(시작시간이 구간 끝나기 전, 끝나는 시간이 구간 시작한 후)
            if(times[j].second >= startNum && times[j].first <= startNum + 999){
                element++;
            }
        }
        if(element > answer){answer = element;}
    }
    
    return answer;
}