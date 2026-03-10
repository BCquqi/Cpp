#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int k,dis[N]; bool vis[N];

void bfs() {
    deque<int> q;
    memset(dis,0x3f,sizeof dis);
    dis[1] = 1;
    q.push_back(1);
    while (!q.empty()) {
        int x = q.front(); q.pop_front();
        int y = x * 10 % k;
        if (dis[x] < dis[y]) {
            dis[y] = dis[x];
            q.push_front(y);
        }
        y = (x + 1) % k;
        if (dis[x] + 1 < dis[y]) {
            dis[y] = dis[x] + 1;
            q.push_back(y);
        }
    }
}

int main() {
    cin >> k;
    bfs();
    cout << dis[0] << endl;
    return 0;
}