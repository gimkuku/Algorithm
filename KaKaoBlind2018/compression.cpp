#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector <string> dict;
    
    for(int i = 0; i < 26;i++){
        string element = "";
        char a = i+65;
        element.push_back(a);
        dict.push_back(element);
    }
    
    int index = 0;
    int word_index;
    
    while(index < msg.length()){
        int word_length = 1; //찾아야되는 글씨 길이
        string search_word =""; // 찾아야 되는 글씨    
        bool flag = true;
        while(flag){ //딕셔너리에서 인덱스 글자를 발견을 못할때까지
            flag = false;
            search_word.push_back(msg[index+word_length-1]); //찾았으면 다음 글자를 찾아보기... 
            for(int i = 0; i < dict.size();i++){
                if(search_word == dict[i]){     //dict에 찾는 단어가 있으면
                    word_index = i;             //찾은 인덱스
                    flag = true;                //찾았음
                    word_length ++;             //다음 글자 찾기
                    break;
                }       
            }
        }
        dict.push_back(search_word);
        answer.push_back(word_index+1);
        index = index+word_length-1;
    }

    return answer;
}