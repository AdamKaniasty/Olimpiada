#include <bits/stdc++.h>
#define N 10001
using namespace std;
const long long INF=100000000000000000011;
int n,g;
int main(){
cin>>n>>g;
int t[N],k[N];
long long koszt[N];
for(int i=0;i<n;i++){
cin>>t[i]>>k[i];
}
for(int i=0;i<g+1;i++){
    koszt[i]=INF;
}
koszt[0]=0;
for(int i=0;i<n;i++){
    int v=t[i];
    int cost=k[i];
    for(int j=g;j>=0;j--){
        if(j+v>g) koszt[g]=min(koszt[g],koszt[j]+cost);
        else koszt[j+v]=min(koszt[j+v],koszt[j]+cost);
    }
}
if(koszt[g]==INF){
    cout<<"NIE";
    return 0;
}
cout<<koszt[g]+g;


return 0;
}
