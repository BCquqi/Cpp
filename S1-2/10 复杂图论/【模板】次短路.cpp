#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dis[N],dis2[N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	memset(dis2,0x3f,sizeof dis2);
	priority_queue<Edge> q;
    dis[1] = 0;
    q.push({1,0});
    while (!q.empty()) {
    	int u = q.top().v,d = q.top().w; q.pop();
    	for (auto [v,w] : G[u]) {
    		int t = d + w;
    		if (t < dis[v]) {
    			dis2[v] = dis[v];
    			dis[v] = t;
    			q.push({v,dis[v]});
    		}
            else if (t > dis[v] && t < dis2[v]) {
            	dis2[v] = t;
            	q.push({v,dis2[v]});
            }
    	}
    }
    return ;
}

int main() {
	int n,r;
	cin >> n >> r;
	for (int i = 1;i <= r;i++) {
		int a,b,d;
		cin >> a >> b >> d;
		G[a].push_back({b,d}); G[b].push_back({a,d});
	}
	dijkstra();
	cout << dis2[n] << endl;
	return 0;
}