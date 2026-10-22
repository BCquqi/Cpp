// ============================================================
// C++ Code Style Report
// Workspace: C:\Users\Administrator\Documents\C++
// Generated: 2026-10
// ============================================================
//
// 1. FILE OVERVIEW
// - Total .cpp files: 1099
// - Total code lines: 56935
// - Total code chars: 1346917
// - Average lines per file: 51.8
// - Directories: 24 (top-level)
//
// 2. FILE STRUCTURE
// - main function location: always at end of file
// - class usage: 0 files use class
// - namespace wrapping: 0 files
// - global scope: all functions and arrays at global scope
// - #define int long long + signed main(): common in 64-bit problems
// - typedef long long LL/ll: selective alternative
// - using ll = long long: 0 occurrences
// - const int N = ...: universal array sizing
//
// 3. INCLUDES
// - bits/stdc++.h: 0 occurrences
// - hand-written #include<xxx>: 100%
// - #include<xxx> no space after include: 100%
// - using namespace std;: universal
// - first include: iostream (most common)
// - include order: iostream, algorithm, vector, queue, stack, set, map, cstring, cmath, cstdio
// - each include on its own line
//
// 4. TYPES
// - #define int long long: present in 64-bit problems
// - signed main(): used with #define int long long
// - typedef long long LL: selective
// - typedef long long ll: selective
// - const int N = 1e5 + 5: spaces around +
// - mod (lowercase): universal, not MOD
// - eps = 1e-6: double problems
// - 1ll * not 1LL *: universal
// - __int128: only when needed (4 files)
//
// 5. VARIABLE NAMING
// Global arrays (short names):
// - a: primary data array
// - dp: dynamic programming
// - vis: visited marker
// - f: general array / DP
// - G: adjacency list (uppercase)
// - N: array size constant
// - M: secondary size constant
// - n, m, q, k: scale variables
// - tree, c: BIT arrays
// - siz, sz: subtree sizes
// - dep: depth
// - fa: parent
// - val: node value
// - ls, rs: left/right child
// - fix: treap priority
// - sum: prefix sum / segment tree sum
// - mx: maximum
// - lazy: lazy tag
// - lzym: multiply lazy tag
// - mod: modulus
//
// Naming patterns:
// - same-type globals on one line: int a[N],tree[N],n,q;
// - struct members: comma no space, trailing ;
// - 1-indexed arrays: universal
// - scale variables separate line: int n,m; int n,q; int n,k;
//
// Engineering/AI style contrast:
// - No long descriptive names
// - No camelCase
// - No snake_case for variables
// - Abbreviations universal
//
// 6. FUNCTIONS
// inline usage:
// - inline for: pushup, pushdown, modify, addtag, read, write, nc, popcount, cal, cmp
// - static inline: only fast read (nc)
// - static for globals: rare (6 files), only static const int MOD/BUF_SIZE
//
// Function signatures:
// - return ; (with space): 113 files
// - return; (no space): 9 files
// - return 0;: main only
// - void functions: return ; with space
// - int functions: return value;
//
// Function organization:
// - helper functions before main
// - main at end
// - no forward declarations needed
//
// Early return:
// - if (...) return x; else return y; (42 files)
// - no braces around single return
//
// 7. FORMAT DETAILS
// Indentation: 4 spaces (universal)
//
// for loops:
// - for (int i = 1;i <= n;i++): no space after ;
// - postfix i++
// - start value 1 (1-indexed), 0 for 0-indexed problems
// - condition: i <= n (not i < n+1)
//
// if/else:
// - } else { on same line
// - else on own line: unbraced case
// - single-statement if/for without braces: common
//
// Comma chaining:
// - while (id) ret += tree[id], id -= lowbit(id);
// - for (int i = l;i <= r;i++) d[i]++, d[i+1]--;
//
// switch/case:
// - switch (op) { with case N : { pattern
//
// Empty lines: minimal, between function definitions
//
// 8. I/O
// Newline:
// - endl: mainstream
// - '\n': rare
//
// Separators:
// - space: ' '
// - no space after comma in output: cout << a << ' ' << b;
//
// Fast IO:
// - ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// - static inline char nc() for fast read
//
// Read patterns:
// - cin >> n >> m; (multiple in one line)
// - for (int i = 1;i <= n;i++) cin >> a[i];
// - unbraced loop body common
//
// 9. NUMERIC
// 64-bit:
// - #define int long long + signed main()
// - typedef long long LL/ll
// - 1ll * for promotion
//
// __int128:
// - only when needed
// - custom print function
//
// Float:
// - double only, float rare
// - eps = 1e-6
//
// Mod:
// - mod (lowercase)
// - 0x3f3f3f3f for infinity (memset 0x3f)
// - -0x3f for negative infinity
//
// 10. BITWISE
// - x & 1 for parity (not x % 2)
// - x >> 1, x << 1
// - (1 << k) for masks
// - lowbit(x) = x & -x
//
// 11. STL
// - vector<int> G[N] for adjacency
// - priority_queue with operator< overload
// - sort(a+1, a+n+1, [](Node x,Node y){return x.z<y.z;})
// - lambda capture: [] (empty), [&] rare
// - auto in range-for without &: for (auto v : G[u])
// - auto for pointers/iterators
// - no emplace_back
// - no .at()
// - no memcpy
// - no auto &
//
// 12. CODE TEMPLATES
// 12.1 Basic: binary search, fast pow, high precision, DFS, BFS, union-find, topo
// 12.2 Basic DS: BIT (2 patterns), seg tree (base/+mx/+lzym/dynamic), FHQ-treap (2 variants), mono queue
// 12.3 Advanced DS: LCA (binary lifting), Mo's, tree DP
// 12.4 String: KMP, AC automaton, Manacher, string hash, high precision
// 12.5 Graph: Dijkstra, SPFA, Floyd, Kruskal, Prim, Tarjan (SCC/bcc), Euler, topo
// 12.6 DP: matrix exp, tree DP rerooting, mono queue opt, digit DP, memo search
// 12.7 Number theory: exgcd, CRT, gauss elim, sieve, combinatorics
// 12.8 Common: lowbit, gcd, swap, min/max
//
// 13. COMMENTS
// - minimal comments
// - Chinese when needed
// - no TODO/FIXME/XXX
// - no explanatory comments in code
//
// 14. DON'T WRITE LIKE THIS
// - no bits/stdc++.h
// - no class, no namespace wrapping
// - no long variable names, no camelCase, no snake_case
// - no emplace_back, no .at(), no memcpy
// - no auto &
// - no '\n' (use endl)
// - no while (--x)
// - no sizeof(x) (use sizeof x)
// - no 1LL * (use 1ll *)
// - no MOD (use mod), no EPS (use eps)
// - no inf const (use 0x3f)
// - no constexpr, no TODO/FIXME
//
// ============================================================
// END OF REPORT
// ============================================================

#include <iostream>
using namespace std;

int main() {
    cout << "C++ Style Report loaded." << endl;
    return 0;
}
