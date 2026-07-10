#include<iostream>
using namespace std;

const int N = 1e6 + 5;
int nxt[N];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                int x,y;
                cin >> x >> y;
                nxt[y] = nxt[x],nxt[x] = y;
                break;
            }
            case 2 : {
                int x;
                cin >> x;
                cout << nxt[x] << endl;
                break;
            }
            case 3 : {
                int x;
                cin >> x;
                nxt[x] = nxt[nxt[x]];
                break;
            }
        }
    }
    return 0;
}