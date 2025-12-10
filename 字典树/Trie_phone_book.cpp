// 电话号码簿检索
// 题目：输入n个电话号码，然后输入m个查询，每个查询可以是：
// 1. 输入完整电话号码，查询该号码是否存在
// 2. 输入电话号码前缀，查询有多少个号码以该前缀开头

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int son[N][10], cnt[N], idx; // son数组第二维改为10（0-9）
bool is_number[N];

void insert(char *phone) {
    int p = 0;
    for (int i = 0; phone[i]; i++) {
        int u = phone[i] - '0'; // 处理数字字符
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++; // 记录以当前节点为前缀的号码数量
    }
    is_number[p] = true;
}

// 查询号码是否存在
bool query_exist(char *phone) {
    int p = 0;
    for (int i = 0; phone[i]; i++) {
        int u = phone[i] - '0';
        if (!son[p][u]) return false;
        p = son[p][u];
    }
    return is_number[p];
}

// 查询前缀匹配的号码数量
int query_prefix_count(char *prefix) {
    int p = 0;
    for (int i = 0; prefix[i]; i++) {
        int u = prefix[i] - '0';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n, m;
    char phone[N], op[2];
    
    cout << "输入电话号码数量n：";
    cin >> n;
    cout << "输入" << n << "个电话号码：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> phone;
        insert(phone);
    }
    
    cout << "输入查询数量m：";
    cin >> m;
    cout << "输入" << m << "个查询（格式：1 电话号码 或 2 前缀）：" << endl;
    for (int i = 0; i < m; i++) {
        cin >> op >> phone;
        if (op[0] == '1') {
            bool exist = query_exist(phone);
            cout << (exist ? "存在" : "不存在") << endl;
        } else if (op[0] == '2') {
            int count = query_prefix_count(phone);
            cout << "以\"" << phone << "\"为前缀的号码数量：" << count << endl;
        }
    }
    
    return 0;
}