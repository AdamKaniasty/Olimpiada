#include <bits/stdc++.h>
#include <experimental/iterator>
using namespace std;
typedef pair<float, float> pairs;
typedef tuple<float,float,float> tp;
struct comp
{
    bool operator()(const tp& x, const tp& y) const
    {
        return get<0>(x) > get<0>(y) || (get<0>(x) == get<0>(y) && get<1>(x)/get<2>(x) < get<1>(y))/get<2>(y);
    }
};
set <tp,comp> s;
vector <pairs> t;
bool c(float x){
 if(x-int(x) == 0)
    return 1;
 else return 0;
}
void f(){
float a,b=0;
for (auto const &var : s) {
      float a=get<0>(var);
      int b=get<1>(var);
      float c=get<2>(var);
      if(fmod(a,2)==0.0){
        s.insert(make_tuple(a/2.0,b,c));
        s.insert(make_tuple(a/2.0,b+a/2.0,c));
        t.push_back(make_pair(b+a/2.0,c));
      }
    else{
        s.insert(make_tuple(float(float(a)/2.0),b,c));
        s.insert(make_tuple(float(float(a)/2.0),a*c+b+b,c*2));
        t.push_back(make_pair(a*c+b+b,c*2));
    }
      break;
   }
auto it=s.begin();
s.erase(it);
}
int n,X,z;
int main(){
std::ios::sync_with_stdio(false);
cin>>n>>X>>z;
int a,b;
cin>>a;
for(int i=1;i<n;i++){
cin>>b;
s.insert(make_tuple(float(b-a),float(a),1));
a=b;
}
int g;
vector<int> T;
for(int i=0;i<z;i++){
    cin>>g;
    T.push_back(g);
}
for(int i=0;i<g;i++){
f();
}
s.clear();
for(int i=0;i<g;i++){
    if(i==*T.begin()-1){
        if(c(t[i].first)==0){
            while(c(t[i].first)==0)
                t[i].first*=2;
                t[i].second*=2;
            cout<<t[i].first<<"/"<<t[i].second<<endl;
        }
        else{
            cout<<t[i].first<<"/"<<t[i].second<<endl;
        }

        T.erase(T.begin());
    }
}

return 0;
}
