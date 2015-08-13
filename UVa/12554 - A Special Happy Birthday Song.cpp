#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 200 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, id;
string song[ ] = { "Happy", "birthday", "to", "you",
                   "Happy", "birthday", "to", "you",
                   "Happy", "birthday", "to", "Rujia",
                   "Happy", "birthday", "to", "you" };
string name[ MAX ];

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> name[ i ];
    for( int i = 0; i < int( ceil( n/16.0 ) ); i++ ) {
        for( int j = 0; j < 16; j++, (id += 1) %= n )
            cout << name[ id ] << ": " << song[ j ] << "\n";
    }

    return 0;
}
