# 我的 C++ 码风总结（从 1090 个源文件归纳）

> 归纳自工作区内全部 `.cpp`。\
> 结论按"必须遵守"和"视情况"两档标注。写代码时以此为准。

---

## 0. 一句话画像

**竞赛实用主义紧凑码风**：手写头文件、全局定长数组、1-indexed、有需要时可以 `#define int long long` + `signed main()`、
函数式拆分（helper 在前 `main` 在后）、**基本不写注释**、`const` 只用于数组定长与模数、`for` 内分号后**不空格**、`return ;` 带空格、
语句可用逗号串联成一行，不影响码风和编译的大括号可以省去。**不用 `bits/stdc++.h`**。

---

## 1. 头文件与预处理

### 手写头文件，绝不用万能头（必须遵守）

工作区 1089 个原有文件里 `bits/stdc++.h` 出现 **0 次**。

```cpp
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
```

- **`include` 与 `<` 之间无空格**：`#include<iostream>`，不是 `#include <iostream>`。
- 顺序习惯：`iostream` → `algorithm` → `cstring` → 容器/其他。早期文件会带 `<cstdio>`。
- 需要随机时：`#include<ctime>` + `#include<cstdlib>` + `#include<random>`。

### 常用宏定义

```cpp
#define int long long
#define lid id * 2
#define rid id * 2 + 1
```

- `#define int long long` 出现频率极高，是**中后期默认写法**；早期用 `typedef long long LL;`。
- 一旦 `#define int long long`，入口必须写 **`signed main()`**。
- 宏值两侧带空格：`#define lid id * 2`。
- 偶尔需要临时关掉：`// #define int long long`（注释掉而非删掉）。

```cpp
using namespace std;
```

---

## 2. 全局区与命名

### 常量与数组

```cpp
const int N = 1e5 + 5;
const int N = 5e5 + 5,M = 1e5 + 5;      // 多常量同行逗号分隔
int a[N],dfn[N],low[N],scc[N],val[N];    // 同类型多个数组挤一行
int n,m;
```

- `const int N = 1e5 + 5;`——`+` **两侧有空格**，不用 `100005` 这种裸数字。
- 数组一律**全局定长**，不 `new`、不 `vector` 化，长度按上界 +5 余量。
- 同类型全局变量**合并声明**成一行。
- **`const` 基本只用在两处**：数组定长（`N`、`M`）、模数（`const int mod = 1e9 + 7;`）。
  不要为 `inf`、块大小、阈值等定义具名常量；这些**直接写字面量**：
  ```cpp
  int res = 1e9;              // 不是 const int inf = 1e9;
  if (res == 1e9) cout << -1 << endl;
  int a[N];                   // 阈值/规模直接内联
  ```

### 标识符风格

| 类别 | 写法 | 例 |
|---|---|---|
| 计数器 | `cnt` `cur` `idx` `num` `tot` | `int idx = 0,cnt = 0,cur = 0;` |
| 结果 | `ans` `res` `ret` | `int ret = 0;` |
| 临时 | `tmp` `now` | `auto [tmp,tmp0,tmp1] = q.top();` |
| 最值 | `mx` `mn` `maxn` `minx` `mxl` `mxr` `lmax` `rmax` | `struct seg_tree {...,lmax,rmax;}` |
| 前驱后继 | `pre` `nxt` `suf` | `int pre(int x)` / `int nxt(int x)` |
| 标记 | `flag` `vis` `bel`/`bid` `pos` | `bool flag[N];` |
| 树结构 | `ls` `rs` `sz` `fix` `val` `fa` `dep` | `struct Node {int ls,rs,sz,fix,val;}` |

命名**全小写、极短、无下划线**（`seg_tree`、`seg_tree` 是唯一常见的下划线用法）。

---

## 3. 结构体

### 一行成员 + 同行实例化（必须遵守）

```cpp
struct Edge {int v,w;};
struct Node {int x,y;} a[N];
struct Query {int op,l,r;} qq[N];
struct seg_tree {int l,r,lazy,sum,lzym;} tr[N << 2];
struct Matrix {int a[N][N];};
struct Block {int l,r,lazy;} block[N];
struct Point {int x,y;} a[N];
```

- 成员**全部写在同一行**，`{...}` 与 `struct` 同行。
- 段树统一命名 `seg_tree`/`Segment_Tree`，实例 `tr[N << 2]`；偶尔 `tr[N << 3]`。
- 图的边：`struct Edge {int v,w;};` 配 `vector<Edge> G[N];`
- 带额外权值就加成员，不另开结构：`struct Node {int u,v,len,w;} a[2 * N];`
- 需要时加注释说明字段含义：
  ```cpp
  struct Node {int val,id,appear;}; // appear 存该类蔬菜首次出现时间
  ```

