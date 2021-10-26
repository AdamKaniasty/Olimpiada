#include <bits/stdc++.h>

using namespace std;
int n;
struct wierzcholki{
	vector <pair<int,char>> polaczenia;
    bool odwiedzony;
}*w;
void print_map(std::map<string,int> const &m)
{
    for (auto const& pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
vector<map <string,int>> arr(2001);
map <string,int> m;
void dfs(int k,string t,int a)
{
	w[k].odwiedzony = 1;
	auto it = m.find(t);
	auto& it2 = it;
	if ( it == m.end() ) {
        m.insert({t,0});
    }
    else {
        it2->second++;
    }
	for(int i=0; i<w[k].polaczenia.size(); i++){
        if(w[w[k].polaczenia[i].first].odwiedzony!=1){
            t=t+w[k].polaczenia[i].second;
            int g=t.length();
			dfs(w[k].polaczenia[i].first,t,a);
			t.erase(t.begin()+g,t.end());
        }


	}

}

int main(){
std::ios::sync_with_stdio(false);
cin>>n;
int a,b;
char c;
w = new wierzcholki[n+1];
for(int i=0; i<n-1; i++)
{
    cin>>a>>b>>c;
    w[a].polaczenia.push_back({b,c});
    w[b].polaczenia.push_back({a,c});
}
for (int i=0;i<n;i++){
    dfs(i+1,"",i+1);
    for(int i=0;i<n+1;i++){
        w[i].odwiedzony=0;
   }
}
int w=0;
for (auto const& pair: m) {
        string a=pair.first;
        int b=pair.second;
        int c=a.size();
        if (c!=1 && c!=0 ){
        int d=n/c + (n%c!=0);
        if(b>d){
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            w++;
        }
        }
}
cout<<w<<endl;
return 0;
}
