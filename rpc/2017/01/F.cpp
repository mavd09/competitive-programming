#include <bits/stdc++.h>

using namespace std;

int n,k, s,b, cur;
string w;

int main(){
	
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	//freopen( "/home/vg/Programacion/input", "r", stdin );
	cin >> n >> k;
	s = 1; b = k;
	for(int i = 0; i < n;i++){
		cin >> cur >> w;
		if( w == "SAFE" ) {
			s = max(s,cur);
		}
		else {
			b = min(b,cur);
		}
	}
	cout << s+1 << " " << b-1 << "\n";

	return 0;
}