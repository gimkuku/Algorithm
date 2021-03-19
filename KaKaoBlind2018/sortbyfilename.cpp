#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
    if(a.first == b.first)
    {
        if(a.second.first == b.second.first)
            return a.second.second < b.second.second;
        return a.second.first < b.second.first;
    }
    else
        return a.first < b.first;
}


vector<string> solution(vector<string> files) {
    
    vector<string> answer;
    vector<pair<string,pair<int, int>>> newFiles;
    string head = "";
    string number = "";
    
    //newFiles 벡터 만들기
    for(int i = 0; i < files.size();i++){
        head = "";
        number = "";
        pair<int, int> numpair;
        int next = files[i].length() -1;
        
        //숫자가 아닐때 =>head
        for(int j = 0; j < files[i].length();j++){
            //숫자면 중지
            if(files[i][j] >= '0'&& files[i][j] <= '9'){
                next = j; 
                break;
            }
           else{
            //대문자라면
            if((files[i][j] >= 'A') && (files[i][j] <= 'Z')){
                head+=tolower(files[i][j]);
            }
            else{head+=files[i][j];}
            }
        }

        
        //숫자일때 -> numb
        for(int j = next; j < files[i].length();j++){
            if(j > next + 4){break;}
            if(files[i][j] >= '0'&& files[i][j] <='9'){
            number+= files[i][j];
            }
            else{break;}
        }
        if(number ==""){number = "0";}
        int num = stoi(number);
        numpair = make_pair(num, i);
        newFiles.push_back(make_pair(head, numpair));
    }
    
    stable_sort(newFiles.begin(),newFiles.end(),cmp);
    
    for(auto itr : newFiles)
        answer.push_back(files[itr.second.second]);
    
    return answer;
}