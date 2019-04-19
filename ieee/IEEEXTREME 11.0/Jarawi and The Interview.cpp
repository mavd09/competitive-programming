#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+10, MAXNM = 105, MAXC = 26;
string s, p;
int q, last[ MAXC ][ MAXN ];

void get_last(){
	for( int k = 0; k < MAXC; ++k ) last[ k ][ 0 ] = -1;
	last[ s[0] - 'a' ][ 0 ] = 0;
	for( int i = 1; i < s.size(); ++i ){
		for( int k = 0; k < MAXC; ++k ){
			last[ k ][ i ] = last[ k ][ i-1 ];
		}
		last[ s[i] - 'a' ][ i ] = i;
	}
}

int find(){
	int cnt = 0;
	int p_sz = p.size();
	for( int i = s.size()-1; i >= 0 && (p_sz - cnt - 1) >= 0; --i ){
		i = last[ p[ p_sz - cnt - 1 ]-'a' ][ i ];
		if( i >= 0 ) ++cnt;
	}
	return cnt;
}

int main(){

	cin >> s >> q;
	get_last();
	while( q-- ){
		cin >> p;
		cout << find() << '\n';
	}


	return 0;
}