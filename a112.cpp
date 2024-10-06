#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, map<string, int>> data;
    vector<string> locationsOrder; // 用於記錄地點出現的順序
    map<string, vector<string>> animalsOrder; // 用於記錄每個地點動物出現的順序

    for (int i = 0; i < N; ++i) {
        string animal, location;
        int count;
        cin >> animal >> count >> location;

        if (data[location].empty()) {
            // 如果是新地點，記錄地點出現順序
            locationsOrder.push_back(location);
        }
        if (data[location][animal] == 0) {
            // 如果是該地點的新動物，記錄動物出現順序
            animalsOrder[location].push_back(animal);
        }
        data[location][animal] += count;
    }

    for (auto &location : locationsOrder) { // 按地點出現順序輸出
        cout << location << ":";
        bool first = true;
        for (auto &animal : animalsOrder[location]) { // 按動物出現順序輸出
            if (!first) cout << ",";
            cout << animal << " " << data[location][animal];
            first = false;
        }
        cout << endl;
    }

    return 0;
}