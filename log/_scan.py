import os, re, glob

ROOT = r"C:\Users\Administrator\Documents\C++"
OUT = os.path.join(ROOT, "log")

# Collect all cpp files
files = []
for dirpath, dirnames, filenames in os.walk(ROOT):
    for f in filenames:
        if f.endswith(".cpp"):
            files.append(os.path.join(dirpath, f))

# Read file with encoding fallback
def read_file(path):
    for enc in ["utf-8", "gbk", "latin-1"]:
        try:
            with open(path, "r", encoding=enc) as fh:
                return fh.read()
        except:
            continue
    return ""

# 1. Directory counts
from collections import Counter, defaultdict
dir_counts = Counter()
for f in files:
    rel = os.path.relpath(f, ROOT)
    top = rel.split(os.sep)[0]
    dir_counts[top] += 1

with open(os.path.join(OUT, "01_dirs.txt"), "w", encoding="utf-8") as fh:
    for d, c in sorted(dir_counts.items()):
        fh.write(f"{d}:{c}\n")
    fh.write(f"TOTAL:{len(files)}\n")

# 2. Style marker counts across ALL files
markers = {
    "endl": r"endl",
    "return_space": r"return ;",
    "return_nospace": r"return;",
    "sizeof_noparen": r"sizeof [a-zA-Z_]",
    "sizeof_paren": r"sizeof\(",
    "for_1indexed": r"for\s*\(\s*int\s+i\s*=\s*1\s*;",
    "auto_ref": r"auto\s*&",
    "emplace_back": r"emplace_back",
    "dot_at": r"\.at\(",
    "bits_stdc": r"bits/stdc",
    "define_int_ll": r"#define\s+int\s+long\s+long",
    "signed_main": r"signed\s+main",
    "memset": r"memset",
    "using_namespace": r"using\s+namespace\s+std",
    "hash_include_no_space": r"#include<",
    "hash_include_space": r"#include <",
    "mod_lowercase": r"\bmod\b",
    "MOD_uppercase": r"\bMOD\b",
    "eps": r"\beps\b",
    "1ll_star": r"1ll\s*\*",
    "1LL_star": r"1LL\s*\*",
    "int128": r"__int128",
    "newline_char": r"'\\n'",
    "cout_cin": r"\bcout\b",
    "scanf_printf": r"\bscanf\b|\bprintf\b",
    "fast_read_nc": r"static\s+inline\s+char\s+nc",
    "inline_func": r"\binline\b",
    "vector_adj": r"vector<\w+>\s+G\[",
    "lambda_sort": r"sort\(.*\[\]",
    "struct_members": r"struct\s+\w+\s*\{[^}]*,[^}]*;",
    "while_x--": r"while\s*\(\s*\w+\s*--\s*\)",
    "while_--x": r"while\s*\(\s*--\s*\w+\s*\)",
    "comma_chain": r"while\s*\(\s*\w+\s*\)\s*\w+\s*\+=\s*\w+\[\w+\]\s*,\s*\w+\s*-=\s*lowbit",
    "switch_case": r"case\s+\d+\s*:",
    "else_same_line": r"\}\s*else\s*\{",
    "else_own_line": r"^\s*else\s*\{",
    "allman_while": r"while\s*\([^)]*\)\s*\n\s*\{",
    "allman_for": r"for\s*\([^)]*\)\s*\n\s*\{",
    "allman_if": r"if\s*\([^)]*\)\s*\n\s*\{",
}

counts = {k: 0 for k in markers}
file_hits = {k: set() for k in markers}
for f in files:
    content = read_file(f)
    for k, pat in markers.items():
        try:
            matches = re.findall(pat, content, re.MULTILINE)
            if matches:
                counts[k] += len(matches)
                file_hits[k].add(f)
        except:
            pass

with open(os.path.join(OUT, "02_marker_counts.txt"), "w", encoding="utf-8") as fh:
    for k in sorted(markers.keys()):
        fh.write(f"{k}: occ={counts[k]} files={len(file_hits[k])}\n")

# 3. Allman style per directory
allman_by_dir = defaultdict(int)
allman_files = []
for f in files:
    content = read_file(f)
    # detect brace on next line after control keyword
    if re.search(r"(while|for|if)\s*\([^)]*\)\s*\n\s*\{", content):
        rel = os.path.relpath(f, ROOT)
        top = rel.split(os.sep)[0]
        allman_by_dir[top] += 1
        allman_files.append(rel)

