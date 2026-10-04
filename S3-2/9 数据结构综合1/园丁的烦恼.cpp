#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e7 + 5;
struct Query {int id,op,x,y,tag;};
vector<Query> q;
int a[N],ans[N],n,m,maxy = 0;

int lowbit(int x) {return x & -x;};
void modify(int x,int val) {
    while (x <= maxy)
        a[x] += val, x += lowbit(x);
}
int query(int x) {
    int ret = 0;
    while (x)
        ret += a[x], x -= lowbit(x);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int x,y;
        cin >> x >> y;
        x++, y++;
        q.push_back({0,1,x,y,0});
        maxy = max(maxy,y);
    }
    for (int i = 1;i <= m;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a++, b++, c++, d++;
        q.push_back({i,2,c,d,1}), 
        q.push_back({i,2,a - 1,b - 1,1}), 
        q.push_back({i,2,a - 1,d,-1}), 
        q.push_back({i,2,c,b - 1,-1});
    }
    sort(q.begin(),q.end(),[](Query u,Query v) {
        return u.x != v.x ? u.x < v.x : u.id < v.id;
    });
    for (auto [id,op,x,y,tag] : q) {
        if (y <= 0) continue;
        if (op == 1)
            modify(y,1);
        else
            ans[id] += tag * query(min(y,maxy));
    }
    for (int i = 1;i <= m;i++) cout << ans[i] << endl;
    return 0;
}