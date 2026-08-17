#include<iostream>
using namespace std;

const int N = 5e5 + 5;
struct Node {int pre,nxt;} a[N];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) a[i].pre = i - 1,a[i].nxt = i + 1;
    a[n].nxt = 0,a[0].nxt = 1;
    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                int x,y;
                cin >> x >> y;
                if (x == y) break;
                a[a[x].pre].nxt = a[x].nxt,
                a[a[x].nxt].pre = a[x].pre,
                a[x].pre = a[y].pre,
                a[a[y].pre].nxt = x,
                a[y].pre = x,
                a[x].nxt = y;
                break;
            } case 2 : {
                int x,y;
                cin >> x >> y;
                if (x == y) break;
                a[a[x].pre].nxt = a[x].nxt,
                a[a[x].nxt].pre = a[x].pre,
                a[x].nxt = a[y].nxt,
                a[a[y].nxt].pre = x,
                a[x].pre = y,
                a[y].nxt = x;
                break;
            } case 3 : {
                int x;
                cin >> x;
                if (a[a[x].nxt].pre != x && a[x].nxt != 0) break;
                a[a[x].pre].nxt = a[x].nxt,
                a[a[x].nxt].pre = a[x].pre;
                break;
            }
        }
    }
    if (a[0].nxt == 0) {
        cout << "Empty!" << endl;
        return 0;
    }
    for (int i = a[0].nxt;i;i = a[i].nxt) cout << i << ' ';
    cout << endl;
    return 0;
}