#include <iostream>

using namespace std;
int n,d,r,p;
unsigned long long w;
int zd,zp,zr;
long long int t[300000][7];
int main()
{
    long long c[9][3];
    c[0][0]=c[1][0]=c[2][0]=999999999999;
    c[3][0]=c[4][0]=c[5][0]=999999999999;
    c[6][0]=c[7][0]=c[8][0]=999999999999;
    c[0][2]=c[1][2]=c[2][2]=0;
    c[3][2]=c[4][2]=c[5][2]=1;
    c[6][2]=c[7][2]=c[8][2]=2;
    cin>>n;

    for(int i=0;i<n;i++)
{
    cin>>t[i][0]>>t[i][1]>>t[i][2];
    if(t[i][0]==0)
        zd++;
    if(t[i][1]==0)
        zp++;
    if(t[i][2]==0)
        zr++;
    r=t[i][6]=t[i][0]+t[i][1];
    d=t[i][4]=t[i][1]+t[i][2];
    p=t[i][5]=t[i][0]+t[i][2];
    int a=min(min(r,d),p);

    w=w+a;
    t[i][3]=0;
    if(d-a<c[0][0]){
    c[2][0]=c[1][0];
    c[2][1]=c[1][1];
    c[1][0]=c[0][0];
    c[1][1]=c[0][1];
    c[0][0]=d-a;
    c[0][1]=i;
    }
    else if(d-a<c[1][0]){
    c[2][0]=c[1][0];
    c[2][1]=c[1][1];
    c[1][0]=d-a;
    c[1][1]=i;
    }
    else if(d-a<c[2][0]){
    c[2][0]=d-a;
    c[2][1]=i;
    }
    if(p-a<c[3][0]){
    c[5][0]=c[4][0];
    c[2][1]=c[4][1];
    c[4][0]=c[3][0];
    c[4][1]=c[3][1];
    c[3][0]=p-a;
    c[3][1]=i;
    }
    else if(p-a<c[4][0]){
    c[5][0]=c[4][0];
    c[5][1]=c[4][1];
    c[4][0]=p-a;
    c[4][1]=i;
    }
    else if(p-a<c[5][0]){
    c[5][0]=p-a;
    c[5][1]=i;
    }
    if(r-a<c[6][0]){
    c[8][0]=c[7][0];
    c[8][1]=c[7][1];
    c[7][0]=c[6][0];
    c[7][1]=c[6][1];
    c[6][0]=r-a;
    c[6][1]=i;
    }
    else if(r-a<c[7][0]){
    c[8][0]=c[7][0];
    c[8][1]=c[7][1];
    c[7][0]=r-a;
    c[7][1]=i;
    }
    else if(r-a<c[8][0]){
    c[8][0]=r-a;
    c[8][1]=i;
    }


}
unsigned long long a,b,d;
unsigned long long amax,bmax,dmax;
unsigned long long add=999999999999999999;
for(int i=0;i<3;i++){
    for(int j=3;j<6;j++){
        for(int g=6;g<9;g++){
            a=c[i][0];
            b=c[j][0];
            d=c[g][0];

            if(c[i][1]!=c[j][1] && c[i][1]!=c[g][1] && c[j][1]!=c[g][1]){
                if(a+b+d<add){
                    add=a+b+d;
                    amax=a;
                    bmax=b;
                    dmax=d;
                }

            }
        }
    }
}
w=w+add;
if(zd==n) w=w-amax;
if(zp==n) w=w-bmax;
if(zr==n) w=w-dmax;
cout<<w;
    return 0;
}

