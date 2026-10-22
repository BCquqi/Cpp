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

# 26. Per-directory style comparison (recent vs early)
recent_dirs = {"S3-1","S3-2","NOICA","2026-8","2026-9-10-11"}
early_dirs = {"J1-1","J1-2","J2-1"}
def dir_of(f):
    return os.path.relpath(f,ROOT).split(os.sep)[0]

def marker_in_dir(marker_func, dirs):
    res = {}
    for d in dirs:
        cnt = 0
        for f in files:
            if dir_of(f)==d:
                content = read_file(f)
                cnt += marker_func(content)
        res[d] = cnt
    return res

# endl per dir
endl_dir = {}
brace_dir = {}
return_space_dir = {}
sizeof_dir = {}
for f in files:
    d = dir_of(f)
    c = read_file(f)
    endl_dir[d] = endl_dir.get(d,0) + c.count("endl")
    brace_dir[d] = brace_dir.get(d,0) + len(re.findall(r"\}\s*else\s*\{",c))
    return_space_dir[d] = return_space_dir.get(d,0) + len(re.findall(r"return ;",c))
    sizeof_dir[d] = sizeof_dir.get(d,0) + len(re.findall(r"sizeof [a-zA-Z_]",c))

for name, data in [("26_endl_by_dir",endl_dir),("27_brace_by_dir",brace_dir),
                   ("28_return_space_by_dir",return_space_dir),("29_sizeof_by_dir",sizeof_dir)]:
    with open(os.path.join(OUT,name+".txt"),"w",encoding="utf-8") as fh:
        for d in sorted(data):
            fh.write(f"{d}:{data[d]}\n")

# 30. Function name frequency (top 60)
fn_counter = Counter()
for f in files:
    c = read_file(f)
    for m in re.finditer(r"(?:void|int|long long|bool|double|char|ll|LL)\s+(\w+)\s*\(", c):
        fn_counter[m.group(1)] += 1
with open(os.path.join(OUT,"30_func_names.txt"),"w",encoding="utf-8") as fh:
    for name,cnt in fn_counter.most_common(60):
        fh.write(f"{name}:{cnt}\n")

# 31. Variable name frequency in declarations
var_counter = Counter()
for f in files:
    c = read_file(f)
    for m in re.finditer(r"(?:int|long long|bool|char|double|ll)\s+(\w+)\s*[=,\[]", c):
        var_counter[m.group(1)] += 1
with open(os.path.join(OUT,"31_var_names.txt"),"w",encoding="utf-8") as fh:
    for name,cnt in var_counter.most_common(60):
        fh.write(f"{name}:{cnt}\n")

# 32. Macro/define patterns
defines = Counter()
for f in files:
    c = read_file(f)
    for m in re.finditer(r"#define\s+(\w+)", c):
        defines[m.group(1)] += 1
with open(os.path.join(OUT,"32_defines.txt"),"w",encoding="utf-8") as fh:
    for name,cnt in defines.most_common(40):
        fh.write(f"{name}:{cnt}\n")

# 33. Header include frequency
includes = Counter()
for f in files:
    c = read_file(f)
    for m in re.finditer(r"#include\s*[<\"]([^>\"]+)[>\"]", c):
        includes[m.group(1)] += 1
with open(os.path.join(OUT,"33_includes.txt"),"w",encoding="utf-8") as fh:
    for name,cnt in includes.most_common(40):
        fh.write(f"{name}:{cnt}\n")

# 34. Main function patterns
main_patterns = Counter()
for f in files:
    c = read_file(f)
    if "signed main" in c: main_patterns["signed_main"] += 1
    elif "int main" in c: main_patterns["int_main"] += 1
    if "return 0" in c: main_patterns["return_0"] += 1
    if "return 0;" in c: main_patterns["return_0_semi"] += 1
with open(os.path.join(OUT,"34_main_patterns.txt"),"w",encoding="utf-8") as fh:
    for k,v in main_patterns.items():
        fh.write(f"{k}:{v}\n")

