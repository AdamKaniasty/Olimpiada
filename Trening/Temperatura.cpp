#include <bits/stdc++.h>
#define N 1000001
#define NTREE 1048576
using namespace std;
const long long INF = 1e9 + 1;
int n;
int tree[NTREE*2];
pair <int,int> t[N];
int query(int p, int k) {
	p += NTREE, k += NTREE;
	if(p == k)
		return tree[p];
	int ans = max(tree[p], tree[k]);
	while(k - p > 1) {
		if(p % 2 == 0) ans = max(ans, tree[p + 1]);
		if(k % 2 == 1) ans = max(ans, tree[k - 1]);
		p /= 2;
		k /= 2;
	}
	return ans;
}
int main(){
ios_base::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++){
cin>>t[i].first>>t[i].second;
}
for(int i=0;i<2*NTREE;i++)
    tree[i]=-INF;
for(int i=1;i<=n;i++)
    tree[i+NTREE]=t[i].first;
for(int i=NTREE-1;i>=1;i--)
    tree[i]=max(tree[2*i],tree[2*i+1]);

int w=1;
int p=1,k=1;
while(k<n){
    k++;
    while(query(p,k)>t[k].second)
        p++;
    w=max(w,k-p+1);
}
cout<<w;

return 0;
}
