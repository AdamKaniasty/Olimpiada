#include<iostream>
#include<vector>
using namespace std;
struct wierzcholki{
	vector <unsigned int> polaczenia;

}*w;
struct input{
	int i1;
	int i2;
	int i3;
	int i4;

}*in;
bool done=0;
int odwiedzoned =0;
int nr=0;
bool daj=1;
vector <int> licz (100000,0);
int wynik=0;
void w_glab(int k, int d, int c,int e)
{

	//cout<<"Odwiedzono "<<k<<" wierzcholek\n";
	//cout<<c<<" "<<e<<endl;
	if(c!=0){
  //  cout<<"biciak "<< w[c].polaczenia[e+1]<<" "<<licz[w[c].polaczenia[e+1]]<<" "<<wynik<<endl;
        licz[w[c].polaczenia[e+1]]++;
        if(licz[w[c].polaczenia[e+1]]==1)
        {
            wynik++;
        }
      //  cout<<"biciak "<< w[c].polaczenia[e+1]<<" "<<licz[w[c].polaczenia[e+1]]<<" "<<wynik<<endl;
	}
	for(int i=0; i<w[k].polaczenia.size(); i=i+2){
   // cout<<w[k].polaczenia.size()<<" "<<k<<" "<<i<<endl;
    if(done==1){
        break;
    }
    if(k==d){
    done=1;
    return;
        }
    if (w[k].polaczenia[i]!=c){
        w_glab(w[k].polaczenia[i],d,k,i);

}
}
//cout<<"PO WYKONIANIU "<<c<<" "<<nr<<endl;
if(done!=1){

      if(licz[w[c].polaczenia[e+1]]!=0){
        licz[w[c].polaczenia[e+1]]--;
        if(licz[w[c].polaczenia[e+1]]==0){
            wynik--;
        }
      }
 //cout<<"koniec "<<pog[k]<<" "<<k<<" "<<wynik<<endl;
    }
}
int main()
{
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
        in[i+1].i2 = w[a].polaczenia.size();
        in[i+1].i3 = b;
        in[i+1].i4 = w[b].polaczenia.size();
    //    cout<<in[i+1].i1<<" "<<in[i+1].i2<<endl;

	}
	//for(int i=1;i<n-1;i++){
    //    cout<<i<<"  ";
   //     for(int j=0;j<w[i].polaczenia.size();j++){
   //         cout<<w[i].polaczenia[j]<<" ";
  //      }
  //      cout<<endl;
//	}
	char d;
	for(int i=0;i<z;i++){
    cin>>d;

    if(d=='Z'){
    cin>>s;
    done=0;
    wynik=0;
    odwiedzoned=0;
    fill(licz.begin(),licz.end(),0);
    w_glab(s,1,0,0);
    cout<<wynik<<endl;
	}
	else{

	cin>>a>>b;
    w[in[a].i1].polaczenia[in[a].i2-1]=b;
    w[in[a].i3].polaczenia[in[a].i4-1]=b;

	}
   // w[in[a].i2].biciaki[in[a].i1]=b;
	}
	return 0;
}
