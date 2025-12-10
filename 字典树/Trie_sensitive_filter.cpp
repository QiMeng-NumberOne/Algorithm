// 敏感词过滤
// 题目：输入n个敏感词，然后输入一段文本，将文本中的所有敏感词替换为"*"，输出过滤后的文本

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int son[N][26], idx;
bool is_sensitive[N];

void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    is_sensitive[p] = true;
}

// 检查从pos位置开始是否有敏感词，返回敏感词长度，0表示没有
int check_sensitive(char *text, int pos) {
    int p = 0;
    int len = 0;
    int max_len = 0;
    
    for (int i = pos; text[i]; i++) {
        int u = text[i] - 'a';
        if (!son[p][u]) break;
        
        p = son[p][u];
        len++;
        
        if (is_sensitive[p]) {
            max_len = len; // 记录最长匹配的敏感词长度
        }
    }
    
    return max_len;
}

string filter_sensitive_words(char *text) {
    string res = "";
    int len = strlen(text);
    
    for (int i = 0; i < len; ) {
        int sensitive_len = check_sensitive(text, i);
        
        if (sensitive_len > 0) {
            // 替换为*号
            for (int j = 0; j < sensitive_len; j++) {
                res += '*';
            }
            i += sensitive_len;
        } else {
            // 正常添加字符
            res += text[i];
            i++;
        }
    }
    
    return res;
}

int main() {
    int n;
    char str[N], text[N];
    
    cout << "输入敏感词数量n：";
    cin >> n;
    cout << "输入" << n << "个敏感词：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> str;
        insert(str);
    }
    
    cout << "输入待过滤的文本：";
    cin.ignore(); // 忽略之前的换行符
    cin.getline(text, N);
    
    string filtered = filter_sensitive_words(text);
    cout << "过滤后的文本：" << filtered << endl;
    
    return 0;
}