with open(os.path.join(OUT, "03_allman_by_dir.txt"), "w", encoding="utf-8") as fh:
    for d, c in sorted(allman_by_dir.items()):
        fh.write(f"{d}:{c}\n")
    fh.write(f"TOTAL_ALLMAN:{len(allman_files)}\n")

# 4. BIT patterns
bit_files = [f for f in files if "树状数组" in f or "BIT" in f.upper()]
bit_info = []
for f in bit_files:
    content = read_file(f)
    arrs = set(re.findall(r"(?:int|long long)\s+(\w+)\s*\[", content))
    fns = set(re.findall(r"(?:void|inline)\s+(\w+)\s*\(", content))
    bit_info.append((os.path.relpath(f, ROOT), sorted(arrs), sorted(fns)))
with open(os.path.join(OUT, "04_bit_patterns.txt"), "w", encoding="utf-8") as fh:
    for rel, arrs, fns in bit_info:
        fh.write(f"{rel} | arr={arrs} | fns={fns}\n")

# 5. Segment tree patterns
seg_files = [f for f in files if "线段树" in f]
seg_info = []
for f in seg_files:
    content = read_file(f)
    has_mx = "mx" in content
    has_lzym = "lzym" in content
    has_ptr = "seg_tree*" in content or "new seg_tree" in content
    struct_m = re.search(r"struct\s+seg_tree\s*\{[^}]*\}", content)
    struct_str = struct_m.group(0).replace("\n", " ") if struct_m else "N/A"
    seg_info.append((os.path.relpath(f, ROOT), has_mx, has_lzym, has_ptr, struct_str))
with open(os.path.join(OUT, "05_seg_patterns.txt"), "w", encoding="utf-8") as fh:
    for rel, mx, lzym, ptr, st in seg_info:
        fh.write(f"{rel} | mx={mx} lzym={lzym} ptr={ptr} | {st}\n")

# 6. FHQ-Treap patterns
treap_files = [f for f in files if "平衡树" in f or "Treap" in f or "treap" in f.lower()]
treap_info = []
for f in treap_files:
    content = read_file(f)
    has_rev = "rev" in content
    has_fa = "fa" in content and "fa[" in content
    has_pushdown = "pushdown" in content
    fields = set(re.findall(r"(?:int|long long)\s+(\w+)\s*\[", content))
    treap_info.append((os.path.relpath(f, ROOT), has_rev, has_fa, has_pushdown, sorted(fields)))
with open(os.path.join(OUT, "06_treap_patterns.txt"), "w", encoding="utf-8") as fh:
    for rel, rev, fa, pd, flds in treap_info:
        fh.write(f"{rel} | rev={rev} fa={fa} pushdown={pd} | fields={flds}\n")

# 7. Template file index
tmpl_files = [f for f in files if "【模板】" in f or "模板" in f]
with open(os.path.join(OUT, "07_template_index.txt"), "w", encoding="utf-8") as fh:
    for f in sorted(tmpl_files):
        fh.write(os.path.relpath(f, ROOT) + "\n")

# 8. Empty brace / single statement patterns
single_stmt = defaultdict(int)
for f in files:
    content = read_file(f)
    # count if without braces (if (cond) stmt;)
    m = re.findall(r"if\s*\([^)]*\)\s*[^\n{;]+;", content)
    single_stmt["if_no_brace"] += len(m)
    m = re.findall(r"for\s*\([^)]*\)\s*[^\n{;]+;", content)
    single_stmt["for_no_brace"] += len(m)
with open(os.path.join(OUT, "08_single_stmt.txt"), "w", encoding="utf-8") as fh:
    for k, v in single_stmt.items():
        fh.write(f"{k}:{v}\n")

# 9. Include order analysis (first include per file)
first_inc = Counter()
for f in files:
    content = read_file(f)
    m = re.search(r"#include\s*[<\"]([^>\"]+)[>\"]", content)
    if m:
        first_inc[m.group(1)] += 1
with open(os.path.join(OUT, "09_first_include.txt"), "w", encoding="utf-8") as fh:
    for inc, c in first_inc.most_common(20):
        fh.write(f"{inc}:{c}\n")

# 10. Struct definition patterns
structs = Counter()
for f in files:
    content = read_file(f)
    for m in re.finditer(r"struct\s+(\w+)\s*\{([^}]*)\}", content, re.DOTALL):
        name = m.group(1)
        body = m.group(2).replace("\n", " ")
        structs[name] += 1
with open(os.path.join(OUT, "10_structs.txt"), "w", encoding="utf-8") as fh:
    for name, c in structs.most_common(50):
        fh.write(f"{name}:{c}\n")

