#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n; //사람 수
    cin >> n;
    vector <int> time(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> time[i];
    }
    sort(time.begin(),time.end());

    int ans = 0;
    for(int i = 0; i < n; i ++){
        ans += time[i] * (n-i);
    }
    cout << ans;
    return 0;
}
