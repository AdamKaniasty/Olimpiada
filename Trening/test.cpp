#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int t[5000];
void dane(){

  ifstream in("dane.txt");
  for(int i; i<=5000; i++)
  {
    in >> t[i];
  }
  in. close();
}

bool czyPierwsza(int a)
{
  if(a<2) return false;
  for(int j=2; j*j<a; j++)
    {
      if(a%j==0) return false;
    }
  return true;
}
string zamiana(int a){
  string binarna="";
  if(a==0) return "";
  else{
    while(a>0)
    {
      if(a%2==0)
        binarna="0"+binarna;
      else
        binarna="1"+binarna;
      a/=2;
    }
  return binarna;
  }
}

bool palindrom(string a)
{
  int n = a.size();
  for(int i=0; i<=n/2; i++)
  {
    if(a[i]!=a[n-i-1])
    {
      return false;
    }
  }
  return true;
}
int main() {
  dane();
  int ile=0;
  int najw=t[1];
  int najm=t[1];
  for(int i=1; i<=5000; i++)
  {
    if(czyPierwsza(t[i])){
      ile++;
      if(t[i]<najm) najm=t[i];
      if(t[i]>najw) najw=t[i];
    }
  }
  cout << "Ilosc:" << ile << endl << "Najwieksza:" << najw << endl << "Najmniejsza:" << najm << endl;
  cout << "Zad2"<<endl;
  int pal = 0;
  int pp = 0;
  for(int i=0; i<=5000; i++)
  {
    if(palindrom(zamiana(t[i]))==true){
        pal++;
    }
    else{
    string a=zamiana(t[i]);
    int b=a.size();
    for(int j=0;j<b/2;j++){
        string c="0";
        a="0"+a;
        if(palindrom(a)==true) pp++;
    }
    }
  }
  cout<<pal<<" "<<pp<<endl;
  cout<<endl<<"zad3"<<endl;
  int w=0;
  for(int i=0;i<5000;i++){
    for(int j=0;j<5000;j++){
        if(i!=j){
            int s1[10];
            int s2[10];
            for(int g=0;g<10;g++){
                s1[g]=0;
                s2[g]=0;
            }
            int f=0;
            string ix=to_string(t[i]);
            string jx=to_string(t[j]);
            for(int g=0;g<ix.size();g++){
                int d=1;
                 for (int i = 0; i<g; i++)
                    {
                    d*=10;
                    }
                int l=t[i]/d%10;
                s1[l]++;
            }
            for(int g=0;g<jx.size();g++){
                int d=1;
                 for (int i = 0; i<g; i++)
                    {
                    d*=10;
                    }
                int l=t[j]/d%10;
                s2[l]++;
            }
            for(int g=0;g<10;g++){
                if((s1[g]==0 && s2[g]==0) || (s1[g]>0 && s2[g]>0)){}
                else{
                    f=1;
                    break;
                }
            }
        if(f==0) w++;
        }

    }
  }
  cout<<w<<endl;
}
