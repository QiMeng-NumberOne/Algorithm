//https://www.acwing.com/problem/content/837/

#include<iostream>
using namespace std;
const int N=100010;
int son[N][26],cnt[N],idx;//idx其实就是节点标号，每次++idx就是创建一个新的节点标号

void insert(char *str){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;//son存储的是当前节点标号p对应元素的下一个节点
        p=son[p][u];//跳到当前节点的下一个节点标号
    }
    cnt[p]++;
}

int find(char *str){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}

int main(){
    int n,sum;
    char str[N],op;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>op>>str;
        if(op=='I') insert(str);
        else if(op=='Q'){
            sum=find(str);
            cout<<sum<<endl;
        }
    }
}