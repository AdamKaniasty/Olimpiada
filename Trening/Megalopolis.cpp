#include <bits/stdc++.h>
#define N 250001
#define NTREE 262144
using namespace std;
int n,idx,h;
vector <int> graf[N];
int tree[2*NTREE];
int preorder[N],postorder[N],height[N];
void dfs(int a,int h){
    idx++;
    preorder[a]=idx;
    height[a]=h;
    for(auto i:graf[a])
        dfs(i,h+1);
    postorder[a]=idx;

}
void update(int l,int r){
l+=NTREE;
r+=NTREE;
if(l==r){
    tree[l]++;
    return;
}
tree[l]++;
tree[r]++;
while(r-l>1){
    if(l%2==0) tree[l+1]++;
    if(r%2==1) tree[r-1]++;
    l/=2;
    r/=2;
}
}
int query(int v){
v+=NTREE;
int sum=0;
while(v){
    sum+=tree[v];
    v/=2;
}
return sum;
}
int main(){
    ios_base::sync_with_stdio(0);
cin>>n;
for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    graf[a].push_back(b);
}
dfs(1,0);
int m;
cin>>m;
for(int i=0;i<n+m-1;i++){
    char d;
    cin>>d;
    if(d=='A'){
        int a,b;
        cin>>a>>b;
        if(a>b){
            swap(a,b);
        }
        update(preorder[b],postorder[b]);
    }
    if(d=='W'){
        int a;
        cin>>a;
        int b=query(preorder[a]);
        cout<<height[a]-b<<endl;
    }
}
return 0;
}
