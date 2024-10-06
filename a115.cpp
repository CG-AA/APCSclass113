#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, bool>>> board(5, vector<pair<int, bool>>(5));

pair<int, int> GetInBpos(int tar){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(board[i][j].first == tar){
                return make_pair(i, j);
            }
        }
    }
}

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int temp;
            cin >> temp;
            board[i][j] = {temp, 0};
        }
    }
    int temp;
    while(cin >> temp && temp != -1){
        pair<int, int> pos = GetInBpos(temp);
        board[pos.first][pos.second].second = 1;
    }
    pair<int, int> ans = {99, 0};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(board[i][j].second) continue;
            int score = [i, j](){
                int res = 2;
                for(int k = 0; k < 5; k++){
                    if(i == k)continue;
                    if(!board[k][j].second){
                        res--;
                        break;
                    }
                }
                for(int k = 0; k < 5; k++){
                    if(i == k)continue;
                    if(!board[i][k].second){
                        res--;
                        break;
                    }
                }
                //diagonal
                if(i == j){
                    res++;
                    for(int k = 0; k < 5; k++){
                        if(i == k)continue;
                        if(!board[k][k].second){
                            res--;
                            break;
                        }
                    }
                }
                //diagonal
                if(i+j == 4){
                    res++;
                    for(int k = 0; k < 5; k++){
                        if(i == k)continue;
                        if(!board[k][4-k].second){
                            res--;
                            break;
                        }
                    }
                }
                return res;
            }();
            if(score >= ans.second){
                if(score > ans.second){
                    ans = {board[i][j].first, score};
                } else if(board[i][j].first < ans.first) {
                    ans = {board[i][j].first, score};
                }
            }
        }
    }
    cout << ans.first;
    return 0;
}