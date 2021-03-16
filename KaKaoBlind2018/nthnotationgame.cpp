#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    vector <char> numArr;
    numArr.push_back('0');
    int i = 1;
    
    //숫자 배열 만들기
    while(numArr.size() < (t*m)){
           vector <char> element;
            int a = i;
            while(a > 0){
            int r = a%n;
            a= (a -r)/n;
            char alp;
            //10진수 이상일 경우
            if(r>=10){
            alp = (char)((r-10)+65);
            }
            else{ 
             alp = (char)(r+48);
            }
            element.push_back(alp);
         }
        for(int j = element.size()-1 ; j >= 0 ;j--){
            numArr.push_back(element[j]);
        }
        i++;
    }
    
    //result 출력하기
    string answer = "";
    for(int i=0;i< t;i++){
        answer.push_back(numArr[(i*m)+p-1]);
    }
    return answer;
}