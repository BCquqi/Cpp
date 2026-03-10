// 插入示例
auto pos = ls.begin();
for (int i = 1;i <= 5;i++) ls.push_front(i);
// or
for (int i = 1;i <= 5;i++) ls.insert(pos,i); // pos迭代器自动向后退

// pos的位移
pos++; // 禁止pos += 1;

// 删除示例
auto pos = ls.begin();
pos++;
cout << *pos << endl;
ls.erase(pos); // pos不变,不能使用
pos = ls.erase(); // pos变成删除项的下一项
cout << *pos << endl;

// 查询示例
// 遍历输出
for (auto t : ls) cout << t << ' ';