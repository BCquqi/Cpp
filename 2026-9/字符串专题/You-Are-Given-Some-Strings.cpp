#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5,mod = 1e9 + 7,P = 129;
string t,s[N];
int n,m;
vector<int> len;
ll power[N],hs[N];
unordered_map<int,unordered_set<ll>> mp;

void init() {
    for (int i = 0;i < t.size();i++) {
        power[i] = power[i - 1] * P % mod;
        hs[i] = (hs[i - 1] * P % mod + t[i]) % mod;
    }
    for (int i = 1;i <= n;i++) {
        int tmphs = 0;
        for (int j = 0;j < s[i].size();j++)
            tmphs = (tmphs * P % mod + s[i][j]) % mod;
        len.push_back(s[i].size());
        mp[s[i].size()].insert(tmphs);
    }
    sort(len.begin(),len.end());
    len.erase(unique(len.begin(),len.end()),len.end());
    m = len.size();
    return ;
}

int main() {
    cin >> t >> n;
    for (int i = 1;i <= n;i++) cin >> s[i];
    init();
    return 0;
}