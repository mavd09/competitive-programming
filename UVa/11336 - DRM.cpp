#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

string map1, map2;
string line, fr, to;
map< string, vector< string > > G1, G2;
set< string > cG1, cG2;

bool can( string f, string t ) {
    set< string > seen;
    queue< string > q;
    q.push( f );
    seen.insert( f );
    while( !q.empty( ) ) {
        string u = q.front( ); q.pop( );
        if( u == t ) return true;
        for( vector< string >::iterator v = G2[ u ].begin( ); v != G2[ u ].end( ); v++ ) {
            if( *v != t && cG1.count( *v ) ) continue;
            if( seen.count( *v ) ) continue;
            seen.insert( *v );
            q.push( *v );
        }
    }
    return false;
}

bool solve( ) {
    for( set< string >::iterator u = cG1.begin( ); u != cG1.end( ); u++ )
        if( !cG2.count( *u ) )
            return false;
    for( map< string, vector< string > >::iterator u = G1.begin( ); u != G1.end( ); u++ )
        for( vector< string >::iterator v = G1[ u->first ].begin( ); v != G1[ u->first ].end( ); v++ )
            if( !can( u->first, *v ) )
                return false;
    return true;
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( getline( cin, map1 ) && map1 != "END" ) {
        G1.clear( );
        cG1.clear( );
        while( getline( cin, line ) && line != "* * *" ) {
            stringstream ss( line );
            ss >> fr >> to;
            G1[ fr ].PB( to );
            G1[ to ].PB( fr );
            cG1.insert( fr );
            cG1.insert( to );
        }
        getline( cin, map2 );
        G2.clear( );
        cG2.clear( );
        while( getline( cin, line ) && line != "* * *" ) {
            stringstream ss( line );
            ss >> fr >> to;
            G2[ fr ].PB( to );
            G2[ to ].PB( fr );
            cG2.insert( fr );
            cG2.insert( to );
        }
        if( solve( ) ) cout << "YES: " << map2 << " is a more detailed version of " << map1 << "\n";
        else           cout << "NO: " << map2 << " is not a more detailed version of " << map1 << "\n";
    }

    return 0;
}
