import os, re
from collections import Counter, defaultdict

ROOT = r"C:\Users\Administrator\Documents\C++"
OUT = os.path.join(ROOT, "log")

files = []
for dp, dn, fn in os.walk(ROOT):
    for f in fn:
        if f.endswith(".cpp"):
            files.append(os.path.join(dp, f))

def read_file(path):
    for enc in ["utf-8","gbk","latin-1"]:
        try:
            with open(path,"r",encoding=enc) as fh: return fh.read()
        except: continue
    return ""

def dir_of(f): return os.path.relpath(f,ROOT).split(os.sep)[0]

# D1: Per-directory detailed style profile (all markers for each dir)
profile = defaultdict(lambda: defaultdict(int))
for f in files:
    d = dir_of(f)
    c = read_file(f)
    profile[d]["files"] += 1
    profile[d]["endl"] += c.count("endl")
    profile[d]["return_space"] += len(re.findall(r"return ;",c))
    profile[d]["return_nospace"] += len(re.findall(r"return;",c))
    profile[d]["sizeof_noparen"] += len(re.findall(r"sizeof [a-zA-Z_]",c))
    profile[d]["sizeof_paren"] += len(re.findall(r"sizeof\(",c))
    profile[d]["brace_else"] += len(re.findall(r"\}\s*else\s*\{",c))
    profile[d]["allman"] += 1 if re.search(r"(while|for|if)\s*\([^)]*\)\s*\n\s*\{",c) else 0
    profile[d]["define_int_ll"] += 1 if "#define int long long" in c else 0
    profile[d]["signed_main"] += 1 if "signed main" in c else 0
    profile[d]["fast_read"] += 1 if "static inline char nc" in c else 0
    profile[d]["sync_stdio"] += 1 if "sync_with_stdio" in c else 0
    profile[d]["bits_stdc"] += 1 if "bits/stdc" in c else 0
    profile[d]["emplace_back"] += c.count("emplace_back")
    profile[d]["auto_ref"] += len(re.findall(r"auto\s*&",c))
    profile[d]["memset"] += c.count("memset")
    profile[d]["scanf"] += c.count("scanf")
    profile[d]["printf"] += c.count("printf")
    profile[d]["lambda"] += len(re.findall(r"\[\s*\]",c))
    profile[d]["range_for"] += len(re.findall(r"for\s*\(\s*auto\s+\w+\s*:\s*\w+",c))
    profile[d]["vector_adj"] += 1 if re.search(r"vector<\w+>\s+G\[",c) else 0
    profile[d]["matrix_adj"] += 1 if re.search(r"int\s+G\[\w+\]\[\w+\]",c) else 0
    profile[d]["2d_array"] += 1 if re.search(r"\w+\s*\[\s*\w+\s*\]\s*\[\s*\w+\s*\]",c) else 0

with open(os.path.join(OUT,"D1_dir_profile.txt"),"w",encoding="utf-8") as fh:
    hdr = "dir|files|endl|ret_space|ret_nospace|sizeof_np|sizeof_p|brace_else|allman|def_int_ll|signed_main|fast_read|sync_stdio|bits_stdc|emplace|auto_ref|memset|scanf|printf|lambda|range_for|vec_adj|mat_adj|2d_arr"
    fh.write(hdr+"\n")
    for d in sorted(profile):
        p = profile[d]
        fh.write(f"{d}|{p['files']}|{p['endl']}|{p['return_space']}|{p['return_nospace']}|{p['sizeof_noparen']}|{p['sizeof_paren']}|{p['brace_else']}|{p['allman']}|{p['define_int_ll']}|{p['signed_main']}|{p['fast_read']}|{p['sync_stdio']}|{p['bits_stdc']}|{p['emplace_back']}|{p['auto_ref']}|{p['memset']}|{p['scanf']}|{p['printf']}|{p['lambda']}|{p['range_for']}|{p['vector_adj']}|{p['matrix_adj']}|{p['2d_array']}\n")

