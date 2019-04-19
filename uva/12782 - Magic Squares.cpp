#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 20 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, sum, tam;
int d[ MAX ];
int r[ MAX ], c[ MAX ];
int cntR[ MAX ], cntC[ MAX ];
int x[ MAX ];
deque< pair< int, int > > all;

string line;

bool dfs( int id ) {
    if( id == n ) return true;
    int sz = all.size( );
    bool ret = false, flag = false;
    while( sz-- ) {
        pair< int, int > cur = all.front( ); all.pop_front( );
        if( flag ) {
            all.PB( cur );
            continue;
        }
        /*if( cntR[ cur.FI ]+1 == tam && r[ cur.FI ]+x[ id ] != sum ) {
            all.PB( cur );
            flag = true;
            continue;
        }
        if( cntC[ cur.SE ]+1 == tam && c[ cur.SE ]+x[ id ] != sum ) {
            all.PB( cur );
            flag = true;
            continue;
        }
        if( ( sum >= 0 && sum-( r[ cur.FI ]+x[ id ] ) < x[ id ] ) || ( sum < 0 && sum-( r[ cur.FI ]+x[ id ] ) < x[ id ] ) ) {
            all.PB( cur );
            flag = true;
            continue;
        }*/
        if( ( sum >= 0 && sum-( c[ cur.SE ]+x[ id ] ) < x[ id ] ) || ( sum < 0 && sum-( c[ cur.SE ]+x[ id ] ) < x[ id ] ) ) {
            all.PB( cur );
            flag = true;
            continue;
        }
        if( ( sum >= 0 && r[ cur.FI ]+x[ id ] > sum ) || ( sum < 0 && r[ cur.FI ]+x[ id ] < sum ) ) {
            all.PB( cur );
            flag = true;
            continue;
        }
        if( ( sum >= 0 && c[ cur.SE ]+x[ id ] > sum ) || ( sum < 0 && c[ cur.SE ]+x[ id ] < sum ) ) {
            all.PB( cur );
            flag = true;
            continue;
        }
        if( cur.FI == cur.SE && ( ( sum >= 0 && d[ 0 ]+x[ id ] > sum ) || ( sum < 0 && d[ 0 ]+x[ id ] < sum ) ) ) {
            all.PB( cur );
            flag = true;
            continue;
        }
        if( cur.FI == tam-cur.SE-1 && ( ( sum >= 0 && d[ 1 ]+x[ id ] > sum ) || ( sum < 0 && d[ 1 ]+x[ id ] < sum ) ) ) {
            all.PB( cur );
            flag = true;
            continue;
        }
        r[ cur.FI ] += x[ id ]; cntR[ cur.FI ]++;
        c[ cur.SE ] += x[ id ]; cntC[ cur.SE ]++;
        if( cur.FI == cur.SE ) d[ 0 ] += x[ id ];
        else if( cur.FI == tam-cur.SE-1 ) d[ 1 ] += x[ id ];
        ret |= dfs( id+1 );
        all.PB( cur );
        r[ cur.FI ] -= x[ id ]; cntR[ cur.FI ]--;
        c[ cur.SE ] -= x[ id ]; cntC[ cur.SE ]--;
        if( cur.FI == cur.SE ) d[ 0 ] -= x[ id ];
        else if( cur.FI == tam-cur.SE-1 ) d[ 1 ] -= x[ id ];
        if( ret ) flag = true;
    }
    return ret;
}

bool check( ) {
    if( n == 1 ) return true;
    tam = sqrt( n );
    if( tam*tam != n || sum%tam ) return false;
    sum /= tam;
    all.clear( );
    for( int i = 0; i < tam; i++ )
        for( int j = 0; j < tam; j++ )
            all.PB( MP( i, j ) );
    sort( x, x+n );
    return dfs( 0 );
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( getline( cin, line ) ) {
        stringstream ss( line );
        for( n = 0, sum = 0; ss >> x[ n ]; sum += x[ n ], n++ );
        cout << ( check( ) ? "Y" : "N" ) << "\n";
        cout << "breve" << endl;
    }

    return 0;
}
