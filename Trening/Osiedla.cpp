#include <bits/stdc++.h>
#define N 1000005
using namespace std;
vector <pair<int,int>> graf[N];
vector <int> g[N],rg[N];
pair<int,int> kr[N];
vector <int> order;
int odw[N],dir[N],w=0;

void dfs1(int n){
odw[n]=1;
for(auto u:graf[n]){
    int nr=u.second;
    if(dir[nr]==0){
        if(n==kr[nr].first){
            dir[nr]=1;
        }
        else{
            dir[nr]=2;
        }
        if(odw[u.first]==0) dfs1(u.first);

    }
}
}
void dfs2(int n){
    odw[n]=1;
    for(auto u: g[n]){
        if(odw[u]==0) dfs2(u);
    }
    order.push_back(n);
}
void dfs3(int n){
    odw[n]=1;
    for(auto u: rg[n]){
        if(odw[u]==0) dfs3(u);
    }
}
int main(){
int n,m;
cin>>n>>m;
for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    graf[a].push_back({b,i});
    graf[b].push_back({a,i});
    kr[i]={a,b};
}
for(int i=1;i<=n;i++){
    if(odw[i]==0) dfs1(i);

}
for(int i=1;i<=n;i++){
    odw[i]=0;
}
for(int i=1;i<=m;i++){
int a=kr[i].first,b=kr[i].second;
if(dir[i]==1){
    g[a].push_back(b);
    rg[b].push_back(a);
}
if(dir[i]==2){
    g[b].push_back(a);
    rg[a].push_back(b);
}
}
for(int i=1;i<=n;i++){
    if(odw[i]==0) dfs2(i);
}
for(int i=1;i<=n;i++){
    odw[i]=0;
}
for(int i=n-1;i>=0;i--){
    int a=order[i];
    if(odw[a]==0){
        w++;
        dfs3(a);
    }
}
cout<<w<<endl;
for(int i=1;i<=m;i++){
    if(dir[i]==1)
        cout<<">";
    else
        cout<<"<";
}


return 0;
}