# 11. Function signature patterns (inline functions)
inline_fns = Counter()
for f in files:
    content = read_file(f)
    for m in re.finditer(r"inline\s+\w+\s+(\w+)\s*\(", content):
        inline_fns[m.group(1)] += 1
with open(os.path.join(OUT, "11_inline_fns.txt"), "w", encoding="utf-8") as fh:
    for fn, c in inline_fns.most_common(40):
        fh.write(f"{fn}:{c}\n")

# 12. Global array declarations
global_arrs = Counter()
for f in files:
    content = read_file(f)
    for m in re.finditer(r"(?:^|\n)\s*(?:int|long long|bool|char|double)\s+(\w+)\s*\[\s*[\w\d]+\s*\]", content):
        global_arrs[m.group(1)] += 1
with open(os.path.join(OUT, "12_global_arrays.txt"), "w", encoding="utf-8") as fh:
    for name, c in global_arrs.most_common(40):
        fh.write(f"{name}:{c}\n")

# 13. Const declarations
consts = Counter()
for f in files:
    content = read_file(f)
    for m in re.finditer(r"const\s+(?:int|double|long long)\s+(\w+)\s*=", content):
        consts[m.group(1)] += 1
with open(os.path.join(OUT, "13_consts.txt"), "w", encoding="utf-8") as fh:
    for name, c in consts.most_common(30):
        fh.write(f"{name}:{c}\n")

# 14. Typedef patterns
typedefs = Counter()
for f in files:
    content = read_file(f)
    for m in re.finditer(r"typedef\s+\w+\s+(\w+)", content):
        typedefs[m.group(1)] += 1
with open(os.path.join(OUT, "14_typedefs.txt"), "w", encoding="utf-8") as fh:
    for name, c in typedefs.most_common(20):
        fh.write(f"{name}:{c}\n")

# 15. Loop variable patterns
loop_vars = Counter()
for f in files:
    content = read_file(f)
    for m in re.finditer(r"for\s*\(\s*int\s+(\w+)\s*=", content):
        loop_vars[m.group(1)] += 1
with open(os.path.join(OUT, "15_loop_vars.txt"), "w", encoding="utf-8") as fh:
    for var, c in loop_vars.most_common(20):
        fh.write(f"{var}:{c}\n")

# 16. Fast IO patterns
fast_io = Counter()
for f in files:
    content = read_file(f)
    if "sync_with_stdio" in content:
        fast_io["sync_with_stdio"] += 1
    if "cin.tie" in content:
        fast_io["cin.tie"] += 1
    if "cout.tie" in content:
        fast_io["cout.tie"] += 1
    if "scanf" in content:
        fast_io["scanf"] += 1
    if "printf" in content:
        fast_io["printf"] += 1
with open(os.path.join(OUT, "16_fast_io.txt"), "w", encoding="utf-8") as fh:
    for k, v in fast_io.items():
        fh.write(f"{k}:{v}\n")

# 17. Comment patterns
comment_stats = Counter()
for f in files:
    content = read_file(f)
    # single line comments
    sl = len(re.findall(r"//.*", content))
    comment_stats["single_line_comments"] += sl
    # chinese comments
    cn = len(re.findall(r"//.*[\u4e00-\u9fff].*", content))
    comment_stats["chinese_comments"] += cn
    # TODO/FIXME
    todo = len(re.findall(r"TODO|FIXME|XXX|HACK", content, re.IGNORECASE))
    comment_stats["todo_fixme"] += todo
with open(os.path.join(OUT, "17_comments.txt"), "w", encoding="utf-8") as fh:
    for k, v in comment_stats.items():
        fh.write(f"{k}:{v}\n")

# 18. STL usage
stl = Counter()
stl_patterns = {
    "vector": r"\bvector\b",
    "queue": r"\bqueue\b",
    "stack": r"\bstack\b",
    "set": r"\bset\b",
    "map": r"\bmap\b",
    "priority_queue": r"\bpriority_queue\b",
    "deque": r"\bdeque\b",
    "string": r"\bstring\b",
    "pair": r"\bpair\b",
    "tuple": r"\btuple\b",
    "sort": r"\bsort\b",
    "lower_bound": r"\blower_bound\b",
    "upper_bound": r"\bupper_bound\b",
    "unique": r"\bunique\b",
    "reverse": r"\breverse\b",
    "max_element": r"\bmax_element\b",
    "min_element": r"\bmin_element\b",
    "accumulate": r"\baccumulate\b",
    "next_permutation": r"\bnext_permutation\b",
}
for f in files:
    content = read_file(f)
    for k, pat in stl_patterns.items():
        if re.search(pat, content):
            stl[k] += 1
