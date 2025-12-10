// 前缀匹配与自动补全
// 题目：输入n个单词，然后输入m个前缀，对于每个前缀，输出所有以该前缀开头的单词，按字典序排列；如果没有匹配的单词，输出"NULL"

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100010;
int son[N][26], idx;
bool is_end[N];
vector<string> words;

void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    is_end[p] = true;
    words.push_back(str);
}

// 深度优先遍历，收集所有以当前节点为前缀的单词
void dfs(int p, string prefix, vector<string> &res) {
    if (is_end[p]) res.push_back(prefix);
    
    for (int u = 0; u < 26; u++) {
        if (son[p][u]) {
            dfs(son[p][u], prefix + (char)(u + 'a'), res);
        }
    }
}

vector<string> autocomplete(char *prefix) {
    vector<string> res;
    int p = 0;
    
    // 先找到前缀对应的节点
    for (int i = 0; prefix[i]; i++) {
        int u = prefix[i] - 'a';
        if (!son[p][u]) return res; // 没有匹配的前缀
        p = son[p][u];
    }
    
    // 从该节点开始遍历所有可能的单词
    dfs(p, prefix, res);
    return res;
}

int main() {
    int n, m;
    char str[N];
    
    cout << "输入单词数量n：";
    cin >> n;
    cout << "输入" << n << "个单词：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> str;
        insert(str);
    }
    
    cout << "输入前缀数量m：";
    cin >> m;
    cout << "输入" << m << "个前缀：" << endl;
    for (int i = 0; i < m; i++) {
        cin >> str;
        vector<string> res = autocomplete(str);
        
        cout << "前缀\"" << str << "\"的匹配结果：";
        if (res.empty()) {
            cout << "NULL" << endl;
        } else {
            for (string word : res) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}