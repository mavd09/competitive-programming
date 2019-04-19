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

int nTest, sz;
string line, d, w;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    cin.ignore( );
    while( nTest-- ) {
        map< string, vector< string > > D;
        getline( cin, line );
        stringstream ss1( line );
        while( ss1 >> d ) {
            w = d;
            sort( w.begin( ), w.end( ) );
            D[ w ].PB( d );
        }
        getline( cin, line );
        stringstream ss2( line );
        int t = 0;
        while( ss2 >> d ) {
            w = d;
            sz = int( d.size( ) );
            sort( w.begin( ), w.end( ) );
            vector< string > tmp = D[ w ];
            bool found = false;
            if( t ) cout << " ";
            t++;
            for( int i = 0; i < int( tmp.size( ) ); i++ ) {
                if( d[ 0 ] == tmp[ i ][ 0 ] && d[ sz-1 ] == tmp[ i ][ sz-1 ] ) {
                    found = true;
                    cout << tmp[ i ];
                    break;
                }
            }
            if( !found ) cout << d;
        }
        cout << "\n";
    }

    return 0;
}
