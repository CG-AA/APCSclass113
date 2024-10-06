#include<bits/stdc++.h>
using namespace std;

int main() {
    string expression;
    cin >> expression;
    stack<char> s;
    int pairs = 0;
    bool isValid = true;
    for(char c : expression) {
        if(c == '(') {
            s.push(c);
        } else if(c == ')') {
            if(s.empty()) {
                isValid = false;
                break;
            } else {
                s.pop();
                pairs++;
            }
        }
    }
    if(!s.empty()) isValid = false;
    cout << (isValid ? pairs : 0) << endl;
    return 0;
}