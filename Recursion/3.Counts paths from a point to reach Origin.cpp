#include<bits/stdc++.h>
using namespace std;
int countMazePath(int n,int m){
    if(n==0 || m==0){
        return 1;
    }
    return countMazePath(n-1,m)+countMazePath(n,m-1);
}
int main(){
    cout<<countMazePath(4,6);
    return 0;
}
