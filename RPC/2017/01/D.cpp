#include <bits/stdc++.h>

using namespace std;

string str;
int n, cntDif, cnt[ 26 ];

int main(){
	
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	//freopen( "/home/vg/Programacion/input", "r", stdin );

	while( cin >> str ){
		n = (int)(str.size());
		for( int i = 0; i < 26; i++ ) cnt[i] = 0;
		for( int i = 0; i < n; i++ ){
			if( !cnt[ str[i] - 'a' ] ) cntDif++;
			++cnt[ str[i] - 'a' ];
		}
		if( cntDif <= 2 ) cout << "0\n";
		else{
			sort( cnt, cnt + 26 );
			cout << (n - cnt[25] - cnt[24]) << "\n";
		}
	}

	return 0;
}