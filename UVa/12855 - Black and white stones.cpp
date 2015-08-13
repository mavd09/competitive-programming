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

ll a, b;
int sz;
deque< int > W, B;
string s;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> a >> b >> s ) {
        W.clear( ); B.clear( );
        sz = int( s.size( ) );
        for( int i = 0; i < sz; i++ ) {
            if( s[ i ] == 'W' ) W.push_back( i );
            if( s[ i ] == 'B' ) B.push_back( i );
        }
        ll ans = 0;
        while( W.size( ) && B.size( ) ) {
            int curW = W.front( ); W.pop_front( );
            int curB = B.back( );  B.pop_back( );
            if( curB < curW ) break;
            ans += min( ll(curB-curW)*(a-b), a );
        }
        cout << ans << "\n";
    }

    return 0;
}