# D2: Template code snippets (first 30 lines of each template file)
tmpl_files = [f for f in files if "【模板】" in f]
with open(os.path.join(OUT,"D2_template_snippets.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(tmpl_files):
        c = read_file(f)
        lines = c.splitlines()[:25]
        fh.write(f"\n===== {os.path.relpath(f,ROOT)} =====\n")
        fh.write("\n".join(lines)+"\n")

# D3: Detailed function patterns per directory
func_by_dir = defaultdict(Counter)
for f in files:
    d = dir_of(f)
    c = read_file(f)
    for m in re.finditer(r"(?:void|int|long long|bool|double|char|ll)\s+(\w+)\s*\(", c):
        func_by_dir[d][m.group(1)] += 1
with open(os.path.join(OUT,"D3_func_by_dir.txt"),"w",encoding="utf-8") as fh:
    for d in sorted(func_by_dir):
        fh.write(f"\n--- {d} ---\n")
        for name,cnt in func_by_dir[d].most_common(20):
            fh.write(f"  {name}:{cnt}\n")

# D4: Variable naming by directory
var_by_dir = defaultdict(Counter)
for f in files:
    d = dir_of(f)
    c = read_file(f)
    for m in re.finditer(r"(?:int|long long|bool|char|double|ll)\s+(\w+)\s*[=,\[]", c):
        var_by_dir[d][m.group(1)] += 1
with open(os.path.join(OUT,"D4_var_by_dir.txt"),"w",encoding="utf-8") as fh:
    for d in sorted(var_by_dir):
        fh.write(f"\n--- {d} ---\n")
        for name,cnt in var_by_dir[d].most_common(15):
            fh.write(f"  {name}:{cnt}\n")

# D5: Include patterns by directory
inc_by_dir = defaultdict(Counter)
for f in files:
    d = dir_of(f)
    c = read_file(f)
    for m in re.finditer(r"#include\s*[<\"]([^>\"]+)[>\"]", c):
        inc_by_dir[d][m.group(1)] += 1
with open(os.path.join(OUT,"D5_inc_by_dir.txt"),"w",encoding="utf-8") as fh:
    for d in sorted(inc_by_dir):
        fh.write(f"\n--- {d} ---\n")
        for name,cnt in inc_by_dir[d].most_common(10):
            fh.write(f"  {name}:{cnt}\n")

# D6: Struct definitions with fields
with open(os.path.join(OUT,"D6_structs_detail.txt"),"w",encoding="utf-8") as fh:
    struct_counter = Counter()
    struct_examples = defaultdict(list)
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"struct\s+(\w+)\s*\{([^}]*)\}", c, re.DOTALL):
            name = m.group(1)
            body = " ".join(m.group(2).split())
            struct_counter[name] += 1
            if len(struct_examples[name]) < 3:
                struct_examples[name].append((os.path.relpath(f,ROOT), body[:200]))
    for name,cnt in struct_counter.most_common(40):
        fh.write(f"\n{name}:{cnt}\n")
        for rel,body in struct_examples[name]:
            fh.write(f"  {rel}: {body}\n")

# D7: Define/macro details
with open(os.path.join(OUT,"D7_defines_detail.txt"),"w",encoding="utf-8") as fh:
    define_counter = Counter()
    define_examples = defaultdict(set)
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"#define\s+(\w+)\s*(.*)", c):
            name = m.group(1)
            val = m.group(2).strip()[:60]
            define_counter[name] += 1
            if len(define_examples[name]) < 5:
                define_examples[name].add(val)
    for name,cnt in define_counter.most_common(40):
        fh.write(f"\n{name}:{cnt} vals={list(define_examples[name])}\n")

