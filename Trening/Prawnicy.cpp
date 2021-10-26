#include <bits/stdc++.h>
#define N 1000000
using namespace std;
vector <pair<int,int>> v;
long long ma,l,cnt,w,wynik,pw,lw;
set <int>p;
long long a[N],b[N];
int n,k;
int main(){
cin>>n>>k;
for(int i=0;i<n;i++){
cin>>a[i]>>b[i];
ma=max(ma,b[i]);
v.push_back(make_pair(a[i],b[i]));
}
sort(v.begin(), v.end());
for(int i=1;i<=ma;i++){

if(v[cnt].first<=i){
    if(w!=k){
        p.insert(v[cnt].second);
        w++;
    }
    else if(w==k){
        p.insert(v[cnt].second);
        auto It = p.begin();
        p.erase(It);

    }
    l=v[cnt].first;
    cnt++;
}
auto It = p.begin();
if(w==k && *It - l>wynik){
    wynik=*It - l;
    pw=*It;
    lw=l;
}
}
cout<<wynik<<endl;
int cnt=0;
for(int i=0;i<n;i++){
    if(a[i]<=lw && b[i]>=pw){
        cout<<i+1<<" ";
        cnt++;
    }
    if(cnt==k)
        return 0;

}
return 0;
}