---

## 4. 格式细节（这是码风最显眼的部分）

### 4.1 `for` 循环：分号后**不空格**（必须遵守）

```cpp
for (int i = 1;i <= n;i++)
for (int i = 1;i <= n;i++)
    for (int j = 1;j <= m;j++)
for (int i = 0;i <= x;i++)
```

对比：`i = 1`（`=` 两侧有空格）、`i <= n`（`<=` 两侧有空格），但 `;` 后面**直接跟** `i++`。
这是全局最一致的签名式写法。

### 4.2 大括号与缩进

- 函数左括号同行：`int main() {`、`void build(int id,int l,int r) {`
- 4 空格缩进（早期 J1/J2 少数文件用 Tab，现统一空格）。
- 单语句 `if` 也常带花括号；短分支可写一行：
  ```cpp
  if (x == 1) {cout << "NO" << endl; return ;}
  if (ans == 1e9) cout << -1 << endl;
  else cout << ans << endl;
  ```

### 4.3 `return ;` —— void 函数返回值前留空格（必须遵守）

```cpp
void init() {
    ...
    return ;
}
void solve() {
    ...
    return ;
}
```

`main` 正常写 `return 0;`。

### 4.4 逗号串联语句（常见）

```cpp
tr[id].l = l,tr[id].r = r,tr[id].lzym = 1;
dep[u] = dep[pa] + 1, fa[u] = pa;
tr[id].lazy = 0,tr[id].lzym = 1;
a[l] = x, b[l] = y;
cout.tie(0);
```
把同组赋值用 `,` 串一行，`cin.tie(0), cout.tie(0);` 也是这个习惯的体现。

### 4.5 函数参数列表

参数间**无空格**：`void build(int id,int l,int r)`、`int query(int l,int r,int c)`。
定义与调用风格一致：`query(1,x,y)`。

### 4.6 空行

- 函数之间空 **一行**。
- 全局区与函数区之间空一行。
- 不写多余的连续空行。

---

## 5. 输入输出

### 默认组合（必须遵守）

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ...
}
```

- `ios::sync_with_stdio(false);` 用 `false`，不用 `(0)`（少数文件写 `(0)`）。
- **`cin.tie(0), cout.tie(0);` 用逗号连接**——高频签名细节。
- 主体用 `cin >>` / `cout <<`。

### 换行

- 历史主流：`cout << ans << endl;`（1000+ 处）。
- 新近部分文件开始用 `cout << ans << '\n';`。**两者都可**，同文件内保持一致，`'\n'` 优先用于输出量大的场合。

### 早期/备用写法

- 早期（J1/J2/S1）用 `scanf` / `printf`：`scanf("%lld%lld%lld",&a,&b,&p);`
- 竞赛/测试题：文件读写，**`freopen` 放在 main 开头**，逗号后无空格：
  ```cpp
  freopen("city.in","r",stdin);
  freopen("darksideofthemoon.out","w",stdout);
  ```
  调试时用注释切换：`// freopen("axis.in", "r", stdin);`

---

## 6. 常用套路写法

### 6.1 memset

```cpp
memset(dp,0x3f,sizeof dp);          // sizeof 后不写括号
memset(flag,false,sizeof flag);
memset(tree, 0, sizeof(tree[0]) * (m + 1));   // 只清有效部分时用这种
```

### 6.2 多测函数化

```cpp
void solve() {
    ...
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
```
单次询问则 `while (q--) { ... }` / `while (m--) { ... }`。

### 6.3 图的存储与遍历 —— 结构化绑定是标配

```cpp
vector<Edge> G[N];

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1, fa[u] = pa;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}
```
- `for (auto [v,w] : G[u])` 是**最典型的遍历签名**，不带引用（需要改写时用 `for (auto &[v,w] : G[u])`）。
- `auto [l,r] = a[i];`、`auto [id,thr] = pq.top();` 直接解包。
- 取堆顶解包：`auto [tmp,tmp0,tmp1] = q.top(); q.pop();`

### 6.4 排序 + lambda

```cpp
sort(a + 1,a + m + 1,[](Node p,Node q) {return p.x != q.x ? p.x > q.x : p.y > q.y;});
sort(id + 1,id + n + 1,[&](int x,int y) {return a[x] != a[y] ? a[x] > a[y] : x > y;});
```
- lambda **参数写具体类型**（`Node p,Node q`），不用 `auto`。
- 捕获用 `[]` 或 `[&]`。
- 多关键字排序写成三目链。
- 1-indexed：`sort(a + 1,a + n + 1);`

### 6.5 段树