# D8: Loop patterns detail
with open(os.path.join(OUT,"D8_loops_detail.txt"),"w",encoding="utf-8") as fh:
    loop_patterns = Counter()
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"for\s*\([^)]*\)", c):
            loop_patterns[m.group(0).strip()] += 1
    for pat,cnt in loop_patterns.most_common(40):
        fh.write(f"{cnt}: {pat}\n")

# D9: If/else patterns detail
with open(os.path.join(OUT,"D9_ifelse_detail.txt"),"w",encoding="utf-8") as fh:
    if_patterns = Counter()
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"if\s*\([^)]*\)\s*\{?", c):
            p = m.group(0).strip()[:80]
            if_patterns[p] += 1
    for pat,cnt in if_patterns.most_common(30):
        fh.write(f"{cnt}: {pat}\n")

# D10: Memset patterns detail
with open(os.path.join(OUT,"D10_memset_detail.txt"),"w",encoding="utf-8") as fh:
    memset_patterns = Counter()
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"memset\s*\([^)]*\)", c):
            memset_patterns[m.group(0).strip()] += 1
    for pat,cnt in memset_patterns.most_common(30):
        fh.write(f"{cnt}: {pat}\n")

# D11: Comment examples (chinese comments)
with open(os.path.join(OUT,"D11_comments_detail.txt"),"w",encoding="utf-8") as fh:
    cn_comments = Counter()
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"//.*", c):
            line = m.group(0).strip()
            if any('\u4e00' <= ch <= '\u9fff' for ch in line):
                cn_comments[line] += 1
    for cmt,cnt in cn_comments.most_common(40):
        fh.write(f"{cnt}: {cmt}\n")

# D12: Adjacency list patterns
with open(os.path.join(OUT,"D12_adj_detail.txt"),"w",encoding="utf-8") as fh:
    adj_patterns = Counter()
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"(?:vector<\w+>|int)\s+G\[\w+\]", c):
            adj_patterns[m.group(0).strip()] += 1
        for m in re.finditer(r"G\[\w+\]\.push_back\([^)]*\)", c):
            adj_patterns[m.group(0).strip()] += 1
    for pat,cnt in adj_patterns.most_common(30):
        fh.write(f"{cnt}: {pat}\n")

# D13: Sort patterns
with open(os.path.join(OUT,"D13_sort_detail.txt"),"w",encoding="utf-8") as fh:
    sort_patterns = Counter()
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"sort\s*\([^)]*\)", c):
            sort_patterns[m.group(0).strip()[:100]] += 1
    for pat,cnt in sort_patterns.most_common(30):
        fh.write(f"{cnt}: {pat}\n")

# D14: Fast read implementations
with open(os.path.join(OUT,"D14_fastread_detail.txt"),"w",encoding="utf-8") as fh:
    fr_count = 0
    for f in files:
        c = read_file(f)
        if "static inline char nc" in c or "inline char nc" in c or "char nc()" in c:
            fr_count += 1
            # extract the nc function
            m = re.search(r"(?:static\s+)?inline\s+char\s+nc\s*\(\s*\)\s*\{[^}]*\}", c, re.DOTALL)
            if m and fr_count <= 5:
                fh.write(f"\n--- {os.path.relpath(f,ROOT)} ---\n")
                fh.write(m.group(0)[:500]+"\n")
    fh.write(f"\nTotal fast-read files: {fr_count}\n")

# D15: Binary search patterns
with open(os.path.join(OUT,"D15_binary_search.txt"),"w",encoding="utf-8") as fh:
    bs_patterns = Counter()
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"while\s*\(\s*[lLrR].*?[lLrR].*?\)", c):
            bs_patterns[m.group(0).strip()[:80]] += 1
    for pat,cnt in bs_patterns.most_common(20):
        fh.write(f"{cnt}: {pat}\n")

# D16: DP state transition patterns
with open(os.path.join(OUT,"D16_dp_transitions.txt"),"w",encoding="utf-8") as fh:
    dp_trans = Counter()
    for f in files:
        c = read_file(f)
        for m in re.finditer(r"dp\[\w+\]\s*=\s*[^;]{1,60};", c):
            dp_trans[m.group(0).strip()] += 1
    for pat,cnt in dp_trans.most_common(30):
        fh.write(f"{cnt}: {pat}\n")

