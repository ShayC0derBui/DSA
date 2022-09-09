#include <bits/stdc++.h>
using namespace std;
int p_snake_n_ladder_die(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=6;i++){
        ans+=p_snake_n_ladder_die(s+i,e);
    }
    return ans;
}
int main()
{
    cout<<p_snake_n_ladder_die(0,27);
    return 0;
}
