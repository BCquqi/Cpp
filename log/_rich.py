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

# R1: Full code of ALL template files (not just first 25 lines)
tmpl_files = [f for f in files if "【模板】" in f]
with open(os.path.join(OUT,"R1_all_templates_full.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(tmpl_files):
        c = read_file(f)
        fh.write(f"\n{'='*80}\n")
        fh.write(f"FILE: {os.path.relpath(f,ROOT)}\n")
        fh.write(f"{'='*80}\n")
        fh.write(c+"\n")

# R2: Code snippets showing each style pattern (actual lines from real files)
patterns = {
    "brace_else": r".*\}\s*else\s*\{.*",
    "return_space": r".*return ;.*",
    "sizeof_noparen": r".*sizeof [a-zA-Z_].*",
    "single_if_no_brace": r"if\s*\([^)]*\)\s*[^\n{;]+;",
    "for_1indexed": r"for\s*\(\s*int\s+i\s*=\s*1\s*;[^)]*\)",
    "while_x--": r"while\s*\(\s*\w+\s*--\s*\)",
    "memset_call": r"memset\s*\([^)]*\)",
    "fast_read_func": r"static\s+inline\s+char\s+nc\s*\(\s*\)\s*\{[^}]*\}",
    "struct_def": r"struct\s+\w+\s*\{[^}]*\}",
    "lambda_sort": r"sort\([^)]*\[\][^)]*\)",
    "define_int": r"#define\s+int\s+long\s+long",
    "signed_main": r"signed\s+main\s*\(\s*\)",
    "include_no_space": r"#include<[^>]+>",
    "global_arr": r"(?:int|long long|bool)\s+\w+\s*\[\s*[\w\d]+\s*\]",
    "inline_func": r"inline\s+\w+\s+\w+\s*\([^)]*\)\s*\{",
    "vector_adj": r"vector<\w+>\s+G\[\w+\]",
    "mod_const": r"const\s+int\s+mod\s*=",
    "eps_const": r"const\s+double\s+eps\s*=",
    "1ll_mul": r"1ll\s*\*",
    "comma_chain_while": r"while\s*\(\s*\w+\s*\)\s*\w+\s*\+=\s*\w+\[\w+\]\s*,\s*\w+\s*-=\s*lowbit\(\w+\)",
}
with open(os.path.join(OUT,"R2_pattern_examples.txt"),"w",encoding="utf-8") as fh:
    for name,pat in patterns.items():
        fh.write(f"\n{'='*60}\n{name}\n{'='*60}\n")
        examples = set()
        for f in files:
            c = read_file(f)
            for m in re.finditer(pat, c, re.MULTILINE):
                line = m.group(0).strip()[:150]
                if line and len(examples) < 15:
                    examples.add(line)
            if len(examples) >= 15: break
        for ex in list(examples)[:15]:
            fh.write(ex+"\n")

# R3: Complete file listing with first 5 lines of each
with open(os.path.join(OUT,"R3_file_headers.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(files):
        c = read_file(f)
        lines = c.splitlines()[:5]
        fh.write(f"\n--- {os.path.relpath(f,ROOT)} ---\n")
        for l in lines:
            fh.write(l+"\n")

def dir_of(f): return os.path.relpath(f,ROOT).split(os.sep)[0]
with open(os.path.join(OUT,"R4_file_fingerprints.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(files):
        c = read_file(f)
        d = dir_of(f)
        fp = []
        fp.append(f"endl={c.count('endl')}")
        fp.append(f"ret_sp={len(re.findall(r'return ;',c))}")
        fp.append(f"sizeof_np={len(re.findall(r'sizeof [a-zA-Z_]',c))}")
        fp.append(f"brace_else={len(re.findall(r'}\\s*else\\s*{',c))}")
        fp.append(f"allman={'Y' if re.search(r'(while|for|if)\\s*\\([^)]*\\)\\s*\\n\\s*\\{',c) else 'N'}")
        fp.append(f"def_int={'Y' if '#define int long long' in c else 'N'}")
        fp.append(f"signed_main={'Y' if 'signed main' in c else 'N'}")
        fp.append(f"fast_read={'Y' if 'static inline char nc' in c else 'N'}")
        fp.append(f"bits={'Y' if 'bits/stdc' in c else 'N'}")
        fp.append(f"emplace={c.count('emplace_back')}")
        fp.append(f"auto_ref={len(re.findall(r'auto\\s*&',c))}")
        fp.append(f"memset={c.count('memset')}")
        fp.append(f"lambda={len(re.findall(r'\\[\\s*\\]',c))}")
        fp.append(f"lines={c.count(chr(10))}")
        fh.write(f"{os.path.relpath(f,ROOT)}: {' '.join(fp)}\n")

# R5: All function definitions with body (first 10 lines each)
with open(os.path.join(OUT,"R5_func_bodies.txt"),"w",encoding="utf-8") as fh:
    func_count = 0
    for f in sorted(files):
        c = read_file(f)
        for m in re.finditer(r"(?:void|int|long long|bool|double|char|ll)\s+(\w+)\s*\([^)]*\)\s*\{", c):
            func_count += 1
            start = m.start()
            # find matching closing brace
            depth = 0
            i = m.end()-1
            while i < len(c):
                if c[i] == '{': depth += 1
                elif c[i] == '}':
                    depth -= 1
                    if depth == 0:
                        body = c[start:i+1]
                        if len(body) < 800:
                            fh.write(f"\n--- {os.path.relpath(f,ROOT)}: {m.group(1)} ---\n")
                            fh.write(body+"\n")
                        break
                i += 1
            if func_count > 2000: break
        if func_count > 2000: break

# R6: All struct definitions with full body
with open(os.path.join(OUT,"R6_structs_full.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(files):
        c = read_file(f)
        for m in re.finditer(r"struct\s+(\w+)\s*\{", c):
            start = m.start()
            depth = 0
            i = m.end()-1
            while i < len(c):
                if c[i] == '{': depth += 1
                elif c[i] == '}':
                    depth -= 1
                    if depth == 0:
                        body = c[start:i+1]
                        fh.write(f"\n--- {os.path.relpath(f,ROOT)} ---\n")
                        fh.write(body+"\n")
                        break
                i += 1

# R7: All #define lines
with open(os.path.join(OUT,"R7_all_defines.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(files):
        c = read_file(f)
        for line in c.splitlines():
            if line.strip().startswith("#define"):
                fh.write(f"{os.path.relpath(f,ROOT)}: {line.strip()}\n")

# R8: All include lines
with open(os.path.join(OUT,"R8_all_includes.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(files):
        c = read_file(f)
        for line in c.splitlines():
            if line.strip().startswith("#include"):
                fh.write(f"{os.path.relpath(f,ROOT)}: {line.strip()}\n")

# R9: Global variable declarations (lines with array declarations at file scope)
with open(os.path.join(OUT,"R9_globals.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(files):
        c = read_file(f)
        for line in c.splitlines():
            stripped = line.strip()
            if re.match(r"(int|long long|bool|char|double|ll|LL)\s+\w+\s*\[", stripped):
                fh.write(f"{os.path.relpath(f,ROOT)}: {stripped}\n")

# R10: All main functions
with open(os.path.join(OUT,"R10_mains.txt"),"w",encoding="utf-8") as fh:
    for f in sorted(files):
        c = read_file(f)
        m = re.search(r"(?:signed\s+)?int\s+main\s*\([^)]*\)\s*\{", c)
        if m:
            start = m.start()
            depth = 0
            i = m.end()-1
            while i < len(c):
                if c[i] == '{': depth += 1
                elif c[i] == '}':
                    depth -= 1
                    if depth == 0:
                        body = c[start:i+1]
                        fh.write(f"\n--- {os.path.relpath(f,ROOT)} ---\n")
                        fh.write(body+"\n")
                        break
                i += 1

print("RICH DONE")
print(f"Files: {len(files)}, Templates: {len(tmpl_files)}")
