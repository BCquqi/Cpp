#include<iostream>
#include<queue>
using namespace std;

const int N = 1e5 + 5;
int a[N],s[N],c[N],x[N],p[N];

// 建立在反向时间运行意义上

struct Node {int val,num,appear;}; // appear 存该类蔬菜首次出现时间
priority_queue<Node> q; // 存放蔬菜价格
bool operator < (const Node &x,const Node &y) {return x.val < y.val;}

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> s[i] >> c[i] >> x[i];
        q.push({a[i] + s[i],1,0}); // 首次卖出
    }
    int maxp = 0;
    for (int i = 1;i <= k;i++) {
        cin >> p[i];
        maxp = max(maxp,p[i]);
    }
    
    return 0;
}