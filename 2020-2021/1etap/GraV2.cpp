#include <bits/stdc++.h>

using namespace std;
struct poziom{
	vector <int> dziury;

}*p;

int n,X,z,k,a,w,x,y,koszt;
int dod(int a,int b){
    if(a-b>0)
        return a-b-1;
    else
        return 0;
}

int main(){
cin>>n>>X>>z;
vector <int> u(n+1,0);
p = new poziom[n+1];
int k[n+1],m;
for(int i=1;i<=n;i++){
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>a;
        p[i].dziury.push_back(a);
    }
}
for(int i=0;i<z;i++){
    cin>>a;
    x=1;
    y=a;
    w=0;
    int d=0;
    int l=0;
    int mi=999999999,id=999999999;
    fill (u.begin(),u.end(),0);

    while(x!=X){
      //  cout<<"start"<<endl;
        mi=999999999;
        for(int i=1;i<=n;i++){
            if(x-1==p[i].dziury[0]){
                    rotate(p[i].dziury.begin(),
                    p[i].dziury.begin()+1,
                    p[i].dziury.end());
                    u[i]++;

            }
            if(l==1){
            if(x-2==p[i].dziury[0]){
                    rotate(p[i].dziury.begin(),
                    p[i].dziury.begin()+1,
                    p[i].dziury.end());
                    u[i]++;
            }
            }
            if(i>y)
            k[i]=dod(y,i)+p[i].dziury.size()-1-u[i];
            else
            k[i]=dod(y,i)+p[i].dziury.size()-u[i];
         //   cout<<y<<" "<<x<<" "<<i<<" "<<k[i]<<" "<<mi<<endl;
         //cout<<w<<endl;
            if(k[i]<mi){
                mi=k[i];
                id=i;
            }
            else if(k[i]==mi && abs(y-i)<abs(y-id)){
                mi=k[i];
                id=i;
            }
            else if(k[i]==mi && abs(y-i)==abs(y-id)&&i>id){
                mi=k[i];
                id=i;
            }
            if(id<y)
                d=2;
            else if (id==y)
                d=1;
            else
                d=0;
        }  //  cout<<" "<<y<<" "<<x<<" "<<*p[y].dziury.begin()<<" "<<*p[y-1].dziury.begin()<<endl;
    //cout<<"kierunek "<<d<<" "<<id<<" "<<y<<" "<<x<<endl;
    if(y==n){
        if(x+1 != *p[y].dziury.begin() && x != *p[y-1].dziury.begin() ){
            x=x+1;
        }
        else if(x+1 == *p[y].dziury.begin() && x != *p[y-1].dziury.begin() ){
            x=x+1;
            w++;
        }
        else if(x == *p[y-1].dziury.begin()){
            if(d==2){
                x=x+1;
                y=y-1;
                w++;
            }
            else if (d==1 && k[y-1]<=k[y]){
                x=x+1;
                y=y-1;
                w++;
            }
            else {
                if (x+1 == *p[y].dziury.begin()){
                    x=x+1;
                    w++;
                }
                else{
                    x=x+1;
                }
            }
        }
    }
    else if(y==1){
        if(x+1 != *p[y].dziury.begin()){
            x=x+1;
        }
        else{
            x=x+1;
            y=y+1;
        }
    }
    else{
        if(x+1 != *p[y].dziury.begin() && x != *p[y-1].dziury.begin() ){
            x=x+1;
        }
        else if(x == *p[y-1].dziury.begin()){
            if(d==2){
                x=x+1;
                y=y-1;
                w++;
            }
            else if (d==1 && k[y-1]<=k[y]){
                x=x+1;
                y=y-1;
                w++;
            }
            else {
                if (x+1 == *p[y].dziury.begin()){
                    x=x+1;
                    y=y+1;
                }
                else{
                    x=x+1;
                }

            }
        }
        else if(x+1 == *p[y].dziury.begin()){
            x=x+1;
            y=y+1;

        }
    }
    if(x==X){
    for(int i=1;i<=n;i++){
            if(x-1==p[i].dziury[0]){
                    rotate(p[i].dziury.begin(),
                    p[i].dziury.begin()+1,
                    p[i].dziury.end());
                    u[i]++;

            }
    }
    }
    }
    cout<<w<<endl;
}

return 0;
}

