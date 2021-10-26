#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int in[1000000];
int mdo[1000000],mpo[1000000],naj=0;
vector <int> o;
vector <int> rev[1000001];
queue <int> Q;
int q,m[1000000],d[1000000];
int main(){
int n,x,y,cnt=0,pocz=0;
cin>>n;
vector <int> w[n+1];


int t[n+1];
for(int i=1;i<=n;i++){
    cin>>t[i];
    cin>>x;
    for(int j=1;j<=x;j++){
        cin>>y;
        in[i]++;
        w[y].push_back(i);
        rev[i].push_back(y);

    }
}
cin>>q;
for(int l=1;l<=q;l++){
    cin>>m[l]>>d[l];
}
for(int i=1;i<=n;i++)
    if(in[i]==0){
        Q.push(i);
    }
while(!Q.empty()){
    int v=Q.front();
    Q.pop();
    o.push_back(v);
    for(int i=0;i<w[v].size();i++){
        in[w[v][i]]--;
        if(in[w[v][i]]==0)
            Q.push(w[v][i]);
    }
}
if(o.size()!=n)
{
    cout<<"CYKL";
    return 0;
}
for(int i=0;i<o.size();i++){
    int v=o[i];
    for(int j=0;j<rev[v].size();j++){
        mdo[v]=max(mdo[v],mdo[rev[v][j]]);
    }
    mdo[v]=mdo[v]+t[v];
}
for(int i=o.size()-1;i>=0;i--){
    int v=o[i];
    for(int j=0;j<w[v].size();j++){
        mpo[v]=max(mpo[v],mpo[w[v][j]]);
    }
    mpo[v]=mpo[v]+t[v];
}
for(int i=1;i<=n;i++){
    naj=max(naj,mpo[i]+mdo[i]-t[i]);
}

cout<<naj<<endl;
for(int i=1;i<=q;i++){
    if(mdo[m[i]]+mpo[m[i]]-t[m[i]] + d[i] > naj)
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;
}


return 0;
}

