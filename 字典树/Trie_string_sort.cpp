// 字符串排序
// 题目：输入n个字符串，使用Trie树按字典序输出这些字符串

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int son[N][26], idx;
bool is_end[N];

void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    is_end[p] = true;
}

// 先序遍历Trie树，按字典序输出所有字符串
void dfs(int p, string current) {
    if (is_end[p]) {
        cout << current << endl;
    }
    
    // 按字母顺序遍历子节点（a-z）
    for (int u = 0; u < 26; u++) {
        if (son[p][u]) {
            dfs(son[p][u], current + (char)(u + 'a'));
        }
    }
}

int main() {
    int n;
    char str[N];
    
    cout << "输入字符串数量n：";
    cin >> n;
    cout << "输入" << n << "个字符串：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> str;
        insert(str);
    }
    
    cout << "按字典序排序的结果：" << endl;
    dfs(0, "");
    
    return 0;
}