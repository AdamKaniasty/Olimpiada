#include <iostream>
#include <stack>
using namespace std;
int useless,t[250001],w;
stack < int > stos;
int main(){
int n;
ios_base::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++){
    cin>>useless>>t[i];
}
stos.push(-1);
for(int i=0;i<n;i++){
    while(t[i]< stos.top()) stos.pop();
    if(stos.top()!=t[i]){
    w++;
    stos.push(t[i]);
    }


}

cout<<w;

return 0;
}