# 35. Namespace usage
ns = Counter()
for f in files:
    c = read_file(f)
    if "using namespace std" in c: ns["using_namespace_std"] += 1
    if "std::" in c: ns["std_colon"] += 1
with open(os.path.join(OUT,"35_namespace.txt"),"w",encoding="utf-8") as fh:
    for k,v in ns.items():
        fh.write(f"{k}:{v}\n")

# 36. Operator overloading
ops = Counter()
for f in files:
    c = read_file(f)
    if "operator <" in c or "operator<" in c: ops["operator_lt"] += 1
    if "operator ==" in c or "operator==" in c: ops["operator_eq"] += 1
    if "operator +" in c or "operator+" in c: ops["operator_plus"] += 1
    if "operator *" in c or "operator*" in c: ops["operator_mul"] += 1
with open(os.path.join(OUT,"36_operator_overload.txt"),"w",encoding="utf-8") as fh:
    for k,v in ops.items():
        fh.write(f"{k}:{v}\n")

# 37. Lambda usage
lambda_cnt = 0
lambda_files = 0
for f in files:
    c = read_file(f)
    n = len(re.findall(r"\[\s*\]", c))
    if n>0:
        lambda_files += 1
        lambda_cnt += n
with open(os.path.join(OUT,"37_lambda.txt"),"w",encoding="utf-8") as fh:
    fh.write(f"lambda_occ:{lambda_cnt}\nlambda_files:{lambda_files}\n")

# 38. Pointer usage in structs/arrays
ptr_usage = Counter()
for f in files:
    c = read_file(f)
    if "struct" in c and "*" in c:
        ptr_usage["struct_with_ptr"] += 1
    if "new " in c:
        ptr_usage["new_keyword"] += 1
    if "delete " in c:
        ptr_usage["delete_keyword"] += 1
with open(os.path.join(OUT,"38_ptr_usage.txt"),"w",encoding="utf-8") as fh:
    for k,v in ptr_usage.items():
        fh.write(f"{k}:{v}\n")

# 39. Range-based for
range_for = 0
range_for_files = 0
for f in files:
    c = read_file(f)
    n = len(re.findall(r"for\s*\(\s*auto\s+\w+\s*:\s*\w+", c))
    if n>0:
        range_for_files += 1
        range_for += n
with open(os.path.join(OUT,"39_range_for.txt"),"w",encoding="utf-8") as fh:
    fh.write(f"range_for_occ:{range_for}\nrange_for_files:{range_for_files}\n")

# 40. Ternary operator
ternary = 0
ternary_files = 0
for f in files:
    c = read_file(f)
    n = len(re.findall(r"\?\s*[^:]+\s*:", c))
    if n>0:
        ternary_files += 1
        ternary += n
with open(os.path.join(OUT,"40_ternary.txt"),"w",encoding="utf-8") as fh:
    fh.write(f"ternary_occ:{ternary}\nternary_files:{ternary_files}\n")

# 41. Bitwise operations
bitwise = Counter()
for f in files:
    c = read_file(f)
    if "<<" in c: bitwise["left_shift"] += 1
    if ">>" in c: bitwise["right_shift"] += 1
    if "&" in c: bitwise["bitwise_and"] += 1
    if "|" in c: bitwise["bitwise_or"] += 1
    if "^" in c: bitwise["bitwise_xor"] += 1
    if "~" in c: bitwise["bitwise_not"] += 1
with open(os.path.join(OUT,"41_bitwise.txt"),"w",encoding="utf-8") as fh:
    for k,v in bitwise.items():
        fh.write(f"{k}:{v}\n")

# 42. Math functions
mathf = Counter()
math_patterns = ["sqrt","pow","abs","max","min","gcd","lcm","__gcd","ceil","floor","log","sin","cos","tan"]
for f in files:
    c = read_file(f)
    for m in math_patterns:
        if m in c:
            mathf[m] += 1
with open(os.path.join(OUT,"42_math_funcs.txt"),"w",encoding="utf-8") as fh:
    for k,v in sorted(mathf.items(),key=lambda x:-x[1]):
        fh.write(f"{k}:{v}\n")

