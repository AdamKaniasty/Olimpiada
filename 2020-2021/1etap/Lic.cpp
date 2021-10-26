#include <bits/stdc++.h>
using namespace std;
set <int> d;
set<int>::iterator it,itup;
int n,z,start,en,dod;
char t;
int j;
char c;
void print(set<int> const &s)
{
	copy(s.begin(),
			s.end(),
			ostream_iterator<int>(cout, " "));
}
int main(){
cin>>n>>z;
char dw[n+1];
char dz[n+1];
dw[n]='0';
dz[n]='0';
dw[0]='0';
dz[0]='0';
for(int i=1;i<n;i++)
    cin>>dw[i];
for(int i=1;i<n;i++)
    cin>>dz[i];
for(int i=1;i<n;i++){
if(dw[i]+dz[i]==9+2*48 && start==0){

    start=i;
    if(dw[i+1]+dz[i+1]!=9+2*48){
        d.insert(start);
        en=0;
        start=0;
    }
}
else if((dw[i]+dz[i]!=9+2*48 && start!=0)){
    en=i-1;
    d.insert(en);
    en=0;
    start=0;
}
else if(i==n-1 && start!=0){
    en=i;
    d.insert(en);
    en=0;
    start=0;
}
}
/*
print(d);
cout<<endl;
cout<<"test"<<dw[n-2317]<<" "<<dz[n-2317]<<endl;
cout<<"test"<<dw[n-2316]<<" "<<dz[n-2316]<<endl;
cout<<"test"<<dw[n-2315]<<" "<<dz[n-2315]<<endl;
cout<<"test"<<dw[n-2314]<<" "<<dz[n-2314]<<endl;*/
//cout<<"test"<<dw[n-3551]<<" "<<dz[n-3551]<<endl;
//cout<<"test"<<dw[n-3550]<<" "<<dz[n-3550]<<endl;
for(int i=0;i<z;i++){
    cin>>t;
     if(t=='W'){
            cin>>j>>c;
        if(dw[n-j]+dz[n-j]==105 && dw[n-j-1]+dz[n-j-1]-2*48==9){
            d.erase(n-j);
            d.insert(n-j-1);


        }
        else if(dw[n-j]+dz[n-j]==105){
            d.erase(n-j);
       //     if(j==2316) cout<<"tak "<<n-j<<endl;
        }
        dw[n-j]=c;

        if(dw[n-j]+dz[n-j]-2*48==9){
            if(dw[n-j+1]+dz[n-j+1]-2*48==9 && dw[n-j-1]+dz[n-j-1]-2*48==9){
                d.erase(n-j-1);
            }
            else if(dw[n-j-1]+dz[n-j-1]-2*48==9 ){
                d.erase(n-j-1);
                d.insert(n-j);
            }
            else if(dw[n-j+1]+dz[n-j+1]-2*48!=9 && dw[n-j-1]+dz[n-j-1]-2*48!=9){
                d.insert(n-j);
            }

        }

        }

    if(t=='Z'){
            cin>>j>>c;
        //    if(j==2315) cout<<"tak2 "<<n-j<<endl;
        if(dw[n-j]+dz[n-j]==105 && dw[n-j-1]+dz[n-j-1]-2*48==9){
            d.erase(n-j);
            d.insert(n-j-1);

        }
        else if(dw[n-j]+dz[n-j]==105){
            d.erase(n-j);
        }

        dz[n-j]=c;
      //  if(j==2315) cout<<"tak3 "<<dz[n-j]+dw[n-j]-2*48<<endl;
        if(dw[n-j]+dz[n-j]-2*48==9){
            if(dw[n-j+1]+dz[n-j+1]-2*48==9 && dw[n-j-1]+dz[n-j-1]-2*48==9){
            //        if(j==2315) cout<<"tak4"<<endl;
                d.erase(n-j-1);
            }
            else if(dw[n-j-1]+dz[n-j-1]-2*48==9 ){
                d.erase(n-j-1);
                d.insert(n-j);
        //    if(j==2315) cout<<"tak5"<<endl;
            }
            else if(dw[n-j+1]+dz[n-j+1]-2*48!=9 && dw[n-j-1]+dz[n-j-1]-2*48!=9){
                d.insert(n-j);
         //       if(j==2315) cout<<"tak6"<<endl;
            }

        }

        }


    else if(t=='S'){
    cin>>j;

  //  cout<<n-j+48<<endl;
   // cout<<dw[n-j+48]+dz[n-j+48]-2*48<<endl;
  // if(j==3553)   cout<<dw[n-j+1]+dz[n-j+1]-2*48<<endl;

if(dw[n-j+1]+dz[n-j+1]-2*48<9) dod=0;
    else if(dw[n-j+1]+dz[n-j+1]-2*48>9) dod=1;
    else if(dw[n-j+1]+dz[n-j+1]-2*48==9){
      //if(j==494)   cout<<"dziewiatka"<<endl;
      //if(j==494)  cout<<dw[n-493]+dz[n-493]-2*48<<endl;
    it=d.find(n-j+1);
 //   if (j==2316) cout<<"n-j+1 "<<n-j+1<<endl;
    if(n-j==n-1) dod=0;
    else if (it !=d.end()){
 //    if (j==2316)   cout<<"111111"<<endl;
    //   if (j==3553) cout<<dw[n-j+2]<<" "<<dz[n-j+2]<<endl;
    //   if (j==3553) cout<<dw[n-j+3]<<" "<<dz[n-j+3]<<endl;
        if(dw[n-j+2]+dz[n-j+2]-2*48>9) dod=1;
        else dod=0;
    }
	else{
	//   if (j==2316) cout<<"2222222"<<endl;
       // cout<<n-j+1+48<<endl;
        itup=d.upper_bound(n-j+1);
     //  if (j==2316){
    //    cout<<dw[*itup]<<" "<<dz[*itup]<<" "<<*itup<<endl;
    //    cout<<dw[n-j+1]<<" "<<dz[n-j+1]<<endl;
    //   }
        if(dw[*itup+1]+dz[*itup+1]-2*48>9) dod=1;
        else dod=0;

	}
    }
  //  cout<<"dod "<<dod<<endl;
  //  cout<<j<<endl;
  //  cout<<dw[n-j]<<" "<<dz[n-j]<<endl;
  //cout<< dw[n-j]<<" "<<dz[n-j]<<endl;

       /* if (j==2316) {
                cout<<"s"<<endl;
                cout<<dw[n-j]<<" "<<dz[n-j]<<endl;
                cout<<dw[n-2315]<<" "<<dz[n-2315]<<endl;
                cout<<dw[n-2317]<<" "<<dz[n-2317]<<endl;


        }*/
    if(dw[n-j]+dz[n-j]-2*48<9) cout<<dw[n-j]+dz[n-j]-2*48+dod<<endl;
    else if(dw[n-j]+dz[n-j]-2*48>9) cout<< dw[n-j]+dz[n-j]-2*48-10+dod<<endl;
    else if (dw[n-j]+dz[n-j]-2*48==9){
        if(dod==0) cout<<9<<endl;
       else cout<<0<<endl;
    }
   // if (j==2316) cout<<dod<<endl;
  //  if (j==2316) print(d);
    }
//cout<<"d"<<endl;
//print(d);
//   cout<<endl;
//cout<<endl;
}


    return 0;
}
