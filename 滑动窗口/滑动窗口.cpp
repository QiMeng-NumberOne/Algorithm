#include<iostream>
#include<deque>
using namespace std;

const int N=1000010;
int a[N];

int main(){
    int n,k;
    deque<int> b;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //最小值
    for(int i=1;i<=n;i++){
        while( b.size() && b.back()>a[i]) b.pop_back();//每次将最小值放在对头
        b.push_back(a[i]);
        if(i-k>=1&&b.front()==a[i-k]) b.pop_front();//如果是[3 4 5 6],元素个数>k,判断对头是否出对,出对后为[4 5 6]
        if(i>=k) cout<<b.front()<<" ";
    }
    b.clear();
    cout<<endl;
    //最大值
    for(int i=1;i<=n;i++){
        while( b.size() && b.back()<a[i]) b.pop_back();//每次将最大值放在对头
        b.push_back(a[i]);
        if(i-k>=1&&b.front()==a[i-k]) b.pop_front();
        if(i>=k) cout<<b.front()<<" ";
    }
}
