#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n & 1){
        cout << 0;
        return 0;
    }
    int ans = sqrt(pow(2, n) / 4);
    int i = 4;
    while(i--){
        cout << ans << ' ';
    }
    return 0;
}