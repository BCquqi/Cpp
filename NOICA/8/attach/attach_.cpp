#include<iostream>
#include<queue>
using namespace std;

const int N = 5e5 + 5;
int p[N],q[N],flag[N],ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("attach.in","r",stdin);
    freopen("attach.out","w",stdout);
    int n;
    cin >> n;
    bool specialA = true,specialB = true,specialC = true,specialD = true;
    for (int i = 1;i <= n;i++) {
        cin >> p[i];
        specialC &= (p[i] > p[i - 1]), 
        specialD &= (p[i] < p[i - 1]);
    }
    for (int i = 1;i <= n;i++) {
        cin >> q[i];
        specialA &= (q[i] > q[i - 1]), 
        specialB &= (q[i] < q[i - 1]);
    }
    if (specialA) {
        for (int i = n;i >= 1;i--)
            ans[i] = max(ans[i + 1],p[i]);
        for (int i = 1;i <= n;i++)
            cout << ans[i] << ' ';
        cout << endl;
    } else {
        for (int i = 1;i <= n;i++) {
            priority_queue<int> pq;
            for (int j = 1;j <= n;j++) {
                pq.push(p[j]);
                if (flag[j]) pq.pop();
            }
            cout << pq.top() << ' ';
            flag[q[i]] = true;
        }
    }
    cout << endl;
    return 0;
}