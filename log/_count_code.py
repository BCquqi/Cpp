import os

ROOT = r"C:\Users\Administrator\Documents\C++"
OUT = os.path.join(ROOT, "log")

# Code extensions only
CODE_EXTS = {
    ".cpp", ".c", ".h", ".hpp", ".cc", ".cxx",
    ".py", ".java", ".js", ".ts", ".go", ".rs",
    ".md", ".txt", ".json", ".xml", ".yaml", ".yml",
    ".cmake", ".make", ".sh", ".bat", ".ps1",
    ".html", ".css", ".sql", ".r", ".m", ".mat",
}

total_lines = 0
total_chars = 0
total_files = 0
by_ext = {}
by_dir = {}

for dirpath, dirnames, filenames in os.walk(ROOT):
    if "log" in dirpath.split(os.sep):
        continue
    if ".git" in dirpath.split(os.sep):
        continue
    for fn in filenames:
        ext = os.path.splitext(fn)[1].lower()
        if ext not in CODE_EXTS:
            continue
        path = os.path.join(dirpath, fn)
        try:
            with open(path, "rb") as f:
                raw = f.read()
            for enc in ["utf-8", "gbk", "latin-1"]:
                try:
                    text = raw.decode(enc)
                    break
                except:
                    continue
            else:
                text = raw.decode("latin-1")
            lines = text.count("\n")
            if not text.endswith("\n") and len(text) > 0:
                lines += 1
            chars = len(text)
            total_lines += lines
            total_chars += chars
            total_files += 1
            by_ext[ext] = by_ext.get(ext, [0,0,0])
            by_ext[ext][0]+=1; by_ext[ext][1]+=lines; by_ext[ext][2]+=chars
            top = os.path.relpath(dirpath, ROOT).split(os.sep)[0]
            by_dir[top] = by_dir.get(top, [0,0,0])
            by_dir[top][0]+=1; by_dir[top][1]+=lines; by_dir[top][2]+=chars
        except Exception as e:
            print(f"ERROR: {path}: {e}")

with open(os.path.join(OUT, "CODE_COUNTS.txt"), "w", encoding="utf-8") as f:
    f.write(f"Total code files: {total_files}\n")
    f.write(f"Total code lines: {total_lines}\n")
    f.write(f"Total code chars: {total_chars}\n")
    f.write(f"\n--- By extension ---\n")
    for ext in sorted(by_ext, key=lambda x: -by_ext[x][1]):
        fc, lc, cc = by_ext[ext]
        f.write(f"{ext}: files={fc} lines={lc} chars={cc}\n")
    f.write(f"\n--- By top-level directory ---\n")
    for d in sorted(by_dir, key=lambda x: -by_dir[x][1]):
        fc, lc, cc = by_dir[d]
        f.write(f"{d}: files={fc} lines={lc} chars={cc}\n")

print(f"Files: {total_files}")
print(f"Lines: {total_lines}")
print(f"Chars: {total_chars}")
