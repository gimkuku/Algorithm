#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n; //도시 개수
    cin >> n;
    long long road[n]; //도로
    long long city[n]; //기름값

    //도로, 도시 입력
    for(int i = 0 ; i < n-1 ; i ++){
        long long element;
        cin >> element;
        road[i] = element; 
    }
    road[n-1] = 0; //마지막 도로는 더이상 길이 없으므로 0으로 둔다

    for(int i = 0 ; i < n ; i ++){
        long long element;
        cin >> element;
        city[i] = element;
    }

    long long temp = city[0];
    long long ans = 0;
    for(int i = 0 ; i < n; i ++){
        if(temp >= city[i]){temp = city[i];}
        ans += 1LL * temp * road[i];
    }

    cout << ans;

}