// 最长前缀匹配
// 题目：输入n个前缀规则，然后输入m个字符串，对于每个字符串，输出它的最长匹配前缀；如果没有匹配的前缀，输出"-1"

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int son[N][26], idx;
bool is_prefix[N];

void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    is_prefix[p] = true;
}

string longest_prefix_match(char *str) {
    string res = "";
    int p = 0;
    string current = "";
    
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) break;
        
        p = son[p][u];
        current += str[i];
        
        if (is_prefix[p]) {
            res = current; // 更新最长匹配前缀
        }
    }
    
    return res;
}

int main() {
    int n, m;
    char str[N];
    
    cout << "输入前缀规则数量n：";
    cin >> n;
    cout << "输入" << n << "个前缀规则：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> str;
        insert(str);
    }
    
    cout << "输入字符串数量m：";
    cin >> m;
    cout << "输入" << m << "个字符串：" << endl;
    for (int i = 0; i < m; i++) {
        cin >> str;
        string res = longest_prefix_match(str);
        
        if (res.empty()) {
            cout << "-1" << endl;
        } else {
            cout << res << endl;
        }
    }
    
    return 0;
}