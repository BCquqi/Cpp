#include<iostream>
#include<cstdlib>
using namespace std;

const int N = 305,M = 605;
int id[M],sl[M],sr[M];
int n,ans;

int two[N],one[N];
int onlyl[N],onlyr[N],brg[N];
int onesl[N],onesr[N];

bool ask(int x,int *s,int len) {
    if (!len) return false;
    cout << "? " << x << ' ' << len;
    for (int i = 1;i <= len;i++) cout << ' ' << s[i];
    cout << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res == 1;
}

int solve(int l,int r) {
    if (l == r) {
        if (one[0] > 0) return one[1];
        return two[1];
    }
    int mid = (l + r) >> 1;
    int lenL = mid - l + 1,lenR = r - mid;
    for (int i = l;i <= mid;i++) sl[i - l + 1] = id[i];
    for (int i = mid + 1;i <= r;i++) sr[i - mid] = id[i];
    int cntl = 0,cntr = 0,cntb = 0;
    int cntol = 0,cntor = 0;
    for (int i = 1;i <= two[0];i++) {
        int v = two[i];
        bool inl = ask(v,sl,lenL),inr = ask(v,sr,lenR);
        if (inl && inr) brg[++cntb] = v;
        else if (inl) onlyl[++cntl] = v;
        else if (inr) onlyr[++cntr] = v;
    }
    for (int i = 1;i <= one[0];i++) {
        int v = one[i];
        if (ask(v,sl,lenL)) onesl[++cntol] = v;
        else onesr[++cntor] = v;
    }
    int score = 2 * cntl + cntol - (lenL - cntb);
    if (score == 1) {
        two[0] = cntl;
        for (int i = 1;i <= cntl;i++) two[i] = onlyl[i];
        one[0] = cntol + cntb;
        for (int i = 1;i <= cntol;i++) one[i] = onesl[i];
        for (int i = 1;i <= cntb;i++) one[cntol + i] = brg[i];
        return solve(l,mid);
    } else {
        two[0] = cntr;
        for (int i = 1;i <= cntr;i++) two[i] = onlyr[i];
        one[0] = cntor + cntb;
        for (int i = 1;i <= cntor;i++) one[i] = onesr[i];
        for (int i = 1;i <= cntb;i++) one[cntor + i] = brg[i];
        return solve(mid + 1,r);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1;i <= 2 * n - 1;i++) id[i] = i;
        for (int i = 1;i <= 2 * n - 1;i++) {
            int j = rand() % (2 * n - 1) + 1;
            swap(id[i],id[j]);
        }
        two[0] = n;
        one[0] = 0;
        for (int i = 1;i <= n;i++) two[i] = i;
        ans = solve(1,2 * n - 1);
        cout << "! " << ans << endl;
    }
    return 0;
}