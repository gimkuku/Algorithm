#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    //사람들이 오는 시간
    vector <int> times;
    for(int i = 0; i < timetable.size();i++){
        int element = 0;
        element += (timetable[i][0] - '0')*600;
        element += (timetable[i][1] - '0')*60;
        element += (timetable[i][3] - '0')*10;
        element += (timetable[i][4] - '0')*1;
        times.push_back(element);
    }
    //시간별로 소팅
    sort(times.begin(),times.end());
    
    //셔틀이 오는 시간
    vector <int> bus;
    int start_time = 540;
    for(int i = 0 ; i < n ;i++){
        int num = start_time + (i*t);
        bus.push_back(num);
    }
    
    //그 앞의 셔틀부터 기다린 사람 명수 구하기
    int waiting_num = 0;
    int waiting_time = 0;
    
    if(n>1){
        for(int i = 0; i< times.size();i++){
            if(waiting_num == m-1){
                //다음 사람도 같은 시간일때, 일분 일찍와야 함
                if(waiting_time == times[i]){
                    waiting_time--;
                }
                //아니면 그냥 그 시간에 와서 꼴지로 타도 됨
                break;
            }
            if(bus[n-2] >= times[i]){
                continue;
            }
            else if(bus[n-1] < times[i]){
                break;
            }
            if((times[i]>bus[n-2])&&(times[i]<=bus[n-1])){
                waiting_num ++;
                waiting_time = times[i];
            }
        }
    }
    else if(n == 1){
         for(int i = 0; i< times.size();i++){
            if(waiting_num == m-1){
                //다음 사람도 같은 시간일때, 일분 일찍와야 함
                if(waiting_time == times[i]){
                    waiting_time = waiting_time -1;
                }
                //아니면 그냥 그 시간에 와서 꼴지로 타도 됨
                break;
            }
            if(bus[0] < times[i]){
                break;
            }
            if(bus[0] >= times[i]){
                waiting_num ++;
                waiting_time = times[i];
            }
        }
    }
    
    if(waiting_num < m-1 || waiting_num == 0 ){
        waiting_time = bus[n-1];
    }
    if(times.size() < m){
        waiting_time = bus[n-1];
    }
    
    int a = waiting_time / 600;
    int b = (waiting_time - (a*600)) / 60;
    int c = (waiting_time - (a*600) - (b*60)) / 10;
    int d = (waiting_time - (a*600) -(b*60) - (c*10)) % 10;
    
    string answer = "";
    char alp = a+48;
    answer.push_back(alp);
    alp = b+48;
    answer.push_back(alp);
    answer.push_back(':');
    alp = c+48;
    answer.push_back(alp);
    alp = d+48;
    answer.push_back(alp);
    
    return answer;
}