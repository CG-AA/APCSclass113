#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
    map<string, int> mp = {{"1B", 1}, {"2B", 2}, {"3B", 3}, {"HR", 4}, {"SO", 0}, {"FO", 0}, {"GO", 0}};
    string play[9][5];
    queue<int> base;

    for (int i = 0; i < 9; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) cin >> play[i][j];
    }

    int b, ans = 0, ocnt = 0;
    cin >> b;
    int i = 0, j = 0;

    while (b) {
        int k = mp[play[i][j]];
        if (k == 0) {
            b--;
            ocnt++;
            if (ocnt == 3) {
                while (!base.empty()) base.pop();
                ocnt = 0;
            }
        } else {
            int n = base.size();
            while (n--) {
                base.push(base.front() + k);
                base.pop();
            }
            base.push(k);
            while (base.front() > 3) {
                ans++;
                base.pop();
            }
        }
        i++;
        j += i / 9;
        i %= 9;
    }

    cout << ans;
}