#include<iostream>
#include<algorithm>
using namespace std;

const int N = 125,Q = 1e4 + 5;
struct Question {int t,id,x,y;bool ans;} a[Q];
bool pos[N][N],exist[N][N];
// pos 为 0 向右，为 1 向下

int main() {
    freopen("darksideofthemoon.in","r",stdin);
    freopen("darksideofthemoon.out","w",stdout);
    int q,maxt = 0;
    cin >> q;
    for (int i = 1;i <= q;i++) {
        int t;
        cin >> a[i].t >> a[i].x >> a[i].y;
        a[i].id = i, a[i].ans = false;
        maxt = max(maxt,t);
    }
    sort(a + 1,a + q + 1,[](Question x,Question y) {return x.t < y.t;});
    exist[1][1] = true;
    int cur = 1;
    for (int i = 1;i <= maxt;i++) {
        for (int i = 120;i >= 1;i--)
            for (int j = 120;j >= 1;j--)
                if (exist[i][j]) {
                    exist[i][j] = false;
                    if (pos[i][j] && i + 1 <= 120) exist[i + 1][j] = true;
                    else if (!pos[i][j] && j + 1 <= 120) exist[i][j + 1] = true;
                    pos[i][j] = !pos[i][j];
                }
        exist[1][1] = true;
        if (a[cur].t == i) a[cur].ans = exist[a[cur].x + 1][a[cur].y + 1], cur++;
    }
    sort(a + 1,a + q + 1,[](Question x,Question y) {return x.id < y.id;});
    for (int i = 1;i <= q;i++) {
        if (a[i].ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}