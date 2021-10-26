#include <bits/stdc++.h>

using namespace std;
int n;
vector <pair<int,int>> x2;
vector <int> x;
vector<int>::iterator it;
vector <int> w;
int main()
{
cin>>n;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    x.push_back(a);
    x2.push_back({a,i});
}
sort(x2.begin(), x2.end());
vector <int>dp;
dp.push_back(x2[0].first);
int mi=1;
int cnt=0;
int cnti=0;
for(int i=1;i<n;i++){
    int a=dp[i-1]+x2[mi].first;
    cout<<a<<" "<<x2[mi].second<<endl;
    if(find (x.begin(), x.begin()+x2[mi].second, a)!=x.begin()+x2[mi].second){
        for (int j=1;j<n-mi;j++){
            a=dp[i-1]+x2[mi+j].first;
            if(find (x.begin(), x.end(), a)==x.end()) break;
        }

    }
    cout<<a<<" "<<cnt+x[cnti]<<endl;
    cout<<x2[mi-1].first<<endl;
    if(a>=cnt+x[cnti]){
            dp.push_back(cnt+x[cnti]+x2[mi-1].first);
            cnt=cnt+x[cnti];
            cnti++;
            int j = 0;
            while(j < x2.size())
                if (x2[j].second == x2[mi-1].first){
                    x2.erase(x2.begin() + j);
                    break;
                }

                else
                    j++;
            }
    else{
            dp.push_back(a);
    }


}
cout<<endl;
for(int i = 0; i < dp.size(); i++)
{
     cout << dp[i]<<" ";
}
    return 0;
}
