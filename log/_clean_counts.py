import re

path = r"C:\Users\Administrator\Documents\C++\码风说明.md"
with open(path, encoding="utf-8") as f:
    content = f.read()

# Pattern: parenthetical content containing a number (Chinese or English parens)
# Remove the entire parenthetical phrase
patterns = [
    r"（[^）]*\d[^）]*）",
    r"\([^)]*\d[^)]*\)",
]

for pat in patterns:
    content = re.sub(pat, "", content)

# Also remove inline count phrases like "（32 个文件，71 处）" already caught above
# Remove "0 次" standalone mentions that are part of "不用 X（0 次）"
# Already handled by parenthetical removal

# Clean up double spaces left behind
content = content.replace("  ", " ")

with open(path, "w", encoding="utf-8") as f:
    f.write(content)

print("DONE")
