#include<iostream>
using namespace std;
bool isSafe(int **a,int i,int j,int m,int n){
    if(i<m && j<n && a[i][j]!=0)
        return true;
    else 
        return false;
}
bool ratMaze(int **a,int i,int j,int **b,int m,int n){
    if(i==m-1 && j==n-1)
    {
        b[i][j]=1;
        return true;
    }
    if(isSafe(a,i,j,m,n)){
        b[i][j]=1;
        if(ratMaze(a,i,j+1,b,m,n))
            return true;
        if(ratMaze(a,i+1,j,b,m,n))
            return true;
        b[i][j]=0;
        return false;
    }
    return false;
}
int main(){
    int m,n;cin>>m>>n;
    
    int **a=new int*[m];
    for(int i=0;i<m;i++){
        a[i]=new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    
    int **b=new int*[m];
    for(int i=0;i<m;i++){
        b[i]=new int[n];
        for(int j=0;j<n;j++){
            b[i][j]=0;
        }
    }
    
    
    
        ratMaze(a,0,0,b,m,n);
        
    
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
