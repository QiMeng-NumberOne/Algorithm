#include <iostream>
using namespace std;

void quick_sort(int a[],int l,int r){
    if(l>=r) return ;
    int i=l,j=r,x=a[(l+r)>>1];
    while(i<j){
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<j) swap(a[i],a[j]);
    }
    quick_sort(a,l,j-1),quick_sort(a,j,r);
}


int main(){
    int n;
    int a[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
