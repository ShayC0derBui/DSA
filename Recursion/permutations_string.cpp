#include <bits/stdc++.h>
using namespace std;
void p(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char fixed=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        p(ros,ans+fixed);
    }
}
void str_permutations(string s){
    p(s,"");
    return;
}
int main()
{
    str_permutations("abcdefg");
    return 0;
}
