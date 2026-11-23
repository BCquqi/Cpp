#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 3005;
int m[N],unq[N],cur1 = 0,cur2 = 0;
long long a,b,ret;

void init(int x) {
    if (x > 1e10) return ;
    m[++cur1] = x;
    init(10 * x + 6); init(10 * x + 8);
}

void unique() {
    for (int u = 1;u <= cur1;u++) {
        bool flag = false;
        for (int v = 1;v <= cur2;v++)
            if (m[u] % unq[v] == 0) {
                flag = true;
                break ;
            }
        if (!flag) unq[++cur2] = m[u];
    }
}

int gcd(int x,int y) {return (x ? gcd(y % x,x) : y);}

void dfs(int pos,int lcm,int x,int tmp) {
    if (lcm > x) return ;
    if (pos < 1) { // 越界，搜索出口
        if (tmp % 2) ret += x / lcm;
        else if (tmp) ret -= x / lcm;
        return ;
    }
    __int128 tmp2 = (__int128)lcm / gcd(lcm,unq[pos]) * unq[pos];
    if (tmp2 <= x) dfs(pos - 1,(long long) tmp2,x,tmp + 1);
    dfs(pos - 1,lcm,x,tmp);
}

int calc(int x) {
    ret = 0;
    int pos = upper_bound(unq + 1,unq + cur2 + 1,x) - unq;
    dfs(pos - 1,1,x,0);
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    init(6); init(8); 
    sort(m + 1,m + cur1 + 1);
    unique();
    cout << (calc(b) - calc(a - 1)) << endl;
    return 0;
}