# 43. String operations
stro = Counter()
str_patterns = ["substr","find","replace","push_back","pop_back","size","length","empty","clear","reverse","sort"]
for f in files:
    c = read_file(f)
    for m in str_patterns:
        if "."+m+"(" in c or m+"(" in c:
            stro[m] += 1
with open(os.path.join(OUT,"43_string_ops.txt"),"w",encoding="utf-8") as fh:
    for k,v in sorted(stro.items(),key=lambda x:-x[1]):
        fh.write(f"{k}:{v}\n")

# 44. Queue/stack operations
qs = Counter()
qs_patterns = ["push","pop","front","back","top","empty","size"]
for f in files:
    c = read_file(f)
    for m in qs_patterns:
        if m+"(" in c or "."+m in c:
            qs[m] += 1
with open(os.path.join(OUT,"44_queue_stack.txt"),"w",encoding="utf-8") as fh:
    for k,v in sorted(qs.items(),key=lambda x:-x[1]):
        fh.write(f"{k}:{v}\n")

# 45. Pair/tuple usage
pair_usage = Counter()
for f in files:
    c = read_file(f)
    if "pair<" in c or "make_pair" in c:
        pair_usage["pair"] += 1
    if "tuple<" in c or "make_tuple" in c:
        pair_usage["tuple"] += 1
    if "tie(" in c:
        pair_usage["tie"] += 1
with open(os.path.join(OUT,"45_pair_tuple.txt"),"w",encoding="utf-8") as fh:
    for k,v in pair_usage.items():
        fh.write(f"{k}:{v}\n")

# 46. Multi-testcase patterns
tc = Counter()
for f in files:
    c = read_file(f)
    if "while (T--)" in c or "while(T--)" in c or "while (t--)" in c:
        tc["while_T--"] += 1
    if "while (m--)" in c or "while(m--)" in c:
        tc["while_m--"] += 1
    if "for (int t = 1" in c or "for(int t=1" in c:
        tc["for_t"] += 1
with open(os.path.join(OUT,"46_testcase.txt"),"w",encoding="utf-8") as fh:
    for k,v in tc.items():
        fh.write(f"{k}:{v}\n")

# 47. 2D array initialization
init2d = Counter()
for f in files:
    c = read_file(f)
    if re.search(r"memset\(\w+,\s*0,\s*sizeof", c):
        init2d["memset_zero"] += 1
    if re.search(r"memset\(\w+,\s*-?0x3f", c):
        init2d["memset_0x3f"] += 1
    if re.search(r"memset\(\w+,\s*-1", c):
        init2d["memset_neg1"] += 1
with open(os.path.join(OUT,"47_init2d.txt"),"w",encoding="utf-8") as fh:
    for k,v in init2d.items():
        fh.write(f"{k}:{v}\n")

# 48. Recursion depth / stack
rec = Counter()
for f in files:
    c = read_file(f)
    if "sys.setrecursionlimit" in c:
        rec["python_rec"] += 1
    # count recursive functions (function calls itself)
with open(os.path.join(OUT,"48_recursion.txt"),"w",encoding="utf-8") as fh:
    fh.write("N/A\n")

# 49. File I/O patterns
fileio = Counter()
for f in files:
    c = read_file(f)
    if "freopen" in c: fileio["freopen"] += 1
    if "ifstream" in c: fileio["ifstream"] += 1
    if "ofstream" in c: fileio["ofstream"] += 1
with open(os.path.join(OUT,"49_file_io.txt"),"w",encoding="utf-8") as fh:
    for k,v in fileio.items():
        fh.write(f"{k}:{v}\n")

# 50. Complexity hints (N values)
complexity = Counter()
for f in files:
    c = read_file(f)
    for m in re.finditer(r"const int N = ([\d.e+]+)", c):
        complexity[m.group(1)] += 1
with open(os.path.join(OUT,"50_n_values.txt"),"w",encoding="utf-8") as fh:
    for k,v in complexity.most_common(30):
        fh.write(f"{k}:{v}\n")

print("SCAN2 DONE")
print(f"Files: {len(files)}")
print("New files: 25 (26-50)")
