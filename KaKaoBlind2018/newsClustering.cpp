#include <vector>
#include <string>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector <int> strArr1;
    vector <int> strArr2;
    
    for(int i = 0; i < str1.length()-1 ; i ++){
        if(isalpha(str1[i]) &&isalpha(str1[i+1]) !=0){
            int element = ((str1[i]&31)*100) + (str1[i+1]&31); 
            strArr1.push_back(element);
        }
    }
    
    for(int i = 0; i < str2.length()-1 ; i ++){
      if(isalpha(str2[i])&&isalpha(str2[i+1]) !=0){
        int element = ((str2[i]&31)*100) + (str2[i+1]&31); 
        strArr2.push_back(element);
        }
    }
    
    int interNum = 0;
    
    for (int i = 0; i < strArr1.size();i ++){
      for (int j = 0; j < strArr2.size();j ++){
        if(strArr1[i] == strArr2[j]){
            strArr2[j] = 0;
            interNum++;
            break;
        }
      }
    }
    
    int total = strArr1.size() + strArr2.size() - interNum;
    if(total != 0){
    float ans = (float)interNum / (float)total;
    answer = ans * 65536;}
    else answer = 65536;
    // answer = interNum;
    return answer;
}