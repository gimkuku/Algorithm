#include <string>
#include <vector>
#include<iostream>
#include <cctype>
using namespace std;



string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string mlower = "";
    if(musicinfos.size() != 0){
    vector <string> musicnames;
    vector <string> musics;
        
    int answerindex = -1;
    //전처리...
    for(int i=0;i<musicinfos.size();i++){
        string music = ""; // 그냥 musicinfo에 들어있는 노래
        string repeatmusic = ""; // 노래를 시간만큼 반복한거
        string musicname = ""; // 그냥 musicinfo에 들어있는 노래제목
        
        //재생 시간 구하기
        int time =
        (musicinfos[i][6]- '0')*600 + (musicinfos[i][7]- '0')*60 + (musicinfos[i][9]- '0')*10 +(musicinfos[i][10]- '0')
        -((musicinfos[i][0]- '0')*600 + (musicinfos[i][1]- '0')*60 + (musicinfos[i][3]- '0')*10 +(musicinfos[i][4]- '0'));
        
        if(time != 0){
            //노래 제목 구하기
            int musicindex = 0;
            for(int j= 12; j <musicinfos[i].length();j++){
                if(musicinfos[i][j] == ','){musicindex = j; break;}
                else{musicname.push_back(musicinfos[i][j]);}
            }
            musicnames.push_back(musicname);

            //노래 구하기
            for(int j = musicindex+1; j < musicinfos[i].length()-1;j++){
                if(musicinfos[i][j] == '#'){continue;}
                
                if(musicinfos[i][j+1] != '#'){ music.push_back(musicinfos[i][j]);}
                else{
               music.push_back(tolower(musicinfos[i][j])); //다음게 샵이면 소문자로 바꿔주기
                }
            }
            if(musicinfos[i][musicinfos[i].length()-1] != '#'){ 
                music.push_back(musicinfos[i][musicinfos[i].length()-1]);
            }
            
            //재생시간만큼 반복한 노래 구하기
            for(int j = 0; j < time ;j++){
                int index = j % (music.length());
                repeatmusic.push_back(music[index]);
            }
            musics.push_back(repeatmusic);
            
        }else{continue;}
    }

    //찾기 시작...
    int mindex = 0;
    int musicsindex = 0;
        
    //m 샵 처리해주기
    for(int j = 0; j < m.length()-1;j++){
        if(m[j] == '#'){continue;}
        if(m[j+1] != '#'){ mlower.push_back(m[j]);}
        else{
            mlower.push_back(tolower(m[j])); //다음게 샵이면 소문자로 바꿔주기
        }
    }
    if(m[m.length()-1] != '#'){ 
        mlower.push_back(m[m.length()-1]);
    }
        
    for(int i = 0; i < musics.size();i++){
        for(int j = 0; j< musics[i].length();j++){
            mindex = 0;
            if(musics[i][j] == mlower[mindex]){
                musicsindex = j;
                while(true){
                if(mlower[mindex] == musics[i][musicsindex]){
                    if(mindex == mlower.length()-1){
                        if(answerindex!=-1){
                        if(musics[i].size() > musics[answerindex].size()){
                            answerindex = i;
                        }    
                        }else{answerindex = i;}
                        break; }
                    else if(musicsindex == musics[i].length()-1){break;}
                    mindex ++;
                    musicsindex ++;
                }else{break;}
            }
            }else{continue;}
        }
    }
    
    if(answerindex == -1){answer = "(None)";}
    else{answer = musicnames[answerindex];}
        
    }else{
        answer = "(None)";
    }
    return answer;
}

