#include<iostream>
#include<set>
using namespace std;

struct Node {
    int l,r;
    bool operator < (const Node &x) const {return r < x.l;}
};

set<Node> s;

int main() {
    int n;
    cin >> n;
    while (n--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int start,end,cnt = 0;
            cin >> start >> end;
            Node t = {start,end};
            auto it = s.find(t);
            while (it != s.end()) {
                cnt++;
                s.erase(it);
                it = s.find(t);
            }
            s.insert(t);
            cout << cnt << endl;
        }
        else cout << s.size() << endl;
    }
    return 0;
}