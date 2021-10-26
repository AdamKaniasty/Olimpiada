#include<iostream>
#include<vector>
#include <set>
using namespace std;
struct wierzcholki{
	vector <int> polaczenia;
    bool odwiedzony;
}*w;

struct input{
	int i1;
	int i2;

}*in;
int pol[150001];
int pol2[150001];
int gr[150001];
int it=1;
set <int> licz;
int wynik=0;
void dfs(int k,int l,int c)
{
	w[k].odwiedzony = 1;
	gr[it]=k;
	pol[k]=gr[it-1];
	pol2[k]=c;
   // cout<<"Odwiedzono "<<k<<" "<<pol[k]<<" "<<c<<endl;
	for(int i=0; i<w[k].polaczenia.size(); i=i+2){
       // cout<<w[k].polaczenia[i]<<" "<<w[w[k].polaczenia[i]].odwiedzony<<endl;
        if(w[w[k].polaczenia[i]].odwiedzony!=1){
            it++;
			dfs(w[k].polaczenia[i],k,w[k].polaczenia[i+1]);
			it--;
        }


	}

}
void droga(int k){
if(k==1 || k==0) return;
licz.insert(pol2[k]);
//cout<<k<<" "<<pol2[k]<<" "<<pol[k]<<endl;
droga(pol[k]);

}
int main()
{
   // cout<<"start"<<endl;
	unsigned int n,s, a,c, b,m,z;
	cin>>n>>m>>z;

	w = new wierzcholki[n+1];
	in = new input[n];
	for(int i=0; i<n-1; i++)
	{
		cin>>a>>b>>c;
        w[a].polaczenia.push_back(b);
        w[b].polaczenia.push_back(a);
        w[a].polaczenia.push_back(c);
        w[b].polaczenia.push_back(c);
        in[i+1].i1 = a;
        in[i+1].i2 = b;
    //    cout<<in[i+1].i1<<" "<<in[i+1].i2<<endl;

	}
   // cout<<"start"<<endl;
   for(int i=0;i<n+1;i++){
    w[i].odwiedzony=0;
   }
    dfs(1,0,0);
	char d;

	for(int i=0;i<z;i++){
    cin>>d;
    if(d=='Z'){
    cin>>s;
    licz.clear();
    droga(s);
    cout<<licz.size()<<endl;
	}
	else{
	cin>>a>>b;
    if(pol[in[a].i1]==in[a].i2)
        pol2[in[a].i1]=b;
    else
        pol2[in[a].i2]=b;

	}
   // w[in[a].i2].biciaki[in[a].i1]=b;
	}
	return 0;
}
