#include<iostream>
using namespace std;

const int N = 5e3 + 5,M = 1e6 + 5;
int x[N],y[N],dis[N],vis[N],cnt = 0,ans = 0,n,c;

int distance(int a,int b) {return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);}

void prim() {
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    dis[1] = 0;
    for (int i = 1;i <= n;i++) {
        int u = 0;
        for (int j = 1;j <= n;j++)
            if (!vis[j] && dis[j] < dis[u]) u = j;
        vis[u] = true;
        if (u != 0) cnt++;
        ans += dis[u];
        for (int y = 1;y <= n;y++) {
            int d = distance(x,y);
            if (d < c) continue;
        }
    }
}

int main() {
    cin >> n >> c;
    for (int i = 1;i <= n;i++) cin >> x[i] >> y[i];
    prim();
    return 0;
}