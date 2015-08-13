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

string word[ ] = { "Hajj"        , "Umrah"         };
string ans[ ]  = { "Hajj-e-Akbar", "Hajj-e-Asghar" };
string w;
int t;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> w ) && ( w != "*" ) ) {
        if( w == word[ 0 ] ) cout << "Case " << ++t << ": " << ans[ 0 ] << "\n";
        if( w == word[ 1 ] ) cout << "Case " << ++t << ": " << ans[ 1 ] << "\n";
    }

    return 0;
}
