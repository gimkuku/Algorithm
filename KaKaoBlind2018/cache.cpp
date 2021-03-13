#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize != 0){
    vector <string> cacheArr;
    for(int i = 0; i < cities.size();i++){
        cacheArr.push_back("0");
    }
    int hit;
    bool full;
    for(int i = 0; i < cities.size();i++){
        string new_c = (cities[i]);
        transform(new_c.begin(), new_c.end(), new_c.begin(), ::tolower);
            hit = -1;
            full = false;
            
            //miss인지 hit인지 판별
            for(int k = 0; k < cacheSize; k++){
                if(new_c == cacheArr[k]){
                    hit = k;
                    break;
                } //hit일 경우 해당 인덱스 저장
            }
            
            //full인지 아닌지 판별
            if(cacheArr[cacheSize-1] != "0"){
                full = true;
            }
            
            //full && miss
            if((full) && (hit == -1)){
                for(int k = 0 ; k < cacheSize-1; k++){
                    cacheArr[k] = cacheArr[k+1];
                }
                cacheArr[cacheSize-1] = new_c;
                answer = answer+ 5;
            }
            //full && hit
            else if(full && (hit != -1)){
                if(hit != cacheSize-1){
                for(int k = hit ; k < cacheSize-1; k++){
                    cacheArr[k] = cacheArr[k+1];
                }
                }
                cacheArr[cacheSize-1] = new_c;   
                answer +=1;
            }
            //nonfull && hit
            else if(!full && (hit != -1)){
                for(int k = hit ; k < cacheSize-1; k++){
                    cacheArr[k] = cacheArr[k+1];
                }
                for(int k = 0; k < cacheSize; k++){
                    if(cacheArr[k] == "0"){
                        cacheArr[k] = new_c;
                        break;
                    }
                }
                answer+=1;
            }
            // nonfull && miss
            else if(!full && (hit == -1)){
                for(int k = 0; k < cacheSize; k++){
                    if(cacheArr[k] == "0"){
                        cacheArr[k] = new_c;
                        break;
                    }
                }
                answer+=5;
            }
            
        }
    }
    else{
         for(int i = 0; i < cities.size();i++){
         answer += 5;
        }         
    }
    return answer;
}