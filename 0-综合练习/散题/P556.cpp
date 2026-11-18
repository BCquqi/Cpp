#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 2e4 + 5;
struct Node {int v,w,y;};
vector<Node> G[N];

int main() {
    int n,m,T;
    cin >> n >> m >> T;
    for (int i = 1;i <= m;i++) {
        int s,t,l,y;
        G[s].push_back({t,l,y});
        
    }
    return 0;
}