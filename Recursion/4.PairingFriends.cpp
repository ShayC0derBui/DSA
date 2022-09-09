#include<iostream>
using namespace std;
int countPairing(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return countPairing(n - 1) + countPairing(n - 2) * n - 1;
}
int main(){
    cout<<countPairing(7);
    return 0;
}