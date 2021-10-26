#include <bits/stdc++.h>
using namespace std;
int n,m,q,w;
int main(){
cin>>n>>m>>q;
vector<vector<int>> t( n+1 , vector<int> (m+1));
for(int j=1;j<=n;j++){
      for(int g=1;g<=m;g++)
            t[j][g]=0;
    }
int x1,x2,y1,y2;
for(int i=0;i<q;i++){
    cin>>x1>>y1>>x2>>y2;
    for(int j=x1;j<=x2;j++){
        for(int g=y1;g<=y2;g++){
            if(t[j][g]==1)
                t[j][g]=0;
            else t[j][g]=1;
        }

    }
   // for(int j=1;j<=n;j++){
   //   for(int g=1;g<=m;g++)
   //         cout<<t[j][g]<<" ";
   //     cout<<endl;
   // }
   // cout<<"s"<<endl;
    w=0;
    vector <int>k(n+1,1);
    for(int j=m;j>0;j--){
        for(int g=n;g>0;g--){
           //  cout<<g<<" "<<k[g]<<" "<<t[g][j]<<endl;
            if(t[g][j]==k[g]){
               // cout<<"tak"<<endl;
                w++;
                for(int h=g;h>0;h--){
                    if(k[h]==1)k[h]=0;
                    else k[h]=1;
                }
            }
        }
    }
    cout<<w<<endl;

}


    return 0;
}