```cpp
#define lid id * 2
#define rid id * 2 + 1
struct seg_tree {int l,r,lazy,sum} tr[N << 2];

void pushdown(int id) {
    if ((tr[id].lazy || tr[id].lzym != 1) && tr[id].l != tr[id].r) {
        ...
    }
}
```
- 区间递归写法：`if (r <= mid) ...; else if (l > mid) ...; else ..., ...;`
- 用 `lid`/`rid` 宏。

### 6.6 树状数组

```cpp
int lowbit(int x) {return x & -x;}
void add(int x,int val,int lim) {while (x <= lim) tree[x] += val, x += lowbit(x);}
long long query(int x) {
    long long ans = 0;
    while (x > 0) ans += tree[x], x -= lowbit(x);
    return ans;
}
```
循环体内用**逗号串联**代替花括号是常见选择。

### 6.7 无穷大与判无解

```cpp
int res = 1e9;                  // 直接写字面量，不定义 const int inf
int ans = -1e9;
if (ans == 1e9) cout << -1 << endl;
else cout << ans << endl;
if (ans >= 1e6) cout << -1 << endl;
```

需要真正的"极大值"参与加法时用 `0x3f3f3f3f` / `0x3f3f3f3f3f3f3f3f`（`memset` 也好用）。

---

## 7. 注释风格

- **基本不写注释**。除非确实有必要（多测 `solve()` 之间、文件顶部题面推导），否则整份代码可以零注释。
- 需要写时用**中文** `//`：只解释"为什么"和"坑在哪"，不解释语法。
- 给关键变量/字段加尾注释是少数允许的例外：`struct Node {int val,id,appear;}; // appear 存该类蔬菜首次出现时间`
- 分段推导用 `1 2 3` 编号列出（见 `交易市场.cpp`）。
- **不要在代码行尾解释每一步在做什么**（这一条最常犯）。

---

## 8. 文件组织

```
头文件 → using namespace std; → #define → const 与全局数组 → struct → helper 函数 → main
```

- **helper 在 `main` 之前**，`main` 永远放最后。
- 常用函数名：`build` `pushup` `pushdown` `query` `modify`/`update` `add` `init` `dfs` `solve` `check` `calc` `create` `merge` `split`。
- `main` 结构：`ios` → 读入 → `init()`/`build()` → 处理循环 → `return 0;`。
- `inline` 只偶尔用于极短函数（`inline void print()`）。

---

## 9. 写作习惯清单（写新代码时逐条自检）

1. [ ] 手写 `#include`，不用 `bits/stdc++.h`
2. [ ] `using namespace std;`
3. [ ] 要 64 位就 `#define int long long` + `signed main()`
4. [ ] `const int N = ...;` 全局定长数组，1-indexed
5. [ ] struct 成员写一行，同行定义数组
6. [ ] `for (int i = 1;i <= n;i++)` —— 分号后不空格
7. [ ] void 函数 `return ;`
8. [ ] `ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);`
9. [ ] 图遍历 `for (auto [v,w] : G[u])`
10. [ ] `memset(x,0,sizeof x)`
11. [ ] **基本不写注释**（写就写中文、只写坑点）
12. [ ] 函数之间空一行，`main` 在最后
13. [ ] 竞赛题记得 `freopen("x.in","r",stdin);`
14. [ ] 必要的同组赋值用 `,` 串一行
15. [ ] `const` 只用于数组定长和模数；`inf`/阈值直接写字面量

---

## 10. 需要注意的是（与我的默认输出的差异）

我之前写的 `P5065.cpp` 有以下**不符合你码风**之处，后续应改正：

| 问题 | 我的写法 | 你的码风 |
|---|---|---|
| 头文件 | `#include <bits/stdc++.h>` | 手写各头文件 |
| 宏 | 无 | 视需要 `#define int long long` |
| `for` | `for (int j = st[i]; j <= ed[i]; j++)` | `for (int j = st[i];j <= ed[i];j++)` |
| void 返回 | `return;`（无空格） | `return ;` |
| 结构体 | `pii` / `std::pair` | 自定义 `struct Node {int x,y;}` |
| 换行 | `printf("%d\n", ...)` | `cout << ... << endl` |
| 全局数组长度 | 常量拼接 `MAXN / B + 5` | `const int N = 5e4 + 5;` 直给上界 |

补充（第二轮修正，针对 `2026-9-10-11\数据结构\不归之人与望眼欲穿的人们.cpp`）：

| 问题 | 我的写法 | 你的码风 |
|---|---|---|
| 注释 | 每行都加说明性尾注释 | **全部删掉**，代码零注释 |
| `const` | `const int inf = 1e9;`、`const int B = 180;` | 只有数组定长/模数用 `const`；`inf` 写 `int res = 1e9;` |
| 分块变量名 | `bel[]`、`bc` | `pos[]`、`num` |
| 结构体成员名 | `len`/`all` 之类语义名 | `l`/`r`，块长用 `len[i]` 数组另存 |