# D17: Graph algorithm patterns (Tarjan, Dijkstra, etc.)
with open(os.path.join(OUT,"D17_graph_algos.txt"),"w",encoding="utf-8") as fh:
    algo_patterns = {
        "tarjan": r"tarjan|dfn\[.*low\[",
        "dijkstra": r"dijkstra|priority_queue.*Node",
        "spfa": r"spfa|SPFA",
        "floyd": r"floyd|Floyd",
        "kruskal": r"kruskal|Kruskal",
        "prim": r"prim|Prim",
        "topo": r"topo_sort|topological",
        "bfs": r"\bbfs\b",
        "dfs": r"\bdfs\b",
        "union_find": r"find\(.*\)|Union\(",
        "lca": r"\bLCA\b",
        "scc": r"\bscc\b|strongly connected",
        "bcc": r"\bbcc\b|biconnected",
    }
    algo_counts = Counter()
    for f in files:
        c = read_file(f)
        for name,pat in algo_patterns.items():
            if re.search(pat,c,re.IGNORECASE):
                algo_counts[name] += 1
    for name,cnt in sorted(algo_counts.items(),key=lambda x:-x[1]):
        fh.write(f"{name}:{cnt}\n")

# D18: Number theory patterns
with open(os.path.join(OUT,"D18_number_theory.txt"),"w",encoding="utf-8") as fh:
    nt = Counter()
    nt_pats = {
        "exgcd": r"exgcd|extended.*gcd|ext_gcd",
        "qpow": r"qpow|quick.*pow|fast.*pow",
        "modinv": r"modinv|mod_inverse|inv\(",
        "crt": r"crt|CRT|chinese",
        "sieve": r"sieve|Eratosthenes|prime",
        "phi": r"phi|euler.*totient",
        "gcd": r"__gcd|gcd\(",
        "lcm": r"lcm\(",
    }
    for f in files:
        c = read_file(f)
        for name,pat in nt_pats.items():
            if re.search(pat,c,re.IGNORECASE):
                nt[name] += 1
    for name,cnt in sorted(nt.items(),key=lambda x:-x[1]):
        fh.write(f"{name}:{cnt}\n")

# D19: String algorithm patterns
with open(os.path.join(OUT,"D19_string_algos.txt"),"w",encoding="utf-8") as fh:
    sa = Counter()
    sa_pats = {
        "kmp": r"kmp|KMP|prefix\[",
        "ac_automaton": r"fail\[.*ch\[",
        "manacher": r"manacher|Manacher|d\[.*center",
        "hash": r"hash|hs\[",
        "trie": r"trie|Trie|ch\[.*\]\[26\]",
        "suffix": r"suffix",
        "z_function": r"z_function|z\[",
    }
    for f in files:
        c = read_file(f)
        for name,pat in sa_pats.items():
            if re.search(pat,c,re.IGNORECASE):
                sa[name] += 1
    for name,cnt in sorted(sa.items(),key=lambda x:-x[1]):
        fh.write(f"{name}:{cnt}\n")

# D20: Tree DP / rerooting patterns
with open(os.path.join(OUT,"D20_tree_dp.txt"),"w",encoding="utf-8") as fh:
    tdp = Counter()
    for f in files:
        c = read_file(f)
        if "dfs1" in c and "dfs2" in c:
            tdp["rerooting"] += 1
        if "siz[" in c and "dp[" in c:
            tdp["size_dp"] += 1
        if "dep[" in c and "fa[" in c:
            tdp["depth_parent"] += 1
    for k,v in tdp.items():
        fh.write(f"{k}:{v}\n")

print("DENSE DONE")
print(f"New dense files: 20 (D1-D20)")
