#include<iostream>
using namespace std;

const int N = 2e5 + 5;
struct Node {int val,nxt;} a[N];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].val;
        a[i].nxt = i + 1;
    }
    a[0].nxt = 1,a[n].nxt = -1;
    int cur = n;
    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                int x,y;
                cin >> x >> y;
                if (x == 0) a[++cur].val = y,a[cur].nxt = a[0].nxt,a[0].nxt = cur;
                else {
                    int id = 0;
                    for (int i = 1;i <= x;i++) id = a[id].nxt;
                    a[++cur].val = y;
                    a[cur].nxt = a[id].nxt,a[id].nxt = cur;
                }
                break;
            } case 2 : {
                int x;
                cin >> x;
                int id = 0;
                for (int i = 1;i <= x - 1;i++) id = a[id].nxt;
                a[id].nxt = a[a[id].nxt].nxt;
                break;
            }
        }
    }
    for (int i = a[0].nxt;i != -1;i = a[i].nxt) cout << a[i].val << ' ';
    cout << endl;
    return 0;
}