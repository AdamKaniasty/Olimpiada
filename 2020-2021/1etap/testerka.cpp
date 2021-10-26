#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i = 1;
	while(true) {
		string num = to_string(i);
		string q1 = "Gra.exe < GraTesty\\in\\gra" + num + ".in > GraTesty\\gra" + num + ".out";
		string q2 = "fc GraTesty\\gra" + num + ".out GraTesty\\out\\gra" + num + ".out";
		system(q1.c_str());
		system(q2.c_str());
		if(system(q2.c_str())==1) break;
		cout<<i++<<"\n";
		}
	return 0;
}
