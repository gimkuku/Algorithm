#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string a;
    cin >> a;
    int ans = 0;
    
    //자른 숫자들을 담을 벡터
    vector <string> nums;

    //우선 처음부터 잘라야 하므로
    int current = 0;

    //'+', '-' 나올때마다 잘라서 벡터에 넣기
    for (int i = 0 ; i < a.size(); i++){
        if(a[i] == '+' || a[i] == '-'){
            string element = a.substr(current,i-current);
            nums.push_back(element);
            if(a[i] == '+'){nums.push_back("+");} else{nums.push_back("-");}
            current = i+1;
        }
    }
    //맨 마지막 숫자까지 벡터에 넣어주기
    string element = a.substr(current,a.size()-current);
    nums.push_back(element);

    //벡터 처음부터 돌리며 ans에 더하기
    bool isminus = false;
    ans = stoi(nums[0]);
    for(int i = 1; i < nums.size();i++){
        if (nums[i] == "-"){
            isminus = true;
        }
        if(nums[i] != "-" && nums[i] != "+"){
            if(isminus){
                ans -= stoi(nums[i]);
            }else{
                ans+= stoi(nums[i]);
            }
        }else{continue;}
    }

    cout << ans;
}