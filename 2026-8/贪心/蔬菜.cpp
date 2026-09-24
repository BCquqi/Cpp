#include<iostream>
#include<queue>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N],s[N],c[N],x[N],p[N];
// a 收益, s 首付额外收益, c 库存, x 每天结束(正向)的变质
int ans[N],cnt[N],flag[N];
// ans 表示卖 i 天的收益, cnt 表示已卖数量, flag 表示是否首次卖出

// 建立在反向时间运行意义上

struct Node {int val,id,appear;}; // appear 存该类蔬菜首次出现时间
struct cmpST {bool operator() (const Node &x,const Node &y) {return x.appear < y.appear;}};
struct cmpQ {bool operator() (const Node &x,const Node &y) {return x.val < y.val;}};
struct cmpLOSS {bool operator() (const Node &x,const Node &y) {return x.val > y.val;}};
priority_queue<Node,vector<Node>,cmpST> st; // 存放未出售的蔬菜
priority_queue<Node,vector<Node>,cmpQ> q; // 存放当日可以出售的蔬菜
priority_queue<Node,vector<Node>,cmpLOSS> loss; // 每天倒推所需维护的丢弃代价

signed main() {
    int n,m,k; // 蔬菜种类数目 每日出售上限 问题个数
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++)
        cin >> a[i] >> s[i] >> c[i] >> x[i];
    int maxp = 0;
    for (int i = 1;i <= k;i++) {
        cin >> p[i];
        maxp = max(maxp,p[i]);
    }
    for (int i = 1;i <= n;i++)
        if (x[i] == 0) st.push({a[i] + s[i],i,maxp});
        else st.push({a[i] + s[i],i,min((c[i] + x[i] - 1) / x[i],maxp)});
    for (int i = maxp; i >= 1;i--) {
        while (!st.empty() && st.top().appear == i) {
            auto cpy = st.top(); st.pop();
            q.push(cpy);
        }
        int num = m;
        queue<int> cache;
        while (num && !q.empty()) {
            auto cpy = q.top(); q.pop();
            if (!flag[cpy.id]) {
                flag[cpy.id] = true, cnt[cpy.id]++, ans[maxp] += cpy.val;
                if (c[cpy.id] != 1) q.push({a[cpy.id],cpy.id,cpy.appear});
                num--;
            } else {
                int avail = c[cpy.id] - cnt[cpy.id] - (i - 1) * x[cpy.id], 
                spend = min(avail,num);
                cnt[cpy.id] += spend, ans[maxp] += spend * cpy.val;
                if (c[cpy.id] != cnt[cpy.id]) cache.push(cpy.id);
                num -= spend;
            }
        }
        while (!cache.empty()) {
            int id = cache.front(); cache.pop();
            q.push({a[id],id,0});
        }
    }
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        if (cnt[i] == 1) loss.push({a[i] + s[i],i,0});
        else if (cnt[i] != 0) loss.push({a[i],i,0});
        sum += cnt[i];
    }
    for (int i = maxp - 1;i >= 1;i--) {
        ans[i] = ans[i + 1];
        if (sum <= m * i) continue;
        int num = sum - m * i;
        while (num && !loss.empty()) {
            auto cpy = loss.top(); loss.pop();
            if (cnt[cpy.id] != 1) {
                int spend = min(num,cnt[cpy.id] - 1);
                cnt[cpy.id] -= spend, ans[i] -= spend * cpy.val, num -= spend;
                if (cnt[cpy.id] == 1)
                    loss.push({a[cpy.id] + s[cpy.id],cpy.id,0});
                else loss.push({a[cpy.id],cpy.id,0});
            }
            else cnt[cpy.id]--, ans[i] -= cpy.val, num--;
        }
        sum = m * i;
    }
    for (int i = 1;i <= k;i++)
        cout << ans[p[i]] << endl;
    return 0;
}