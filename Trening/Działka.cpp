#include <bits/stdc++.h>
using namespace std;
int prawo[2001],lewo[2001];
bool t[2001][2001];
int a[2001][2001],wk=0;
int n;
int f(int i){
    stack < pair<int,int> > stos;
    stos.push({-1,-1});
    for(int j=0;j<n;j++){
        while(stos.top().first >= a[i][j]) stos.pop();
        lewo[j]=stos.top().second;
        stos.push({a[i][j],j});
    }
    while(stos.size()) stos.pop();
    stos.push({-1,n});
    for(int j=n-1;j>=0;j--){
        while(a[i][j]<=stos.top().first) stos.pop();
        prawo[j]=stos.top().second;
        stos.push({a[i][j],j});
    }
    int w=0;
    for(int j=0;j<n;j++){
        w=max(w,(prawo[j]-lewo[j]-1)*a[i][j]);
    }
    return w;
}
int main(){
ios_base::sync_with_stdio(0);
cin>>n;


for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>t[i][j];
    }
}
for(int j=0;j<n;j++){
    for(int i=n-1;i>=0;i--){
        if(t[i][j]==1) a[i][j]=0;
        else a[i][j]=a[i+1][j]+1;
    }
}
for(int i=0;i<n;i++){
int w=f(i);
wk=max(wk,w);
}
cout<<wk;

return 0;
}

