//https://www.acwing.com/problem/content/787/

#include<iostream>
using namespace std;
 void quick_sort(int a[],int l,int r){
    if(l>=r) return;
    int i=l-1,j=r+1,x=a[l+r>>1];
    while(i<j){
        do i++;while(a[i]<x);
    }
 }




