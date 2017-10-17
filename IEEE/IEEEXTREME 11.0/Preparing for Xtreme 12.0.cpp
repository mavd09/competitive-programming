#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, cur_id;
int dp[ 1<<21 ];
int ts[ 110 ], masks[ 110 ];
map< string, int > ids;

/*int solve( int pos, int cur_mask ){
	if( pos == n ){
		if( cur_mask == (1<<cur_id)-1 ) return 0;
		return INF;
	}
	int &r = dp[ pos ][ cur_mask ];
	if( r == -1 ){
		r = min( solve( pos+1, cur_mask ), 
			min( INF, ts[ pos ] + solve( pos+1, cur_mask|masks[pos] ) ) );
	}
	return r;
}*/

int main(){
	string name, line;
	while( getline( cin, line ) ){
		stringstream in( line );
		in >> ts[ n ];
		while( in >> name ){
			if( !ids.count( name ) ) ids[ name ] = cur_id++;
			masks[ n ] |= (1 << ids[ name ] );
		}
		++n;
	}

	int max_mask = (1 << cur_id) - 1;
	dp[ 0 ] = 0;
	for( int cur_mask = 1; cur_mask <= max_mask; ++cur_mask ) dp[ cur_mask ] = INF;

	for( int i = 0; i < n; ++i ){
		for( int cur_mask = max_mask; cur_mask >= 0; --cur_mask ){
			if( cur_mask == INF ) continue;
			dp[ cur_mask | masks[ i ] ] = min( dp[ cur_mask | masks[ i ] ], dp[ cur_mask ] + ts[ i ] );
		}
	}

	cout << dp[ max_mask ] << endl;

	return 0;
}