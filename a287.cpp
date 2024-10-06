#include<bits/stdc++.h>
using namespace std;

struct node{
    node* pre = nullptr,* pos = nullptr;
    string word;
};

class dict{
    public:
    node* head = nullptr;

    string use(int index){
        node* curn = head;
        while(index--){
            curn = curn->pos;
        }
        if(curn->pre) curn->pre->pos = curn->pos;
        else head = curn->pos; // Update head if curn is the first node
        if(curn->pos) curn->pos->pre = curn->pre;
        string word = curn->word;
        delete curn;
        this->push_f(word);
        return word;
    }

    void push_f(string word){
        node* n = new node;
        n->word = word;
        if(head != nullptr){
            head->pre = n;
            n->pos = head;
        }
        head = n;
    }
};

int main(){
    char in;
    string word = "", ans = "";
    int num = 0;
    dict dic;
    while(1){
        in = cin.get();
        if(in == '0' && ans.back() == '\n'){
            if(num){
                ans+=dic.use(num-1);
                num = 0;
            }
            break;
        }
        if(in >= 'a' && in <= 'z' || in >= 'A' && in <= 'Z'){
            if(num){
                ans+=dic.use(num-1);
                num = 0;
            }
            word += in;
            ans += in;
        } else if (in >= '0' && in <= '9') {//in end, number should -1 before use in use()
            if(!word.empty()){
                dic.push_f(word);
                word.clear();
            }
            num *= 10;
            num += in-'0';
        } else {
            if(num){
                ans+=dic.use(num-1);
                num = 0;
            }
            if(!word.empty()){
                dic.push_f(word);
                word.clear();
            }
            ans+=in;
        }
    }
    cout << ans;
    return 0;
}