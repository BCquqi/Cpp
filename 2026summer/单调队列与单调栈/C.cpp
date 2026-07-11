#include<iostream>
#include<stack>
using namespace std;

const int N = 1e5 + 5;
int h[N],ans[N];
stack<int> st;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> h[i];
    for (int i = n;i >= 1;i--) {
        while (!st.empty() && h[i] >= h[st.top()]) st.pop();
        ans[i] = (st.empty() ? 0 : st.top());
        st.push(i);
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
    return 0;
}