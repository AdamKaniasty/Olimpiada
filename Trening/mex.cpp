#include <iostream>
#include <vector>
using namespace std;
int n;
int main(){
cin>>n;
vector <float> v;
for(int i=0;i<2*n;i++){
v.push_back(float(i)/2);
}
for(int i=0;i<2*n;i++){
cout<<v[i]<<" ";
}



return 0;
}

