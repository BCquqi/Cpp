#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const ll mod = 998244353,P = 129;
string t[N],s;
ll power[N],hs[N];
vector<int> len;
unordered_map<ll,bool> mp;
int n,m;

char st[N];
ll top = 0;

ll Hash(int l,int r) {return (hs[r] - hs[l - 1] * power[r - l + 1] % mod + mod) % mod;}

void init() {
    power[0] = 1;
    for (int i = 1;i <= s.size();i++) power[i] = power[i - 1] * P % mod;
    for (int i = 1;i <= n;i++) {
        ll tmphs = 0;
        len.push_back(t[i].size());
        for (int j = 0;j < t[i].size();j++)
            tmphs = (tmphs * P % mod + t[i][j]) % mod;
        mp[tmphs] = true;
    }
    sort(len.begin(),len.end(),greater<int>());
    len.erase(unique(len.begin(),len.end()),len.end());
    m = len.size();
    return ;
}

int main() {
    cin >> s;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> t[i];
    init();
    for (int i = 0;i < s.size();i++) {
        st[++top] = s[i];
        hs[top] = (hs[top - 1] * P % mod + s[i]) % mod;
        for (int j = 0;j < m;j++) {
            if (top < len[j]) continue;
            if (mp.count(Hash(top - len[j] + 1,top))) top -= len[j];
        }
    }
    for (int i = 1;i <= top;i++) cout << st[i];
    cout << endl;
    return 0;
}