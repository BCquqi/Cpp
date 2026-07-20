#include<iostream>
using namespace std;

const int N = 1e6 + 5;
int id = 1;

struct Node {
    int sum = 0,cnt = 0;
    Node *ch[26];
} Trie[N];

Node *newNode() {
    Node *p = &Trie[++id];
    for (int i = 0;i < 26;i++) p -> ch[i] = nullptr;
    return p;
}

Node *root = newNode();

void insert(string s) {
    Node *x = root;
    for (auto c : s) {
        int i = c - 'a';
        if (x -> ch[i] == nullptr) x -> ch[i] = newNode();
        x = x -> ch[i];
        x -> sum++;
    }
    x -> cnt++;
}

int query(string s) {
    Node *x = root;
    for (auto c : s) {
        int i = c - 'a';
        if (x -> ch[i] == nullptr) return 0;
        x = x -> ch[i];
    }
    return x -> sum;
}

int main() {
    int n,q;
    cin >> n >> q;
    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }
    while (q--) {
        string s;
        cin >> s;
        cout << query(s) << endl;
    }
    return 0;
}