with open(os.path.join(OUT, "18_stl_usage.txt"), "w", encoding="utf-8") as fh:
    for k, v in sorted(stl.items(), key=lambda x: -x[1]):
        fh.write(f"{k}:{v}\n")

# 19. Graph representation patterns
graph = Counter()
for f in files:
    content = read_file(f)
    if re.search(r"vector<\w+>\s+G\[", content):
        graph["vector_adj"] += 1
    if re.search(r"int\s+G\[\w+\]\[\w+\]", content):
        graph["matrix_adj"] += 1
    if "edge" in content.lower() and "struct" in content:
        graph["struct_edge"] += 1
with open(os.path.join(OUT, "19_graph_repr.txt"), "w", encoding="utf-8") as fh:
    for k, v in graph.items():
        fh.write(f"{k}:{v}\n")

# 20. DP patterns
dp = Counter()
for f in files:
    content = read_file(f)
    if re.search(r"\bdp\[", content):
        dp["dp_array"] += 1
    if re.search(r"\bmemset\(dp", content):
        dp["memset_dp"] += 1
    if re.search(r"f\[", content):
        dp["f_array"] += 1
with open(os.path.join(OUT, "20_dp_patterns.txt"), "w", encoding="utf-8") as fh:
    for k, v in dp.items():
        fh.write(f"{k}:{v}\n")

# 21. Tree traversal patterns
tree_trav = Counter()
for f in files:
    content = read_file(f)
    if re.search(r"void\s+dfs\s*\(", content):
        tree_trav["dfs_void"] += 1
    if re.search(r"int\s+dfs\s*\(", content):
        tree_trav["dfs_int"] += 1
    if "bfs" in content.lower():
        tree_trav["bfs"] += 1
    if re.search(r"dep\[\w+\]\s*=\s*dep\[\w+\]\s*\+\s*1", content):
        tree_trav["dep_assign"] += 1
with open(os.path.join(OUT, "21_tree_traversal.txt"), "w", encoding="utf-8") as fh:
    for k, v in tree_trav.items():
        fh.write(f"{k}:{v}\n")

# 22. Modulo arithmetic
mod_pat = Counter()
for f in files:
    content = read_file(f)
    if re.search(r"%\s*mod", content):
        mod_pat["mod_modulo"] += 1
    if re.search(r"%\s*1000000007", content):
        mod_pat["1e9+7"] += 1
    if re.search(r"%\s*998244353", content):
        mod_pat["998244353"] += 1
    if re.search(r"\+mod\b", content):
        mod_pat["plus_mod"] += 1
with open(os.path.join(OUT, "22_mod_arith.txt"), "w", encoding="utf-8") as fh:
    for k, v in mod_pat.items():
        fh.write(f"{k}:{v}\n")

# 23. Pointer/struct access
ptr = Counter()
for f in files:
    content = read_file(f)
    if "->" in content:
        ptr["arrow"] += 1
    if re.search(r"\.\w+\s*=", content):
        ptr["dot_assign"] += 1
with open(os.path.join(OUT, "23_ptr_access.txt"), "w", encoding="utf-8") as fh:
    for k, v in ptr.items():
        fh.write(f"{k}:{v}\n")

# 24. Array size constants
arr_sizes = Counter()
for f in files:
    content = read_file(f)
    for m in re.finditer(r"const\s+int\s+N\s*=\s*([\d.e+]+)", content):
        arr_sizes[m.group(1)] += 1
with open(os.path.join(OUT, "24_arr_sizes.txt"), "w", encoding="utf-8") as fh:
    for size, c in arr_sizes.most_common(20):
        fh.write(f"{size}:{c}\n")

# 25. Multi-dim array
multidim = Counter()
for f in files:
    content = read_file(f)
    if re.search(r"\w+\s*\[\s*\w+\s*\]\s*\[\s*\w+\s*\]", content):
        multidim["2d_array"] += 1
    if re.search(r"\w+\s*\[\s*\w+\s*\]\s*\[\s*\w+\s*\]\s*\[\s*\w+\s*\]", content):
        multidim["3d_array"] += 1
with open(os.path.join(OUT, "25_multidim.txt"), "w", encoding="utf-8") as fh:
    for k, v in multidim.items():
        fh.write(f"{k}:{v}\n")

print("DONE")
print(f"Files scanned: {len(files)}")
print(f"Log files created: 25")
