#include<iostream>
using namespace std;
const int N=10010;
int head,idx,ne[N],e[N];

void init(){
    head=-1;
    idx=0;
}

void add_to_head(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx++;
}

void add_to_head(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k-1];
    ne[k-1]=idx++;
}

void del_k(int k){
    ne[k-1]=ne[ne[k-1]];
}

int main(){
    int m;
    init();
    cin>>m;
    while(m--){
        char s;
        cin>>s;
        if(s=='H'){
            int x;
            cin>>x;
            add_to_head(x);
        }
        if(s=='I'){
            int k,x;
            cin>>k>>x;
            add_to_k(k,x);
        }
        if(s=='D'){
            int k;
            cin>>k;
            if (k == 0) head = ne[head];
            else del_k(k);
        }
    }
    for(int i=head;i!=-1;i=ne[i]){
        cout<<e[i]<<" ";
    }
    return 0;
}